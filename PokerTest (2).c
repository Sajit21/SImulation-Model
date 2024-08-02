#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate random numbers using Arithmetic Congruential Generator
void generateRandomNumbers(int Xo, int X1, int m, int randomNumbers[], int count) {
    int X[count];
    X[0] = Xo;
    X[1] = X1;

    for (int i = 2; i < count; i++) {
        X[i] = (X[i - 1] + X[i - 2]) % m;
        randomNumbers[i - 2] = X[i]; // Storing random numbers generated
    }
}

// Function to calculate observed frequencies for each class interval
void calculateObservedFrequencies(int randomNumbers[], int observedFreq[], int count) {
    for (int i = 0; i < count; i++) {
        int num = randomNumbers[i];
        int digits[4];
        for (int j = 0; j < 4; j++) {
            digits[j] = num % 10;
            num /= 10;
        }
        int uniqueDigits = 0;
        int freq[10] = {0}; // Frequency of each digit

        for (int j = 0; j < 4; j++) {
            if (freq[digits[j]] == 0) {
                uniqueDigits++;
            }
            freq[digits[j]]++;
        }

        if (uniqueDigits == 1) {
            observedFreq[0]++; // All same
        } else if (uniqueDigits == 4) {
            observedFreq[1]++; // All different
        } else if (uniqueDigits == 2) {
            for (int j = 0; j < 10; j++) {
                if (freq[j] == 3) {
                    observedFreq[2]++; // Three of a kind
                    break;
                } else if (freq[j] == 2) {
                    observedFreq[3]++; // One pair
                    break;
                }
            }
        } else if (uniqueDigits == 3) {
            observedFreq[4]++; // Two pairs
        }
    }
}

// Function to perform Poker Test
void pokerTest(int observedFreq[], int totalCount) {
    double expectedFreq[] = {0.001 * totalCount, 0.504 * totalCount, 0.036 * totalCount, 0.432 * totalCount, 0.027 * totalCount};
    double chiSquare = 0;

    printf("Class Interval\tExpected Frequency\tObserved Frequency\tO_i - E_i\t(O_i - E_i)^2\tX_0^2\n");

    for (int i = 0; i < 5; i++) {
        double O_minus_E = observedFreq[i] - expectedFreq[i];
        double O_minus_E_squared = pow(O_minus_E, 2);
        double X_0_squared = O_minus_E_squared / expectedFreq[i];
        chiSquare += X_0_squared;
        printf("%d\t\t%.3lf\t\t\t%d\t\t\t%.3lf\t\t%.3lf\t\t%.3lf\n", i + 1, expectedFreq[i], observedFreq[i], O_minus_E, O_minus_E_squared, X_0_squared);
    }

    printf("\nChi-Square value: %lf\n", chiSquare);
    printf("Critical value: 9.49\n");

    if (chiSquare > 9.49) {
        printf("Chi-Square value exceeds critical value. Random numbers are not independent.\n");
    } else {
        printf("Chi-Square value does not exceed critical value. Random numbers are independent.\n");
    }
}


int main() {
    // Step 1: Generate 1000 random numbers
    int Xo = 111, X1 = 212, m = 10000;
    int count = 1002;
    int randomNumbers[count - 2];
    generateRandomNumbers(Xo, X1, m, randomNumbers, count);

    // Displaying generated random numbers
    printf("Generated random numbers:\n");
    for (int i = 0; i < count - 2; i++) {
        printf("%04d ", randomNumbers[i]);
        if ((i + 1) % 10 == 0) {
//            printf("\n");
        }
    }
    printf("\n\n");

    // Step 2: Perform Poker Test
    int observedFreq[5] = {0}; // All same, All different, Three of a kind, One pair, Two pairs
    calculateObservedFrequencies(randomNumbers, observedFreq, count - 2);

    printf("Observed Frequencies:\n");
    printf("All same: %d\n", observedFreq[0]);
    printf("All different: %d\n", observedFreq[1]);
    printf("Three of a kind: %d\n", observedFreq[2]);
    printf("One pair: %d\n", observedFreq[3]);
    printf("Two pairs: %d\n\n", observedFreq[4]);

    printf("Performing Poker Test...\n");
    pokerTest(observedFreq, count - 2);

    return 0;
}


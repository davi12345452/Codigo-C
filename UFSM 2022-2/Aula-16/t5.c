#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GUESSES 10
#define CODE_LENGTH 4

// Generate a random code with 4 digits, each in the range 0-6
int* generateCode() {
    static int code[CODE_LENGTH];
    for (int i = 0; i < CODE_LENGTH; i++) {
        code[i] = rand() % 7;
    }
    return code;
}

// Check the guess and return the number of correct digits in the correct position
// and the number of correct digits in the wrong position
int checkGuess(int* code, int* guess, int* correctPos, int* correctNum) {
    *correctPos = *correctNum = 0;
    int used[CODE_LENGTH] = {0};
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] == code[i]) {
            (*correctPos)++;
            used[i] = 1;
        }
    }
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (!used[i]) {
            for (int j = 0; j < CODE_LENGTH; j++) {
                if (!used[j] && guess[i] == code[j]) {
                    (*correctNum)++;
                    used[j] = 1;
                    break;
                }
            }
        }
    }
}

int main() {
    srand(time(0));

    int* code = generateCode();
    int numGuesses = 0;
    int correctPos, correctNum;
    int guess[CODE_LENGTH];

    while (numGuesses < MAX_GUESSES) {
        printf("Enter your guess (%d digits, each 0-6): ", CODE_LENGTH);
        for (int i = 0; i < CODE_LENGTH; i++) {
            scanf("%d", &guess[i]);
        }
        checkGuess(code, guess, &correctPos, &correctNum);
        printf("%d correct digits in the correct position\n", correctPos);
        printf("%d correct digits in the wrong position\n", correctNum);
        if (correctPos == CODE_LENGTH) {
            printf("You win!\n");
            break;
        }
        numGuesses++;
    }
    if (numGuesses == MAX_GUESSES) {
        printf("You lose! The correct code was: ");
        for (int i = 0; i < CODE_LENGTH; i++) {
            printf("%d ", code[i]);
        }
        printf("\n");
    }

    return 0;
}


#include <stdio.h>

int possibilities(int score) {
    // below are short descriptions of each variable
    // TD is just a touchdown
    // FG is a single field goal
    // Safety is a single safety
    // TD2 is a touchdown plus a 2 point conversion
    // TD1 is a touchdown plus an extra point
    int TD, FG, Safety, TD2, TD1;

    // tracking possible combinations with count variable
    int count = 0;

    // loop for all possible combinations
    for (TD = 0; TD <= score / 6; TD++) {
        for (TD1 = 0; TD1 <= score / 7; TD1++) {
            for (TD2 = 0; TD2 <= score / 8; TD2++) {
                for (FG = 0; FG <= score / 3; FG++) {
                    for (Safety = 0; Safety <= score / 2; Safety++) {
                        // check if the combination matches the given score
                        if ((TD * 6) + (TD1 * 7) + (TD2 * 8) + (FG * 3) + (Safety * 2) == score) {
                            // print the valid combination
                            printf("TD: %d, TD1: %d, TD2: %d, FG: %d, Safety: %d\n", TD, TD1, TD2, FG, Safety);
                            count++;
                        }
                    }
                }
            }
        }
    }

    // outputting possible combinations based on score inputted
    printf("There are %d combinations of scoring plays if a team's score is %d\n\n", count, score);
    return 0;
}


int main() {
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score:");
        scanf("%d",&score);

        if (score == 0 || score == 1) {
            // breaking out of loop if user enters 0 or 1
            break;
        }

        possibilities(score);
    }

    return 0;
}
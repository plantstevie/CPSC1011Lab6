#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    bool playing = true;
    char selection;
    int rosterLength;
    int replaceNum;
    int rating;
    int k = 0;
    int j = 0;

    printf("How many players to enter: \n");
    scanf(" %d", &rosterLength);
    int roster[rosterLength][2];
    for (int i = 0; i < rosterLength; ++i) {
        printf("Enter player %d's jersey number:\n", i + 1);
        scanf(" %d", &roster[i][0]);
        printf("Enter player %d's rating:\n", i + 1);
        scanf(" %d", &roster[i][1]);    
        printf("\n");    
    }
    while (playing == true) {
        // main menu
        printf("MENU\n");
        printf("p - Print roster\n");
        printf("u - Update player rating\n");
        printf("a - Print players above a rating\n");
        printf("r - Replace player\n");
        printf("q - Quit\n");
        printf("Choose an option:\n");
        scanf(" %c", &selection);

        // selection statement
        switch (selection) {
        // p option
            case 'p':
                printf("PLAYER ROSTER\n");
                printf("----------------------------\n");
                printf("|  Player|  Jersey|  Rating|\n");
                for (int i = 0; i < rosterLength; ++i) {
                    printf("|%8d|%8d|%8d|\n", i + 1, roster[i][0], roster[i][1]);
                }
                printf("----------------------------\n");
                break;
        // u option
            case 'u':
                printf("Enter a jersey number:\n");
                scanf(" %d", &replaceNum);
                for (int i = 0; i < rosterLength; ++i) {
                    if (roster[i][0] == replaceNum) {
                        printf("Enter a new rating for player:\n");
                        scanf(" %d", &roster[i][1]);
                        ++k;
                    }
                }
                if (k < 1) {
                     printf("Player not in roster.\n");
                }
                k = 0;
                break;
        // a option
            case 'a':
                printf("Enter a rating:\n");
                scanf(" %d", &rating);
                printf("PLAYER RATING ABOVE %d\n", rating);
                printf("----------------------------\n");
                printf("|  Player|  Jersey|  Rating|\n");
                for (int i = 0; i < rosterLength; ++i) {
                    if (roster[i][1] > rating) {
                        printf("|%8d|%8d|%8d|\n", i + 1, roster[i][0], roster[i][1]);
                    }
                }
                printf("----------------------------\n");
                break;
        // r option
            case 'r':
                printf("Enter a jersey number:\n");
                scanf(" %d", &replaceNum);
                for (int i = 0; i < rosterLength; ++i) {
                    if (roster[i][0] == replaceNum) {
                        printf("Enter a new jersey number:\n");
                        scanf(" %d", &roster[i][0]);
                        printf("Enter a rating for the new player:\n");
                        scanf(" %d", &roster[i][1]);
                        ++j;
                    }
                }
                if (j < 1) {
                     printf("Player not in roster.\n");
                }
                j = 0;
                break;
        // q option
            case 'q':
                playing = false;
                break;
        // error message
            default:
                printf("Please enter a valid option\n");
                break;
        }
    }
}
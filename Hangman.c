
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int
main(int argc, char *argv[]) {

    srand(time(NULL));
    
    char AnswerOptions[4][11] ={
        "swift",
        "python",
        "javascript",
        "c++"
    };

    int LivesRemaining = 3;
    int CorrectAnswers = 0;
  
    int n = rand() % 4 ;    

    char Answer[11];
    strcpy(Answer,AnswerOptions[n]);
    int AnswerLength = strlen(Answer);
    int LetterFound = 0;

    int LettersGuessed[] = {0,0,0,0,0,0,0,0,0,0};
    char InputCharacter;

    printf("\n\nThis is a game of hangman\n\nThe words are all coding languages\n\nYou will have 3 chances before you're hanged\n\n");


    while ( CorrectAnswers < AnswerLength ){
        LetterFound = 0;

        printf("Lives Remaining %d\n\n", LivesRemaining);
        printf("(");
        for ( int j = 0; j < AnswerLength; j++) {
            if (LettersGuessed[j] == 1 ) {
                printf("%c", Answer[j] );
            } else { 
                printf("_");
                }

        }
        printf(")");
        
        /* prints out correct letters */

        printf("\n\nPlease enter a letter\n\n");
        scanf(" %c", &InputCharacter);
        /* input form user */

        for ( int i = 0; i < AnswerLength; i++ ) {
            if (LettersGuessed[i] == 1 ) {
                continue;
            }

            if ( InputCharacter == Answer[i] || InputCharacter == Answer[i]+32 ) {
                LettersGuessed[i] = 1;
                CorrectAnswers++;
                LetterFound = 1;
                break;
            }
        }

        if ( LetterFound  == 0 ) {
            LivesRemaining--;
            printf("\nUh-oh! Thats the wrong Letter\n");
        }


        if ( LivesRemaining == 0 ) {
            printf("You've ran out of lives and have been hanged :(\n Try again next time\nThe word was %s",Answer);
            exit(1);
        }

        /* checks lettser in answer , skips dupilcates */
        printf("\n\n--------------------------------\n\n\n");
    }

    printf("You solved it, congratulations!\n\n");
    printf("\nThe word was %s\n", Answer);

// functions pulled from this loop

    return 0;
}



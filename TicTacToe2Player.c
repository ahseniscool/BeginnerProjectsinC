#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
/* player 1 = X
player 2 = O
*/

/*****************************************************/

void Printboard(int[3][3], int[2]);
int Checkwin(int[3][3],int[2]);
void Turninput (int[3][3],int[2]);
// turns contains the turncount ( turns[0]) and the plyer whose current turn it is  ( turns[1])
// board is simply the state of the board at the moment 

int
main(int argc, char *argv[]) {
    int result = 0;

    int turns[2] = {1,1};
    int board[3][3] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };

   do {
        printf("---------------------\n");
        printf("Turn Number %d\n", turns[0]);
        printf("---------------------\n\n");
        Printboard(board,turns);
        Turninput(board,turns);
        result = Checkwin(board,turns);
        if ( turns[1] == 1 ) {
            turns[1] = 2;
        } else { turns[1] = 1; 
        }
        turns[0]++;
   }  while (result == 0);
   
   result = Checkwin(board,turns);

   if ( result == 1 ) {
    printf("\n3 in A ROW !!, Player 1 won\n");

   } else if ( result == 2 ) {
    printf("\n3 in A ROW !!, Player 2 won\n");

   } else {
    printf("\nA tie ...\n");
   }

   printf("\n\n");
   Printboard(board,turns);
   exit(0);
}

/*****************************************************/
// prints the baord after a turn //

void 
Printboard ( int board[3][3], int turn[2] ) 
{
    for ( int i = 0; i < 3 ; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            if( ( board[j][2-i] ) == 1 ) {
                printf("X");
                } else if ( ( board[j][2-i] ) == 2 ) {
                    printf("0");
                } else {
                    printf(" ");
                }
             if ( j!= 2 ) {
                printf("|");
            } 
            }
        if ( i != 2 ) {
            printf("\n-----\n");
        }         
        }        
        printf("\n");
}

/*****************************************************/
// returns 0 if the game is still going, 1 if player 1 wins, 2 if player 2 wins , 3 for a tie//
// checks 
int 
Checkwin(int board[3][3],int turns[2]) {
for ( int i = 0; i < 3; i ++ ) {
    if ( board[0][i] != 0 && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
        return board[0][i];
    }
}

for ( int i = 0; i < 3; i ++ ) {
    if ( board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2]){
        return board[i][0];
    }
}

if ( board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
    return board[0][0];
}

if ( board[0][2] != 0 && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
    return board[0][2];
}

if ( turns[0] == 9 ) {
    return 3;
}
return 0;
} 

/*****************************************************/

void Turninput(int board[3][3], int turns[2]) {
    int x = 0, y = 0, satisfied = 0, attempts = 0;
    char exit;

    while (attempts < 5) {
        printf("\n\nIt is Player %d's turn\nEnter the coordinate (x,y): ", turns[1]);
        
        if (scanf(" (%d,%d)", &x, &y) == 2) {
            x--;
            y--;
            if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && board[x][y] == 0) {
                board[x][y] = turns[1];
                satisfied = 1;
                break;
            } else {
                printf("Please enter valid coordinates (x,y) between 1 and 3 without a marking.\n");
            }
        } else {
            printf("Invalid input format. Please enter coordinates in the format (x,y).\n");
        }
        
        while (getchar() != '\n'); // Clear input buffer
        attempts++;
    }

    if (satisfied == 0) {
        printf("Maximum attempts reached. Exiting turn.\n");
        turns[1] = (turns[1] == 1) ? 2 : 1; // Switch player
    }
}
/***************************************************/
 
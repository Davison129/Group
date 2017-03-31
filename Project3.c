#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Slot Declarations
enum slotType {levelGround, Hill, City};
struct slotList{
	int slotRow;					// The slot row index
	int slotCol;					// The slot column index
	enum slotType sType;			// enum to index slot types
	char slotLabel[15];				// char representation of slot type
	int Occupied;					// Denotes whether or not slot is occupied
	struct playerStats *playerOn;	// Points to the player on the slot if applicable, otherwise NULL
	struct slotList *sUp;			// Points to the slot above
	struct slotList *sDown;			// Points to the slot below
	struct slotList *sLeft;			// Points to the slot to the left
	struct slotList *sRight;		// Points to the slot to the right
};
struct slotList *sCurrent;
struct slotList *sPtr;
struct slotList *upLeft;
struct slotList *upRight;
struct slotList *downLeft;
struct slotList *downRight;
struct slotList *rowStart;

int main(void)
{
	srand(time(NULL));						// Ensure rand is random each  time
	setvbuf(stdout, NULL, _IONBF, 0);		// To make each printf occur automatically in Eclipse

	int i,j;
// Build board
	struct slotList gameBoard[7][7];

/*	upLeft = &gameBoard[0][0];
		upLeft->sUp = NULL;
		upLeft->sDown = &gameBoard[1][0];
		upLeft->sLeft = NULL;
		upLeft->sRight = &gameBoard[0][1];
	upRight = &gameBoard[0][6];
		upRight->sUp = NULL;
		upRight->sDown = &gameBoard[1][6];
		upRight->sLeft = &gameBoard[0][5];
		upRight->sRight = NULL;
	downLeft = &gameBoard[6][0];
		downLeft->sUp = &gameBoard[5][0];
		downLeft->sDown = NULL;
		downLeft->sLeft = NULL;
		downLeft->sRight = &gameBoard[6][1];
	downRight = &gameBoard[6][6];
		downRight->sUp = &gameBoard[5][6];
		downRight->sDown = NULL;
		downRight->sLeft = &gameBoard[6][5];
		downRight->sRight = NULL;
*/


	for(i=1 ; i<8 ; i++){
		for(j=1 ; j<8 ; j++){
			sPtr = malloc(7*sizeof(struct slotList));
			sPtr = &gameBoard[i-1][j-1];
			sPtr->slotRow = i;
			sPtr->slotCol = j;
			sPtr->sType = rand()%4;
			sPtr->playerOn = NULL;
			switch(sPtr->sType){			// Label slots for easier reference to user
			case 0:
				strcpy(sPtr->slotLabel, "Level Ground");
				break;
			case 1:
				strcpy(sPtr->slotLabel, "Hill");
				break;
			case 2:
				strcpy(sPtr->slotLabel, "City");
				break;
			}
// Put in if statement to blanket assign if not corner!!!!
		for(i=1 ; i<6 ; i++){
			for(j=1 ; j<6 ; j++){

			}
		}

/*			switch(sPtr->slotRow){
			case 1:
				sPtr->sUp = NULL;
				sPtr->sDown = &gameBoard[1][j];
				break;
			case 2:
				sPtr->sUp = &gameBoard[0][j];
				sPtr->sDown = &gameBoard[2][j];
				break;
			case 3:
				sPtr->sUp = &gameBoard[1][j];
				sPtr->sDown = &gameBoard[3][j];
				break;
			case 4:
				sPtr->sUp = &gameBoard[2][j];
				sPtr->sDown = &gameBoard[4][j];
				break;
			case 5:
				sPtr->sUp = &gameBoard[3][j];
				sPtr->sDown = &gameBoard[5][j];
				break;
			case 6:
				sPtr->sUp = &gameBoard[4][j];
				sPtr->sDown = &gameBoard[6][j];
				break;
			case 7:
				sPtr->sUp = &gameBoard[5][j];
				sPtr->sDown = NULL;
				break;
			default:
				sPtr->sUp = &gameBoard[i-1][j];
				sPtr->sDown = &gameBoard[i+1][j];
			}
			switch(sPtr->slotCol){
			case 1:
				sPtr->sLeft = NULL;
				sPtr->sRight = &gameBoard[i][1];
				break;
			case 7:
				sPtr->sLeft = &gameBoard[i][5];
				sPtr->sRight = NULL;
				break;
			default:
				sPtr->sLeft = &gameBoard[i][j-1];
				sPtr->sRight = &gameBoard[i][j+1];
				break;
			}
*/
/*
			sPtr->sUp = &gameBoard[i-1][j];
			sPtr->sDown = &gameBoard[i+1][j];
			sPtr->sLeft = &gameBoard[i][j-1];
			sPtr->sRight = &gameBoard[i][j+1];
*/
		}
	}

	upLeft = &gameBoard[0][0];
	upRight = &gameBoard[0][6];
	downLeft = &gameBoard[6][0];
	downRight = &gameBoard[6][6];

	for(i=0 ; i<7 ; i++){
		for(j=0 ; j<7 ; j++){
			sPtr = &gameBoard[i][j];
			printf("%d%d\t",sPtr->slotRow,sPtr->slotCol);
		}
		puts("\n");
	}

/*	sPtr=upLeft;
	rowStart=sPtr->sDown;
	i=1;
	while(sPtr->sRight!=NULL || sPtr->sDown!=NULL){
		do{
			printf("%d%d",sPtr->slotRow,sPtr->slotCol);
			sPtr = sPtr->sRight;
		}while(sPtr->sRight != NULL);
		sPtr=rowStart;
		rowStart=rowStart->sDown;
		puts("\n");
	}
*/


	return 0;
}


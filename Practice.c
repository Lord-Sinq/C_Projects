#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

// global variables
//int userChoice;

// questions game
int q;
int counter = 0;
char qgAgain;
char q1[100];
char q2[100];
char q3[100];
char q4[100];
char q5[100];

// question game function
void questionGame(){
	// holds the logic for the points you gain and lose in the game
	while (true) {

		// game
		printf("\n==Welcome==\nYou have 5 questions.\n");

		for (q = 0;q < 5; q++){
			q++;
			printf("Question %d: 1 ", q);
			scanf("%s", q1);
			q++;
			printf("Question %d: 2 ", q);
			scanf("%s", q2);
			q++;
			printf("Question %d: 3 ", q);
			scanf("%s", q3);
			q++;
			printf("Question %d: 4 ", q);
			scanf("%s", q4);
			q++;
			printf("Question %d: 5 ", q);
			scanf("%s", q5);

			//printf("%d", q);

			//results

			//check if they want to play again
			printf("\nWould you like to play again\n");
			printf("enter a ( Y ) to play again?\n");
			printf("enter a ( N ) to go back to the menu?\n");
			scanf("%c", qgAgain);

			while (qgAgain != "\n");

			if (qgAgain == 'y' || qgAgain == 'Y'){
				q = -1;
			}
		}

		// end while loop
		break;
	}
}

// main fucntion
int main(){

	int userChoice;

	printf("!!!!!!!!!!!!!!!!!!!!!!!HELLO!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("!-------Please pick a number 1-2 for a game--------!\n");
	printf("!--------------------------------------------------!\n");
	printf("! (1)Question Game            (2)Next Game         !\n");
	printf("!__________________________________________________!\n");
	scanf("%d", &userChoice);

	switch (userChoice){
	case 1:
		printf("Question game!");
		questionGame();
		break;
	case 2:
		printf("Next game!");
		break;
	}


	return 0;
}
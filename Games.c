#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

// math game
void mathGame() {

}

// questions game
int counter = 0;
bool playAgain = false;
char qgAgain;
char q1[100];
char q2[100];
char q3[100];
char q4[100];
char q5[100];
char qgUserAnswer[];
char qgCorrectAnswer[] = {'True','A','D','C','Yes'};

bool checkAnswers( char qgUserAnswer, char qgCorrectAnswer);

// question game function
void questionGame(){
	// holds the logic for the points you gain and lose in the game
	do {

		// game
		printf("\n==Welcome==\nYou have 5 questions.\n");

		for (int q = 1;q <= 5; q++){
			printf("Question %d: Is the statement true or false.\n", q);
			printf("I have a male cat. \n:");
			scanf("%s", q1);
			q++;
			printf("Question %d: Pick the correct answer\n", q);
			printf(" ");
			scanf("%s", q2);
			q++;
			printf("Question %d: Pick the correct answer\n", q);
			scanf("%s", q3);
			q++;
			printf("Question %d: Pick the correct answer\n", q);
			scanf("%s", q4);
			q++;
			printf("Question %d: Last question\n", q);
			printf("Do you love me????\n:");
			scanf("%s", q5);

			//results


		}

	} while (playAgain);
}

void checkPlayAgain() {
	//check if they want to play again
	printf("\nWould you like to play again\n");
	printf("enter a ( Y ) to play again?\nenter a ( N ) to go back to the menu?\n");

	// consumes any newline char left in the buffer
	while ((getchar()) != '\n');

	while(1){

		// stops for user input
		scanf(" %c", &qgAgain);

		// consumes new line char
		while (getchar() != '\n');


		if (qgAgain == 'y' || qgAgain == 'Y'){
			//reset the questions (q) to count from 0
			playAgain = true;
			break;

		} else if (qgAgain == 'n' || qgAgain == 'N'){
			// back to the game menu
			playAgain = false;
			break;
		} else {
			printf("Please enter a ( Y ) to play again or a ( N ) to stop!\n");
			// consumes any remaining char in the nput buffer
			while (getchar() != '\n');
		}
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
			do {
				printf("Question game!");
				questionGame();
				// check if they want to play again
				checkPlayAgain();

			} while (playAgain);
			break;
		case 2:
			do {
				printf("Math game!");
				mathGame();
				// check if they want to play again
				checkPlayAgain();

			} while (playAgain);
			break;

		default:
			printf("default choice\n");
			break;
	}


	return 0;
}
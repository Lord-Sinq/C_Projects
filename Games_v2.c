#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <setjmp.h>

// function decloration
bool checkAnswers( char qgUserAnswer, char qgCorrectAnswer);
void mathGame();
void diceGame();
char checkPlayAgain();
void questionGame();

// dice game
void diceGame() {

}
// math game
void mathGame() {

}

// questions game

#define ARRAY_SIZE 5

int counter = 0;
bool playAgain = false;
char qgAgain;
char q1[100];
char q2[100];
char q3[100];
char q4[100];
char q5[100];

// question game function
void questionGame(){
	/*Question game
	it asks 5 questions and scores
	the user based on there response*/
	
	// correct answers & users answers
	char qgCorrectAnswer[ARRAY_SIZE] = {'t','a','d','c','y'};
	char qgUserAnswer[ARRAY_SIZE];

	// copy the correct ans to the users ans array
	memcpy(qgUserAnswer, qgCorrectAnswer, ARRAY_SIZE * sizeof(char));

	// holds the logic for the points you gain and lose in the game
	do {

		int q = 1;
		int qgUserScore = 0;
		char q1UserAns;
		char q2UserAns;
		char q3UserAns;
		char q4UserAns;
		char q5UserAns;
		char temp;

		// game
		printf("\n==Welcome==\nYou have 5 questions.\n");

		//q1
		printf("Question %d: Is the statement true or false.\n", q++);
		printf("I have a male cat. \n: ");
		scanf(" %1s", &q1UserAns);
		qgUserAnswer[0] = tolower(q1UserAns);

		// clear the input buffer
		while ((temp = getchar()) != '\n' && temp != EOF);

		//q2
		printf("Question %d: Pick the correct answer\n: ", q++);
		scanf(" %1s", &q2UserAns);
		qgUserAnswer[1] = tolower(q2UserAns);

		// clear the input buffer
		while ((temp = getchar()) != '\n' && temp != EOF);

		//q3
		printf("Question %d: Pick the correct answer\n: ", q++);
		scanf(" %1s", &q3UserAns);
		qgUserAnswer[2] = tolower(q3UserAns);

		// clear the input buffer
		while ((temp = getchar()) != '\n' && temp != EOF);

		//q4
		printf("Question %d: Pick the correct answer\n: ", q++);
		scanf(" %1s", &q4UserAns);
		qgUserAnswer[3] = tolower(q4UserAns);

		// clear the input buffer
		while ((temp = getchar()) != '\n' && temp != EOF);

		//q5
		printf("Question %d: Last question\n", q);
		printf("Do you love me????\n: ");
		scanf(" %1s", &q5UserAns);
		qgUserAnswer[4] = tolower(q5UserAns);


		// clear the input buffer
		while ((temp = getchar()) != '\n' && temp != EOF);

		printf("Your answers are:\n");
		for (int i = 0; i < ARRAY_SIZE; i++){
			printf("Q%d: %c\n", i + 1, qgUserAnswer[i]);
		}

		//check answer1
		for (int i = 0; i < ARRAY_SIZE; i++){
			bool qgResult = checkAnswers(qgUserAnswer[i], qgCorrectAnswer[i]);
			if (qgResult){
				qgUserScore += 20;
			}
		}
		printf("\nScore: %d out of 100\n", qgUserScore);
		if (qgUserScore == 100) {
			printf("!!! Congragulations you got a 100 !!!\n");
		}
		// check if they want to play again
		checkPlayAgain();

	} while (playAgain);
}

bool checkAnswers(char qgUserAnswer, char qgCorrectAnswer) {
	// compares users answer to the correct list
	return qgUserAnswer == qgCorrectAnswer;
}

char checkPlayAgain() {
	/*Check if user want to play or if the 
	user wants to go to the main menu*/

	char qgAgain;

	//check if they want to play again
	printf("\nWould you like to play again\n");
	printf("enter a ( Y ) to play again and\nor a ( N ) to go back to the menu.\n");

	while(1){

		// stops for user input
		scanf(" %c", &qgAgain);

		// consumes the input buffer
		while (getchar() != '\n');


		if (qgAgain == 'y' || qgAgain == 'Y'){
			return qgAgain;
		} else {
			printf("Please enter a ( Y ) to play again or a ( N ) to stop!\n");
		}
	}
}


// main fucntion
int main(){

	int userChoice;
	char qgAgain;
	bool keepRunning = true;

	while(keepRunning){
		printf("!!!!!!!!!!!!!!!!!!!!!!!HELLO!!!!!!!!!!!!!!!!!!!!!!!!\n");
		printf("!-------Please pick a number 1-9 for a game--------!\n");
		printf("!--------------------------------------------------!\n");
		printf("! (1) Question Game            (2) Math Game       !\n");
		printf("! (3) Dice Game                (9) Exit Game Menu  !\n");
		printf("!__________________________________________________!\n");


		scanf("%d", &userChoice);

		// clear input buffer after interger input
		while(getchar() != '\n');

		switch (userChoice){
			case 1:
				do {
					printf("Question game!");
					questionGame();
					// ask if use wants to play again
					qgAgain = checkPlayAgain();
				} while (tolower(qgAgain) == 'y');
				break;

			case 2:
				do {
					printf("Math game!");
					mathGame();
					// ask if use wants to play again
					qgAgain = checkPlayAgain();
				} while (tolower(qgAgain) == 'y');
				break;

			case 3:
				do {
					printf("Dice game!");
					diceGame();
					// ask if use wants to play again
					qgAgain = checkPlayAgain();
				} while (tolower(qgAgain) == 'y');
				break;

			case 9:
				printf("GoodBye\n");
				break;

			default:
				printf("default choice\n");
				break;
		}

		// prompt for next action or exit
		if (tolower(qgAgain) == 'n') {
			//check if they want to play again
			printf("\nWould you like to return to the main menu?\n");
			printf("Enter a ( Y ) to return.\nEnter a ( N ) to exit the game.\n");

			while(1){

				// stops for user input
				scanf(" %c", &qgAgain);

				// consumes the input buffer
				while (getchar() != '\n');


				if (tolower(qgAgain) == 'y'){
					// return to main menu
					break;

				} else if (tolower(qgAgain) == 'n'){
					// leave the game
					printf("Exiting the game....\n");
					keepRunning = false;
					break;
				} else {
					printf("Please enter a ( Y ) or a ( N ) to stop or continue!\n");
				}
			}
		}
	}

	return 0;

}

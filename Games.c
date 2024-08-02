#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <setjmp.h>

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

// function decloration
bool checkAnswers( char qgUserAnswer, char qgCorrectAnswer);

// question game function
void questionGame(){
	
	// correct answers & users answers
	int qgUserScore = 0;
	char qgCorrectAnswer[ARRAY_SIZE] = {'t','a','d','c','y'};
	char qgUserAnswer[ARRAY_SIZE];
	// copy the correct ans to the users ans array
	memcpy(qgUserAnswer, qgCorrectAnswer, ARRAY_SIZE * sizeof(char));

	// holds the logic for the points you gain and lose in the game
	do {

		int q = 0;
		char q1UserAns[2];
		char q2UserAns[2];
		char q3UserAns[2];
		char q4UserAns[2];
		char q5UserAns[2];
		char temp;

		// game
		printf("\n==Welcome==\nYou have 5 questions.\n");

		//q1
		printf("Question %d: Is the statement true or false.\n", q++);
		printf("I have a male cat. \n: ");
		scanf(" %s", q1UserAns);

		strcpy(&qgUserAnswer[1], q1UserAns);
		//q2
		printf("Question %d: Pick the correct answer\n: ", q++);
		scanf(" %s", q2UserAns);
		strcpy(&qgUserAnswer[2], q2UserAns);
		//q3
		printf("Question %d: Pick the correct answer\n: ", q++);
		scanf(" %s", q3UserAns);
		strcpy(&qgUserAnswer[3], q3UserAns);
		//q4
		printf("Question %d: Pick the correct answer\n: ", q++);
		scanf(" %s", q4UserAns);
		strcpy(&qgUserAnswer[4], q4UserAns);
		//q5
		printf("Question %d: Last question\n", q);
		printf("Do you love me????\n: ");
		scanf(" %s", q5UserAns);
		strcpy(&qgUserAnswer[5], q5UserAns);

		// clear the input buffer
		while ((temp = getchar()) != '\n' && temp != EOF);


		for (int q = 0; q <= 5; q++){
			printf("q %d: ", qgUserAnswer[q]);
		}

		//check answer1
		for (int q = 0; q <= 5; q++){
			bool qgResult = checkAnswers(&qgUserAnswer[q], qgCorrectAnswer[q]);
			if (qgResult){
				qgUserScore + 20;
				q++;
			}else{
				qgUserScore + 0;
				q++;
			}
			printf("\nScore: %d", qgResult);
		}
		printf("\n\nScore: %d", qgUserScore);

	} while (playAgain);
}

// function definition
bool checkAnswers(char qgUserAnswer, char qgCorrectAnswer) {
	return qgUserAnswer == qgCorrectAnswer;
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
	printf("! (1) Question Game            (2) Math Game       !\n");
	printf("!__________________________________________________!\n");
	scanf("%d", &userChoice);

	switch (userChoice){
		case 1:
			do {
				// trys setjmp code
				//setjmp(env);
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
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int Guessing(int num_guess){
	/**
	 * Takes the users number and if it does not match 
	 * it wil tell you if you are to high or low
	 * */
	int random = rand() % 10 + 1;
	int trys = 0;

	while (num_guess != random){ 
		trys++;
		
		if( num_guess < random){

			printf("Too Low: %d\n",num_guess);
		}else{

			printf("Too High: %d\n",random);
		}

		scanf("%d", &num_guess);
	}

	printf("You got in in :%d:- tries",trys);
	return 0;
}

int main(void){
	/***
	 * Takes user input of a number
	 * 
	 * */
	int num;

	printf("Enter a number:");
	scanf("%d",&num);

	Guessing(num);
	return 0;
}
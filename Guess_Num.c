#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int Guessing(int* num_guess){
	int random = rand();
	while (num_guess != random){ 
		if( num_guess == random){
			printf("%d",num_guess);
		}else{
			printf("%d",random);
		}
	}
	return 0;
}

int main(void){
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	int *num1 = &num;
	printf("Guessing a number:%d",Guessing(num1));


	return 0;
}
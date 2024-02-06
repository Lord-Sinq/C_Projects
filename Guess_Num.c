#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int Guessing(int(num)){
	int random = rand();
	int num = num;
	while (num != random){ 
		if( num == random){
			return num;
		}else{
			return random;
		}
	}
}

int main(){
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	int *num1 = &num;
	printf("Guessing a number:%d",Guessing(*num1) );
}
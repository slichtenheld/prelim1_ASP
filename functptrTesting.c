#include <stdio.h>

int functest1(char x){
	return x;
}

int functest2(char x){
	return x*2;
}

void callbackex(char x, int (*functptr)(char)){
	printf("value %d\n", (*functptr)(x));
}


main(int argc, char *argv[]){

	/*
	int (*functptr)(char);
	functptr = &functest1; 

	int temp1 = (*functptr)('x');

	functptr = &functest2;

	int temp2 = (*functptr)('x');

	printf("test1: %d, test2:%d\n",temp1,temp2);
	*/

	// callback example

	callbackex('x',&functest1);
	callbackex('x', &functest2);

}
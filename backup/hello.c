#include <stdio.h>
#include "cs50.h"
#include "cs50.c"
int main(){
	int i;
	printf("Hello C!\nHello World!\n");
	scanf("%d",&i);
	printf("%d\n",i);
	while(i<0 || i>24){
		scanf("%d",&i);
		printf("%d\n",i);
	}
	printf("hello %d\n",i);
}
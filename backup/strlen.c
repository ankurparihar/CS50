#include <stdio.h>

int main(){
	int l=0;
	char str[100];
	printf("Enter string :");
	scanf("%s",str);
	while(str[l]!=0){
		l++;
	}
	printf("%d\n",l);
}
#include <stdio.h>
#include <string.h>

int main(){
	char str[100];
	int i,n,p='a'-'A';
	printf("Enter string :");
	scanf("%s",str);
	for(i=0,n=strlen(str);i<n;i++){
		if(str[i]>='a' && str[i]<='z'){
			printf("%c",str[i]-p);
		}
		else{
			printf("%c",str[i]);
		}
	}
	printf("\n");
}
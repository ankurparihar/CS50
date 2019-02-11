#include <stdio.h>
#include <string.h>

int main(){
	char  str[20];
	int i,len;
	printf("Enter name :");
	scanf("%s",str);
	// scanf("%[^\n]%*c", str);
	len = strlen(str);
	for(i=0;i<len;i++){
		printf("%i\n",str[i]);
	}
}
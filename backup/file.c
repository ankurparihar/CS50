#include <stdio.h>

int main(){
	printf("Enter filename :");
	char * str;
	scanf("%s",str);
	FILE *fp = fopen(str,"r");
		printf("\n<------------------------- %s ------------------------->\n",str);
	char ch = getc(fp);
	while(ch != EOF){
		printf("%c",ch);
		ch = getc(fp);
	}
	if(feof(fp)){
		printf("\n<------------------------- End ------------------------->\n");
	}
	else{
		printf("Something went wrong.\n");		
	}

	fclose(fp);
	getchar();
	return 0;
}
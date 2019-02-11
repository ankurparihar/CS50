#include <stdio.h>

int main(int argc, char * argv[]){
	if(argc>1){
		// printf("%s\n",argv[0]);
		printf("%s\n",argv[55]);
		for(int i=1; i<argc; i++){
			printf("hello %s\n",argv[i]);
		}
	}
	else {
		printf("Hello C!\n");
		for(int i=0;i<55;i++){
			printf("%d : %s\n",i,argv[i]);
		}
	}
}
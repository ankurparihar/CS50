#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

	if(argc!=2){
		fprintf(stderr, "Usage: ./recover image\n");
		return 1;
	}
	FILE *card = fopen(argv[1], "r");
	if(!card){
		fprintf(stderr, "Cannot open raw file\n");
		return 2;
	}
	// FILE *image;
	char image_name[] = "000.jpg";
	int image_count = 0;
	unsigned char *buffer = malloc(512);
	// int count = 0;
	while(fread(buffer, 1, 512, card)==512){
		// printf("%05d: %x\n", count, buffer[0]);
		// count++;
		if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && ((buffer[3] & 0xf0)==0xe0)){
			// printf("hello\n");
			break;
		}
	}
	// return 0;
	FILE *image = fopen(image_name, "w");
	fwrite(buffer, 512, 1, image);
	// printf("count: %d\n", count);
	
	while(fread(buffer, 1, 512, card)==512){
		// printf("%03d.jpg\n", image_count);
		if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff && ((buffer[3] & 0xf0)==0xe0)){
			image_count++;
			printf("%s\n", image_name);
			sprintf(image_name, "%03d.jpg", image_count);
			fclose(image);
			FILE *image = fopen(image_name, "w");
			fwrite(buffer, 512, 1, image);
		}
		else{
			fwrite(buffer, 512, 1, image);
		}
	}
	fclose(image);
	fclose(card);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
typedef char * string;
string GetString(void)
{
    // growable buffer for chars
    string buffer = NULL;

    // capacity of buffer
    unsigned int capacity = 0;

    // number of chars actually in buffer
    unsigned int n = 0;

    // character read or EOF
    int c;

    // iteratively get chars from standard input
    while ((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        // grow buffer if necessary
        if (n + 1 > capacity)
        {
            // determine new capacity: start at 32 then double
            if (capacity == 0)
            {
                capacity = 32;
            }
            else if (capacity <= (UINT_MAX / 2))
            {
                capacity *= 2;
            }
            else
            {
                free(buffer);
                return NULL;
            }

            // extend buffer's capacity
            string temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        // append current character to buffer
        buffer[n++] = c;
    }

    // return NULL if user provided no input
    if (n == 0 && c == EOF)
    {
        return NULL;
    }

    // minimize buffer
    string minimal = malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    // terminate string
    minimal[n] = '\0';

    // return string
    return minimal;
}


int main(){
	int i,len,sum,k;
	bool flag;
	char *str;
	do{
		printf("Number: ");
		// scanf("%s",str);
		str = GetString();
		flag = false;
		len = strlen(str);
		// printf("len %s\n",str);
		// for(i=0;i<5;i++){
		// 	printf("%d %c\n",i,str[i]);
		// }
		// strcpy(str,str);
		flag=true;
		for(i=0;i<len;i++){
			// printf("here %d\n",i);
			if(str[i]<'0'||str[i]>'9'){
				flag = false;
				break;
			}
		}
	}
	while(!flag||str[0]==0);
	sum=0;
	for(i=len-2;i>=0;i-=2){
		k = str[i]-'0';
		sum += (k>4) ? 1+(k*2)%10 : 2*k;
	}
	for(i=len-1;i>=0;i-=2){
		sum += (str[i]-'0');
	}
	// printf("sum : %d\n",sum);
	if(sum%10==0){
		i=str[0]-'0';
		k=str[1]-'0';
		if(len==15&&i==3&&(k==4||k==7)){
			printf("AMEX\n");
		}
		else if(len==16&&i==5&&(str[1]>'0'&&str[1]<'6')){
			printf("MASTERCARD\n");
		}
		else if((len==16||len==16)&&i==4){
			printf("VISA\n");
		}
		else{
			printf("INVALID\n");
		}
	}
	else{
		printf("INVALID\n");
	}
}
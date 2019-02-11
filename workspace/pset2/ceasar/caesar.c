#include <stdio.h>
#include <cs50.h>
#include <string.h>


// converting string to int
int sti(string num)
{
    int length = strlen(num);
    int res = 0;
    for (int i = 0; i < length; i++)
    {
        res *= 10;
        res += num[i] - '0';
    }
    return res;
}

int main(int argc, char *argv[])
{
    // if args !=2 break;
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    // user input
    string text = get_string("plaintext: ");
    int length = strlen(text);
    int key = sti(argv[1]);
    char ch;
    printf("ciphertext: ");
    // output goes here
    for (int i = 0; i < length; i++)
    {
        // use one char
        ch = text[i];
        // for capital
        if (ch <= 'Z' && ch >= 'A')
        {
            printf("%c", ((ch - 'A' + key) % 26 + 'A'));
        }
        // for smalls
        else if (ch <= 'z' && ch >= 'a')
        {
            printf("%c", ((ch - 'a' + key) % 26 + 'a'));
        }
        // if not alphabat print without manipulation
        else
        {
            printf("%c", ch);
        }
    }
    printf("\n");
    return 0;
}
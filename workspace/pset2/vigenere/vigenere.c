#include <stdio.h>
#include <cs50.h>
#include <string.h>


bool is_string(string str)
{
    int i = strlen(str) - 1;
    // int i = strlen(str) - 1;
    while (i >= 0)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            return false;
            // return false;
        }
        i--;
    }
    return true;
    // return true;
}

// char *resolve_key(string  key)
char *resolve_key(string  key)
{
    int i = strlen(key) - 1;
    // int i = strlen(key) - 1;
    char *key2 = key;
    // char *key2 = key;
    while (i >= 0)
    {
        if (key[i] <= 'z' && key[i] >= 'a')
        {
            // key2[i] = key[i] - 'a' + 'A';
            key2[i] = key[i] - 'a' + 'A';
        }
        else if (key[i] > 'Z' || key[i] < 'A')
        {
            // printf("returning zero for %i %c\n",i,key[i]);
            return "0";
        }
        i--;
    }
    return key2;
}

int main(int argc, char *argv[])
{
    if (argc != 2 || (!is_string(argv[1])))
    {
        printf("Usage: ./vigenere k\n");
        // return 1;
        return 1;
    }
    string key = resolve_key(argv[1]);
    // printf("key = %s\n", key);
    // getting user input
    string text = get_string("plaintext: ");
    // key all uppercase
    int length = strlen(text);
    int keylen = strlen(key);
    char ch;
    // int length = strlen(text);
    // int keylen = strlen(key);
    // char ch;
    printf("ciphertext: ");
    for (int i = 0, j = 0; i < length; i++)
    {
        // taking chars
        ch = text[i];
        if (ch <= 'Z' && ch >= 'A')
        {
            printf("%c", (ch - 'A' + key[j] - 'A') % 26 + 'A');
            j = (j + 1) % keylen;
            // printf("%c", (ch - 'A' + key[j] - 'A') % 26 + 'A');
            // j = (j + 1) % keylen;
            // j = (j + 1) % keylen;
        }
        else if (ch <= 'z' && ch >= 'a')
        {
            printf("%c", (ch - 'a' + key[j] - 'A') % 26 + 'a');
            j = (j + 1) % keylen;
            // printf("%c", (ch - 'a' + key[j] - 'A') % 26 + 'a');
            // j = (j + 1) % keylen;
            // j = (j + 1) % keylen;
        }
        else
        {
            printf("%c", ch);
        }
    }
    printf("\n");
    return 0;
}
#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <crypt.h>

bool isValid(string str)
{
    int i = strlen(str) - 1;
    char ch;
    while (i >= 0)
    {
        ch = str[i];
        if (ch < 'A' || ch > 'z' || (ch > 'Z' && ch < 'a'))
        {
            return false;
        }
    }
    return true;
}


int main(int argc, string argv[])
{
    if (argc != 2)                       // && isValid(argv[1]))
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    char array[] = {'\0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string hash = argv[1];
    // string salt = hash.substr(0,2);
    char salt[3];// = {,hash[1]};
    salt[0] = hash[0];
    salt[1] = hash[1];
    // salt[0] = argv[1][0];
    // printf("debug\n");
    // salt[1] = argv[1][1];
    // printf("hash: %c %c %s\n",hash[0],hash[1],hash);
    // printf("salt: %s\n",salt);
    // printf("%s\n",crypt("PASS\0",salt));
    // printf("array: %s\n",array);
    char pass5[6], pass4[5], pass3[4], pass2[3], pass1[2];
    // pass[0] = '\0';
    // pass[1] = '\0';
    // pass[2] = '\0';
    // pass[3] = '\0';
    // pass[4] = '\0';
    pass5[5] = '\0';
    pass4[4] = '\0';
    pass3[3] = '\0';
    pass2[2] = '\0';
    pass1[1] = '\0';
    // pass/**/
    int p1, p2, p3, p4, p5;
    // for 1 length pass
    for (p1 = 1; p1 < 53; p1++)
    {
        pass1[0] = array[p1];
        if (strcmp(hash, crypt(pass1, salt)) == 0)
        {
            printf("Pass: %s\n", pass1);
            return 0;
        }
    }
    for (p1 = 1; p1 < 53; p1++)
    {
        pass2[0] = array[p1];
        for (p2 = 1; p2 < 53; p2++)
        {
            pass2[1] = array[p2];
            if (strcmp(hash, crypt(pass2, salt)) == 0)
            {
                printf("Pass: %s\n", pass2);
                return 0;
            }
        }
    }
    for (p1 = 1; p1 < 53; p1++)
    {
        pass3[0] = array[p1];
        for (p2 = 1; p2 < 53; p2++)
        {
            pass3[1] = array[p2];
            for (p3 = 1; p3 < 53; p3++)
            {
                pass3[2] = array[p3];
                if (strcmp(hash, crypt(pass3, salt)) == 0)
                {
                    printf("Pass: %s\n", pass3);
                    return 0;
                }
            }
        }
    }
    for (p1 = 1; p1 < 53; p1++)
    {
        pass4[0] = array[p1];
        for (p2 = 1; p2 < 53; p2++)
        {
            pass4[1] = array[p2];
            for (p3 = 1; p3 < 53; p3++)
            {
                pass4[2] = array[p3];
                for (p4 = 1; p4 < 53; p4++)
                {
                    pass4[3] = array[p4];
                    if (strcmp(hash, crypt(pass4, salt)) == 0)
                    {
                        printf("Pass: %s\n", pass4);
                        return 0;
                    }
                }
            }
        }
    }
    for (p1 = 1; p1 < 53; p1++)
    {
        pass5[0] = array[p1];
        for (p2 = 1; p2 < 53; p2++)
        {
            pass5[1] = array[p2];
            for (p3 = 1; p3 < 53; p3++)
            {
                pass5[2] = array[p3];
                for (p4 = 1; p4 < 53; p4++)
                {
                    pass5[3] = array[p4];
                    for (p5 = 1; p5 < 53; p5++)
                    {
                        pass5[4] = array[p5];
                        if (strcmp(hash, crypt(pass5, salt)) == 0)
                        {
                            printf("Pass: %s\n", pass5);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    // for(p5=0;p5<5;p5++){
    //     return 0;
    //     pass5[4] = array[p5];
    //     for(p4=0;p4<5;p4++){
    //         pass5[3] = array[p4];
    //         for(p3=0;p3<5;p3++){
    //             pass5[2] = array[p3];
    //             for(p2=0;p2<5;p2++){
    //                 pass5[1] = array[p2];
    //                 for(p1=0;p1<5;p1++){
    //                     pass5[0] = array[p1];
    //                     printf("%d%d%d%d%d : %c%c%c%c%c\n",p1,p2,p3,p4,p5,array[p1],array[p2],array[p3],array[p4],array[p5]);
    //                     // if(strcmp(crypt(pass,salt),hash) == 0){
    //                     //     printf("Pass: %s\n",pass);
    //                     //     return 0;
    //                     // }
    //                 }
    //             }
    //         }
    //     }
    // }
    return 0;
}
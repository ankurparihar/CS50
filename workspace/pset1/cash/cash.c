#include <stdio.h>
#include </usr/include/cs50.h>
#include <math.h>

int main()
{
    float temp, change2;
    do
    {
        temp = get_float("Change owed: ");
    }
    while (temp < 0);
    // convert
    change2 = temp * 10;
    // printf("1:%f\n",change2);
    change2 *= 10;
    // printf("1:%f\n",change2);
    int change = (int)round((change2 * 10));
    change /= 10;
    // calculate 25 coins
    // printf("coin:%d\n",change);
    int coins = change / 25;
    change %= 25;
    // printf("coin:%d\n",change);
    // calculate 10 coins
    coins += change / 10;
    change %= 10;
    // printf("coin:%d\n",change);
    // calculate 5 coins
    coins += change / 5;
    change %= 5;
    // printf("coin:%d\n",change);
    // calculate 1 coins
    coins += change;
    printf("%d\n", coins);
}
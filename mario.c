#include <stdio.h>
#include <cs50.h>
// the purpose of this program is to recreate a pyramid in mario using hastags (#)
// the user can give the height of the pyramid as long as it is between 1 and 8 inclusive

int main(void)
{
    int n;
    do 
    {
        n = get_int("give me a height between 1 and 8: ");
    } 
    while (n < 1 || n > 8);
    {
        for (int i = 0; i < n; i++)
        {
            
            // this is the spaces before the hashtag
            for (int j = n - 1; j > i; j--)
            {
                printf(" ");
            }  
            // this is for the hashtag itself
            for (int j = 0; j <= i; j++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
}
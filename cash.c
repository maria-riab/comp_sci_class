# include <stdio.h>
# include <cs50.h>
# include <math.h>
// this program is a "greedy algorithm", gets user input on the number of change they have and returns the minimum amount of coins needed to make that amount
// it only works with coins of 25c, 10c, 5c, and 1c, no dollars


int coin_counter(void);




int main(void)
{
    int change = coin_counter();
    printf("%i \n", change);
}




int coin_counter(void)
{
    float dollars;
    do
    {
        //to let the user give the program change in decimals, we assign dollars to be a float variable
        dollars = get_float("change owed: ");
        
    } 
    while (dollars <= 0);
    {
        // int cents converts user's float input of dollars into cents and rounds it to the nearest penny, to be as precise as possible
        int cents = round(dollars * 100);
        int coins = 0;
        
        while (cents >= 25)
        {
            cents -= 25;
            coins++;
        }    
            
        while (cents >= 10)
        {
            cents -= 10;
            coins++;
        }
        while (cents >= 5)
        {
            cents -= 5;
            coins++;
        }
        while (cents >= 1)
        {
            cents -= 1;
            coins++;
        }
        return coins;
    } 
   
}






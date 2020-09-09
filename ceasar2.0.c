# include <stdio.h>
# include <cs50.h>
# include <ctype.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

string cipher_to_plaintext(string s, int key);

bool check_argv(string s);

string error_key = "Usage: ./caesar key";

int main(int argc, string argv[])
{

    if (argc == 2 && check_argv(argv[1]))
    {
        int key= atoi(argv[1]);

        string plaintext= get_string("Get Plaintext: ");

        printf("ciphertext: ");

        printf("%s",cipher_to_plaintext(plaintext, key));

        printf("\n");

        return 0;
    }
    else
    {
        printf("%s \n", error_key);

        return 1;
    }

}

string cipher_to_plaintext(string s, int k)
{
    for (int i = 0, n = strlen(s) ; i < n; i++)
    {
        if (islower(s[i]))
        {
            s[i] = ((((s[i] - 'a') + k) % 26) + 'a');
        }
        else if (isupper(s[i]))
        {
            s[i] = ((((s[i] - 'A') + k) % 26) + 'A');
        }
        else
        {
            s[i] = s[i];
        }
    }return s;
}

bool check_argv(string s)
{
    for (int i = 0,  b   = strlen(s) ; i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

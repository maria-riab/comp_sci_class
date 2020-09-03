# include <stdio.h>
# include <cs50.h>
# include <ctype.h>
# include <math.h>
# include <string.h>

// this program is designed to analyze a text and determine its approximate US grade level using the Coleman-Liau index
// the formula takes an input of letters per 100 words and sentences per 100 words to determine its complexity by how long the words are and how long the sentences are
// this is not an exact formula, the program doesn't distinguish between a regular period and abbreviations like Mr. or Mrs. 

int letter_counter(string s);

int word_counter(string s);

int sentence_counter(string s);

int index_calculator(float a, float b);

int main(void)
{
    string text = get_string("Text: ");

    float let = letter_counter(text);

    float w = word_counter(text);

    float sen = sentence_counter(text);

    float l = (let / w) * 100;

    float p = (sen / w) * 100;



    int index = index_calculator(l, p);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }

}

// to count letters in my text 
int letter_counter(string s)
{
    int letters = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            letters++;
        }
        if (s[i] >= 97 && s[i] <= 122)
        {
            letters++;
        }
    }
    return letters;
}

// to count words in my text 
int word_counter(string s)
{
    int words = 1;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isspace(s[i]))
        {
            words++;
        }
    }
    return words;
}

// to count sentences in my text
int sentence_counter(string s)
{
    int sentence = 0;

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            sentence++;
        }

    }
    return sentence;

}

// takes two inputs to plug into the Coleman-Liau formula and returns US grading level

int index_calculator(float a, float b)
{
    int ind = round(0.0588 * a - 0.296 * b - 15.8);
    return ind;
}
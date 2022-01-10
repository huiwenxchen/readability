#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main()
{
//prompt user to get string 
    string text = get_string("Text: ");

//count
    int lettercount = count_letters(text);
    int wordcount = count_words(text);
    int sentencecount = count_sentences(text);

//calculate the average number of letters per 100 words
    float L = ((float)lettercount / (float)wordcount * 100);

//calculate the average number of sentences per 100 words
    float S = ((float)sentencecount / (float)wordcount * 100);

//compute the Coleman-Liau formula, rounded to the nearest int  
    int index = round(0.0588 * L - 0.296 * S - 15.8);

//output the reading or grade level
    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
}

//count the number of letters
int count_letters(string text)
{
    int letters = 0;
    int n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            letters++;
        }
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            letters++;
        }
    }
    return letters;
}

//count the number of words (start w 0 or 1?)
int count_words(string text)
{
    int words = 1;
    int n = strlen(text);
    for (int j = 0; j < n; j++)
    {
        if (text[j] == ' ')
        {
            words++;
        }
    }
    return words;
}

//count the number of sentences (calculate punctuations.!?)
int count_sentences(string text)
{
    int sentences = 0;
    int n = strlen(text);
    for (int k = 0; k < n; k++)
    {
        if ((int)text[k] == 33 || (int)text[k] == 46 || (int)text[k] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}

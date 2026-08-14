#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float)letters / words) * 100;
    float S = ((float)sentences / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int roundednum = round(index);

    if (roundednum >= 1 && roundednum < 16)
    {
        printf("Grade %i\n", roundednum);
    }

    else if (roundednum >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

int count_letters(string text)
{
    int count_letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count_letters++;
        }
    }
    return count_letters;
}

int count_words(string text)
{
    int count_words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count_words++;
        }
    }
    return count_words;
}
int count_sentences(string text)
{
    int count_sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_sentences++;
        }
    }
    return count_sentences;
}
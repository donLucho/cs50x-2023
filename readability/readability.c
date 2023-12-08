// Required Problem set 2 by Luis Artavia - Readability
// draft processed on June 28, 2023
// submitted for grade on: July 5, 2023

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Hoisted function name declarations
int chars_testing(string str, int len);
int spaces_testing(string str, int len);
int punctuation_testing(string str, int len);
float calculate_index(int letters, int sentences, int words);
void print_conclusion(int num);

int main(void)
{

    // Get the string from user
    string str;
    do
    {
        str = get_string("Text: ");
    }
    while (strlen(str) < 0);

    int len = strlen(str);

    // Calculate the key numbers necessary to operate the Coleman-Liau Formula
    int numberofletters = chars_testing((string) str, (int) len);
    // printf("numberofletters: %i\n", numberofletters);
    int numberofspaces = spaces_testing((string) str, (int) len);
    // printf("numberofspaces: %i\n", numberofspaces);
    int numberofwords = spaces_testing((string) str, (int) len) + 1;
    // printf("numberofwords: %i\n", numberofwords);
    int numberofsentences = punctuation_testing((string) str, (int) len);
    // printf("numberofsentences: %i\n", numberofsentences);

    // Return value according to calculated formula
    float myfloatedresult = calculate_index((int) numberofletters, (int) numberofsentences, (int) numberofwords);
    // printf("\n\nmyfloatedresult: %f\n", myfloatedresult);

    // Round the floated amount and silently convert to an integer value
    int finalroundedinteger = round(myfloatedresult);
    // printf("finalroundedinteger: %i\n", finalroundedinteger);

    print_conclusion((int) finalroundedinteger);

}

// Todo - Confirm number of characters excluding spaces and punctuation
int chars_testing(string str, int len)
{
    int lettercount = 0;
    for (int i = 0; i < len; i++)
    {
        if (!isspace(str[i]) && !isblank(str[i]) && !ispunct(str[i]))
        {
            // printf("char str[i]: %c\n", str[i]);
            lettercount = lettercount + 1;
            // printf("lettercount c: %i\n", lettercount);
        }
    }
    return lettercount;
}

// Todo - Confirm number of spaces
int spaces_testing(string str, int len)
{
    int spacecount = 0;
    for (int i = 0; i < len; i++)
    {
        if (isspace(str[i]) || isblank(str[i]))
        {
            // printf("char str[i]: %c\n", str[i]);
            spacecount = spacecount + 1;
            // printf("spacecount c: %i\n", spacecount);
        }
    }
    return spacecount;
}

// Todo - Confirm number of punctuation marks
// Per the instructions in walkthrough, "a period, exclamation mark, question mark [indicates a sentence]"

// Plus, confirm that str[i + 1] is not equal to an alphabetical character
// and ensure that str[i + 1] is a space with "isspace(str[i + 1]) || isblank(str[i + 1])"
int punctuation_testing(string str, int len)
{
    int punctuationcount = 0;
    for (int i = 0; i < len; i++)
    {
        // if (ispunct(str[i]) && (str[i] == '!' || str[i] == '?' || (str[i] == '.' && (isspace(str[i + 1]) || isblank(str[i + 1])))))
        if (ispunct(str[i]) && (str[i] == '!' || str[i] == '?' || str[i] == '.'))
        {
            // printf("char str[i]: %c\n", str[i]);
            punctuationcount = punctuationcount + 1;
            // printf("punctuationcount c: %i\n", punctuationcount);
        }
    }
    return punctuationcount;
}

// TODO - Coleman Liau formula
float calculate_index(int letters, int sentences, int words)
{
    // printf("letters: %i\n", letters);
    // printf("sentences: %i\n", sentences);
    // printf("words: %i\n", words);

    float lettersMultiple;
    lettersMultiple = round((float) letters / (float) words * 100);
    // printf("lettersMultiple: %f\n", lettersMultiple);

    float sentencesMultiple;
    sentencesMultiple = (float) sentences / (float) words * 100;
    // printf("sentencesMultiple: %f\n", sentencesMultiple);

    float idx;
    // idx = ((0.0588 * letters) - (0.296 * sentences)) - 15.8;
    // idx = 0.0588 * letters - 0.296 * sentences - 15.8;
    idx = 0.0588 * lettersMultiple - 0.296 * sentencesMultiple - 15.8;

    // return 1234.567;

    // printf("idx: %f\n", idx);
    return idx;
}

// Print to console according to original instructions re-inforced in walkthrough
void print_conclusion(int num)
{
    if (num >= 16)
    {
        printf("Grade 16+\n");
    }
    if (num < 1)
    {
        printf("Before Grade 1\n");
    }
    if (num < 16 && num >= 1)
    {
        printf("Grade %d\n", num);
    }
}
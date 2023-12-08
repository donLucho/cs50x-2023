// Required Lab(s) 2 by Luis Artavia- Scrabble
// draft processed on June 28, 2023
// submitted for grade on: July 5, 2023

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int assign_points(char phoneme);
void printResponse(int s1, int s2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // printf("score1: %i\n", score1);
    // printf("score2: %i\n", score2);

    // TODO: Print the winner
    printResponse((int) score1, (int) score2);
}

// TODO - Calculate the sum of the points assigned to each of the chars
int compute_score(string word)
{
    // TODO: Compute and return score for string
    // printf("word: %s\n", word);

    int length = strlen(word);
    // printf("length: %i\n", length);

    int total = 0;
    for (int i = 0; i < length; i = i + 1)
    {
        total = total + assign_points((char) word[i]);
    }

    // return 69;
    return total;
}

// TODO - Extrapolate amount of assigned points according to index-based POINTS array
int assign_points(char phoneme)
{
    // printf("phoneme: %c\n", phoneme);
    // return 45;

    if (isspace(phoneme) || ispunct(phoneme) || isdigit(phoneme) || isblank(phoneme))
    {
        return 0;
    }

    // a
    if (isalpha(phoneme) && (phoneme == 'a' || phoneme == 'A'))
    {
        return POINTS[0];
    }

    // b
    if (isalpha(phoneme) && (phoneme == 'b' || phoneme == 'B'))
    {
        return POINTS[1];
    }

    // c
    if (isalpha(phoneme) && (phoneme == 'c' || phoneme == 'C'))
    {
        return POINTS[2];
    }

    // d
    if (isalpha(phoneme) && (phoneme == 'd' || phoneme == 'D'))
    {
        return POINTS[3];
    }

    // e
    if (isalpha(phoneme) && (phoneme == 'e' || phoneme == 'E'))
    {
        return POINTS[4];
    }

    // f
    if (isalpha(phoneme) && (phoneme == 'f' || phoneme == 'F'))
    {
        return POINTS[5];
    }

    // g
    if (isalpha(phoneme) && (phoneme == 'g' || phoneme == 'G'))
    {
        return POINTS[6];
    }

    // h
    if (isalpha(phoneme) && (phoneme == 'h' || phoneme == 'H'))
    {
        return POINTS[7];
    }

    // i
    if (isalpha(phoneme) && (phoneme == 'i' || phoneme == 'I'))
    {
        return POINTS[8];
    }

    // j
    if (isalpha(phoneme) && (phoneme == 'j' || phoneme == 'J'))
    {
        return POINTS[9];
    }

    // k
    if (isalpha(phoneme) && (phoneme == 'k' || phoneme == 'K'))
    {
        return POINTS[10];
    }

    // l
    if (isalpha(phoneme) && (phoneme == 'l' || phoneme == 'L'))
    {
        return POINTS[11];
    }

    // m
    if (isalpha(phoneme) && (phoneme == 'm' || phoneme == 'M'))
    {
        return POINTS[12];
    }

    // n
    if (isalpha(phoneme) && (phoneme == 'n' || phoneme == 'N'))
    {
        return POINTS[13];
    }

    // o
    if (isalpha(phoneme) && (phoneme == 'o' || phoneme == 'O'))
    {
        return POINTS[14];
    }

    // p
    if (isalpha(phoneme) && (phoneme == 'p' || phoneme == 'P'))
    {
        return POINTS[15];
    }

    // q
    if (isalpha(phoneme) && (phoneme == 'q' || phoneme == 'Q'))
    {
        return POINTS[16];
    }

    // r
    if (isalpha(phoneme) && (phoneme == 'r' || phoneme == 'R'))
    {
        return POINTS[17];
    }

    // s
    if (isalpha(phoneme) && (phoneme == 's' || phoneme == 'S'))
    {
        return POINTS[18];
    }

    // t
    if (isalpha(phoneme) && (phoneme == 't' || phoneme == 'T'))
    {
        return POINTS[19];
    }

    // u
    if (isalpha(phoneme) && (phoneme == 'u' || phoneme == 'U'))
    {
        return POINTS[20];
    }

    // v
    if (isalpha(phoneme) && (phoneme == 'v' || phoneme == 'V'))
    {
        return POINTS[21];
    }

    // w
    if (isalpha(phoneme) && (phoneme == 'w' || phoneme == 'W'))
    {
        return POINTS[22];
    }

    // x
    if (isalpha(phoneme) && (phoneme == 'x' || phoneme == 'X'))
    {
        return POINTS[23];
    }

    // y
    if (isalpha(phoneme) && (phoneme == 'y' || phoneme == 'Y'))
    {
        return POINTS[24];
    }

    // z
    if (isalpha(phoneme) && (phoneme == 'z' || phoneme == 'Z'))
    {
        return POINTS[25];
    }

    else
    {
        return 0;
    }
}

// TODO - Print to console
void printResponse(int s1, int s2)
{
    // Print findings
    string winner = NULL;

    if (s1 < s2)
    {
        winner = "Player 2 wins!";
    }
    if (s1 > s2)
    {
        winner = "Player 1 wins!";
    }
    if (s1 == s2)
    {
        winner = "Tie!";
    }

    // printf("Testing!!!\n");
    printf("%s\n", winner);
}

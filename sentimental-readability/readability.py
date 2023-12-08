# Required Problem set 6 by Luis Artavia - sentimental-readability
# draft processed on: September 07, 2023
# submitted for grade on: September 07, 2023


import string


def main():
    # TODO: prompt user for height for numbers between 1 and 8 of type integer

    while True:
        try:
            string = input("Text: ")
            if len(string) > 0:
                break
        except ValueError as v:
            continue
        except:
            continue
    # print(string)

    strlen = len(string)

    # Calculate the key numbers necessary to operate the Coleman-Liau Formula

    numberofletters = chars_testing(string, strlen)
    # print(f"numberofletters: {numberofletters}")

    numberofspaces = spaces_testing(string, strlen)
    # print(f"numberofspaces: {numberofspaces}")

    numberofwords = spaces_testing(string, strlen) + 1
    # print(f"numberofwords: {numberofwords}")

    numberofsentences = punctuation_testing(string, strlen)
    # print(f"numberofsentences: {numberofsentences}", )
    # Return value according to calculated formula

    myfloatedresult = calculate_index(numberofletters, numberofsentences, numberofwords)
    # print(f"\n\nmyfloatedresult: {myfloatedresult}")
    # Round the floated amount and silently convert to an integer value

    finalroundedinteger = round(myfloatedresult)
    # print(f"finalroundedinteger: {finalroundedinteger}")
    # Submit findings

    print_conclusion(finalroundedinteger)


# Todo - Confirm number of characters excluding spaces and punctuation
# int chars_testing(string str, int len)


def chars_testing(str, len):
    lettercount = 0
    for i in range(0, len):
        if not str[i].isspace() and not str[i] in string.punctuation:
            # print(f"char str[{i}]: {str[i]}")

            lettercount += 1
            # print(f"lettercount: {lettercount}")

    return lettercount


# Todo - Confirm number of spaces
# int spaces_testing(string str, int len)


def spaces_testing(str, len):
    spacecount = 0
    for i in range(0, len):
        if str[i].isspace():
            # print(f"char str[{i}]: {str[i]}")

            spacecount += 1
            # print(f"spacecount: {spacecount}")

    return spacecount


# Todo - Confirm number of punctuation marks
# Per the instructions in walkthrough, "a period, exclamation mark, question mark [indicates a sentence]"
# Plus, confirm that str[i + 1] is not equal to an alphabetical character
# and ensure that str[i + 1] is a space with "isspace(str[i + 1]) || isblank(str[i + 1])"
# int punctuation_testing(string str, int len)


def punctuation_testing(str, len):
    punctuationcount = 0
    for i in range(0, len):
        if str[i] in string.punctuation and (
            str[i] == "!" or str[i] == "?" or str[i] == "."
        ):
            # print(f"char str[{i}]: {str[i]}")

            punctuationcount += 1
            # print(f"punctuationcount: {punctuationcount}")

    return punctuationcount


# TODO - Coleman Liau formula
# float calculate_index(int letters, int sentences, int words)


def calculate_index(letters, sentences, words):
    # print(f"letters: {letters}")
    # print(f"sentences: {sentences}")
    # print(f"words: {words}")

    lettersMultiple = round(letters / words * 100)
    # print(f"lettersMultiple: {lettersMultiple}")

    sentencesMultiple = sentences / words * 100
    # print(f"sentencesMultiple: {sentencesMultiple}")

    idx = 0.0588 * lettersMultiple - 0.296 * sentencesMultiple - 15.8
    # print(f"idx:.03f: {idx:.03f}")

    return idx


# Print to console according to original instructions re-inforced in walkthrough
# void print_conclusion(int num)


def print_conclusion(num):
    if num >= 16:
        print("Grade 16+")
    elif num < 1:
        print("Before Grade 1")
    elif num < 16 and num >= 1:
        print(f"Grade {num}")


main()

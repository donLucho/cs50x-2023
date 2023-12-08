# Optional Lab(s) 6 by Luis Artavia - figlet
# draft processed on: August 31, 2023
# Composed on: August 31, 2023
# Practice document not intended for evaluation

import sys
import random
import pyfiglet


figlet = pyfiglet.Figlet()
fonts = figlet.getFonts()


def main():
    # print("main")

    # implement a program that [...] Expects zero or two command-line arguments [...] Zero if the user would like to output text in a random font [...] Two if the user would like to output text in a specific font, in which case the first of the two should be -f or --font , and the second of the two should be the name of the font.

    testone = step1()
    # print(testone)
    # print("Moving on!")

    # If the user provides two command-line arguments and the first is not -f or --font or the second is not the name of a font, the program should exit via sys.exit with an error message.

    if len(sys.argv) == 3:
        testtwo = step2()
    # print("Moving on!")

    if len(sys.argv) == 3:
        testthree = step3()
    # print("Moving on!")

    # Prompts the user for a str of text [...] Outputs that text in the desired font.

    s = step4()
    # print(f"s: {s}")

    mot = step5(s)
    # sys.exit(0)


def herpaderrp():
    print("Invalid usage")
    sys.exit(1)


def step1():
    # Expects zero or two command-line arguments
    # print("step1")
    if len(sys.argv) == 1 or len(sys.argv) == 3:
        return True
    elif len(sys.argv) != 1 and len(sys.argv) != 3:
        herpaderrp()


def step2():
    # print(sys.argv)
    # [...the [second] CLA is EITHER -f OR --font]
    for str in sys.argv[1:2]:
        # print(f"str in sys.argv[1:2]: {str}")
        if str == "-f" or str == "--font":
            return True
        elif str != "-f" and str != "--font":
            herpaderrp()


def step3():
    # print("tbd")
    for str in sys.argv[2:3]:
        # print(f"str in sys.argv[2:3]: {str}")
        # print(f"fonts: {fonts}")
        if str in fonts:
            return True
        elif str not in fonts:
            herpaderrp()


def step4():
    # print("step4")
    userinput = input("Enter a string of text to be converted: ")
    # print(f"userinput: {userinput}")
    return userinput


def step5(s):
    # print("step5")
    if len(sys.argv) == 1:
        f = random.choice(fonts)
    elif len(sys.argv) == 3:
        f = sys.argv[2:3][0]
    # return f
    figlet.setFont(font=f)
    print(figlet.renderText(s))


main()
sys.exit(0)

if __name__ == "__main__":
    main()

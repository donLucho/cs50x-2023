# Required Problem set 6 by Luis Artavia - sentimental-mario-less
# draft processed on: September 06, 2023 and September 07, 2023
# submitted for grade on: September 06, 2023 and September 07, 2023


def main():
    # print_hashes(3)

    height = set_height()
    # print(height)

    print_hashes(height)


def set_height():
    # TODO: prompt user for height for numbers between 1 and 8 of type integer

    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                break
        except ValueError as v:
            continue
        except:
            continue
    return n


def print_hashes(max_value):
    # TODO: print hashes to screen

    min_value = 1

    # Rows
    # for (int row = min_value; row <= max_value; row++)

    for row in range(min_value, max_value + 1, 1):
        # print("")
        # Spaces
        # for (int space = row; space < max_value; space++)
        # for space in range(min_value, max_value, 1):

        for space in range(row, max_value, 1):
            print(" ", end="")

        # Columns
        # for (int column = min_value; column <= row; column++)

        for column in range(min_value, row + 1, 1):
            print("#", end="")
        print()


main()

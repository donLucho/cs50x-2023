# Required Problem set 6 by Luis Artavia - sentimental-cash
# draft processed on: September 06, 2023
# submitted for grade on: September 06, 2023


from math import floor


def main():
    cents = get_cents()

    # Calculate the number of quarters to give the customer

    quarters = calculate_quarters(cents)
    cents = cents - (quarters * 25)

    # Calculate the number of dimes to give the customer

    dimes = calculate_dimes(cents)
    cents = cents - (dimes * 10)

    # Calculate the number of nickels to give the customer

    nickels = calculate_nickels(cents)
    cents = cents - (nickels * 5)

    # Calculate the number of pennies to give the customer

    pennies = calculate_pennies(cents)
    cents = cents - (pennies * 1)

    # Sum coins

    coins = quarters + dimes + nickels + pennies

    # Print total number of coins to give the customer

    print(f"{coins}")


def get_cents():
    # Ask how many cents the customer is owed
    while True:
        try:
            n = float(input("Change owed: "))
            if n > 0:
                break
        except ValueError as v:
            continue
        except:
            continue

    n = round(n * 100)
    return n


def calculate_quarters(cents):
    # Calculate the number of quarters to give the customer

    if cents >= 25:
        quarters = floor(cents / 25)
    elif cents < 25:
        quarters = 0
    return quarters


def calculate_dimes(cents):
    # Calculate the number of dimes to give the customer

    if cents >= 10:
        dimes = floor(cents / 10)
    elif cents < 10:
        dimes = 0
    return dimes


def calculate_nickels(cents):
    # Calculate the number of nickels to give the customer

    if cents >= 5:
        nickels = floor(cents / 5)
    elif cents < 5:
        nickels = 0
    return nickels


def calculate_pennies(cents):
    # Calculate the number of pennies to give the customer

    if cents >= 1:
        pennies = cents
    elif cents < 1:
        pennies = 0
    return pennies


main()

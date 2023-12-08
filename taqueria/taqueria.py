# Optional Lab(s) 6 by Luis Artavia - taqueria
# draft processed on: September 04, 2023
# Composed on: September 04, 2023
# Practice document not intended for evaluation


menu = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00,
}

total = 0.00


def main(total):
    # taco taco ~~ 3 + 3
    # baja taco tortilla salad ~~ 4 + 8
    # burger chicken tuna sammich ~~ ?!?!?!

    while True:
        try:
            selection = input("Enter a menu item: \n")

            if menu.get(selection.lower().title()):  # NO PROBLEM
                # if selection.lower().title() in menu.keys():  # ALSO O-TAY!!!
                entree = selection.lower().title()
                total += menu[entree]
                print(f"${total:.02f}")

            # elif menu.get(selection.lower().title()) == None:  # NO PROBLEM
            # elif selection.lower().title() not in menu.keys():
            #     return False

        except EOFError as e:
            # print("\nYou prolly pressed ctrl + d")
            # print(f"EOFError: {e}")
            print()
            break
        except ValueError as v:
            # print(f"ValueError: {v}")
            print()
            break
        except KeyboardInterrupt as ki:
            # print("\nYou prolly pressed ctrl + c")
            # print(f"KeyboardInterrupt: {ki}")
            print()
            break
        except:
            print()
            break


main(total)

# Optional Lab(s) 6 by Luis Artavia - jar
# draft processed on: September 01 and September 02 2023
# Composed on: September 01 and September 02 2023
# Practice document not intended for evaluation


class Jar:
    # ■ __init__ should initialize a cookie jar with the given capacity , which represents the maximum number of cookies that can fit in the cookie jar. If capacity is not a non-negative int , though, __init__ should instead raise a ValueError (via raise ValueError ).

    def __init__(self, capacity=12):
        if capacity < 0 or not isinstance(capacity, int):
            raise ValueError("'capacity' has to be a non-negative integer")
        else:
            """protected (non-public) instance attribute(s) WITH preceeding underscore"""
            self._capacity = capacity
            self._n = 0

    # ■ __str__ should return a str with n, where n is the number of cookies in the cookie jar. For instance, if there are 3 cookies in the cookie jar, then str should return "■ ■ ■"

    def __str__(self):
        return "🍪" * self._n

    # ■ deposit should add n cookies to the cookie jar. If adding that many would exceed the cookie jar’s capacity, though, deposit should instead raise a ValueError.

    def deposit(self, n):
        if n + self._n > self._capacity:
            raise ValueError("Cookie jar capacity exceeded")
        self._n += n

    # ■ withdraw should remove n cookies from the cookie jar. Nom nom nom. If there aren’t that many cookies in the cookie jar, though, withdraw should instead raise a ValueError.

    def withdraw(self, n):
        if n > self._n:
            raise ValueError("Withdraw amount exceeds n number of 🍪 (cookies)")
        self._n -= n

    # ■ capacity should return the cookie jar’s capacity.
    @property
    def capacity(self):
        """Get the 'capacity' property."""
        print("Getting capacity value...")
        return self._capacity

    # ■ size should return the number of cookies actually in the cookie jar.
    @property
    def size(self):
        """Get the 'n' property."""
        print("Getting n value...")
        return self._n


def main():
    # print(f"Nyom-Nyom!")
    try:
        # bork!
        # jar = Jar(-5)

        # 12
        jar = Jar()

        # 5 < 12
        jar.deposit(5)
        print(jar.__dict__)
        print(str(jar))

        # 11 < 12
        jar.deposit(6)
        print(jar.__dict__)
        print(str(jar))

        # 9 < 12
        jar.withdraw(2)
        print(jar.__dict__)
        print(str(jar))

        # bork! : 10 > 9
        # jar.withdraw(10)

        jar.withdraw(9)

        print(jar.__dict__)
        print(str(jar))

    except AttributeError as derrp:
        print("No such object attribute with that name exists")
        print("AttributeError", derrp)
    except ValueError as ferrp:
        print("ValueError", ferrp)
    except:
        print("Default Error output: a non-descript ERROR has occurred!")
    finally:
        print("We are done here.")


main()

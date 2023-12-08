# Optional Lab(s) 6 by Luis Artavia - seven-day-average
# draft processed on: September 02, 2023 and September 03, 2023
# Composed on: September 02, 2023 and September 03, 2023
# Practice document not intended for evaluation

import csv
import requests


def main():
    # Read NYTimes Covid Database
    # download = requests.get("http://localhost/cs50/c/week6/us-states.csv")
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # print(f"new_cases: {new_cases}")

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)
    """
    """


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    # print(f"reader: {reader}\n\n") # <csv.DictReader object at 0x7fda1a3a6f70>

    records = {}  # records = dict()
    # print(f"records: {records}")

    for line in reader:
        # line["date"]     line["state"]     line["fips"]     line["cases"]     line["deaths"]

        # establish new dictionaries with 56 UNIQUE (line["state"]s) acting as key

        if line["state"] not in records:
            records[line["state"]] = []

        # New insertion
        # First restriction - for each key (state) restrict data to it's respective final 14 records
        # and repetitively pop off the zero index of each key until the 14 cases are achieved

        if len(records[line["state"]]) >= 14:
            records[line["state"]].pop(0)

        # cyclically append all cases to same 56 UNIQUE keys in string format notwithstanding other restrictions
        # i.e. {"Massachusetts": [ '1', '2' '3', '8', '13', '28', ... , '2227610', '2230150']}
        # The keys by default are in reverse order (i.e. - 'Washington' to 'American Samoa')
        # but the number of appended cases are correctly displayed from top to bottom similar to the csv file

        # records[line["state"]].append(line["cases"])
        records[line["state"]].append(int(line["cases"]))

    return records


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    # print(f"new_cases: {new_cases}\n\n")
    # print(f"states: {states}\n\n")

    # Massachusetts had a 7-day average of 1646 and an increase of 46%.
    # New York had a 7-day average of 7502 and a decrease of 1%.

    for state in states:
        """
        print(f"len(new_cases): {len(new_cases)}") # 56

        print(f"new_cases['Wyoming']: {new_cases['Wyoming']}")
        wyoming = new_cases['Wyoming']
        print(f"wyoming: {wyoming}")

        print(f"new_cases['Wyoming'][0:7]: {new_cases['Wyoming'][0:7]}")
        previous_cases = wyoming[0:7]
        print(f"previous_cases: {previous_cases}")

        print(f"new_cases['Wyoming'][7:]: {new_cases['Wyoming'][7:]}")
        recent_cases = wyoming[7:]
        print(f"recent_cases: {recent_cases}")
        """

        previous_cases = new_cases[state][0:7]
        previous_sum = sum(previous_cases)
        prev_len = len(previous_cases)
        # print(f"previous_sum: {previous_sum}")
        # print(f"prev_len: {prev_len}")

        recent_cases = new_cases[state][7:]
        recent_sum = sum(recent_cases)
        recent_len = len(recent_cases)
        # print(f"recent_sum: {recent_sum}")
        # print(f"recent_len: {recent_len}")

        previous_avg = previous_sum // prev_len
        recent_avg = recent_sum // recent_len
        # print(f"previous_avg: {previous_avg}")
        # print(f"recent_avg: {recent_avg}")

        # You can then calculate the percent increase or decrease, by taking the difference of the two 7-day averages and dividing by last week’s average.

        difference = recent_sum - previous_sum
        # print(f"difference: {difference}")

        try:
            # <variable> = <true_value> if <condition> else <false_value>
            phrase = "an increase" if difference > 0 else "a decrease"
            # print(f"phrase: {phrase}")

            change_up_down = difference / previous_avg * 100
            # print(f"change_up_down: {change_up_down:.03f}")

            # New York had a 7-day average of 7502 and a decrease of 1%.
            # final_string = "{state} had a 7-day average of {recent_avg} and {phrase} of {change_up_down:.03f}%."
            # print(f"{final_string}")
            # print(f"{state} had a 7-day average of {recent_avg} and {phrase} of {change_up_down:.03f}%.")
            print(
                f"{state} had a 7-day average of {recent_avg} and {phrase} of {round(change_up_down)}%."
            )

        except ZeroDivisionError as zerrp:
            print("ZeroDivisionError", zerrp)
        except:
            print("Default Error output: a non-descript ERROR has occurred!")
        # finally:
        #     print("We are done here.")


main()

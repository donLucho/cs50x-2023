# Required Problem set 6 by Luis Artavia - Tbd
# draft processed on: September 07, 2023 and September 08, 2023
# submitted for grade on: September 08, 2023


import csv
import sys


def main():
    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable

    database_file = []
    with open(sys.argv[1]) as dbfile:
        memory_db_obj = csv.DictReader(dbfile)
        for specimen in memory_db_obj:
            database_file.append(specimen)
    # print(f"DEV ONLY ~ database_file: {database_file}")

    """
    [
        {'name': 'Alice', 'AGATC': '2', 'AATG': '8', 'TATC': '3'},
        {'name': 'Bob', 'AGATC': '4', 'AATG': '1', 'TATC': '5'},
        {'name': 'Charlie', 'AGATC': '3', 'AATG': '2', 'TATC': '5'}
    ]

    ***pseudo-code***
    for i in database_file:
        print(database_file[i].keys())
        'name' is of no interest... access the remaining keys and their corresponding values
    """

    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2]) as samplefile:
        dnasequence = samplefile.read()
    # print(f"DEV ONLY ~ dnasequence: {dnasequence}\n")

    """
    5 instances of 'TATC' eliminates Alice...  Bob and Charlie are in the running
    1 instance of 'AATG' eliminates Charlie... only Bob remains by deference of database data
    170 chars

                                                                               1   2   3   4   5                                         1
                                                                               tatctatctatctatctatc                                      aatg
    AAGGTAAGTTTAGAATATAAAAGGTGAGTTAAATAGAATAGGTTAAAATTAAAGGAGATCAGATCAGATCAGATCTATCTATCTATCTATCTATCAGAAAAGAGTAAATAGTTAAAGAGTAAGATATTGAATTAATGGAAAATATTGTTGGGGAAAGGAGGGATAGAAGG
    """

    # 3
    # print(f"DEV ONLY ~ len(database_file): {len(database_file)}")
    # for i in database_file:
    #     print(f"DEV ONLY ~ i: {i}")
    # {'name': 'Alice', 'AGATC': '2', 'AATG': '8', 'TATC': '3'} etc, etc...

    # print(f"DEV ONLY ~ database_file[0].keys(): {database_file[0].keys()}")

    dict_keys_headers = database_file[0].keys()
    # print(f"DEV ONLY ~ dict_keys_headers: {dict_keys_headers}")
    # dict_keys(['name', 'AGATC', 'AATG', 'TATC'])

    headers_list = list(dict_keys_headers)
    # print(f"DEV ONLY ~ headers_list: {headers_list}")
    # ['name', 'AGATC', 'AATG', 'TATC']

    sliced_list = headers_list[1:]
    # print(f"DEV ONLY ~ sliced_list: {sliced_list}")
    # ['AGATC', 'AATG', 'TATC']

    # TODO: Find longest match of each STR in DNA sequence
    hits = dict()
    for sub in sliced_list:
        hits[sub] = longest_match(dnasequence, sub)
    # print(f"DEV ONLY ~ hits: {hits}")
    # for strand in hits:
    #     print(f"DEV ONLY key : value ~ for...in: {strand} : {hits[strand]}")

    # TODO: Check database for matching profiles

    for person in database_file:
        match = 0
        for sub in sliced_list:
            # print(f"DEV ONLY hits[sub]: {hits[sub]} : {type(hits[sub])} ")
            # print(f"DEV ONLY person[sub]: {person[sub]} : {type(person[sub])} \n")

            if hits[sub] == int(person[sub]):
                match += 1
                # print(f"DEV ONLY: match: {match}")
                # print(f"DEV ONLY: len(sliced_list): {len(sliced_list)}")

        # IF MATCH IS FOUND

        if match == len(sliced_list):
            print(f"{person['name']}")
            return

    # IF NO MATCH IS FOUND
    print(f"No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables

    longest_run = 0

    subsequence_length = len(subsequence)
    # e.g. - 4 (i.e. len('TATC'))
    # e.g. - 5 (i.e. len('AGATC'))

    sequence_length = len(sequence)
    # e.g. - 170

    # Check each character in sequence for most consecutive runs of subsequence

    for i in range(sequence_length):
        # e.g. - 0 to 170

        # Initialize count of consecutive runs

        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches

        while True:
            # Adjust substring start and end

            start = i + count * subsequence_length
            # e.g. WHEN i EQ. 0...  0 + (0 * 4) >>> 0
            # e.g. WHEN i EQ. 1...  1 + (0 * 4) >>> 1
            # e.g. WHEN i EQ. 76..  76 + (0 * 4) >>> 76
            # e.g. WHEN i EQ. 78..  77 + (1 * 4) >>> 81

            end = start + subsequence_length
            # e.g. WHEN i EQ. 0...  0 + 4       >>> 4
            # e.g. WHEN i EQ. 1...  1 + 4       >>> 5
            # e.g. WHEN i EQ. 76..  76 + 4       >>> 80
            # e.g. WHEN i EQ. 77..  81 + 4       >>> 85

            # If there is a match in the substring
            # e.g. WHEN i EQ. 0... sequence[0:4] denotes cutting off at index 4 and examining indices 0 to 3 (4 places)
            # if sequence[0:4] == 'TATC'    >>> THEN "count it!" if true >>> RUN count += 1 ELSE EXAMINE next four indices
            # if sequence[1:5] == 'TATC'    >>> ditto above, etc.
            # if sequence[76:80] == 'TATC'    >>> RUN count += 1, STILL "True" EXAMINE next four indices
            # if sequence[81:85] == 'TATC'    >>> THEN "count it!" if true >>> RUN count += 1 ELSE EXAMINE next four indices

            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            # e.g. evaluate the next substring similar to above >>> "wash, rinse, repeat"

            else:
                break

        # Update most consecutive matches found
        # e.g. self explicatory assign the greater of the two value b/t longest_run (self) and count

        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    # e.g. return the greater of the two value determined above

    return longest_run


main()
sys.exit(0)

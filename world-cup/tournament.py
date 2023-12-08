# Required Lab(s) 6 by Luis Artavia - tournament
# draft processed on: September 05, 2023
# submitted for grade on: September 05, 2023

# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run

"""
N = 10
N = 100
"""
N = 1000
"""
N = 10000
N = 100000
N = 1000000
"""

# print(f"DEV ONLY ~ N: {N}")


def main():
    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file

    # Add teams by reading csv file
    with open(sys.argv[1]) as file:
        memory_object = csv.DictReader(file)
        for participant in memory_object:
            participant["rating"] = int(participant["rating"])
            teams.append(participant)

    # print(teams)
    # print(f"There are {len(teams)} records when interpreted by the DictReader method!\n")

    # print(f"DEV ONLY ~ teams: {teams}")

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N):
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1

    # print(f"\nDEV ONLY ~ counts: {counts}\n")

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")

    # DEV ONLY
    # for team in sorted(counts, key=lambda team: counts[team], reverse=False):
    # print(f"DEV ONLY ~ {team}: {counts[team]}")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]["team"]


if __name__ == "__main__":
    main()

"""
python3 tournament.py 2019w.csv
time python3 tournament.py 2019w.csv

python3 tournament.py 2018m.csv
time python3 tournament.py 2018m.csv

"""

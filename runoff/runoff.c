// Required Problem set 3 by Luis Artavia - Runoff
// draft processed on: July 13, 2023, July 15, 2023, July 20, 2023, July 21, 2023
// submitted for grade on: July 21, 2023

#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;


// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

// DEV ONLY
// void candidates_to_console(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();

        // printf("DEV ONLY: The lowest amount is %i.\n", min);
        // break; // DEV ONLY

        bool tie = is_tie(min);

        // string stringula = tie ? "true" : "false";  // DEV ONLY
        // printf("DEV ONLY: y/n Tied or not: %s.\n", stringula);  // DEV ONLY
        // break; // DEV ONLY

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // @ 7m32s to 8m20s, 8m20s to 9m35s
    //     - Look for a candidate through parameter name
    //     - If candidate located, update preferences so that
    //     they are the voter's rank preference, and return true.
    //     - If no candidate found, don't update any preferences and return false.

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // @ 9m35s to 10m07s, 10m07s to 11m46s
    //     - Update vote counts for all non-eliminated candidates
    //     - Recall that each voter votes for their highest preference candidate who has not yet been eliminated
    //     Index 0 of all rows gives scoreboard

    for (int voter = 0; voter < voter_count; voter = voter + 1)
    {
        int j = 0;
        while (true)
        {
            int idx = preferences[voter][j];
            if (candidates[idx].eliminated == true)
            {
                // boost the next non-eliminated candidate into the slot for immediate tabulation
                j = j + 1;
            }
            if (candidates[idx].eliminated == false)
            {
                candidates[idx].votes = candidates[idx].votes + 1;
                break;
            }
        }
    }

    // candidates_to_console();

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // @ 11m46s to 12m16s, 12m16s to 12m56s
    //     - If any candidate has more than half the vote, print out their name and return true.
    //     - If nobody has yet won the election, return false.

    // Endless terminal, at least, with a definitive winner break the infinite loop acc. to main()
    // cycle through candidates, count the votes

    int majority_definition = round((float) voter_count / 2);
    for (int i = 0; i < candidate_count; i = i + 1)
    {
        if (candidates[i].votes > majority_definition)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // @ 12m57s to 13m15s, 13m15s to 14m18s
    //     - Return the minimum number of votes of anyone still remaining in the election.
    //     (e.g. - WHERE candidates[i].eliminated == false)
    //     (e.g. - RETURN candidates[i].votes LOWBALL of the bunch)
    //     (e.g. - WHERE candidates[i].name "Alice")

    candidate worst_candidate;
    worst_candidate = candidates[0];
    for (int i = 0; i < candidate_count; i++)
    {
        if ((worst_candidate.votes > candidates[i].votes) && (candidates[i].eliminated == false))
        {
            worst_candidate = candidates[i];
        }
    }

    // printf("DEV ONLY: The lowest amount is %i.\n", worst_candidate.votes);

    return worst_candidate.votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // @ 14m18s to 14m28s, 14m28s to 14m50s, 14m50s to 15m20s
    //     - Decide whether this election is tied between all of the remaining candidates
    //     - Accepts the minimum number of votes 'min()' as input
    //     - Returns true if the election is tied between all remaining candidates, and returns false otherwise

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false)
        {
            if (candidates[i].votes != min)
            {
                return false;
            }
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // @ 15m20s to 16m00s, 16m00s to 16m20s, 16m20s to 17m00s

    //     - Eliminate anyone still in the race who has the 'min' number of votes

    //     - This is the function that's going to take
    //     care of the process of actually eliminating
    //     the candidate who's in last place in the
    //     action such that the election can run
    //     again as if that person had not been in
    //     the election in the first place

    //     - this function will change struct candidate[i].eliminated from
    //     default value of false to that of true instead

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}

// DEV ONLY
// void candidates_to_console(void)
// {
//     for (int i = 0; i < candidate_count; i++)
//     {
//         string booly = (candidates[i].eliminated) ? "true" : "false";
//         printf("DEV ONLY: Candidate: %s, Votes: %i, Eliminated: %s\n", candidates[i].name, candidates[i].votes, booly);
//     }
// }
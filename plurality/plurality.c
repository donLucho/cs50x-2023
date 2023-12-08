// Required Problem set 3 by Luis Artavia - Plurality
// draft processed on: July 13, 2023, July 14, 2023 and July 15, 2023
// submitted for grade on: July 15, 2023
// draft-07-corrected-plurality.c

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);



int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
            i = i - 1; // ...here
        }
    }

    // Display winner of election
    print_winner();
}

// TODO - Update vote totals given a new vote
bool vote(string name)
{
    bool the_acceptable_answer = false;  // (int) the_acceptable_answer of false RETURNS 0
    // bool the_acceptable_answer = true;       // (int) the_acceptable_answer of true RETURNS 1

    // int looplen = sizeof(candidates) / sizeof(candidates[0]);
    // for (int i = 0; i < MAX; i++)
    // for (int i = 0; i < looplen; i++)
    for (int i = 0; i < candidate_count; i++)
    {

        // printf("DEV CONSOLE ONLY: Presenting %s with %i votes\n" , candidates[i].name, candidates[i].votes );

        if (strcmp(candidates[i].name, name) == 0)
        {
            string candidate_name = candidates[i].name;
            int candidate_votes = candidates[i].votes;


            // It's 2023. And, this looks like a good place for a stick-up!
            // Insert the calc code here...

            // printf("DEV CONSOLE ONLY: %s had %i votes.\n", candidate_name, candidate_votes);
            candidates[i].votes = candidates[i].votes + 1;
            // printf("DEV CONSOLE ONLY: Next, %s WILL HAVE %i votes.\n", candidate_name, (int) (candidate_votes + 1));

            // printf("DEV CONSOLE ONLY: Both 'name'(s) of %s are equal. \n", candidates[i].name);
            // printf("DEV CONSOLE ONLY: %s had %i votes.\n", candidate_name, candidate_votes);

            the_acceptable_answer = true;
        }

    }

    // printf("DEV CONSOLE ONLY: the_acceptable_answer: %i\n" , (int) the_acceptable_answer);

    // the_acceptable_answer is the decision to not count vote with a value of false
    // a value of true is an exception meaning the vote has since been counted and tallied as confirmation of the fact

    return the_acceptable_answer;
}

// TODO- Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // Complete the print_winner function.
    //     - The function should print out the name of the candidate who received the most votes in the election, and then print a newline.
    //     - It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, you should output the names of each of the winning candidates, each on a separate line.

    // return; // orig
    // printf("Joe deRita\n");

    candidate zed_index;

    zed_index = candidates[0];

    // do not need this letter j for the moment
    // int j;

    // int looplen = sizeof(candidates) / sizeof(candidates[0]);

    // for (int i = 0; i < MAX; i++)
    // for (int i = 0; i < looplen; i++)
    for (int i = 0; i < candidate_count; i++)
    {

        // printf("fubarfubar DEV CONSOLE ONLY: Presenting %s with %i votes\n" , candidates[i].name, candidates[i].votes );

        if (zed_index.votes < candidates[i].votes)
        {
            zed_index = candidates[i];
        }
    }

    // printf("DEV CONSOLE ONLY: zed_index.votes: %i\n", zed_index.votes);

    // printf("DEV CONSOLE ONLY: Hold my beer...\n");

    // for (int k = 0; k < MAX; k++)
    // for (int k = 0; k < looplen; k++)
    for (int k = 0; k < candidate_count; k++)
    {
        // printf("tarfutarfu DEV CONSOLE ONLY: Presenting %s with %i votes\n" , candidates[k].name, candidates[k].votes );

        if ((candidates[k].votes > 0) && (candidates[k].votes == zed_index.votes))
        {
            printf("%s\n", candidates[k].name);
        }
    }
}


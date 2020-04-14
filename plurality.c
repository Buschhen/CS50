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
            //if invalid print and ask user agin
            printf("Invalid vote.\n");
            // while awnser is false ask agin for input
            int tillright = 0;
            while (tillright == 0)
            {
                //init loop breaker
                int invalidcounter = 0;
                //Get string
                string votename = get_string("Vote: ");
                // check if enterd name is equal to candidate
                for (int n = 0; n < candidate_count; n++)
                {
                    //compare strings
                    if (strcmp(candidates[n].name, votename) == 0)
                    //if true end loop and give name vote +1
                    {
                        candidates[n].votes++;
                        tillright++;
                    }
                }
                //if tillright 0 print invalid
                if (tillright == 0)
                {
                    printf("Invalid vote.\n");
                }
            }
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int true_counter = 0;
    // Loop through canidates and check if name is eqal to candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        // if true candidate 1+ vote and loopbreaker active
        {
            candidates[i].votes++;
            true_counter++;
        }
    }
    if (true_counter > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // init var with first candidate to go around errors
    int max_votes = candidates[0].votes;
    // Get max votes of user
    for (int i = 0; i < candidate_count; i++)
    {
        // if the current max is lower then the checking one make checking one max
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }
    //check for all user that have max_votes votes and print name
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}


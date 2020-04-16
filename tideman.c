#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int f = i + 1; f < candidate_count; f++)
    {
            if ( i != candidate_count - 1)
            {
                preferences[ranks[i]][ranks[f]]++;
            }
        }
    }
    //for (int i = 0; i < candidate_count; i++)
    //{
    //    if (i != ranks[0])
    //    {
    //        preferences[ranks[0]][i]++;
    //    }
    //    if (i != ranks[0] && i != ranks[1])
    //    {
    //        preferences[ranks[1]][i]++;
    //    }
    //}
        for (int i = 0; i < candidate_count; i++)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                //printf("%i",preferences[i][j]);
            }
            //printf("\n");
        }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] != 0)
            {
                if (preferences[i][j] != preferences[j][i])
                {
                    if (preferences[i][j] > preferences[j][i])
                    {
                        int count = 0;
                        for (int k = 0; k < pair_count + 1; k++)
                        {
                            if (pairs[k].winner == i && pairs[k].loser == j)
                            {
                                count++;
                            }
                        }
                        if (count == 0 && preferences[i][j] != preferences[j][i])
                        {
                            pairs[pair_count].winner = i;
                            pairs[pair_count].loser = j;
                            pair_count++;
                        }
                    }
                    else
                    {
                        int count = 0;
                        for (int k = 0; k < pair_count + 1; k++)
                        {
                            if (pairs[k].winner == j && pairs[k].loser == i)
                            {
                                count++;
                            }
                        }
                        if (count == 0 && preferences[i][j] != preferences[j][i])
                        {
                        pairs[pair_count].winner = j;
                        pairs[pair_count].loser = i;
                        pair_count++;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < pair_count; i++)
    {
        //printf("winner %s\n",candidates[pairs[i].winner]);
        //printf("loser %s\n",candidates[pairs[i].loser]);
    }
    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    int sort[pair_count];
    for (int p = 0; p < pair_count; p ++)
    {
        sort[p] = preferences[pairs[p].winner][pairs[p].loser] - preferences[pairs[p].loser][pairs[p].winner];
        //printf("sort: %i\n", sort[p]);
    }
    for (int z = 0; z < pair_count - 1; z++)
    {
        for (int s = 0; s < pair_count - z - 1; s++)
        {
            if(sort[s] < sort[s + 1])
            {
                int temp = sort[s];
                sort[s] = sort[s + 1];
                sort[s + 1] = temp;
                //change in the pairs array
                int pairwin = pairs[s].winner;
                int pairlos = pairs[s].loser;
                pairs[s].winner = pairs[s + 1].winner;
                pairs[s].loser = pairs[s + 1].loser;
                pairs[s + 1].winner = pairwin;
                pairs[s + 1].loser = pairlos;
            }
        }
    }
    for (int i = 0; i < pair_count; i++)
    {
        //printf("winner %s\n",candidates[pairs[i].winner]);
        //printf("loser %s\n",candidates[pairs[i].loser]);
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        bool skip = true;
        int cycle = 0;
        for (int c = 0; c < candidate_count; c++)
        {
            cycle = 0;
            for (int v = 0; v < candidate_count; v++)
             {
                if (locked[v][c] == false)
                {
                    cycle++;
                }
             }
             if (cycle == candidate_count)
             {
                 skip = false;
             }
        }
        if(!skip)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
          //  printf("%i",locked[i][j]);
        }
        //printf("\n");
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int winnerc = 0;
    int winner_index = 0;
    int winners = 0;
    for (int q = 0; q < candidate_count; q++)
    {
        int tempc = 0;
        for (int h = 0; h < candidate_count; h++)
        {
            if (locked[q][h] == 1)
            {
                tempc++;
            }
        }
        if (tempc > winnerc)
        {
            winnerc = tempc;
        }
    }
    for (int p = 0; p < candidate_count; p++)
    {
        int tempc = 0;
        for (int u = 0; u < candidate_count; u++)
        {
            if (locked[p][u] == 1)
            {
                tempc++;
            }
        }
        if (tempc == winnerc)
        {
            winners++;
        }
    }
    int winnerarray[winners];
    int winnerindexc = 0;
    for (int a = 0; a < candidate_count; a++)
    {
        int tempc = 0;
        for (int b = 0; b < candidate_count; b++)
        {
            if (locked[a][b] == 1)
            {
                tempc++;
            }
        }
        if (tempc == winnerc)
        {
            winnerarray[winnerindexc] = a;
            winnerindexc++;
        }
    }
    for (int m = 0; m < winnerindexc; m++)
    {
        printf("%s\n",candidates[winnerarray[m]]);
    }
    return;
}

//winner Bob
//loser Alice
//winner Alice
//loser Gwen
//winner Gwen
//loser Bob
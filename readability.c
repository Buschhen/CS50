// All includings
# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

// Telling compiler in code blow are these functions
int words(string text);
int letters(string text);
int sentences(string text);

// Start of main function
int main(void)
{
    // Get string from user
    string text = get_string("TEXT: ");
    // Initialize vars for math operation
    float index, L, S, word = words(text);
    // how many letters in 100 words and how many sentences per 100 words
    float to100 = 100 / word;
    L = to100 * letters(text);
    S = to100 * sentences(text);
    // Getting the final number for which grade
    index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");    
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
    


}

//function for how many words
int words(string text)
{
    // setting words to one becasue there is always 1 word more than spaces
    int words = 1;
    for (int i = 0,  n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }
    return words;
}


int letters(string text)
{
    //initializing letter
    int letters = 0;
    for (int i = 0,  n = strlen(text); i < n; i++)
    {
        //dont count any spezial signs like . or ,
        if (text[i] == 32 || text[i] == 33 || text[i] == 39 || text[i] == 44 || text[i] == 45 || text[i] == 46 || text[i] == 59
            || text[i] == 63 || text[i] == 96)
        {

        }
        else
        {
            letters++;
        }
    }
    return letters;
}

// for home many sentences in string
int sentences(string text)
{
    int sentences = 0;
    for (int i = 0,  n = strlen(text); i < n; i++)
    {
        //if there is a . or ! or ? the sentence is finished
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}
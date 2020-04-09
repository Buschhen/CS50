# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main(int argc, string argv[])
{
    //Get input from user in shorter var
    string k = argv[1];
    //Check if no command is enterd
    if (argc == 1)
    {
        printf("please enter a key\n");
        return 1;
    }
    // check if more then 1 command is entered
    else if (argc > 2)
    {
        printf("please enter only one key\n");
        return 1;
    }
    else
    {
        // Check if the entered key is 26 chars long
        if (strlen(k) != 26)
        {
            printf("Please enter a key which is 26 chars long\n");
            return 1;
        }
        // make array with 26 indexs and initialize them with 0
        int checkarray[26] = {0};
        // loop throug array which was command line input
        for (int i = 0, n = strlen(k); i < n; i++)
        {
            // If you can make them to upper or lower case they are a string and you can procede
            if (islower(k[i]) || isupper(k[i]))
            {
                // take the command line array and make them to lower and - 97 so its 0 and  26 in array index and then inc the number at this index
                checkarray[tolower(k[i]) - 97] ++;
                // if a letter is repeated the number is over 1 and so you just check if it is more than one if it's more than one return error
                if (checkarray[tolower(k[i]) - 97] > 1)
                {
                    printf("Please enter every char only once\n");
                    return 1;
                }
            }
            //there the command line enterd is not a letter return error
            else
            {
                printf("Please enter only chars\n");
                return 1;
            }
        }
    }
    //All checks are valid proceed with encrypting
    //Get string from user
    string t = get_string("plaintext:  ");
    //loop through string
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        //If its lowercase letter use this method
        if (t[i] > 96 && t[i] < 123)
        {
            //save in the array enter from user the letter with the same index in the command line entered array
            t[i] = tolower(k[tolower(t[i]) - 97]);
        }
        // if its uppercase letter use this method
        else if (t[i] > 64 && t[i] < 91)
        {
            //save in the array enter from user the letter with the same index in the command line entered array
            t[i] = toupper(k[tolower(t[i]) - 97]);
        }
    }
    //printf the new text
    printf("ciphertext: %s\n", t);
    // return everything is fine
    return 0;
}

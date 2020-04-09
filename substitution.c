# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>

int check(string k);

int main(int argc, char* argv[])
{
    string k = argv[1];

    if (argc == 1)
    {
        printf("please enter a key\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("please enter only one key\n");
        return 1;
    }
    else
    {
        if (strlen(k) != 26)
        {
            printf("Please enter a key which is 26 chars long\n");
            return 1;
        }
        int checkarray[26] = {0};
        for (int i = 0,n = strlen(k); i < n; i++)
        {
            if (islower(k[i]) || isupper(k[i]))
            {
                checkarray[tolower(k[i]) - 97] ++;
                if (checkarray[tolower(k[i]) - 97] > 1)
                {
                    printf("Please enter every char only once\n");
                    return 1;
                }
            }
            else
            {
                printf("Please enter only chars\n");
                return 1;
            }
        }
    }
    string t = get_string("plaintext:  ");
    for (int i = 0,n = strlen(t); i < n; i++ )
    {
        if (t[i] > 96 && t[i] < 123)
        {
            t[i] = k[tolower(t[i])- 97];
        }
        else if (t[i] > 64 && t[i] < 91)
        {
            t[i] = toupper(k[tolower(t[i]) - 97]);
        }
    }
    printf("cihpertext: %s\n", t);
    return 0;
}

# include<cs50.h>
# include<stdio.h>

int main(void)
{
    //Get use imput
    long int prompt = get_long("creditCard = ");
    long int ccn = prompt;
    //Get length of array1
    int length = 1;
    while (prompt > 0)
    {
        int temp = prompt % 10;
        length++;
        prompt /= 10;
    }
    //Put string in array
    int lengthindex = length;
    int array1[length - 1];
    int array1index = 0;
    while (ccn > 0)
    {
        int temp = ccn % 10;
        array1[array1index] = temp;
        array1index++;
        ccn /= 10;
    }
    //Get length of arrays;
    int arrayt2index = 0;
    int arrayrestindex = 0;

    for (int i = 0; i < length - 1 ; i++)
    {
        if (i == 0)
        {
            arrayrestindex++;
        }
        else if (i % 2 == 0)
        {
            arrayrestindex++;
        }
        else
        {
            arrayt2index++;
        }
    }
    //make 2 Array for further math
    int arrayrest[arrayrestindex];
    int arrayrestcounter = 0;
    int arrayt2[arrayt2index];
    int arrayt2counter = 0;

    //Get arrays
    for (int i = 0; i < lengthindex - 1; i++)
    {
        if (i == 0)
        {
            arrayrest[arrayrestcounter] = array1[i];
            arrayrestcounter++;
        }
        else if (i % 2 == 0)
        {
            arrayrest[arrayrestcounter] = array1[i];
            arrayrestcounter++;
        }
        else
        {
            arrayt2[arrayt2counter] = array1[i];
            arrayt2counter++;
        }
    }
    for (int i = 0; i < arrayt2index; i++)
    {
        arrayt2[i] *= 2;
    }
    //Array loop through arrayt2
    int sum = 0;
    int temp = 0;
    for (int i = 0; i < arrayt2index; i++)
    {
        if (arrayt2[i] >= 10)
        {
            temp = arrayt2[i] % 10;
            sum += temp;
            arrayt2[i] /= 10;
            sum += arrayt2[i];
        }
        else
        {
            sum += arrayt2[i];
        }
    }
    //For loop for returning status
    for (int i = 0; i < arrayrestindex; i++)
    {
        sum += arrayrest[i];    //Summ everything up
    }
    if (sum % 10 != 0 || length < 13)
    {
        printf("INVALID\n");
    }
    else
    {
        int Cardhost = (array1[length - 2] * 10) + array1[length - 3]; //First two digets of number passed in by user
        switch (Cardhost)
        {
            case 34:        //Cases for American Express
            case 37:
            {
                printf("AMEX\n");
                break;
            }
            case 51:        //Cases for Mastercard
            case 52:
            case 53:
            case 54:
            case 55:
            {
                printf("MASTERCARD\n");
                break;
            }
            case 40:        //Cases fro Visa
            case 41:
            case 42:
            case 43:
            case 44:
            case 45:
            case 46:
            case 47:
            case 48:
            case 49:
            {
                printf("VISA\n");
                break;
            }
            default:
            {
                printf("INVALID\n");
                break;
            }
        }
    }
}

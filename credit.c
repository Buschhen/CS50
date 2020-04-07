# include<cs50.h>
# include<stdio.h>

int main (void)
{
    long int prompt = get_long("creditCard = ");
    long int ccn = prompt;
    int length = 1;
    while (prompt > 0)
    {
        int temp = prompt % 10;
        length++;
        prompt /= 10;
    }
    int lengthindex = length;
    int array1[length - 1];
    int array1index = length - 2;
    while (ccn > 0)
    {
        int temp = ccn % 10;
        array1[array1index] = temp;
        array1index--;
        ccn /= 10;
    }
    for (int i = 0; i < length - 1; i++)
    {
        //printf("array = %i\n", array1[i]);
    }
    //Get length of arrays;
    int arrayt2index = 0;
    int arrayrestindex = 0;
    while (length - 1 > 0)
    {
        if(length % 2 == 0)
        {
            arrayt2index++;
            length--;
        }
        else
        {
            arrayrestindex++;
            length--;
        }
    }
    int arrayrest[arrayrestindex];
    int arrayrestcounter = 0;
    int arrayt2[arrayt2index];
    int arrayt2counter = 0;

    //Get arrays
    for (int i = 0; i < lengthindex - 1; i++)
    {
        if (i == 0){
            arrayt2[arrayt2counter] = array1[i];
            arrayt2counter++;
        }
        else if(i % 2)
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
    for (int i = 0;i < arrayt2index; i++)
    {
        //printf("arrayt2 %i\n",arrayt2[i]);
        arrayt2[i] *= 2;
        //printf("arrayt2 %i\n",arrayt2[i]);
    }
    for (int i = 0;i < arrayrestindex; i++)
    {
        //printf("arrayrestindex %i\n", arrayrest[i]);
    }
    //Array loop through arrayt2
    int sum = 0;
    int temp = 0;
    for (int i = 0; i < arrayt2index; i++)
    {
        if(arrayt2[i] >= 10)
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
    //printf("sum = %i", sum);
    for (int i = 0; i < arrayrestindex;i++)
    {
        //printf("arrayrest = %i\n", arrayrest[i]);
        sum += arrayrest[i];
    }
    //printf("sum = %i\n", sum);
    if(sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        int Cardhost = 0;
        Cardhost = (array1[0] * 10) + array1[1];
        //printf("Cardhost number is = %i", Cardhost);
        switch(Cardhost)
        {
            case 34:
            case 37:
            {
                printf("AMEX\n");
                break;
            }
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
            {
                printf("MASTERCARD\n");
                break;
            }
            case 40:
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
        }
    }
    //printf("arrayrestindex = %i\n arayt2index = %i", arrayrestindex,arrayt2index);
}

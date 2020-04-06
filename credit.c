# include <cs50.h>
# include <stdio.h>

int main (void)
{
    //Get crad number
    long int prompt = get_long("credit card number: ");
    long int ccn = prompt;
    //Get arraylength
    int arraylength = 0;
    while(prompt > 0)
    {
        int s = prompt % 10;
        arraylength ++;
        prompt /= 10;
    }
    //printf("%i",arraylength);
    //Get in array for better handling
    int arraycounter = 1;
    int ccnarray[arraylength + 1];
    while(ccn > 0)
    {
        int res = ccn % 10;
        ccnarray[arraylength - arraycounter] = res;
        ccn /= 10;
        arraycounter ++;
    }
    int resultlength  = 0;
    arraylength ++;
    if (arraylength % 2 == 1)
    {
        resultlength = (arraylength - 1) / 2;
    }
    else
    {
        resultlength = arraylength / 2;
    }
    //Get array length

    //printf("%i\n",resultlength);

    //Make every second element in array
    int resultarray[resultlength];
    int resultarraycounter = 0;
    for (int i = 0; i < arraylength - 1; i += 2)
    {
        resultarray[resultarraycounter] = ccnarray[i] * 2;
        //printf("ccnarray: %i\n", ccnarray[i]);
        resultarraycounter ++;
    }
    //Summ all together 
        int sum = 0;
        int tempres = 0;
        int tempres2 = 0;
        for (int i = 0; i < resultlength ; i++)
    {
        if(resultarray[i]>10)
        {
            tempres = resultarray[i] % 10;
            sum += tempres;
            resultarray[i] /= 10;
            tempres2 = resultarray[i];
            sum += tempres2;
        }
        else
        {
            sum += resultarray[i];
        }
    
    }
    printf("%i",sum);


    for (int i = 0; i < resultlength ; i++)
    {
        //printf("%i\n",resultarray[i]);
    }
}

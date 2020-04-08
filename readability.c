# include <cs50.h>
# include <stdio.h>
# include <string.h>
# include <math.h>

int words(string text);
int letters(string text);
int sentences(string text);

int main(void)
{
    string text = get_string("TEXT: ");
    
    float index,L,S,word = words(text);
    float to100 = 100 / word;
    L = to100 * letters(text);
    S = to100 * sentences(text);
    index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1 )
    {
        printf("Before Grade 1\n");    
    }else if (index >= 16)
    {
        printf("Grade 16 +\n");
    }else
    {
        printf("Grade %.0f\n", round(index));
    }
    
    //printf("%i letter (s)\n%i word (s)\n%i sentence (s)\n", letters(text),words(text),sentences(text));
    //printf("Grade %.0f\n",index);

}


int words(string text)
{
    int words = 1;
    for (int i = 0,  n = strlen(text); i < n; i++)
    {
       if(text[i] == 32)
       {
           words++;
       }
    }
    return words;
}

//It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.
//When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
 //space ! ' , . ; ?

int letters(string text)
{
    int letters = 0;
    for (int i = 0,  n = strlen(text); i < n; i++)
    {
       if (text[i] == 32 ||text[i] == 33 || text[i] == 39 ||text[i] == 44 || text[i] == 45 || text[i] == 46 || text[i] == 59 || text[i] == 63 || text[i] == 96)
       {

       }
       else
       {
           letters++;
       }
    }
    return letters;
}

int sentences(string text)
{
    int sentences = 0;
    for (int i = 0,  n = strlen(text); i < n; i++)
    {
       if (text[i] == 33 ||text[i] == 46 || text[i] == 63)
       {
            sentences++;
       }
    }
    return sentences;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//Define how large your blocks should be you want to search
#define BLOCK_SIZE 512
//Make a Type with bytes because you want to store bytes
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check that the usage is correct
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    //save entered file
    char *file = argv[1];
    FILE *infile = fopen(file, "r");
    //check if file can be opend
    if (infile == NULL)
    {
        printf("Could not open %s\n", file);
        return 2;
    }
    //make array for name of the file
    char filename[8];
    //buffer for each block
    BYTE buffer[512];

    //check if file is open
    int open = 0;
    //image counter
    int imgcounter = 0;
    //create file which is empty
    FILE *img = NULL;
    //while file out put is 1 so not empty repeate process
    while (fread(buffer, BLOCK_SIZE, 1, infile) == 1)
    {
        //check if first 4 bytes are beginning of a jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if a file is open the counter is one close file and reset var to 0
            if (open == 1)
            {
                fclose(img);
                open = 0;
            }
            //make file name
            sprintf(filename, "%03i.jpg", imgcounter);
            //open new file with new file name
            img = fopen(filename, "w");
            //if file can't be open return error
            if (img == NULL)
            {
                return 3;
            }
            //Counters for which image and that a file is currently open
            imgcounter++;
            open++;
        }
        //if the file can be read write in it
        if (img != NULL)
        {
            //write each block one from buffer to img
            fwrite(buffer, BLOCK_SIZE, 1, img);
        }
    }
    //close last open file and card file
    fclose(img);
    fclose(infile);
    //return with success
    return 0;
}

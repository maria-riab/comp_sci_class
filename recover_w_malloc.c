#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#define NUM 512

typedef uint8_t BYTE;

bool is_jpeg(BYTE *buffer[]);

int main(int argc, char* argv[])
{

    // check if input is valid, else return one
    if (argc != 2)
    {
        printf("invalid entry\n");
        return 1;
    }

    // open the file and make sure its not NULL
    char *card = argv[1];

    FILE *memory_card = fopen(card, "r");
    if (memory_card == NULL)
    {
        printf("can't open file\n");
        return 1;
    }

    //initialize buffer, output file, jpeg counter
    FILE* img = NULL;

    BYTE *buffer = malloc(512 * sizeof(BYTE));

    int jpeg_counter = -1;

//repeat till end of file, read 512 bytes into the memory card
    while (fread(&buffer, sizeof(NUM), 1, memory_card) == 1)
    {
        //if jpeg header found
        if(is_jpeg(&buffer))
        {
            jpeg_counter++;

            // //a jpeg has already been found, close current open jpeg
            if (jpeg_counter > 0)
            {
                fclose(img);
            }

            //open a file w these perameters and increment jpeg counter
            char filename[9];

            sprintf(filename, "%03i.jpg", jpeg_counter);

            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("cant open a new file");
                return 1;
            }

            fwrite(&buffer, NUM, 1, img);


        }
        else
        {
            if (jpeg_counter >= 0) //if we found a jpeg already
            {
               fwrite(&buffer, NUM, 1, img);
            }
            else // dont worry bout it keep goin
            {
                continue;
            }
        }

    }


    free(buffer);

    fclose(memory_card);

    fclose(img);


}

bool is_jpeg(BYTE *buffer[])
{
    return (*buffer[0] == 0xff) && (*buffer[1] == 0xd8) && (*buffer[2] == 0xff) && ((*buffer[3] & 0xf0) == 0xe0);
}

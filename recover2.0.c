
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define NUM 512

typedef uint8_t BYTE;

bool jpeg_header_found(BYTE buffer[]);

int main(int argc, char *argv[])
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
    FILE *img = NULL ;

    BYTE buffer[NUM];

    int jpeg_counter = 0;


    char filename[9];

    //repeat till end of file, read 512 bytes into the memory card
    while (!feof(memory_card))// check how many bytes have i read
    {
        int bytes_read = fread(&buffer, sizeof(BYTE), NUM, memory_card);

       if(bytes_read != NUM)
        {
            break;
        }


        //if jpeg header found
        if (jpeg_header_found(buffer))
        {
             // //a jpeg has already been found, close current open jpeg
            if (jpeg_counter > 0)
            {
                fclose(img);
            }

            //open a file w these perameters
            sprintf(filename, "%03i.jpg", jpeg_counter);

            img = fopen(filename, "w");

            jpeg_counter++; //increment jpeg counter
        }
        if (img != NULL)
        {

            fwrite(&buffer, sizeof(BYTE), bytes_read, img);
        }




    }
    fclose(memory_card);

    fclose(img);
}

bool jpeg_header_found(BYTE buffer[])
{
    return (buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0);
}

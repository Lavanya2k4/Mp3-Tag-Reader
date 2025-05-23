#include "header.h"
int edit(int argc, char* argv,char* argv1)
{
    FILE *in = fopen("sample.mp3","r"); //open the file in read mode
    if (in == NULL) 
    {
        printf("Input file cannot be opened\n");
        return 0;
    }
    FILE *out = fopen("temp.mp3","w"); //open the file in write mode
    if (out == NULL) 
    {
        printf("Output file cannot be opened\n");
        return 0;
    }
    char header[10];
    fread(header, 10, 1, in); //read the 10 bytes header
    fwrite(header, 10, 1, out);//copy the 10 bytes of header into new file
    for(int i=0;i<6;i++)
    {
        char tag[5];
        int size_b; // big endian
        char flag[3];

        fread(tag, 4, 1, in);//read the tag
        tag[4] = '\0';

        fread(&size_b, 4, 1, in);
        // Convert size from big endian to little endian
        int size = size_b;
        char *ptr = (char *)&size;
        for (int j = 0; j < 4/2; j++)
        {
            char temp = ptr[j];
            ptr[j] = ptr[4 - j - 1];
            ptr[4 - j - 1] = temp;
        }
        fread(flag, 3, 1, in);//read the flag

        char data[600];
        fread(data, size - 1, 1, in);//read the data
        data[size - 1] = '\0';
        // Determine target tag based on argument
        char update_tag[5] ={0};
        if (strcmp(argv, "-t") == 0)
        {
            strcpy(update_tag, "TIT2");
        }
        else if (strcmp(argv, "-p") == 0)
        {
            strcpy(update_tag, "TPE1");
        }
        else if (strcmp(argv, "-a") == 0)
        {
            strcpy(update_tag, "TALB");
        }
        else if (strcmp(argv, "-y") == 0)
        {
            strcpy(update_tag, "TYER");
        }
        else if (strcmp(argv, "-c") == 0)
        {
            strcpy(update_tag, "TCON");
        }
        else if (strcmp(argv, "-m") == 0)
        {
            strcpy(update_tag, "COMM");
        }
        // Check if this is the tag to update
        if (strcmp(tag,update_tag) == 0)
        {
            int new_size = strlen(argv1) + 1; // new size (little endian)
            int size2 = new_size;//bigendian

            // Convert size2 to big endian
            ptr = (char *)&size2;
            for (int j = 0; j < 4/2; j++)
            {
                char temp = ptr[j];
                ptr[j] = ptr[4 - j - 1];
                ptr[4 - j - 1] = temp;
            }
            // Write updated tag
            fwrite(tag, 4, 1, out);
            fwrite(&size2, 4, 1, out);
            fwrite(flag, 3, 1, out);
            fwrite(argv1, new_size - 1, 1, out); // remove null terminator
            printf("Successfully updated\n");
        }
        else
        {
            // Write original tag
            fwrite(tag, 4, 1, out);
            fwrite(&size_b, 4, 1, out);
            fwrite(flag, 3, 1, out);
            fwrite(data, size - 1, 1, out);
        }
    }
    // Copy remaining bytes
    char ch;
    while (fread(&ch, 1, 1, in) > 0) 
    {
        fwrite(&ch, 1, 1, out);
    }
    fclose(in);
    fclose(out);
    remove("sample.mp3");             // remove  old file
    rename("temp.mp3", "sample.mp3"); // Rename newfile file as original file
    return 0;
}

#include "header.h"

void convert(int *size) //convert big endian to little endian
{
    char *ptr = (char *)size;
    for (int i = 0; i < 4/2; i++)
    {
        char temp = ptr[i];
        ptr[i] = ptr[4-i-1];
        ptr[4-i-1] = temp;
    }
}
void read_tag(char *tag, FILE *fp)//read the tag
{
    fread(tag, 4, 1, fp);
    tag[4] = '\0';
}
int read_size(int *size,FILE *fp)//read the size
{
    fread(size, 4, 1, fp);
    convert(size);
}
void read_data(char *data, int size, FILE *fp)//read the data
{
    fread(data, size - 1, 1, fp);
    data[size - 1] = '\0';
}
int view(int argc,char argv[])
{
    printf("\n------------------------------------->\n");
    printf("MP-3 Tag Reader and Editor for ID3v2.3");
    printf("\n-------------------------------------->\n");
    FILE *fp= fopen("sample.mp3", "r"); //open the file in read mode
    if (fp == NULL)
    {
        printf("file cannot be opened\n");
        return 0;
    }
    char tag[5];
    int size;
    char data[600];
    fseek(fp, 10, SEEK_SET);//skips the 10 bytes 
    for (int i = 0; i < 6; i++)
    {
        read_tag(tag,fp);
        if (strcmp(tag, "TIT2") == 0)
        {
            printf("Title\t:");
        }
        else if (strcmp(tag, "TPE1") == 0)
        {
            printf("Artist\t:");
        }
        else if (strcmp(tag, "TALB") == 0)
        {
            printf("Album\t:");
        }
        else if (strcmp(tag, "TYER") == 0)
        {
            printf("Year\t:");
        }
        else if (strcmp(tag, "TCON") == 0)
        {
            printf("Genre\t:");
        }
        else if(strcmp(tag, "COMM") == 0)
        {
            printf("comment\t:");
        }
        read_size(&size,fp);
        fseek(fp,3,SEEK_CUR);//skip the 3 bytes flag from current position 
        read_data(data,size,fp);
        printf("%s\n",data); //print the all data
    }
    fclose(fp);
}

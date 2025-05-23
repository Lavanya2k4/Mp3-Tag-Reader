//*Description:
//NAME: Chintala Lavanya
//Date:07/05/2025
//TITLE:MP3 Tag Reader and Editor

#include "header.h"

int validation_view(int argc, char *argv)
{
    if (argc == 3)  //check if the arguments count are equal to 3
    {
      
        if (strstr(argv, ".mp3")) // Check if the file ends with ".mp3"
        {
            printf("The file is in mp3 format\n");
            return 0; //valid view argument
        }
        else
        {
            printf("Please upload the file in mp3 format\n");
            return 1; 
        }
    }
    else
    {
        
        if(argc==1)//if entered only one argument it prints error msg
        {
            printf("error:only 3 arguments should be provided for view\n");
            return 1;
        }  
    }
}
int validation_edit(int argc, char *argv)
{
    if (argc == 5)  ////check if the  arguments count are equal to 3 
    {
        if (strstr(argv,".mp3"))  // Check if the file ends with ".mp3"
        {
            printf("The file is in mp3 format\n");
            return 0; //valid edit argument 
        }
        else
        {
            printf("Please upload the file in mp3 format\n");
            return 1;  
        }
    }
    else
    {
        if(argc==1)//if entered only one argument it prints error msg
        {
            printf("error:Only 5 arguments should be provided for editing\n");
            return 1; 
        } 
    }
    return 0;
}
int validation_help(int argc, char *argv)
{
    if (argc == 2)  // Expecting one argument for help: program_name -h
    {
        printf("...Helpers...\n");
        return 0;  // Valid help argument
    }
    return 1;  // Invalid argument count for help
}
int main(int argc, char *argv[])
{

    if (argc >= 3) //it will check entered the arguments more than 3
    {
        if (strcmp(argv[1], "-v") == 0) //compare the argument variable 1 with '-v'
        {
            int result = validation_view(argc, argv[2]);//validation the view
            if (result == 0)
            {
                printf("View option is selected\n");
                view(argc,argv[2]);//calling the function of view
            }
        }
        else if (strcmp(argv[1], "-e") == 0) //compare the argument variable 1 with '-e'
        {
            int res = validation_edit(argc, argv[2]);//validation of edit
            if (res == 0)
            {
                printf("Edit option is selected\n");
                edit(argc,argv[3],argv[4]);//calling the function of edit
            }
        }

        else
        {
            printf("Give at least 3 arguments\n");
            printf("1. ../a.out\t 2. '-v' -> view\t '-e' -> edit\t '-h' -> help\t 3. <file_name>\n");
        }
    }
    
    else if (argc >= 2) //it will check entered the arguments more than 2
    {
        if (strcmp(argv[1], "-h") == 0)//compare the argument variable 1 with '-e'
        {
            printf("Header option is selected\n");
            int res = validation_help(argc, argv[1]);//validation of help
            if (res == 0)
            {
                printf("Help option is selected\n");
                help(argv[1]);//calling the function of help
            }
        }
        else
        {
            printf("Invalid argument:\n");
            printf("Hints: 1. View: '-v'\t 2. Edit: '-e'\t 3. Help: '-h'\n");
        }
    }
    else
    {
        printf(" ---Give at least 3 arguments---\n");
        printf("1. ../a.out\t 2. '-v' -> view\t '-e' -> edit\t '-h' -> help\t 3. <file_name>\n");
    }

    return 0;
}


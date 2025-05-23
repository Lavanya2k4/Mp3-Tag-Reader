#include "header.h"

int main(char* argv)
{
    printf("\n....main menu....\n");
    printf("1.View\n 2.Edit\n 3.Help\n");
    printf("\n-----view syntax----- \n");
    printf("1. ../a.out\t 2. '-v'\t -> view\t 3. <file_name>\n");
    printf("-------edit syntax------\n");
    printf("1. ../a.out\t 2. '-e' ->edit\t 3. <file_name>\t 4.'-modifier'\t 5.<new_one>\n");
    printf("\n--------------------------\n");
    printf("1.Title '-t'\n");
    printf("2.Artist '-p'\n");
    printf("3.Album '-a'\n");
    printf("4.Year '-y'\n"); 
    printf("5.Content '-c'\n");
    printf("6.genre '-m'\n");
    printf("\n--------------------------\n");
    printf("\n-----Help syntax----\n");
    printf("1. ../a.out\t 2.'-h'->help\t 3.<file_name>\n");
    return 0;
}

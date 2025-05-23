#include<stdio.h>
#include<stdarg.h>
#include<string.h>

void convert(int *size);                    //convert the big endian to little endian
void read_tag(char *tag, FILE *fp);          //reading the tag
int read_size(int *size,FILE *fp);           //reading the size
void read_data(char *data, int size, FILE *fp);  //reading the data
int view(int argc, char* );                        // For view
int edit(int argc, char* argv, char* argv1);         // For edit
int help(char * );                                  //for help
int validation_view(int argc, char *argv);     //validation of view
int validation_edit(int argc, char *argv);     //validation of edit
int validation_help(int argc, char *argv);     //validation of help

                                 
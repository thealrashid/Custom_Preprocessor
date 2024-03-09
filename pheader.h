#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

extern void remove_comments(FILE *, FILE *);
extern void replace(char *, const char *, const char *);
extern void replace_macros(FILE *, FILE *);
extern void include_header_files(FILE *, FILE *);

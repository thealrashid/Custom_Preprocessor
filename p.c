#include<stdio.h>
#include<string.h>
#include"header.h"

#define pf printf

/* multi line
comment*/

#define SIZE 10

void main()
{
	pf("Hello World!\n"); //comment
	int arr[SIZE]; //more comment
	char *s = malloc(10);
	printf("Enter string: ");
	scanf("%s", s);
	printf("%s length: %ld\n", s, strlen(s));
}

//again comment

/*


last comment


*/

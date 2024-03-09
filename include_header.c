#include"pheader.h"

void include_header_files(FILE *tempfile2, FILE *ifile)
{
	unsigned long int len = 0;
	char *s = NULL, test[1000], ch;
	int f;
	FILE *temp = fopen("temp.c", "w");
	
	while(getline(&s, &len, tempfile2) != -1)
	{
		f = 0;
		sscanf(s, "%s", test);
		if(strncmp(test, "#include", 8) == 0) f = 1;
		if(strstr(s, "#include") != NULL && f == 1)
		{
			fputs(s, temp);
		}
	}
	fclose(temp);
	
	if(fork() == 0)
	{
		execlp("cc", "cc", "-E", "temp.c", "-o", "temp.i", NULL);
        	perror("exec");
        	exit(EXIT_FAILURE);
	}
	else wait(NULL);
	
	temp = fopen("temp.i", "r");
	while((ch=fgetc(temp)) != EOF)
	{
		fputc(ch, ifile);
	}
	fclose(temp);
	
	rewind(tempfile2);
	while(getline(&s, &len, tempfile2) != -1)
	{
		f = 0;
		sscanf(s, "%s", test);
		if(strncmp(test, "#include", 8) == 0) f = 1;
		if(f == 0)
		{
			fputs(s, ifile);
		}
	}
	
	remove("temp.c");
	remove("temp.i");
}

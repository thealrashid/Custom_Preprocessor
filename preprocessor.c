#include"pheader.h"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		return -1;
	}

	char *cfilename = argv[1], ifilename[20];
	
	if(strcmp(".c", cfilename+strlen(cfilename)-2) != 0)
	{
		printf("Not a C file\n");
		return -1;
	}
	
	sscanf(cfilename, "%[^.]", ifilename);
	strcat(ifilename, ".i");
	
	FILE *cfile = fopen(cfilename, "r");
	if(cfile == NULL)
	{
		printf("%s not present\n", cfilename);
		return -1;
	}
	FILE *tempfile1 = fopen("tempfile1", "w");
	remove_comments(cfile, tempfile1);
	fclose(cfile);
	fclose(tempfile1);
	
	tempfile1 = fopen("tempfile1", "r");
	FILE *tempfile2 = fopen("tempfile2", "w");
	replace_macros(tempfile1, tempfile2);
	fclose(tempfile1);
	fclose(tempfile2);
	remove("tempfile1");
	
	tempfile2 = fopen("tempfile2", "r");
	FILE *ifile = fopen(ifilename, "w");
	include_header_files(tempfile2, ifile);
	fclose(tempfile2);
	fclose(ifile);
	remove("tempfile2");
    	
	return 0;
}



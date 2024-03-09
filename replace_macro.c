#include"pheader.h"

void replace(char *s, const char *oldword, const char *newword)
{
	char *pos = strstr(s, oldword);
	
	while(pos != NULL)
	{
		int f = 0;
		char *quote = s;
		
		while(quote<pos)
		{
			if(*quote == '"') f = !f;
			quote++;
		}
		
		if(f == 0)
		{
			int pre = pos - s;
			int post = strlen(pos+strlen(oldword));
			int l = pre + strlen(newword) + post;
			char *temp = malloc(l+1);
			
			strncpy(temp, s, pre);
			temp[pre] = '\0';
			strcat(temp, newword);
			strcat(temp, pos+strlen(oldword));
			strcpy(s, temp);
			
			free(temp);
		}
		
		pos = strstr(pos+1, oldword);
	}
}

void replace_macros(FILE *tempfile1, FILE *tempfile2)
{
	unsigned long int len = 0;
	char *s = NULL, ch, macro[100][2][20], temp[500], define[8], test[8];
	int i = 0, f;

	while(getline(&s, &len, tempfile1) != -1)
	{
		f = 0;
		sscanf(s, "%s", test);
		if(strcmp(test, "#define") == 0) f = 1;
		if(strstr(s, "#define") != NULL && f == 1)
		{
			
			
			sscanf(s, "%s %s %[^\n]", define, macro[i][0], macro[i][1]);
			i++;
			
		}
		else
		{
			strcpy(temp, s);
			for(int j=0;j<i;j++)
			{
				if(strstr(temp, macro[j][0]) != NULL) replace(temp, macro[j][0], macro[j][1]);
			}
			fputs(temp, tempfile2);
		}
		
		s = NULL;
	}
	
	free(s);
}

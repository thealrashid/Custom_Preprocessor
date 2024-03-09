#include"pheader.h"

void remove_comments(FILE *cfile, FILE *tempfile1) 
{
    	fseek(cfile, 0, SEEK_END);
    	size_t size = ftell(cfile);
    	rewind(cfile);

    	char *s = malloc(size + 1);

    	int n = 0;
    	char ch;

    	while((ch = fgetc(cfile)) != EOF) s[n++] = ch;
    	s[n] = '\0';

    	char *out = malloc((n + 1) * sizeof(char));
    	int j = 0, single = 0, multi = 0, f = 0;

    	for(int i=0;i<n;++i)
    	{
    		if(s[i] == '"')
    		{
    			if(f == 0) f = 1;
    			else f = 0;
    		}
        	if(!single && !multi)
        	{
            		if(s[i] == '/') 
            		{
                		if(s[i + 1] == '/' && f == 0) 
                		{
                    			single = 1;
                    			continue;
                		} 
                		else if(s[i + 1] == '*' && f == 0)
                		{
                    			multi = 1;
                    			i++;
                    			continue;
                		}
            		}
            		out[j++] = s[i];
        	} 
        	else if(single && s[i+1] == '\n' && f == 0)
        	{
            		single = 0;
        	} 
        	else if(multi && s[i] == '*' && s[i + 1] == '/' && f == 0) 
        	{
            		multi = 0;
            		i++;
        	}
    	}

    	out[j] = '\0';

    	fputs(out, tempfile1);

    	free(s);
    	free(out);
}

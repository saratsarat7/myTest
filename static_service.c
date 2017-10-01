#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char statFilename[]	= "stat_serv_file.dsg";

void main()
{
  FILE * staticFp;

	staticFp = fopen (statFilename, "rb");
	// fread(p,sizeof(struct staticVar),1,fp);

  fseek(staticFp, 0, SEEK_END);
  int lengthOfFile = ftell(staticFp);
  fseek(staticFp, 0, SEEK_SET);

  char *ptr;

  ptr = (char*) calloc(1,lengthOfFile*sizeof(char));

  fread(ptr,lengthOfFile,1,staticFp);

  printf("%s", ptr);

  fclose(staticFp);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char statFilename[]	= "stat_serv_file.dsg";

void main()
{
  FILE * staticFp;

  char temp[20];

	staticFp = fopen (statFilename, "rb");
	// fread(p,sizeof(struct staticVar),1,fp);

  fseek(staticFp, 0, SEEK_END);
  int lengthOfFile = ftell(staticFp);
  fseek(staticFp, 0, SEEK_SET);

  char *ptr;

  ptr = (char*) calloc(1,lengthOfFile*sizeof(char));

  fread(ptr,lengthOfFile,1,staticFp);

  printf("This is data :\n%s", ptr);
  printf("This is pointer address:\n%p", ptr);

  scanf("Enter some data :%s", temp);

  printf("This is modified data :\n%s", ptr);

  fclose(staticFp);
  free(ptr);
}

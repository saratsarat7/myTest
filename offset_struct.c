#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "crypt.h"
#include "accessdata.h"
#include "vars.h"

static char statFilename[]	= "Static_File.dsg";
static char inFilename[]	= "Input.dsg";
static char ruleFilename[]	= "Rule.dsg";
static char outFilename[]	= "Output.dsg";

void main()
{
	// struct offsetVar ofvar;
  int s1 = 10;
  float s2 = 100.4;
  char s3[] = "Sarat";
  double s4 = 2145.43;
  char s5[] = "Mahesh";

  typedef unsigned char byte;
  int offset_array[10];

  // int temp_offset = 0;
	// struct offsetVar *p;
	char *p;

	// p = malloc(sizeof(struct offsetVar));
	p = calloc(1,100);
  printf("Initial pointer :%d \n", *p);
  p = (int *)&s1;
  printf("After int :%d \n", *p);
  p = p + sizeof(s1);
  *p = (float *)&s2;
  printf("After float :%f \n", *p);
  p = p + sizeof(s2);
  *p = (char *)&s3;
  printf("After first char :%s \n", *p);
  p = p + sizeof(s3);
  *p = (double *)&s4;
  printf("After double :%d \n", *p);
  p = p + sizeof(s4);
  *p = (char *)&s5;
  printf("After second char :%s \n", *p);
  p = p + sizeof(s5);

	FILE * fp;

	fp = fopen (statFilename, "w+");
	// fp = fopen (statFilename, "r+");
	fwrite(p,sizeof(struct offsetVar),1,fp);
	// fread(p,sizeof(struct staticVar),1,fp);

	// printf("%d \n", p->offset);
	// printf("%d \n", p->length);

	fclose(fp);
}

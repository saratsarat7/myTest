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
	// struct staticVar svar;
	struct staticVar *p;

	p = malloc(sizeof(struct staticVar));
	// p = &svar;

	// strcpy(svar.s1, "Sarat");
	// svar.s2 = 10;
	// svar.s3 = 16.5;
	// strcpy(svar.s4, "Mahesh");
	// svar.s5 = 1234567.67;
	// strcpy(svar.s6, "Y");
	// svar.s7 = 143.23;
	// svar.s8.varId = 10;
	// strcpy(svar.s8.varData,"Inside a structure.");

	FILE * fp;

	// fp = fopen (statFilename, "w+");
	fp = fopen (statFilename, "r+");
	// fwrite(p,sizeof(struct staticVar),1,fp);
	fread(p,sizeof(struct staticVar),1,fp);

	printf("%s \n", p->s8.varData);

	fclose(fp);
}

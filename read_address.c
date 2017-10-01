#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
  // const char *ptr = (const char *) 0x006221F8;

  // char temp[20] = "Hello";

  // ptr = &temp;
  // ptr = (void *) 00A121F8;

  char sAddr[] = "0x008721F8";
  unsigned int uAddr = strtoul(sAddr,NULL,0);
  void * pAddr = (void *) uAddr;

  char *temp;

  // temp  = pAddr;
  memcpy(temp, pAddr, 100);

  printf("%p \n", pAddr);

  printf("This is before\n");
  printf("This is data :\n%s", temp);
  printf("This is after\n");
  // printf("This is pointer address:\n%p", ptr);

}

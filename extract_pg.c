#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

char *extract_db_name (char *to_extract)
{
char *ptr;
char *ptr2;

int    ch = ' ';
char* substr_res = malloc(30 * sizeof(char));
ptr = strchr( strchr( to_extract , ch) + 1 , ch);
ptr2 = strchr( ptr + 1 , ch);
strncpy (substr_res,ptr,ptr2 - ptr);
return (substr_res + 1);
}

int main(void)
{
  char *buf1  = "postgres: postgres bdt 172.16.170.1(53402) idle";
  char *buf2  = "postgres: postgres bdt [local] idle";
  char *buf3  = "postgres: postgres postgres [local] idle";
 
  char* res_extracted = extract_db_name(buf1);
  printf("%s est \n",res_extracted);

  res_extracted = extract_db_name(buf2);
  printf("%s est \n",res_extracted);

  res_extracted = extract_db_name(buf3);
  printf("%s est \n",res_extracted);

  return 0;
}

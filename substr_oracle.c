#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

char *extract_instance_name (char *to_extract, char string_type)
{
char *ptr;

if ( string_type == 'b') {
int    ch = '_';
ptr = strchr( strchr( to_extract , ch) + 1 , ch);
return (ptr + 1);
}
else
{
int    ch = ' ';
char* substr_res = malloc(30 * sizeof(char));
ptr = strchr( to_extract, ch );
strncpy (substr_res,to_extract+6, ptr - to_extract - 6);
substr_res[ptr - to_extract - 6]='\0';
return (substr_res);
}
}

int main(void)
{
  char *buf1  = "ora_dbw0_BDTS_1";
  char *buf2  = "oracleBDTS_1 (LOCAL=NO)";
  char *buf3  = "oracleBDTS_1 (DESCRIPTION=(LOCAL=YES)(ADDRESS=(PROTOCOL=beq)))";
 
  char* res_extracted = extract_instance_name(buf1,'b');
  printf("%s est \n",res_extracted);

  res_extracted = extract_instance_name(buf2,'f');
  printf("%s est \n",res_extracted);

  res_extracted = extract_instance_name(buf3,'f');
  printf("%s est \n",res_extracted);

  return 0;
}

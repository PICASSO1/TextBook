#include<stdio.h>
#define LEN 20

const char *msgs[5]=
{
"    Thank you for the wonderful evening, ",   /* *msgs[0] */
"You certainly prove that a ",                 /* *msgs[1] */
"is a special kind of guy. We must together",  /* *msgs[2] */
"over a delicious ",                           /* *msgs[3] */
" and have a few laughs"                       /* *msgs[4] */
};

struct name  /* first struct */
{
char first[LEN],last[LEN];
};

struct guy  /* second struct */
{
struct name handle;  /* struct in struct*/
char favfood[LEN],job[LEN];
float income;
};

int main(void)
{
struct guy fellow=
 {
  {"Chip","Vejer"},
  "nachos plate",
  "memory broker",
  36827.00
 };

printf("Dear %s: \n\n",fellow.handle.first);
printf("%s%s. \n",msgs[0],fellow.handle.first);
printf("%s%s \n",msgs[1],fellow.job);
printf("%s \n",msgs[2]);
printf("%s%s%s",msgs[3],fellow.favfood,msgs[4]);
if(fellow.income>150000.0)
 put("!!");
else
 if(fellow.income>75000.0)
  puts("!");
 else
  puts(".");
printf("\n%40s%s\n"," ","See you soon,");
printf("%40s%s\n"," ","Shalala");
return 0;
}
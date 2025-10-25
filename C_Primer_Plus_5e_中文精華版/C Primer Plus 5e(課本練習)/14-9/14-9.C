#include<stdio.h>
#include<string.h>

struct namect
{
char fname[20],lname[20];
int letter;
};

struct namect getinfo(void);
struct namect makeinfo(struct namect);
void showinfo(struct namect);

int main(void)
{
struct namect person;
while((person.fname[0]!='\0')||(person.lname[0]!='\0'))
/* while(person.letter!=0) */
 {
 person=getinfo();
 person=makeinfo(person);
 showinfo(person);
 }
return 0;
}

struct namect getinfo(void)
{
struct namect temp;
printf("Please enter your first name. \n");
gets(temp.fname);
printf("Please enter your last name. \n");
gets(temp.lname);
return temp;
}

struct namect makeinfo(struct namect info)
{
info.letter=strlen(info.fname)+strlen(info.lname);
return info;
}

void showinfo(struct namect info)
{
printf("%s %s, your name contains %d letters. \n",info.fname,info.lname,info.letter);
}
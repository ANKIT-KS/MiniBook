#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<conio.h>
#include<math.h>
struct student
{
char sname[10];
char susername[10];
char spassword[10];
char secques[10];
long long sphone;
char sgender;
char sabout[20];
int sdob;
char slocation[15];
char scollege[20];
char smessage[50];
int ssno;
int sfriend[20]
struct student *down;
struct messages *right;
struct friendreq *left;
};
typedef struct student student;
/*struct friends
{
char fname[10];
struct freinds *next;
};
typedef struct freinds frenz;*/
struct messages //using queues technique
{
char smsg[50];
struct messages *next;
};
typedef struct messages msg;
struct friendreq //using stack technique
{
int fssno;
char fname[10];
struct friendreq *prev;
};
typedef struct friendreq request;
student *sstart=NULL;
int count=0;//total no. of users till date
//void enter();
//void signin();
//void signup();
//void display();
int main()
{
int ch;
//clrscr();
printf("WELCOME TO MINIBOOK\n");
printf("1:SIGN UP\t 2:SIGN IN");
scanf("%d"&ch);
if(ch==1)
{
signup();
count++;
}
else
signin();
//getch();
}
void signup()
{
char ch,ch1;
int flag =1;
student *sptr,*stemp;
sptr=(student*)malloc(sizeof(student));
sptr->down=NULL;
sptr->right=NULL;
printf("\nEnter your name: ");
scanf("%s",&student->sname);
fflush(stdin);
printf("\nEnter a suitable username: ");
scanf("%s",&student->susername);
fflush(stdin);
printf("\nEnter your desired password: ");
scanf("%s",&student->spassword);
fflush(stdin);
printf("\nGender(m/f): ");
scanf("%c",&student->sgender);
fflush(stdin);
//printf("\nDOB(dd/mm/yy): ");
//scanf("%d/%d/%d");
//fflush(stdin);
printf("\nDo you want to enter the security related queries right now??(y/n)");
scanf("%c",&ch);
if(ch=='y')
{
printf("\nWhat it the name of your first car?\n");
scanf("%s",&student->secques);
fflush(stdin);
printf("\nEnter your mobile no: ");
scanf("%lld",&student->sphone);
fflush(stdin);
printf("\nEnter your location: ");
scanf("%s",&student->slocation);
fflush(stdin);
printf("\nEnter your college: ");
scanf("%s",&student->scollege);
fflush(stdin);
printf("\nDo you want to describe yourself?(y/n)");
scanf("%c",&ch1);
if(ch1=='y')
{
gets(student->sabout);
fflush(stdin);
}
else
{
continue;
printf("\nYour are done with basic information and are good to go\n");
}
}
else
{
flag=0;//security issues left
printf("\nYour are done with basic information and are good to go\n");
}
student->ssno=count;
if(sstart==NULL)
{
sstart=sptr;
printf("\nYou are the first user of MINIBOOK\n");
}
else
{
stemp=sstart;
while(stemp->down!=NULL)
stemp=stemp->down;
stemp->down=sptr;
}
}
void signin()
{
int flag=0;
char cuser[10];
char cpass[10];
int ch==1;
int attempt=0;
char cques[10];
student *ctemp=sstart;
student *center;
while(ch==1)
{
flag=0;
attempt++;
printf("\nUsername: ");
scanf("%s",&cuser);
printf("\nPassword: ");
scanf("%s",&cpass);
if(attempt>1)
{
printf("\nSince the login attempt is more than once you would be required to answer the security ques as well\n");
printf("\nEnter the name of your first car: ");
scanf("%s",&cques);
}
while(ctemp->down!=NULL)
{
if(strcmp(cuser,ctemp->susername)==1)
{
if(strcmp(cpass,ctemp->spassword)==1)
{
if(attempt>1)
{
if(strcmp(cques,ctemp->secques)==1)
{
flag=1;
center=ctemp;//storing address of the user if every information is correct
}
else
{
printf("\nSorry yor are not a valid user of this account\n");
exit();
}
}
center=ctemp;//storing address of the user if every information is correct in first attempt
}
else 
{
continue;
}
}
ctemp=ctemp->down;
}
if(flag==0)
{
printf("\nWrong combination of username and password\n");
printf("do you want to try again(1=yes)/(2=no)  ");
scanf("%d",ch);
}
else
{
void enter(center)/////////pass the address of the user info in enter
}
//printf("\nDo you want to (1)Continue or(2)Try again later\n");
//scanf("%d",&ch);
}
void enter(student *center)//use of graphics in displaying the page
{

}
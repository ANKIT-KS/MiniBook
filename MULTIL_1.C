#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include <stdlib.h>
#include <dos.h>

union REGS i,o;
struct friends
	{
	char name[20];
	struct friends *next;
	}*st,*p,*t;

typedef struct friends f;


struct student
	{
	char name[20];
	char gender[1];
	char city[20];
	char username[10];
	char email[30];
	char password[20];
	f *right;
	struct student *down;
	}*start,*ptr,*temp;

typedef struct student s;


f * createSLL()
	{
	char ch='y';
	st=NULL;
	while((ch=='y')||(ch=='Y'))
		{

		p=(f *) malloc(sizeof(f));
		printf("Enter Name of Friend\n");
		fflush(stdin);
		gets(p->name);
		p->next=NULL;
		if(st==NULL)
			st=p;
		else
			{
			for(t=st;t->next!=NULL;t=t->next);
			t->next=p;
			}
		printf("Enter More Friends y/n\n");
		fflush(stdin);
		scanf("%c",&ch);
		}
	return st;
}

void load()
{
int i,j,x,y;
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
setbkcolor(BLUE);

x=getmaxx()/2;
y=getmaxy()/2;
for(j=30;j<200;j++)
{
delay(10);
setcolor(j/20);
arc(x,y,0,180,j-10);
}
settextstyle(3,0,6);
outtextxy(150,250,"");
settextstyle(4,0,4);
outtextxy(250,340,"LOADING");
for(i=100; i<500; i++)
{
bar(i,380,i,400);
delay(10);
}
}

int create()
	{
	int i,n;
	start=NULL;
	fflush(stdin);
		ptr=(s *) malloc(sizeof(s));
		printf("Enter Your Name.\n");
		fflush(stdin);
		gets(ptr->name);
		printf("Enter Your Gender(M/F).\n");
		fflush(stdin);
		gets(ptr->gender);
		printf("Enter Your City.\n");
		fflush(stdin);
		gets(ptr->city);
		printf("Enter Your Email address.\n");
		fflush(stdin);
		gets(ptr->email);
		printf("Enter Your Username.\n");
		fflush(stdin);
		gets(ptr->username);
		printf("Enter Your Password.\n");
		fflush(stdin);
		gets(ptr->password);

		ptr->right=createSLL();
		ptr->down=NULL;
		if(start==NULL)
			start=ptr;
		else
			{
			for(temp=start;temp->down!=NULL;temp=temp->down);
			temp->down=ptr;
			}

	return 0;
	}

int print()
	{
	for(temp=start;temp!=NULL;temp=temp->down)
		{
		printf("%s\n",temp->name);
		for(t=temp->right;t!=NULL;t=t->next)
		printf("%s\t",t->name);
		printf("\n\n");
		}
	return 0;}
	int initmouse()
	{
	i.x.ax=0;
	int86(0X33,&i,&o);
	return(o.x.ax);
	}

int showmouseptr()
	{
	i.x.ax=1;
	int86(0X33,&i,&o);
	return 0;
	}


void detect()
	{
	int xx,yy,password,a,b,l=50,j,choice,ans;
	while(!kbhit())
	{
	i.x.ax=3;
	int86(0X33,&i,&o);
		if(o.x.bx==1)
		{
		// printf("Left click only");
		xx=o.x.cx;
		yy=o.x.dx;
			if(xx>190 && xx<305 && yy>250 && yy<280)
				{

				create();
				}
			else if(xx>365 && xx<432 && yy>250 && yy<280)
				{

				print();
				}

		}

	}
}

int fract(int x,int y, int a, int n)
{
if(n==0)
return 0;
else
{
      line(x,y-a,x,y+a);
      line(x-a,y,x+a,y);
      fract(x,y-a*4/5,a/3,n-1);
      fract(x,y+a*4/5,a/3,n-1);
      fract(x-a*4/5,y,a/3,n-1);
      fract(x+a*4/5,y,a/3,n-1);
}
}
void rain(int x,int y)
{
    circle(x,y,1);
    setcolor(1+random(17));
    delay(5) ;
}

int main(void)
{
   int gdriver = DETECT, gmode,i,k=0,x,y,status;
      clrscr();
   initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
   setbkcolor(GREEN);
   outtextxy(260,240,"LOADING..");
   setcolor(RED);
   for(i=0;i<150;i++)
   {
   outtextxy(220+i,260,"I");
   delay(50);
   }
   setcolor(WHITE);
   outtextxy(220,320,"Press enter to continue...");
   getch();

   cleardevice();


i=0;

//clrscr();
setcolor(WHITE);
	settextstyle(4,0,5);
	outtextxy(180,60,"THE MINIBOOK.");


	for(i=0;i<1000;i++)
	{
		x=random(640);
		y=random(480);
		rain(x,y);
		i=i+1;
		rectangle(160,60,530,120);

	}

	delay(1500);
   cleardevice();
   setbkcolor(BLUE);
   for(i=0;i<97;i++)
   {
   cleardevice();
    setcolor(RED);
    settextstyle(0,HORIZ_DIR,4);
   outtextxy(440-i,410,"WELCOME");
   setcolor(DARKGRAY);

arc(100+i,430,0,180,50);
line(50+i,430,150+i,430);
line(100+i,380,100+i,430);
line(105+i,385,105+i,405);
line(105+i,405,125+i,405);
arc(105+i,405,0,90,20);
line(75+i,405,95+i,405);
line(95+i,385,95+i,405);
arc(95+i,405,90,180,20);
line(105+i,410,110+i,410);
line(90+i,410,95+i,410);
rectangle(150+i,415,175+i,430);
rectangle(175+i,420,182+i,430);
circle(75+i,440,10);
circle(160+i,440,10);
delay(60);
}

getch();



   outtextxy(220,450,"Press Enter to continue");
   getch();
   setbkcolor(WHITE);
   setcolor(BROWN);
   setfillstyle(SOLID_FILL,RED);
   rectangle(30,175,50,400);
   setcolor(DARKGRAY);
   setfillstyle(SOLID_FILL,GREEN);
   fillellipse(55,130,20,20);
   fillellipse(15,140,20,20);
   fillellipse(75,153,20,20);
   fillellipse(63,133,20,20);
   fillellipse(40,120,20,20);
   fillellipse(20,175,20,20);
   fillellipse(30,150,20,20);
   fillellipse(63,175,20,20);
   fillellipse(55,150,20,20);
   fillellipse(45,170,20,20);
   setcolor(BROWN);
   setfillstyle(SOLID_FILL,RED);
   rectangle(545,175,565,400);
   setcolor(DARKGRAY);
   setfillstyle(SOLID_FILL,GREEN);
   fillellipse(565,130,20,20);
   fillellipse(525,140,20,20);
   fillellipse(585,153,20,20);
   fillellipse(573,133,20,20);
   fillellipse(550,120,20,20);
   fillellipse(530,175,20,20);
   fillellipse(540,150,20,20);
   fillellipse(583,175,20,20);
   fillellipse(565,150,20,20);
   fillellipse(555,170,20,20);

   setcolor(DARKGRAY);
   arc(300,200,0,180,200);
   line(100,200,100,400);
   line(500,200,500,400);
   line(100,400,500,400);
   line(300,0,300,400);
   rectangle(310,210,320,280);
   rectangle(280,180,290,250);
   setcolor(GREEN);
   setfillstyle(WIDE_DOT_FILL,GREEN);
   fillellipse(30,390,15,15);
   fillellipse(40,365,15,15);
   fillellipse(73,390,15,15);
   fillellipse(65,367,15,15);
   fillellipse(55,385,15,15);
   setcolor(GREEN);
   setfillstyle(WIDE_DOT_FILL,GREEN);
   fillellipse(540,390,15,15);
   fillellipse(550,365,15,15);
   fillellipse(583,390,15,15);
   fillellipse(575,365,15,15);
   fillellipse(565,385,15,15);
   getch();
   clrscr();
   cleardevice();
   delay(10);
   setbkcolor(YELLOW);
   setcolor(RED);
   x=20;
   for(i=1;i<25;i++)
   {
   fract(x,20,10,5);
   x+=30;
   delay(20);
   }
   x=20;
   for(i=1;i<25;i++)
   {
   fract(x,460,10,5);
   x+=30;
   delay(20);
   }
   setcolor(CYAN);
   settextstyle(1,HORIZ_DIR,6);
   outtextxy(120,100,"THE MINIBOOK.");
   setcolor(DARKGRAY);
   settextstyle(3,HORIZ_DIR,3);
   outtextxy(140,200,"It's Your World.- Sign In or Sign Up today.");
   outtextxy(200,250,"SignUp");
   outtextxy(370,250,"SignIn");

   rectangle(190,250,305,280);
   rectangle(365,250,432,280);
    setfillstyle(EMPTY_FILL,RED);
   status=initmouse();
   if (status==0)
   printf("mouse support not available");
   else
	{
	// printf("mouse support available");
	showmouseptr();
	detect();
	}
   getch();

   closegraph();
   return 0;
}

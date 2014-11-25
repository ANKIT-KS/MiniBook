#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>

void draw_man();
int jump(int, int);
int bend(int, int);
void gameover();
void loading();

struct{
int top_x,top_y,bottom_x,bottom_y;
}man;

struct{
int x,y;
}obstacle;


static int score=0;
char a[50],b[50];

void loading()
{
int i,j,x,y;

setbkcolor(6);

	x=getmaxx()/2;
	y=getmaxy()/2;
	for(j=30;j<200;j++)
	{
		delay(10);
		setcolor(j/20);
		arc(x,y,0,180,j-10);
	}
settextstyle(3,0,6);
outtextxy(150,250,"!..DOGDE IT..!");
settextstyle(4,0,4);
outtextxy(250,340,"LOADING");
for(i=100; i<600; i++)
{
bar(i,380,i,400);
delay(10);
}
}



main()
{
   int gdriver = DETECT,gmode;
   int i,j,ran;
   char ch,menu;
   clrscr();
   first();  
   initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
   loading();
   cleardevice();

   setbkcolor(YELLOW);
   setcolor(BLUE);
    h:
    outtextxy(100,100,"Press I to read instructions.");
    outtextxy(100,200,"Press S to start the game.");
    outtextxy(100,300,"Press E to exit.");
    
    menu=getchar();
    clrscr();
    toupper(menu);
    switch(menu)
   { case 'S' : break;
     case 's' : break;
     case 'I' : instructions();
		goto h;
     case 'i' : instructions();
		goto h;
     case 'E' : exit(0);
     case 'e' : exit(0);
     default : goto h;
   }
  
   setviewport(0,170,639,310,1);
   
  start:
   
   setbkcolor(YELLOW);
   randomize();
   ran=random(2);


  if(ran==0)
{

  for(i=0;i<639;i++)

  {  draw_man();

       setcolor(RED);
       rectangle(635-i,120,639-i,140);
       setcolor(BLACK);
       rectangle(637-i,120,641-i,140);

       man.top_y=90;
       man.top_x=55;
       man.bottom_x=55;
       man.bottom_y=140;

       obstacle.x=635-i;
       obstacle.y=120;

     if(kbhit())
     { ch=getch();

	  if(ch=='y'||ch=='Y')
	  {  i=jump(i,ran);
	     draw_man();

             if(man.bottom_x>obstacle.x)
	       {  score++;
		  goto start; }

	 else if(man.bottom_y >=obstacle.y && man.bottom_x==obstacle.x)
	    {

	      gameover();
	    }

	

		 
	  }

	else if(ch=='h'||ch=='H')
	{     i=bend(i,ran);
	     draw_man();

	
             if(man.bottom_x>obstacle.x)
	       {  score++;
		  goto start; }
               
	 else if(man.bottom_y >=obstacle.y && man.bottom_x==obstacle.x)
	    {

	      gameover();
	    }

	 }
      }
  delay(10);
  }

}


else  if(ran==1)
{

  for(i=0;i<639;i++)

  {  draw_man();
      setcolor(RED);
      rectangle(635-i,20,639-i,80);
      setcolor(BLACK);
      rectangle(637-i,20,641-i,80);

       obstacle.x=635-i;
       obstacle.y=60;

     if(kbhit())
     { ch=getch();



	 if(ch=='y'||ch=='Y')
	  {  i=jump(i,ran);

	    draw_man();


	     if(man.bottom_x>obstacle.x)
	       {  score++;
		  goto start; }



	    else if(man.top_y<=obstacle.y && man.bottom_x==obstacle.x)

	    {

	      gameover();
	    }
	     
	  }

	else if(ch=='h'||ch=='H')
	{     i=bend(i,ran);

	  draw_man();

	
             if(man.bottom_x>obstacle.x)
	       {  score++;
		  goto start; }
               
	 else if(man.bottom_y >=obstacle.y && man.bottom_x==obstacle.x)
	    {

	      gameover();
	    }
	  
	 }
      }
    delay(10);
  }

}
  gameover();
  closegraph();
  return 0;
}


void draw_man()
{  setcolor(BLUE);
   rectangle(50,105,60,125);
   line(53,125,53,140);
   line(57,125,57,140);
   line(50,115,40,115);
   line(60,115,70,115);
   line(55,105,55,90);
   circle(55,80,10);
}

int jump(int i, int ran)
{ int j;

  for(j=0;j<23;j++)

  {  man.top_y--;
     man.bottom_y--;
     obstacle.x--;
     i++;

     setcolor(BLUE);
     rectangle(50,105-j,60,125-j);
     line(53,125-j,53,140-j);
     line(57,125-j,57,140-j);
     line(50,115-j,40,115-j);
     line(60,115-j,70,115-j);
     line(55,105-j,55,90-j);
     circle(55,80-j,10);
     setcolor(BLACK);
      rectangle(50,106-j,60,126-j);
     line(53,126-j,53,141-j);
     line(57,126-j,57,141-j);
     line(50,116-j,40,116-j);
     line(60,116-j,70,116-j);
     line(55,106-j,55,91-j);
     circle(55,81-j,10);

     if(ran==0)
      {rectangle(635-i,120,639-i,140);
      setcolor(BLACK);
      rectangle(637-i,120,641-i,140);}

     else
     {rectangle(635-i,20,639-i,80);
     setcolor(BLACK);
     rectangle(637-i,20,641-i,80);}


     delay(10);

  }
  setcolor(BLACK);
  j--;
  rectangle(50,105-j,60,125-j);
     line(53,125-j,53,140-j);
     line(57,125-j,57,140-j);
     line(50,115-j,40,115-j);
     line(60,115-j,70,115-j);
     line(55,105-j,55,90-j);
     circle(55,80-j,10);

man.top_y+=23;
man.bottom_y+=23; 
return i;
}

int bend(int i,int ran)
{ int j;

  man.top_x+=35;
  man.top_y+=35;



  for(j=0;j<23;j++)

  {  setcolor(BLACK);
      rectangle(50,105,60,125);
   line(53,125,53,140);
   line(57,125,57,140);
   line(50,115,40,115);
   line(60,115,70,115);
   line(55,105,55,90);
   circle(55,80,10);


     setcolor(BLUE);
     rectangle(50,105,60,125);
   line(53,125,53,140);
   line(57,125,57,140);
   line(50,115,40,115);
   line(60,115,70,115);
   line(55,105,75,105);
   circle(85,105,10);


     obstacle.x--;
     i++;

      if(ran==0)
      {rectangle(635-i,120,639-i,140);
      setcolor(BLACK);
      rectangle(637-i,120,641-i,140);}

      else

      {rectangle(635-i,20,639-i,80);
      setcolor(BLACK);
      rectangle(637-i,20,641-i,80);}

      delay(10);
  }
  setcolor(BLACK);
   rectangle(50,105,60,125);
   line(53,125,53,140);
   line(57,125,57,140);
   line(50,115,40,115);
   line(60,115,70,115);
   line(55,105,75,105);
   circle(85,105,10);

          man.top_x-=35;
	  man.top_y-=35;

return i;
}
void gameover()

{
clearviewport();
cleardevice();
  sound(500);
  sleep(1);
  nosound();
  setcolor(BLUE);
  sprintf(a,"Your score is %d",score);
  sprintf(b,"Thanks for playing !!");
  settextstyle(3,0,4);
  outtextxy(150,50,a);
  outtextxy(150,100,b);
getch();

}

first()
{ gotoxy(300,200);
  textcolor(YELLOW+BLINK);
  printf("PROJECT MADE BY:-\n");
  printf("-ANKIT KUMAR SRIVASTAVA\n");
  printf("-AYUSH JAGGI\n");
  printf("-DIVYANSH GUPTA\n");
  getch();
  return 1;
}

instructions()
{  cleardevice();
   setbkcolor(YELLOW);
   setcolor(BLUE); 
       clrscr();
  outtextxy(5,100,"Obstacles will come either from top or bottom.");
  outtextxy(5,150,"You have to jump over them or bend accordingly.");
  outtextxy(5,200,"Each time you succeed your score increase by 1.");
  outtextxy(5,250,"Press Y to jump and H to bend.");
  outtextxy(5,300,"Tip:-Jump when obstacle is near legs and bend") ;
  outtextxy(5,350,"when obstacle is near face.");
  delay(10000);
  return 1;
}



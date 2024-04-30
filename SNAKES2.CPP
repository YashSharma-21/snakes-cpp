#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<math.h>

struct Egg
{int x,y;}eggs[800];
int top=-1;


class snake
{ int colh,rowh,colt,rowt,len,color,dirh,dirt,rear;
  static int bg;


  struct {int x,y; char dir;  }queue[50];



  public:  snake(int color,int colh,int rowh,int colt,int rowt,int dirh=3)
	   {
	     this->color=color;
	     this->colh=colh;
	     this->colt=colt;
	     this->rowh=rowh;
	     this->rowt=rowt;
	     this->dirh=dirh;
	     this->dirt=dirh;
	     rear=-1;
	   }

	   void input(char ch);
	   void move();
	   void correct();

	   void makeEggs(int a);
	   int copyEgg(int,int);

	   void eat();

	   Egg ClosestEgg();

};

float Distance(int x1,int y1,int x2,int y2)
{return  sqrt(pow(x1-x2,2)+pow(y1-y2,2));}


Egg snake::ClosestEgg()
{
 Egg close;


 close.x=eggs[0].x;
 close.y=eggs[0].y;

 for(int i=0;i<=top;i++)
 {
     if(Distance(colh,rowh,close.x,close.y)>Distance(colh,rowh,eggs[i].x,eggs[i].y))
	 {
	  close.x=eggs[i].x;
	  close.y=eggs[i].y;

	 }



 }



return close;
}


void snake::correct()
{   if(colh==ClosestEgg().x)
      goto row;

   if(colh>ClosestEgg().x)
   input('a');
   else if(colh<ClosestEgg().x)
   input('d');
row:
   if(rowh>ClosestEgg().y&&colh==ClosestEgg().x)
   input('w');
   else if(rowh<ClosestEgg().y&&colh==ClosestEgg().x)
   input('s');









}


void snake::eat()
{
      for(int i=0;i<=top;i++)
      {

	    if(colh==eggs[i].x&&rowh==eggs[i].y)
	    {   reRandom:

		    eggs[i].x=random(639)+1;
		    eggs[i].y=random(479)+1;
		    putpixel(eggs[i].x,eggs[i].y,WHITE);



		  //  if(copyEgg(eggs[i].x,eggs[i].y))
		   // goto reRandom;



		    switch(dirh)
		    {
		      case 1:  colh-=1; break;
		      case 3:  colh+=1; break;
		      case 4:  rowh+=1; break;
		      case 2:  rowh-=1; break;



		    }


		    if(colh<1)colh=639;
		    else if(colh>639)colh=1;
		    if(rowh<1)rowh=479;
		    else if(rowh>479)rowh=1;

		    putpixel(colh,rowh,color);
	       // Changes are expected in makeegg()   top--;




	    }



      }






}


int snake::copyEgg(int x,int y)
{
   int i;

   for(i=0;i<=top;i++)
   {    if(eggs[i].x==x&&eggs[i].y==y)
		return 1;


   }


return 0;}

void snake::makeEggs(int a)
{

    int i,x,y;






  if(top+1<a)
  {
    for(i=0;i<=a;i++)
    {  top++;

    reRandom:
       x=random(639)+1;
       y=random(479)+1;

      if(copyEgg(x,y))
       goto reRandom;

       putpixel(x,y,WHITE);

       eggs[top].x=x;
       eggs[top].y=y;

    }



  }



}

void snake::move()
{
     switch(dirh)
     {
       case 1: colh--; break;
       case 2: rowh--; break;
       case 3: colh++; break;
       case 4: rowh++; break;



     }

     if(colh<1)colh=639;
     else if(colh>639)colh=1;
     if(rowh<1)rowh=479;
     else if(rowh>479)rowh=1;

    putpixel(colh,rowh,color);



    // Tail Part

     switch(dirt)
     {
       case 1: colt--; break;
       case 2: rowt--; break;
       case 3: colt++; break;
       case 4: rowt++; break;



     }

     if(colt<1){colt=639;  putpixel(1,rowt,bg);   }
     else if(colt>639){colt=1;  putpixel(639,rowt,bg);   }
     if(rowt<1){rowt=479;  putpixel(colt,1,bg);     }
     else if(rowt>479){rowt=1;  putpixel(colt,479,bg);  }

    putpixel(colt,rowt,color);



      if(rear>=0&&colt==queue[0].x&&rowt==queue[0].y)
      {
	  // Extra Erase Logic


	  switch(dirt)
    {
    case 1: putpixel(colt+1,rowt,bg); break;
    case 2: putpixel(colt,rowt+1,bg); break;
    case 3: putpixel(colt-1,rowt,bg); break;
    case 4: putpixel(colt,rowt-1,bg); break;





    }

	  // Extra Erase Logic Ends



	 dirt=queue[0].dir;


	 for(int i=0;i<=rear-1;i++)
	    {
		queue[i].x=queue[i+1].x;
		queue[i].y=queue[i+1].y;
		queue[i].dir=queue[i+1].dir;

	    }

	    rear--;


      }



    // Erasing Tail Here

    switch(dirt)
    {
    case 1: putpixel(colt+1,rowt,bg); break;
    case 2: putpixel(colt,rowt+1,bg); break;
    case 3: putpixel(colt-1,rowt,bg); break;
    case 4: putpixel(colt,rowt-1,bg); break;





    }




}


int snake::bg=BLACK;



void snake::input(char ch)
{  char oldDirh=dirh;

   switch(ch)
   {
    case 'a':
    case 'A': dirh=1; break;

    case 'd':
    case 'D': dirh=3; break;

    case 's':
    case 'S': dirh=4; break;

    case 'w':
    case 'W': dirh=2; break;



   }

   if(dirh==oldDirh)
   return;

   rear++;
   queue[rear].x=colh;
   queue[rear].y=rowh;
   queue[rear].dir=dirh;

}


void main()
{  int gd=DETECT,gm;
   char input,esc;
    snake green(GREEN,125,125,115,125);
    snake red(RED,200,300,180,300);

    snake _2(3,300,450,290,450);
    snake _3(4,100,266,70,266);
    snake _4(5,100,300,70,300);
    snake _5(6,100,280,70,280);
    snake _6(7,10,252,1,252);
    snake _7(8,19,120,10,120);
    snake _8(9,100,120,70,120);
    snake _9(10,88,25,70,25);
    snake _10(11,100,66,70,66);
    snake _11(12,100,455,95,455);
    snake _12(13,200,350,189,350);
    snake _13(14,100,400,92,400);
    snake _14(15,100,297,70,297);



clrscr();

initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
setbkcolor(BLUE);

while(input!='0')
{

    while(!kbhit())
    { delay(5);
      green.move();
      green.makeEggs(300);
      green.eat();

      green.correct();




     red.move();
     red.eat();
     red.correct();



    //  blue.move();
  //    blue.eat();
//      blue.correct();



    //  yellow.move();
  //    yellow.eat();
//      yellow.correct();


   // esc= getch();



    //  if(esc=='0')exit(0);

    }


    if(kbhit())
    {
      input=getch();
      green.input(input);
    }




}

getch();
closegraph();}
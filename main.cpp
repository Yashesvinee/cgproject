#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Gl/gl.h>
#include<stdio.h>
#include<string.h>
#include <array>
#include<math.h>
#include <iterator>
#include <algorithm>
using std::fill;
int maxy=700;
int count=0;
int maxx=650;
int countarr[100];
float n=0.25,m=0.5;
int f=0,r=0,c=0;
int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0,count11=0,count12=0,count13=0;
float x=-60, y=50;
char str [10];
void id1();
void id();
void draw_target();
void redraw();
void draw_ground()
{
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0.28, 0.11);
    glVertex2f(-100.0,0.0);
    glVertex2f(-100.0,100.0);
    glVertex2f(2000.0,100.0);
    glVertex2f(2000.0,0.0);
    glEnd();

}

void draw_tree()
{

    glPushMatrix();
    glScalef(1.7, 1.9, 0.0);
    glTranslatef(-200, -100, 0);

    glBegin(GL_POLYGON);        //bark
    glColor3f(0.3f, 0.1f, 0.0f);
    glVertex2f(530 ,125 );
    glVertex2f(530 ,200 );
    glVertex2f(480 ,200 );
    glVertex2f(480 ,125 );
    glEnd();



    glBegin(GL_POLYGON);    //tree1-lower1
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(415 ,200 );
    glVertex2f(390 ,230 );
    glVertex2f(415 ,255 );
    glVertex2f(600 ,255 );
    glVertex2f(625 ,230 );
    glVertex2f(600 ,200 );
    glEnd();


    glBegin(GL_POLYGON);    //tree-lower2
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(425 ,255 );
    glVertex2f(395 ,260 );
    glVertex2f(425 ,310 );
    glVertex2f(590 ,310 );
    glVertex2f(615 ,260 );
    glVertex2f(590 ,255 );
    glEnd();


    glBegin(GL_POLYGON);    //tree-lower3
    glColor3f(0.0f, 0.5f, 0.0f);
    glVertex2f(440 ,310 );
    glVertex2f(410 ,330 );
    glVertex2f(440 ,380 );
    glVertex2f(575 ,380 );
    glVertex2f(600 ,330 );
    glVertex2f(575 ,310 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2f(465 ,380 );
    glVertex2f(435 ,400 );
    glVertex2f(465 ,420 );
    glVertex2f(550 ,420 );
    glVertex2f(575 ,400 );
    glVertex2f(550 ,380 );
    glEnd();

    glPopMatrix();

}

void draw_catapult()
{

    //GLint x=catapult_x,y=catapult_y;

    glColor3f(1.0, 1.0, 0.0);
    glLineWidth(20.0);
    glBegin(GL_LINES);
    glVertex2i(x, y);
    glVertex2i(x, y - 150);
    glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glVertex2i(x, y);
    glVertex2i(x - 45,y + 45);
    glEnd();


    glBegin(GL_LINES);
    glVertex2i(x, y);
    glVertex2i(x + 45, y + 45);
    glEnd();
}


void reshape(int width, int height)
{
   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(50.0,1.0,15.0,600.0);  //Perspective
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void output(int x, int y, char *string,void *font)
{
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(font, string[i]);
  }
}
/*to display bitmap char*/
void bitmap_output(int x, int y, char *string, void *font)
{
int len,i;
glRasterPos2f(x,y);
len=(int)strlen(string);
for(i=0;i<len;i++)
{
glutBitmapCharacter(font,string[i]);
}
return;
}
/*based on count display no of arrows and result of game*/
int totcount(){
int a;
for(a=0;a<13;a++)
    if (countarr[a]==1)c++;
    return c;
}
/*based on count display no of arrows and result of game*/
void counting()
{
 sprintf(str,"No of Arrows:%d",count);

 bitmap_output(40,40,str,GLUT_BITMAP_HELVETICA_18);
if(count1==1&&count2==1&&count3==1&&count4==1&&count5==1&&count6==1&&count7==
1&&count8==1&&count9==1&&count10==1&&count11==1&&count12==1&&count13==1)
{
 bitmap_output(5,350,"CONGRATULATIONS!!!!!",GLUT_BITMAP_TIMES_ROMAN_24);
 glutIdleFunc(NULL);
}
else if(count>=25)
{
 sprintf(str,"NO ARROWS LEFT  No of hits: %d",totcount());
bitmap_output(5,350,str,GLUT_BITMAP_TIMES_ROMAN_24);
glutIdleFunc(NULL);
}
}
/*TO CHECK WHETHER ARROW HITS TARGET*/
void disa(int l)
{
if((x+110==480)&&(y>=470&&y<=490)&&(!count1))
{
countarr[0]=1;count1=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if ((x+110==400)&&(y>=440&&y<=460)&&(!count2))
{
countarr[1]=1;count2=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if ((x+110==600) &&(y>=460&&y<=480) &&(!count3))
{
countarr[2]=1;count3=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if((x+110==480)&&(y>=390&&y<=410)&&(!count4))
{
countarr[3]=1;count4=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if((x+110==420)&&(y>=350&&y<=370)&&(!count5))
{
countarr[4]=1;count5=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if((x+110==615)&&(y>=330&&y<=350)&&(!count6))
{
countarr[5]=1;count6=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if((x+110==480)&&(y>=290&&y<=310)&&(!count7))
{
countarr[6]=1;count7=1;
x=25;
y=0;
count++;
glutIdleFunc (id);
}
else if((x+110==500)&&(y>=205&&y<=225)&&(!count8))
{
countarr[7]=1;count8=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if((x+110==610)&&(y>=230&&y<=250)&&(!count9))
{
countarr[8]=1;count9=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if((x+110==420)&&(y>=220&&y<=240)&&(!count10))
{
countarr[9]=1;
count10=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if((x+110==560)&&(y>=290&&y<=310)&&(!count11))
{
countarr[10]=1;
count11=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if((x+110==590)&&(y>=380&&y<=400)&&(!count12))
{
countarr[11]=1;
count12=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
else if((x+110==400)&&(y>=270&&y<=290)&&(!count13))
{
countarr[12]=1;
count13=1;
x=25;
y=0;
count++;
glutIdleFunc(id);
}
}
/*to move arrow up*/
void id()
{
y+=n;
glutTimerFunc(1000,disa,1);
if(y>maxy)
 {
 y=0;
 count++;
 }
glutPostRedisplay();
}
/*to draw the arrow*/
void disp()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glColor3f(1,0.4,0.2);
//bitmap_output(215,497,"BLOCKSHOOTING",GLUT_BITMAP_TIMES_ROMAN_24);
counting();

// Drawing of arrow
glColor3f(0.1f, 0.0f, 0.0f);
glBegin(GL_LINES);
glVertex2d(x,y);
glVertex2d(x+100,y);
glEnd();
glLineWidth(2);
glColor3f(0.1f, 0.0f, 0.0f);
glBegin(GL_LINES);
glVertex2d(x,y+2);
glVertex2d(x+100,y+2);
glEnd();
glColor3f(0.1f, 0.0f, 0.0f);
glBegin(GL_LINES);
glVertex2d(x,y-2);
glVertex2d(x+100,y-2);
glEnd();
glColor3f(0.5,0.5,0.5);
glBegin(GL_TRIANGLES);
glVertex2d(x+100,y+7);
glVertex2d(x+110,y);
glVertex2d(x+100,y-7);
glEnd();

draw_target();
draw_tree();
draw_ground(); // Drawing of target
glFlush();
glutSwapBuffers();
}
/*to clear screen & set projection mode*/
void init()
{
glClearColor(0,0,0,1);
if (f==2)
    glClearColor(0.0f, 1.0f, 1.0f,1.0f);
glColor3f(0.0f, 0.5f, 1.0f);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-100,800,0,500);
glMatrixMode(GL_MODELVIEW);
}
/*to draw the target inside line loop*/
void draw_target()
{
if(count1==0)
{
glColor3f(1,0,0);
glEnable(GL_POINT_SMOOTH);
glPointSize(60);
glBegin(GL_POINTS);
glVertex2d(480,480);
glEnd();
}
else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(480,480);
 glEnd();
}
if(count2==0)
{
glColor3f(1,0,0);
 glPointSize(30);
 glBegin(GL_POINTS);
 glVertex2d(400,450);
 glEnd();

}
else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(400,450);
 glEnd();
}
if(count3==0)
{
 glColor3f(1,0,0);
 glPointSize(30);
 glBegin(GL_POINTS);
 glVertex2d(600,470);
 glEnd();

}else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(600,470);
 glEnd();
}
if(count4==0)
{
glColor3f(1,0,0);
 glPointSize(30);
 glBegin(GL_POINTS);
 glVertex2d(480,400);
 glEnd();

}else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(480,400);
 glEnd();
}
if(count5==0)
{
 glColor3f(1,0,0);
 glPointSize(30);
 glBegin(GL_POINTS);
 glVertex2d(420,360);

 glEnd();

}else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);

glVertex2d(420,360);
 glEnd();
}
if(count6==0)
{
glColor3f(1,0,0);
 glPointSize(30);

 glBegin(GL_POINTS);
 glVertex2d(615,340);
 glEnd();

}else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(615,340);
 glEnd();
}
if(count7==0)
{
 glColor3f(1,0,0);
 glPointSize(30);
 glBegin(GL_POINTS);
 glVertex2d(480,300);
 glEnd();

}
else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(480,300);

glEnd();
}
if(count8==0)
{
 glColor3f(1,0,0);
 glPointSize(30);
 glBegin(GL_POINTS);
 glVertex2d(500,215);
 glEnd();

}
else {
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(500,215);
 glEnd();
}
if(count9==0)
{
 glColor3f(1,0,0);
 glPointSize(30);
 glBegin(GL_POINTS);
 glVertex2d(610,240);
 glEnd();

}
else
{
glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(610,240);
 glEnd();
}
if(count10==0)
{
 glColor3f(1,0,0);
 glPointSize(30);

 glBegin(GL_POINTS);
 glVertex2d(420,230);
 glEnd();

}
else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(420,230);
 glEnd();
}
if(count11==0)
{
glColor3f(1,0,0);
glEnable(GL_POINT_SMOOTH);
glPointSize(60);
glBegin(GL_POINTS);
glVertex2d(560,300);
glEnd();
}
else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(560,300);
 glEnd();
}
if(count12==0)
{
glColor3f(1,0,0);
glEnable(GL_POINT_SMOOTH);
glPointSize(60);
glBegin(GL_POINTS);
glVertex2d(590,390);
glEnd();
}
else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(590,390);
 glEnd();
}
if(count13==0)
{
glColor3f(1,0,0);
glEnable(GL_POINT_SMOOTH);
glPointSize(60);
glBegin(GL_POINTS);
glVertex2d(400,280);
glEnd();
}
else
{
 glColor3f(1,1,1);
 glPointSize(20);
 glBegin(GL_POINTS);
 glVertex2d(400,280);
 glEnd();
}

glFlush();
}
/* to move the arrow left wen 'r' pressed*/
void id1()
{
x+=m;
disa(1);
if(x+110>maxx)
{
x=25;
y=0;
count++;
glutIdleFunc(id);
}
glutPostRedisplay();
}
void reset(){
    count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0,count11=0,count12=0,count13=0;
    x=0,y=0,count=0,c=0;
    int a;
    for(a=0;a<10;a++)
        countarr[a]=0;
     disp();
}

void *fonts[]=
{
GLUT_BITMAP_9_BY_15,
GLUT_BITMAP_TIMES_ROMAN_10,
GLUT_BITMAP_TIMES_ROMAN_24,
GLUT_BITMAP_HELVETICA_18,
GLUT_BITMAP_HELVETICA_12
};
void front()
{
	glColor3f(1.0,1.0,0.0);
	output(445,650,"DSATM",fonts[2]);
	glColor3f(1.0,1.0,0.0);
	output(340,600,"DEPARTMENT OF COMPUTER SCIENCE",fonts[2]);
	//glColor3f(0.8,0.1,0.2); red
	glColor3f(1.0,1.0,1.0);
	output(435,540,"ARCHERY",fonts[2]);
	output(410,500,"     SHOOTING",fonts[2]);
	glColor3f(0.8,0.1,0.2);
	output(260,350,"YASHESVINEE V",fonts[2]);
	output(570,350,"SUSHMITHA M",fonts[2]);
	output(380,250,"[ PRESS ANY KEY TO CONTINUE ]",fonts[3]);
}
void menu()
{
	glColor3f(0.8,0.1,0.2);
	output(400,650,"     ARCHERY - SHOOTING",fonts[2]);
	glColor3f(0.0,0.6,0.3);
	output(300,400,"MENU",fonts[2]);
	output(300,380,"-----------------",fonts[2]);
	glColor3f(0.3,0.5,0.8);
	output(300,340,"[1] PLAY",fonts[3]);
	output(300,300,"[2] HELP",fonts[3]);
	output(300,260,"[b] BACK",fonts[3]);
	output(300,220,"[q] QUIT",fonts[3]);
	glColor3f(0.5,0.2,0.6);
}
void help()
{
	glColor3f(0.8,0.1,0.2);
	output(400,650,"ARCHERY - SHOOTING",fonts[2]);
	glColor3f(0.0,0.6,0.3);
	output(180,560,"=>  INSTRUCTIONS <=",fonts[3]);
	output(180,520,"=> ARROWS WILL CONTINUE TO MOVE UPWARDS ONE BY ONE.<=",fonts[3]);
	output(180,480,"=>  YOU HAVE TO SHOOT THE ARROWS AT THE RIGHT TIME TO HIT THE APPLE.<=",fonts[3]);
	output(180,440,"=> [R] TO SHOOT ARROW <=",fonts[3]);
	output(180,400,"=> [P] TO REPLAY <=",fonts[3]);
	glColor3f(0.3,0.5,0.8);
	output(400,280,"SELECT AN OPTION",fonts[2]);
	output(400,265,"-----------------",fonts[2]);
	output(400,230,"[h] HOME",fonts[3]);
	output(400,190,"[b] BACK",fonts[3]);
	output(400,150,"[q] QUIT",fonts[3]);

}

void menuset()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1000, 0.0, 750,-2000,1500);
	glMatrixMode(GL_MODELVIEW);
	glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}
void display()
{
	if(f==0)
	{
		menuset();
		front();

	 	glutSwapBuffers();
	}
	else if(f==1)
	{
	    menuset();
		menu();
		glutSwapBuffers();

	}
	else if(f==2)
    {
        init();
        disp();

    }
	else if(f==3)
	{
		menuset();
		help();
	 	glutSwapBuffers();
	}

	else
	{
        glClearColor(0.0,0.0,0.0,0.0);
	}
}
void keyboardFunc( unsigned char key, int x, int y )
{
	if(f==0)
		f=1;
	else if(f==1)
	{
		switch(key)
		{
		case '1':f=2;break;
		case '2':f=3;break;
		case '3':f=4;break;
		case 'b':
		case 'B':f=0;break;
		case 'q':
		case 'Q':exit(0);
		}
	}

	else if(f==2)
	{
		switch(key)
		{
		case 'q':
		case 'Q':exit(0);break;
		case 'b':
		case 'B':f=1;break;
		case 'h':
		case 'H':f=0;break;
        case 'r': glutIdleFunc(id1);break;
        case 'p': reset();break;

		}
	}
	else if(f==3)
	{
		switch(key)
		{
		case 'b':
		case 'B':f=1;break;
		case 'h':
		case 'H':f=0;break;
		case 'q':
		case 'Q':exit(0);
		case 'P': reset();break;
		}
	}
	else
	{	switch(key)
		{
		case 'b':
		case 'B':f=1;break;
		case 'h':
		case 'H':f=0;break;
		case 'q':
		case 'Q':exit(0);
		}
	}

   reshape( 1580,850 );
    glutPostRedisplay( );
}
/*main to call display,keyboard and idle func*/
int main(int argc,char **argv)
{

glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(1500,1500);
glutCreateWindow("ARCHERY GAME BLOCK SHOOTING");
glutFullScreen();
glutDisplayFunc(display);
glutIdleFunc(id);
glutKeyboardFunc(keyboardFunc);
init();
glEnable(GL_DEPTH_TEST);
glutMainLoop();
return 0;
}

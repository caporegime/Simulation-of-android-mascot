/*
This is a OpenGL program to demonstrate basic movements of a Android Mascot

    Uses Mouse Interaction to move the parts of the robot by,

  		Faisal                    Phalgun Shenoy                        */


//#include "stdafx.h"
#include<stdio.h>
#include <GL/glut.h>
#define TORSO_HEIGHT 4
#define UPPER_ARM_HEIGHT 2.0
#define LOWER_ARM_HEIGHT 2.0
#define UPPER_LEG_RADIUS  0.5
#define LOWER_LEG_RADIUS  0.5
#define LOWER_LEG_HEIGHT 2.0
#define UPPER_LEG_HEIGHT 2.0
#define TORSO_RADIUS 1.7
#define UPPER_ARM_RADIUS  0.5
#define LOWER_ARM_RADIUS  0.5
#define HEAD_HEIGHT 1.5
#define HEAD_RADIUS 1.0

typedef float point[3];

static GLfloat theta[11] = {0.0,0.0,0.0,180.0,0.0,180.0,0.0,180.0,0.0,180.0,0.0};//angles for rotation of body parts
static GLint angle = 2;

int j,k,i,line=0,flag=0,ball=TORSO_RADIUS;
char ch;
GLUquadricObj *t,*l, *h, *lua, *lla, *rua, *rla, *lll, *rll, *rul, *lul,*jnt;   //quadric objects 
double size=1.0;

//***************************************************************//

void torso()
{
	glClearColor(0.7,0.9,0.0,0.5);
	glColor3f(1.0f,0.8f,0.0f);
    	glPushMatrix();
    	glRotatef(-90.0, 1.0, 0.0, 0.0);
    	gluCylinder(t,TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT,10,10);      	//body
    	glPopMatrix();
}

//***************************************************************//

void ear()
{
	int x=-2;
	glLineWidth(3);
	glBegin(GL_LINES);

	glVertex3d(0.5+x, 3.5+x,-1);
    	glVertex3d(1.3+x, 2.5+x,-1);
	glVertex3d(3.5+x, 3.5+x,-1);
    	glVertex3d(2.8+x, 2.5+x,-1);
	
   	glEnd();
}

//***************************************************************//

void head()	
{
   	glPushMatrix();
   	glTranslatef(0.0, 0.1*HEAD_HEIGHT,0.0);
   	glScalef(HEAD_RADIUS, HEAD_HEIGHT, HEAD_RADIUS);
   	gluSphere(h,1.3,10,10);
   	glTranslatef(0,0.5,1.0);
   	ear();
   	glTranslatef(0.4,0.2,-0.15);
   	glDisable (GL_LIGHTING);
   	glColor3f(1,1,1);
 	gluSphere(jnt,0.23,10,10);
 	glEnable (GL_LIGHTING);
 	glPointSize(10);
   	glTranslatef(-0.8,0.0,0.0);
   	glDisable(GL_LIGHTING);
   	glColor3f(1,1,1);
   	gluSphere(jnt,0.23,10,10);
   	glEnable(GL_LIGHTING);
   	glTranslatef(0.0, UPPER_ARM_HEIGHT, 0.0); 
 	gluCylinder(h,0.2,0.2,0,10,10);
	glPopMatrix();
}

//***************************************************************//

void left_upper_arm()
{
   	glPushMatrix();
   	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	gluCylinder(lua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);  //upper part of left arm
   	glPopMatrix();
}

//***************************************************************//

void right_upper_arm()
{
   	glPushMatrix();
   	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	gluCylinder(rua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);   //upper part of right arm
   	glPopMatrix();
}

//***************************************************************//

void left_upper_leg() 
{
   	glPushMatrix();
   	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	gluCylinder(lul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);  //upper part of left leg
   	glPopMatrix();
}

//***************************************************************//

void right_upper_leg()
{
   	glPushMatrix();
   	glRotatef(-90.0, 1.0, 0.0, 0.0);
   	gluCylinder(rul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);  //upper part of right leg
   	glPopMatrix();
}

//***************************************************************//

void joint()
{
	glPushMatrix();
    	glRotatef(-90.0,1.0,0.0,0.0);
	gluSphere(jnt,UPPER_LEG_RADIUS,10,10);    //for joints of legs and arms
	glPopMatrix();
}

//***************************************************************//

void joint1(float ball)
{
	glPushMatrix();
    	glRotatef(-90.0,1.0,0.0,0.0);
	gluSphere(jnt,ball,10,10);    		 //for joints of legs and arms
	glPopMatrix();
}

//***************************************************************//

void display(void)
{
    	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    	glLoadIdentity();
    	glTranslatef(1.0,-1.5,1.0);
	switch(line)
	{
	case 1:	
		l=gluNewQuadric();
		gluQuadricDrawStyle(l, GLU_LINE);
        	h=gluNewQuadric();
        	gluQuadricDrawStyle(h, GLU_LINE);
        	t=gluNewQuadric();
        	gluQuadricDrawStyle(t, GLU_LINE);
        	
		lua=gluNewQuadric();
        	gluQuadricDrawStyle(lua, GLU_LINE);
										    //to draw lined quadric objects
        	rua=gluNewQuadric();
        	gluQuadricDrawStyle(rua, GLU_LINE);
 
  	lul=gluNewQuadric();
        	gluQuadricDrawStyle(lul, GLU_LINE);

	        rul=gluNewQuadric();
	        gluQuadricDrawStyle(rul, GLU_LINE);
  
		jnt=gluNewQuadric();
		gluQuadricDrawStyle(jnt, GLU_LINE);

	break;
	case 0:
		l=gluNewQuadric();
	        gluQuadricDrawStyle(l, GLU_FILL);
	
	        h=gluNewQuadric();
	        gluQuadricDrawStyle(h, GLU_FILL);

	        t=gluNewQuadric();
 	        gluQuadricDrawStyle(t, GLU_FILL);

        	lua=gluNewQuadric();
        	gluQuadricDrawStyle(lua, GLU_FILL);
     
        	rua=gluNewQuadric();
        	gluQuadricDrawStyle(rua, GLU_FILL);       //to draw solid quadric objects
       
        	lul=gluNewQuadric();
        	gluQuadricDrawStyle(lul, GLU_FILL);
  
        	rul=gluNewQuadric();
        	gluQuadricDrawStyle(rul, GLU_FILL);
    
		jnt=gluNewQuadric();
		gluQuadricDrawStyle(jnt, GLU_FILL);
		
		break;
	}
    	glRotatef(theta[0], 0.0, 1.0, 0.0);  //rotation for dody
    	
	torso();
    	glPushMatrix();
    	glTranslatef(0.0, TORSO_HEIGHT+0.5*HEAD_HEIGHT, 0.0);
    	glRotatef(theta[1], 1.0, 0.0, 0.0);     //rotations for head
    	glRotatef(theta[2], 0.0, 1.0, 0.0);
    	glTranslatef(0.0, -0.5*HEAD_HEIGHT, 0.0);
    	
	head();
    	glPopMatrix();
    	glPushMatrix();
    	glTranslatef(-(TORSO_RADIUS+UPPER_ARM_RADIUS), 3.3, 0.0);
    	glRotatef(theta[3], 1.0, 0.0, 0.0);     //rotation for upper part of left arm
    	joint();
	
	left_upper_arm();
    	glTranslatef(0.0, UPPER_ARM_HEIGHT, 0.0);
    	glRotatef(theta[4], 1.0, 0.0, 0.0);  //rotation for lower part of left arm
    	joint();
	glTranslatef(0.0, LOWER_ARM_HEIGHT+.35, 0.0);
    	glPopMatrix();
    	glPushMatrix();
    	glTranslatef(TORSO_RADIUS+UPPER_ARM_RADIUS, 3.3, 0.0);
    	glRotatef(theta[5], 1.0, 0.0, 0.0);     //rotation for upper part of right arm
    	joint();
	
	right_upper_arm();
    	glTranslatef(0.0, UPPER_ARM_HEIGHT, 0.0);
    	glRotatef(theta[6], 1.0, 0.0, 0.0);  //rotation for lower part of right arm
    	joint();
	glTranslatef(0.0, LOWER_ARM_HEIGHT+.35, 0.0);
    	glPopMatrix();
    	glPushMatrix();
    	glTranslatef(0.6, 0.1*UPPER_LEG_HEIGHT, 0.0);
    	glRotatef(theta[7], 1.0, 0.0, 0.0);    //rotation for upper part of left leg
     	joint();

	left_upper_leg();
  	glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
    	glRotatef(theta[8], 1.0, 0.0, 0.0);    //rotation for lower part of left leg
	joint();
	glTranslatef(0, LOWER_LEG_HEIGHT+.35, 0.0);
    	glPopMatrix();
    	glPushMatrix();
    	glTranslatef(-0.5, 0.1*UPPER_LEG_HEIGHT, 0.0);
	glRotatef(theta[9], 1.0, 0.0, 0.0); 	//rotation for upper part of right leg
	joint();

	right_upper_leg();
	glTranslatef(0.0,UPPER_LEG_HEIGHT, 0.0);
    	glRotatef(theta[10], 1.0, 0.0, 0.0);    //rotation for lower part of right leg
    	joint();
	glTranslatef(0.0, LOWER_LEG_HEIGHT+.35, 0.0);
    	glPopMatrix();
	glTranslatef(2.0, LOWER_LEG_HEIGHT-8, 0.0);

    	glFlush();
    	glutSwapBuffers();
}

//***************************************************************//

void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
        {
        if(flag==1)
		{
			theta[9] -= 10.0;
        		if( theta[9] ==120.0 ) exit(0);
				ball+=1.0;
		}
		else 
		{
			if((angle==1||angle==2)&&theta[angle]<65)
			theta[angle] += 5.0;
			else if(angle==0||angle>2)
			{
        			theta[angle] += 5.0;
        			if( theta[angle] > 360.0 ) theta[angle] -= 360.0;   //rotation by +5 degree if left clicked
        		}
		}
	}
	if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN) 
        {
		if((angle==1||angle==2)&&theta[angle]>-65)
        		theta[angle] -= 5.0;
		else if(angle==0||angle>2)
		{
        		theta[angle] -= 5.0;
        		if( theta[angle] < 360.0 ) theta[angle] += 360.0;   //rotation by -5 degree if right clicked
        	}
	}
        display();
}

//***************************************************************//

void printString(float x,float y,float z,void *font,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
	for (c=string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}

//***************************************************************//

void display_about(void)
{
	glClearColor(0.0,1.0,0.0,0.5);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.0,0.0,0.0);
	printString(-7,4,0.0,GLUT_BITMAP_TIMES_ROMAN_24,"DEPARTMENT OF COMPUTER SCIENCE");
 	glColor3f(0.0,0.0,0.0);
	printString(-6.5,3,0.0,GLUT_BITMAP_9_BY_15,"CG MINI PROJECT ON SIMULATION OF ANDROID MASCOT");
   	glColor3f(0.0,0.0,0.0);
    	glColor3f(0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.0);
	printString(-7.0,-0.5,0.0,GLUT_BITMAP_9_BY_15,"SUBMITTED BY:");
	glColor3f(0.0,0.0,0.0);
	printString(-7,-1.1,0.0,GLUT_BITMAP_9_BY_15,"B PHALGUN SHENOY (4PA10CS018)");
	glColor3f(0.0,0.0,0.0);
	printString(-7,-1.6,0.0,GLUT_BITMAP_9_BY_15,"FAISAL (4PA10CS024)");
    	glColor3f(0.0,0.0,0.0);
	glColor3f(0.0,0.0,0.0);
	printString(-7,-8,0.0,GLUT_BITMAP_9_BY_15,"SINGLE CLICK TO RETURN TO SIMULATION");
	printString(-7,-9,0.0,GLUT_BITMAP_9_BY_15,"PRESSING MIDDLE BUTTON IN SIMULATION REVEALS OPTIONS");
    	glutSwapBuffers();
	glFlush();
}

//***************************************************************//

void menu(int id)
{
	if(id==6)
	{display_about();}

   	if(id <11 ) angle=id;
   	if(id ==13 )
	{ 
		flag=1;
	   	//exit(0);
   	}
   	if(id==12)
   	{
	   line=(!line);
   	}
}

//***************************************************************//

void myReshape(int w, int h)
{
    	glViewport(0, 0, w, h);
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	if (w <= h)
        	glOrtho(-10.0, 10.0, -10.0 * (GLfloat) h / (GLfloat) w,10.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    	else
        glOrtho(-10.0 * (GLfloat) w / (GLfloat) h,10.0 * (GLfloat) w / (GLfloat) h, 0.0, 10.0, -10.0, 10.0);
    	glMatrixMode(GL_MODELVIEW);
    	glLoadIdentity();
}

//***************************************************************//

void myinit()
{	
        GLfloat mat_specular[]={1.0, 1.0, 1.0, 1.0};
        GLfloat mat_diffuse[]={0.0, 1.0, 0.0, 1.0};
        GLfloat mat_ambient[]={1.0, 1.0, 1.0, 1.0};           	  // amount of red,green,blue content in light and apha of light
        GLfloat mat_shininess={100.0};
        GLfloat light_ambient[]={0.0, 0.0, 0.0, 1.0};
        GLfloat light_diffuse[]={1.0, 1.0, 1.0, 1.0};               
        GLfloat light_specular[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_position[]={10.0, 10.0, 10.0, 0.0};         // initial position of light source

        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);          // creating light source
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

        glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);          // set properties of light source   
        glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
        glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);

        glShadeModel(GL_SMOOTH);
        glEnable(GL_LIGHTING); 
        glEnable(GL_LIGHT0);
        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST); 

        glClearColor(1.0, 1.0, 1.0, 1.0);
}

//***************************************************************//

int main(int argc , char **argv)
{
    	glutInit(&argc, argv);
    	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    	glutInitWindowSize(600,600);
	glutInitWindowPosition(380,40);
    	glutCreateWindow("Simulation Of Android Mascot");
    	myinit();
    	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
    	glutMouseFunc(mouse);

    	glutCreateMenu(menu);
    
    	glutAddMenuEntry("Rotate Head Vertically", 1);
    	glutAddMenuEntry("Rotate Head Horizontally", 2);
    	glutAddMenuEntry("Move Left Arm", 3);
    	glutAddMenuEntry("Move Right Arm", 5);
	glutAddMenuEntry("Move Left Leg", 9);
    	glutAddMenuEntry("Move Right Leg", 7);
	glutAddMenuEntry("Rotate The Body", 0);
	glutAddMenuEntry("Skeletal Mode (Enable/Disable)", 12);
	glutAddMenuEntry("About Project", 6);
	
	glutAttachMenu(GLUT_MIDDLE_BUTTON);

    	glutMainLoop();
}

//***************************** E ** N ** D ******************************//

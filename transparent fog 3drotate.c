#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
/*abhivandit*/
GLfloat xAngle, yAngle, zAngle;
GLfloat yRotated=0;
GLdouble radius=4;

GLfloat red[4] = {0.5,0.5,0.5,1};
GLfloat fog[1] = {0.02};
GLfloat qaAmbientLight[]    = {0.1, 0.1, 0.1, 1.0};
GLfloat qaDiffuseLight[]    = {1, 1, 1, 1.0};
GLfloat qaSpecularLight[]    = {1.0, 1.0, 1.0, 1.0};
GLfloat emitLight[] = {0.9, 0.9, 0.9, 0.01};
GLfloat Noemit[] = {0.0, 0.0, 0.0, 1.0};

GLfloat qaLightPosition[]    = {0, 0, 2, 1};
GLfloat qaLightDirection[]    = {1, 1, 1, 0};
GLfloat dirVector0[]={ 1.0, 0.0, 0.0, 0.0};

GLfloat qaBlack[] = {0.0, 0.0, 0.0, 1.0};
GLfloat qaPurple[] = {1.0, 0.0, 1.0, 1.0};
GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0}; 
GLfloat qaRed[] = {1.0, 0.0, 0.0, 0.3}; 

void display(void)
{


    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);//for transparency
glDisable(GL_CULL_FACE);
    glClearColor(0.2, 0.2, 0.2, 1);
    glClear(GL_COLOR_BUFFER_BIT);
//foggng puposes
glFogfv(GL_FOG_COLOR, red);

glFogfv(GL_FOG_DENSITY,fog);
  glEnable(GL_FOG);
   
    glLoadIdentity();
   
    glTranslatef(0.0,0.0,-20.0);


   glPushMatrix();
 
    //for rotation purposes 
    glTranslatef(5.0,0.0,0);

        glRotatef(-xAngle,1.0,0.0,0.0);
 
    glRotatef(-yAngle,0.0,1.0,0.0);
       glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaRed);

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaRed);

     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaRed);

     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
 
    //glutSolidCube(radius);
     glutSolidCube(2*radius);
     glPopMatrix();



      glPushMatrix();
 
     
    glTranslatef(5.0,0.0,0);
  
    glRotatef(xAngle,1.0,0.0,0.0);
 
    glRotatef(yAngle,0.0,1.0,0.0);


       glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaPurple);

    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, qaPurple);

     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, qaWhite);

     glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 20);
 
    glutSolidCube(radius);
     glPopMatrix();



    glPushMatrix();  
    glRotatef(yRotated,0.0,1.0,0.0);
     
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
 

    glPopMatrix(); 



    

    glFlush();
    glutSwapBuffers();

   
}
 void idleFunc(void)
{
    
    yAngle += 0.1;
     xAngle += 0.2;
    display();
}
void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,40.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  
}
 

void initLighting()//factor m to reduxe or increase density
{


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


       glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
 


     glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
     glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirVector0); 
     glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1); 


}
void keyboard(unsigned char key, int x, int y)
{
    
     
     if (key == 'l' || key == 'L')  
    { 
          glEnable(GL_LIGHTING);
    }
    else if (key == 'd' || key == 'D')  
    { 
        glDisable(GL_LIGHTING);
    }

}

 
int main (int argc, char **argv)
{
    glutInit(&argc, argv); 
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowSize(450,450);
    glutCreateWindow("Cube fog and spotlight");
    initLighting(); 

    
    glutIdleFunc(idleFunc);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // Register keyboard callback
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
 

 
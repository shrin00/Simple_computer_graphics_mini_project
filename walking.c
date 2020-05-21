#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>

float theta, theta3, theta4;
float x=-450.0, y=0, dx=320, dy=0;
int state=1;
float angle=0.0, angle1=0.0;

void display(void);
void timer(int);
void reshape(int, int);
void drawroom(void);
void drawman(void);
void drawdoctor(void);

int init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
}
int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB| GLUT_DOUBLE);
    glutInitWindowPosition(000,000);
    glutInitWindowSize(1600,1000);
    glutCreateWindow("CG PROJECT-walking man");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();
    glutMainLoop();

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    drawroom();
    drawman();
    drawdoctor();

    glutSwapBuffers();
    //glFlush();
}

void reshape(int w, int h){
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-500,500,-300,300);
    glMatrixMode(GL_MODELVIEW);

}

void timer(int a){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    //x+=1;
    if(x<225){
        x+=3.0;
    }
    if(x>220){
        if(angle>-80){
        angle-=0.30*2;
        }else{
            Sleep(5000);
            x=-450.0;
            angle1=0.0;
            angle=0.0;
        }

        if(angle<-20){
            if(angle1>-105)
                angle1-=0.30*1.75*2;
        }
    }
}

void drawroom()
{
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.7, 0.4);
    glVertex2f(500, 300);
    glVertex2f(-450, 300);
    glVertex2f(-450, 0);
    glVertex2f(500, 0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.14);
    glVertex2f(-450, 0);
    glVertex2f(-500, -300);
    glVertex2f(500, -300);
    glVertex2f(500, 0);
    glEnd();

    // drawing clock
    glBegin(GL_POLYGON);
    glColor3f(1.0,1.0,1.0);
    for(int z=0;z<360;z++)
    {
        theta4=z*3.142/180;//convert degree into radian
        glVertex2f(400+50*cos(theta4),230+50*sin(theta4));

    }
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(400, 230);
    glVertex2f(400, 270);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(400, 230);
    glVertex2f(440, 230);
    glEnd();

    //frame
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0, 220);
    glVertex2f(60, 220);
    glVertex2f(60, 150);
    glVertex2f(0, 150);
    glEnd();
    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(5, 185);
    glVertex2f(55, 185);
    glVertex2f(30, 155);
    glVertex2f(30, 215);
    glEnd();

}

void drawman(){
    //leg 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x+5, y-40);
    glVertex2f(x+5, y-115);
    glVertex2f(x+20, y-115);
    glVertex2f(x+20, y-40);
    glEnd();
    //leg 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(x+21, y-40);
    glVertex2f(x+21, y-110);
    glVertex2f(x+36, y-110);
    glVertex2f(x+36, y-40);
    glEnd();

    //shoe 1
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.4, 0.1);
    glVertex2f(x+5, y-115);
    glVertex2f(x+5, y-120);
    glVertex2f(x+25, y-120);
    glVertex2f(x+25, y-115);
    glEnd();
    //shoe 2
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.4, 0.1);
    glVertex2f(x+21, y-110);
    glVertex2f(x+21, y-115);
    glVertex2f(x+41, y-115);
    glVertex2f(x+41, y-110);
    glEnd();

    //body
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(x-5, y-40);
    glVertex2f(x-5, y+60);
    glVertex2f(x+45, y+60);
    glVertex2f(x+45, y-40);
    glEnd();

    //hand;
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.6, 0.4);
    glVertex2f(x+15, y+58);
    glVertex2f(x+15, y-10);
    glVertex2f(x+30, y-10);
    glVertex2f(x+30, y+58);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.14);
    glVertex2f(x+15, y-10);
    glVertex2f(x+17, y-15);
    glVertex2f(x+28, y-15);
    glVertex2f(x+30, y-10);
    glEnd();

    //neck
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.7,0.4);
    glVertex2f(x+15, y+60);
    glVertex2f(x+15, y+70);
    glVertex2f(x+20, y+70);
    glVertex2f(x+20, y+60);
    glEnd();

    //head
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.9,0.5);
    for(int i=0;i<360;i++){
        theta=i*3.142/180;
        glVertex2f((x+17)+15*cos(theta),(y+80)+15*sin(theta));

    }
    glEnd();

    // create eye

    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    for(int z=0;z<360;z++)
    {
        theta3=z*3.142/180;
        glVertex2f((x+24)+2.5*cos(theta3),(y+82)+2.5*sin(theta3));

    }
    glEnd();

}

void drawdoctor(){
    //leg 1
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(dx+5, y-40);
    glVertex2f(dx+5, y-110);
    glVertex2f(dx+20, y-110);
    glVertex2f(dx+20, y-40);
    glEnd();
    //leg 2
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(dx+21, y-40);
    glVertex2f(dx+21, y-115);
    glVertex2f(dx+36, y-115);
    glVertex2f(dx+36, y-40);
    glEnd();

    //shoe 1
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.4, 0.1);
    glVertex2f(dx+20, y-110);
    glVertex2f(dx+20, y-115);
    glVertex2f(dx+0, y-115);
    glVertex2f(dx+0, y-110);
    glEnd();
    //shoe 2
    glBegin(GL_POLYGON);
    glColor3f(0.8, 0.4, 0.1);
    glVertex2f(dx+36, y-115);
    glVertex2f(dx+36, y-120);
    glVertex2f(dx+16, y-120);
    glVertex2f(dx+16, y-115);
    glEnd();

    //body
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(dx-5, y-40);
    glVertex2f(dx-5, y+60);
    glVertex2f(dx+45, y+60);
    glVertex2f(dx+45, y-40);
    glEnd();

    //neck
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.7,0.4);
    glVertex2f(dx+15, y+60);
    glVertex2f(dx+15, y+70);
    glVertex2f(dx+20, y+70);
    glVertex2f(dx+20, y+60);
    glEnd();

    //head
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.9,0.5);
    for(int i=0;i<360;i++){
        theta=i*3.142/180;
        glVertex2f((dx+17)+15*cos(theta),(y+80)+15*sin(theta));

    }
    glEnd();

    // create eye
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    for(int z=0;z<360;z++)
    {
        theta3=z*3.142/180;
        glVertex2f((dx+10)+2.5*cos(theta3),(y+82)+2.5*sin(theta3));

    }
    glEnd();

    glLoadIdentity();
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(dx+20, y+60);
    glVertex2f(dx-5, y+30);
    glEnd();

    //stethoscope
    //glLineWidth(3);
    glTranslatef(dx-5, y+30, 0.0);
    glRotatef(angle1, 0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(0, 0);
    glVertex2f(0, -45);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.0,0.0);
    for(int z=0;z<360;z++)
    {
        theta3=z*3.142/180;
        glVertex2f((0)+5*cos(theta3),(-45)+5*sin(theta3));

    }
    glEnd();

    glLoadIdentity();
    glTranslatef(dx+15, y+58, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    //hand;
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0, 0);
    glVertex2f(0, -58);
    glVertex2f(15, -58);
    glVertex2f(15, 0);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.3, 0.14);
    glVertex2f(0, -58);
    glVertex2f(2, -63);
    glVertex2f(13, -63);
    glVertex2f(15,-58);
    glEnd();

}


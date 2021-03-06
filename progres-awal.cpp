#include<Windows.h>
#include<gl\freeglut.h> //sesuaikan dengan lokasi glut.h
#include<gl\glut.h>

void myinit(void);
void tampilan(void);
void keybord(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukur(int, int);
void mouseMotion(int x, int y);

float xrot =0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;
int is_depth;


void tampilan(void){
	if(is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
//------------------------------------------
    glBegin(GL_LINES);//gais kordinat x
	glColor3f(1,0,0);//merah
	glVertex3f(-100,0,-100);
	glVertex3f(100,0,-100);
	glEnd();

    glBegin(GL_LINES);//gais kordinat y
	glColor3f(0, 0, 1);//biru
	glVertex3f(-100,-100,-100);
	glVertex3f(-100,100,-100);
	glEnd();

    glBegin(GL_LINES);//gais kordinat z
	glColor3f(0, 1, 0);//hijau
	glVertex3f(-100,0,-100);
	glVertex3f(-100,0,100);
	glEnd();

//-----------------------------------------
    glBegin(GL_POLYGON);//bagian depan
	glColor3ub(174, 174, 174);
	glVertex3f(-50,-20,30);
	glVertex3f(20,-20,30);
	glVertex3f(20,20,30);
	glVertex3f(-50,20,30);
	glEnd();

    glBegin(GL_POLYGON);//atap
	glColor3ub(165, 149, 149);
	glVertex3f(-50,20,30);
	glVertex3f(20,20,30);
	glVertex3f(40,20,10);
	glVertex3f(40,20,-40);
	glVertex3f(-50,20,-40);
	glEnd();
//---------------------------------------------------------

    glBegin(GL_POLYGON);//bagian dinding kiri
	glColor3ub(174, 174, 174);
	glVertex3f(-50,-20,30);
	glVertex3f(-50,20,30);
	glVertex3f(-50,20,-40);
	glVertex3f(-50,-20,-40);
	glEnd();

    glBegin(GL_POLYGON);//bagian dinding kanan
	glColor3ub(174, 174, 174);
	glVertex3f(40,-20,10);
	glVertex3f(40,-20,-40);
	glVertex3f(40,20,-40);
	glVertex3f(40,20,10);
	glEnd();

    glBegin(GL_POLYGON);//bundaran keatas
	glColor3ub(130, 235, 254);
	glVertex3f(15,-20,24);
	glVertex3f(19,-20,31);
	glVertex3f(19,21,31);
	glVertex3f(15,21,24);
	glEnd();
    glBegin(GL_POLYGON);//bundaran keatas
    glColor3ub(130, 235, 254);
	glVertex3f(19,-20,31);
    glVertex3f(26,-20,35);
    glVertex3f(26,21,35);
	glVertex3f(19,21,31);
	glEnd();
	glBegin(GL_POLYGON);//bundaran keatas
	glColor3ub(130, 235, 254);
    glVertex3f(26,-20,35);
    glVertex3f(34,-20,35);
    glVertex3f(34,21,35);
    glVertex3f(26,21,35);
	glEnd();
    glBegin(GL_POLYGON);//bundaran keatas
    glColor3ub(130, 235, 254);
    glVertex3f(34,-20,35);
    glVertex3f(41,-20,31);
    glVertex3f(41,21,31);
    glVertex3f(34,21,35);
	glEnd();
    glBegin(GL_POLYGON);//bundaran keatas
    glColor3ub(130, 235, 254);
    glVertex3f(41,-20,31);
    glVertex3f(45,-20,24);
    glVertex3f(45,21,24);
    glVertex3f(41,21,31);
	glEnd();
    glBegin(GL_POLYGON);//bundaran keatas
    glColor3ub(130, 235, 254);
    glVertex3f(45,-20,24);
    glVertex3f(45,-20,16);
    glVertex3f(45,21,16);
    glVertex3f(45,21,24);
	glEnd();
    glBegin(GL_POLYGON);//bundaran keatas
    glColor3ub(130, 235, 254);
    glVertex3f(45,-20,16);
	glVertex3f(41,-20,9);
    glVertex3f(41,21,9);
    glVertex3f(45,21,16);
	glEnd();


    glBegin(GL_POLYGON);//lantainya
	glColor3ub(0, 149, 149);
	glVertex3f(-50,-20,30);
	glVertex3f(20,-20,30);
	glVertex3f(40,-20,10);
	glVertex3f(40,-20,-40);
	glVertex3f(-50,-20,-40);
	glEnd();

    glBegin(GL_POLYGON);//bundaran alas
	glColor3ub(175, 161, 8);
	glVertex3f(15,-20,24);
	glVertex3f(19,-20,31);
    glVertex3f(26,-20,35);
	glVertex3f(34,-20,35);
	glVertex3f(41,-20,31);
	glVertex3f(45,-20,24);
	glVertex3f(45,-20,16);
	glVertex3f(41,-20,9);
	glVertex3f(34,-20,5);
	glVertex3f(26,-20,5);
	glVertex3f(19,-20,9);
	glVertex3f(15,-20,16);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap
	glColor3ub(175, 161, 8);
	glVertex3f(15,21,24);
	glVertex3f(19,21,31);
    glVertex3f(26,21,35);
	glVertex3f(34,21,35);
	glVertex3f(41,21,31);
	glVertex3f(45,21,24);
	glVertex3f(45,21,16);
	glVertex3f(41,21,9);
	glVertex3f(34,21,5);
	glVertex3f(26,21,5);
	glVertex3f(19,21,9);
	glVertex3f(15,21,16);
	glEnd();


	glPushMatrix();
	glPopMatrix();
	glutSwapBuffers();
}

void myinit(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(10.0);
	glLineWidth(7.0f);
}


void keybord(unsigned char key, int x, int y){
	switch (key){
		case 'w':
			case 'W':
				glTranslatef(0,0,3);
				break;
		case 'd':
			case 'D':
				glTranslatef(3,0,0);
				break;
		case 's':
			case 'S':
				glTranslatef(0,0,-3);
				break;
		case 'a':
			case 'A':
				glTranslatef(-3,0,0);
				break;

		case '7':

				glTranslatef(0,3,0);
				break;
		case '9':

				glTranslatef(0,-3,0);
				break;
		case '2':

				glRotatef(2,1,0,0);
				break;
		case '8':

				glRotatef(2,1,0,0);
				break;
		case '6':

				glRotatef(2,0,1,0);
				break;
		case '4':

				glRotatef(-2,0,1,0);
				break;
		case '1':

				glRotatef(2,1,0,1);
				break;
		case '3':

				glRotatef(-2,0,0,1);
				break;
		case '5':
			if(is_depth){
				is_depth=0;
				glDisable(GL_DEPTH_TEST);
			}
			else{
				is_depth=1;
				glEnable(GL_DEPTH_TEST);
			}
	}
	tampilan();
}

void ukur(int lebar, int tinggi){
	if(tinggi==0) tinggi=1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,lebar/tinggi, 5, 450);
	glTranslatef(0,0,-200);
	glMatrixMode(GL_MODELVIEW);
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3;
		yrot += 0.4;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{
	
	glLoadIdentity();
	gluLookAt(0,0,3,0,0,0,0,1,0);
	glRotatef(xrot, 1, 0,0);
	glRotatef(yrot, 0,1,0);
	if(mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(300, 0);//posisi jendela project
  glutInitWindowSize(800, 800);//ukuran jendela projeck
  glutCreateWindow("Mall Siam Paragon");
  myinit();
  glutDisplayFunc(tampilan);
  glutKeyboardFunc(keybord);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
  glutReshapeFunc(ukur);
  glutMainLoop();
}

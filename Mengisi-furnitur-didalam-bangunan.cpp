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

	glLoadIdentity();
	gluLookAt(0,0,3,0,0,0,0,1,0);
	glRotatef(xrot, 1, 0,0);
	glRotatef(yrot, 0,1,0);
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
    glBegin(GL_POLYGON);//bagian dinding depan
	glColor3ub(174, 174, 174);
	glVertex3f(-50,-20,30);
	glVertex3f(20,-20,30);
	glVertex3f(20,20,30);
	glVertex3f(-50,20,30);
	glEnd();

    glBegin(GL_POLYGON);//detail dinding depan hitam
	glColor3ub(52, 52, 52);
	glVertex3f(-40,-20,30.1);
	glVertex3f(-30,-20,30.1);
	glVertex3f(-30,0,30.1);
	glVertex3f(-40,0,30.1);
	glEnd();
    glBegin(GL_POLYGON);//detail dinding depan merah
	glColor3ub(255, 77, 77);
	glVertex3f(-40,0,30.1);
	glVertex3f(-30,0,30.1);
	glVertex3f(-30,10,30.1);
	glVertex3f(-40,10,30.1);
	glEnd();
    glBegin(GL_POLYGON);//detail dinding depan hitam 2
	glColor3ub(52, 52, 52);
	glVertex3f(-25,-20,30.1);
	glVertex3f(-15,-20,30.1);
	glVertex3f(-15,0,30.1);
	glVertex3f(-25,0,30.1);
	glEnd();
    glBegin(GL_POLYGON);//detail dinding depan merah 2
	glColor3ub(255, 77, 77);
	glVertex3f(-25,0,30.1);
	glVertex3f(-15,0,30.1);
	glVertex3f(-15,10,30.1);
	glVertex3f(-25,10,30.1);
	glEnd();
    glBegin(GL_POLYGON);//detail dinding depan hitam 2
	glColor3ub(52, 52, 52);
	glVertex3f(-10,-20,30.1);
	glVertex3f(-0,-20,30.1);
	glVertex3f(-0,0,30.1);
	glVertex3f(-10,0,30.1);
	glEnd();
    glBegin(GL_POLYGON);//detail dinding depan merah 2
	glColor3ub(255, 77, 77);
	glVertex3f(-10,0,30.1);
	glVertex3f(-0,0,30.1);
	glVertex3f(-0,10,30.1);
	glVertex3f(-10,10,30.1);
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
    glBegin(GL_POLYGON);//bagian detail dinding kanan
	glColor3ub(125, 174, 174);
	glVertex3f(40.1,-15,8);
	glVertex3f(40.1,-15,0);
	glVertex3f(40.1,0,0);
	glVertex3f(40.1,0,8);
	glEnd();
    glBegin(GL_POLYGON);//bagian detail dinding kanan
	glColor3ub(255, 255, 0);
	glVertex3f(40.1,2,8);
	glVertex3f(40.1,2,0);
	glVertex3f(40.1,0,0);
	glVertex3f(40.1,0,8);
	glEnd();

    glBegin(GL_POLYGON);//bagian detail dinding kanan
	glColor3ub(125, 174, 174);
	glVertex3f(40.1,-15,-2);
	glVertex3f(40.1,-15,-10);
	glVertex3f(40.1,0,-10);
	glVertex3f(40.1,0,-2);
	glEnd();
    glBegin(GL_POLYGON);//bagian detail dinding kanan
	glColor3ub(255, 255, 0);
	glVertex3f(40.1,2,-2);
	glVertex3f(40.1,2,-10);
	glVertex3f(40.1,0,-10);
	glVertex3f(40.1,0,-2);
	glEnd();

    glBegin(GL_POLYGON);//bagian detail dinding kanan
	glColor3ub(125, 174, 174);
	glVertex3f(40.1,-15,-12);
	glVertex3f(40.1,-15,-20);
	glVertex3f(40.1,0,-20);
	glVertex3f(40.1,0,-12);
	glEnd();
    glBegin(GL_POLYGON);//bagian detail dinding kanan
	glColor3ub(255, 255, 0);
	glVertex3f(40.1,2,-12);
	glVertex3f(40.1,2,-20);
	glVertex3f(40.1,0,-20);
	glVertex3f(40.1,0,-12);
	glEnd();

    glBegin(GL_POLYGON);//bagian detail dinding kanan
	glColor3ub(0, 0, 255);
	glVertex3f(40.1,5,8);
	glVertex3f(40.1,5,-8);
	glVertex3f(40.1,17,-8);
	glVertex3f(40.1,17,8);
	glEnd();

    glBegin(GL_POLYGON);//bagian detail dinding kanan
	glColor3ub(255, 222, 40);
	glVertex3f(40.1,5,-10);
	glVertex3f(40.1,5,-20);
	glVertex3f(40.1,17,-20);
	glVertex3f(40.1,17,-10);
	glEnd();

    glBegin(GL_POLYGON);//bagian dinding belakang
	glColor3ub(174, 174, 174);
	glVertex3f(-50,-20,-40);
	glVertex3f(40,-20,-40);
	glVertex3f(40,20,-40);
	glVertex3f(-50,20,-40);
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
    glColor3ub(174, 174, 174);
	glVertex3f(-50,-20,30);
	glVertex3f(20,-20,30);
	glVertex3f(40,-20,10);
	glVertex3f(40,-20,-40);
	glVertex3f(-50,-20,-40);
	glEnd();

    glBegin(GL_POLYGON);//bundaran alas
    glColor3ub(174, 174, 174);
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
    glBegin(GL_POLYGON);//bundaran atap 1
	glColor3ub(175, 161, 8);
	glVertex3f(12,21,25.5);
	glVertex3f(16,21,34);
    glVertex3f(25.5,21,38);
	glVertex3f(35.5,21,38);
	glVertex3f(44,21,34);
	glVertex3f(48,21,25.5);
	glVertex3f(48,21,15.5);
	glVertex3f(44,21,6);
	glVertex3f(35.5,21,2);
	glVertex3f(25.5,21,2);
	glVertex3f(16,21,6);
	glVertex3f(12,21,15.5);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap 2
	glColor3ub(175, 161, 8);
	glVertex3f(12,23,25.5);
	glVertex3f(16,23,34);
    glVertex3f(25.5,23,38);
	glVertex3f(35.5,23,38);
	glVertex3f(44,23,34);
	glVertex3f(48,23,25.5);
	glVertex3f(48,23,15.5);
	glVertex3f(44,23,6);
	glVertex3f(35.5,23,2);
	glVertex3f(25.5,23,2);
	glVertex3f(16,23,6);
	glVertex3f(12,23,15.5);
	glEnd();

    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
	glVertex3f(12,21,25.5);
	glVertex3f(16,21,34);
	glVertex3f(16,23,34);
	glVertex3f(12,23,25.5);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
	glVertex3f(16,21,34);
    glVertex3f(25.5,21,38);
    glVertex3f(25.5,23,38);
	glVertex3f(16,23,34);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(25.5,21,38);
	glVertex3f(35.5,21,38);
    glVertex3f(35.5,23,38);
    glVertex3f(25.5,23,38);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(35.5,21,38);
    glVertex3f(44,21,34);
    glVertex3f(44,23,34);
    glVertex3f(35.5,23,38);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(44,21,34);
    glVertex3f(48,21,25.5);
    glVertex3f(48,23,25.5);
    glVertex3f(44,23,34);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(48,21,25.5);
    glVertex3f(48,21,15.5);
    glVertex3f(48,23,15.5);
    glVertex3f(48,23,25.5);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(48,21,15.5);
    glVertex3f(44,21,6);
    glVertex3f(44,23,6);
    glVertex3f(48,23,15.5);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(44,21,6);
    glVertex3f(35.5,21,2);
    glVertex3f(35.5,23,2);
    glVertex3f(44,23,6);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(35.5,21,2);
    glVertex3f(25.5,21,2);
    glVertex3f(25.5,23,2);
    glVertex3f(35.5,23,2);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(25.5,21,2);
    glVertex3f(16,21,6);
    glVertex3f(16,23,6);
    glVertex3f(25.5,23,2);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(16,21,6);
    glVertex3f(12,21,15.5);
    glVertex3f(12,23,15.5);
    glVertex3f(16,23,6);
	glEnd();
    glBegin(GL_POLYGON);//bundaran atap keatas
	glColor3ub(175, 161, 8);
    glVertex3f(12,21,15.5);
    glVertex3f(12,21,25.5);
    glVertex3f(12,23,25.5);
    glVertex3f(12,23,15.5);
	glEnd();

    glBegin(GL_POLYGON);//balkon bundaran bawah
	glColor3ub(175, 161, 8);
	glVertex3f(26,5,35);
	glVertex3f(34,5,42);
	glVertex3f(52,5,22);
	glVertex3f(45,5,16);
	glEnd();
    glBegin(GL_POLYGON);//balkon bundaran depan
	glColor3ub(175, 161, 8);
	glVertex3f(34,5,42);
	glVertex3f(52,5,22);
	glVertex3f(52,7,22);
	glVertex3f(34,7,42);
	glEnd();
    glBegin(GL_POLYGON);//balkon bundaran kiri
	glColor3ub(175, 161, 8);
	glVertex3f(26,5,35);
	glVertex3f(34,5,42);
	glVertex3f(34,7,42);
	glVertex3f(26,7,35);
	glEnd();
    glBegin(GL_POLYGON);//balkon bundaran kanan
	glColor3ub(175, 161, 8);
	glVertex3f(52,5,22);
	glVertex3f(45,5,16);
	glVertex3f(45,7,16);
	glVertex3f(52,7,22);
	glEnd();
    glBegin(GL_POLYGON);//balkon bundaran
	glColor3ub(175, 161, 8);
	glVertex3f(26,7,35);
	glVertex3f(34,7,42);
	glVertex3f(52,7,22);
	glVertex3f(45,7,16);
	glEnd();

    glBegin(GL_POLYGON);//lantai bundaran bawah
    glColor3ub(174, 174, 174);
	glVertex3f(10,-20,40);
	glVertex3f(60,-20,40);
	glVertex3f(60,-20,0);
	glVertex3f(10,-20,0);
	glEnd();
    glBegin(GL_POLYGON);//lantai bundaran depan
    glColor3ub(237, 227, 227);
	glVertex3f(10,-20,40);
	glVertex3f(60,-20,40);
	glVertex3f(60,-15,40);
    glVertex3f(10,-15,40);
	glEnd();
    glBegin(GL_POLYGON);//lantai bundaran kanan
    glColor3ub(237, 227, 227);
	glVertex3f(60,-20,40);
	glVertex3f(60,-20,0);
	glVertex3f(60,-15,0);
	glVertex3f(60,-15,40);
	glEnd();

    glBegin(GL_POLYGON);//lantai bundaran kiri
    glColor3ub(237, 227, 227);
	glVertex3f(10,-20,40);
	glVertex3f(10,-20,30);
    glVertex3f(10,-15,30);
    glVertex3f(10,-15,40);
	glEnd();
    glBegin(GL_POLYGON);//lantai bundaran belakang
    glColor3ub(237, 227, 227);
	glVertex3f(60,-20,0);
	glVertex3f(50,-20,0);
    glVertex3f(50,-15,0);
    glVertex3f(60,-15,0);
	glEnd();
    glBegin(GL_POLYGON);//lantai bundaran
    glColor3ub(237, 227, 227);
	glVertex3f(10,-15,40);
	glVertex3f(60,-15,40);
	glVertex3f(60,-15,0);
	glVertex3f(10,-15,0);
	glEnd();

    glBegin(GL_POLYGON);//lantai bundaran 2
    glColor3ub(174, 171, 174);
	glVertex3f(40,-20,0);
	glVertex3f(50,-20,0);
	glVertex3f(50,-20,-40);
	glVertex3f(40,-20,-40);
	glEnd();
    glBegin(GL_POLYGON);//lantai bundaran 2
    glColor3ub(237, 227, 227);
	glVertex3f(40,-15,0);
	glVertex3f(50,-15,0);
	glVertex3f(50,-15,-40);
	glVertex3f(40,-15,-40);
	glEnd();
    glBegin(GL_POLYGON);//lantai bundaran 2
    glColor3ub(237, 227, 227);
	glVertex3f(50,-20,0);
	glVertex3f(50,-20,-40);
	glVertex3f(50,-15,-40);
    glVertex3f(50,-15,0);
	glEnd();
    glBegin(GL_POLYGON);//lantai bundaran 2
    glColor3ub(237, 227, 227);
	glVertex3f(50,-20,-40);
	glVertex3f(40,-20,-40);
	glVertex3f(40,-15,-40);
	glVertex3f(50,-15,-40);
	glEnd();
//---------------------------------------------------------
    glBegin(GL_POLYGON);//lantai tingkat dalam 2
    glColor3ub(65,65,65);
	glVertex3f(-50,-5,30);
	glVertex3f(-20,-5,30);
	glVertex3f(-20,-5,-40);
	glVertex3f(-50,-5,-40);
	glEnd();

    glBegin(GL_POLYGON);//lantai tingkat dalam 2
    glColor3ub(65,65,65);
	glVertex3f(-20,-5,-10);
	glVertex3f(10,-5,-10);
	glVertex3f(10,-5,-40);
	glVertex3f(-20,-5,-40);
	glEnd();



    glBegin(GL_POLYGON);//lantai tingkat dalam 2
    glColor3ub(65,65,65);
	glVertex3f(10,-5,30);
	glVertex3f(40,-5,10);
	glVertex3f(40,-5,-40);
	glVertex3f(10,-5,-40);
	glEnd();

//------------------------------------------------------------------------

    glBegin(GL_POLYGON);//eskalator 1 ke 2 kiri
    glColor3ub(255,255,255);
	glVertex3f(-15,-20,5);
	glVertex3f(-8,-20,5);
	glVertex3f(-8,-5,-15);
	glVertex3f(-15,-5,-15);
	glEnd();
    glBegin(GL_POLYGON);//eskalator 2 ke 3 kiri
    glColor3ub(0,0,0);
	glVertex3f(-8,-20,5);
	glVertex3f(-8,-15,5);
	glVertex3f(-8,0,-15);
	glVertex3f(-8,-5,-15);
	glEnd();
    glBegin(GL_POLYGON);//eskalator 2 ke 3 kiri
    glColor3ub(0,0,0);
	glVertex3f(-15,-20,5);
	glVertex3f(-15,-15,5);
	glVertex3f(-15,0,-15);
	glVertex3f(-15,-5,-15);
	glEnd();

    glBegin(GL_POLYGON);//eskalator 2 ke 3 kanan
    glColor3ub(255,255,255);
	glVertex3f(6,-20,5);
	glVertex3f(-2,-20,5);
	glVertex3f(-2,-5,-15);
	glVertex3f(6,-5,-15);
	glEnd();
	    glBegin(GL_POLYGON);//eskalator 2 ke 3 kiri
    glColor3ub(0,0,0);
	glVertex3f(-2,-20,5);
	glVertex3f(-2,-15,5);
	glVertex3f(-2,0,-15);
	glVertex3f(-2,-5,-15);
	glEnd();
    glBegin(GL_POLYGON);//eskalator 2 ke 3 kiri
    glColor3ub(0,0,0);
	glVertex3f(6,-20,5);
	glVertex3f(6,-15,5);
	glVertex3f(6,0,-15);
	glVertex3f(6,-5,-15);
	glEnd();


    glBegin(GL_POLYGON);//BOT STAND
    glColor3ub(0,255,0);
	glVertex3f(-40,-17,15);
	glVertex3f(-30,-17,15);
	glVertex3f(-30,-17,10);
	glVertex3f(-40,-17,10);
	glEnd();
    glBegin(GL_POLYGON);//BOT STAND
	glVertex3f(-40,-20,15);
	glVertex3f(-30,-20,15);
	glVertex3f(-30,-17,15);
	glVertex3f(-40,-17,15);
	glEnd();
    glBegin(GL_POLYGON);//BOT STAND
	glVertex3f(-40,-20,10);
	glVertex3f(-30,-20,10);
	glVertex3f(-30,-17,10);
	glVertex3f(-40,-17,10);
	glEnd();
    glBegin(GL_POLYGON);//BOT STAND
	glVertex3f(-40,-13,15);
	glVertex3f(-30,-13,15);
	glVertex3f(-30,-10,15);
	glVertex3f(-40,-10,15);
	glEnd();
    glBegin(GL_LINES);//BOT STAND
    glColor3ub(0,0,0);
	glVertex3f(-40,-20,15);
	glVertex3f(-40,-10,15);
	glEnd();
    glBegin(GL_LINES);//BOT STAND
    glColor3ub(0,0,0);
	glVertex3f(-30,-20,15);
	glVertex3f(-30,-10,15);
	glEnd();

    glBegin(GL_POLYGON);//dinding toko 1
	glColor3ub(174, 174, 174);
	glVertex3f(-50,-5,-25);
	glVertex3f(-50,-5,-40);
	glVertex3f(-50,5,-40);
	glVertex3f(-50,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//toko 1
    glColor3ub(100,5,5);
	glVertex3f(-50,5,-40);
	glVertex3f(-35,5,-40);
	glVertex3f(-35,5,-25);
	glVertex3f(-50,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//toko 1
    glColor3ub(100,5,5);
	glVertex3f(-50,-5,-25);
	glVertex3f(-35,-5,-25);
	glVertex3f(-35,5,-25);
	glVertex3f(-50,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//pintu toko 1
    glColor3ub(100,125,125);
	glVertex3f(-47,-5,-25);
	glVertex3f(-38,-5,-25);
	glVertex3f(-38,3,-25);
	glVertex3f(-47,3,-25);
	glEnd();
    glBegin(GL_LINES);//pintu toko 1
    glColor3ub(0,0,0);
	glVertex3f(-42.5,-5,-25);
	glVertex3f(-42.5,3,-25);
	glEnd();

    glBegin(GL_POLYGON);//toko 2
    glColor3ub(80,150,10);
	glVertex3f(-35,5,-40);
	glVertex3f(-20,5,-40);
	glVertex3f(-20,5,-25);
	glVertex3f(-35,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//toko 2
    glColor3ub(80,150,10);
	glVertex3f(-35,-5,-25);
	glVertex3f(-20,-5,-25);
	glVertex3f(-20,5,-25);
	glVertex3f(-35,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//pintu toko 2
    glColor3ub(100,125,125);
	glVertex3f(-32,-5,-25);
	glVertex3f(-23,-5,-25);
	glVertex3f(-23,3,-25);
	glVertex3f(-32,3,-25);
	glEnd();
    glBegin(GL_LINES);//pintu toko 2
    glColor3ub(0,0,0);
	glVertex3f(-27.5,-5,-25);
	glVertex3f(-27.5,3,-25);
	glEnd();

    glBegin(GL_POLYGON);//toko 3
     glColor3ub(100,5,5);
	glVertex3f(-20,5,-40);
	glVertex3f(-5,5,-40);
	glVertex3f(-5,5,-25);
	glVertex3f(-20,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//toko 3
     glColor3ub(100,5,5);
	glVertex3f(-20,-5,-25);
	glVertex3f(-5,-5,-25);
	glVertex3f(-5,5,-25);
	glVertex3f(-20,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//pintu toko 3
    glColor3ub(100,125,125);
	glVertex3f(-18,-5,-25);
	glVertex3f(-9,-5,-25);
	glVertex3f(-9,3,-25);
	glVertex3f(-18,3,-25);
	glEnd();
	    glBegin(GL_LINES);//pintu toko 3
    glColor3ub(0,0,0);
	glVertex3f(-13.5,-5,-25);
	glVertex3f(-13.5,3,-25);
	glEnd();

    glBegin(GL_POLYGON);//toko 4
    glColor3ub(80,150,10);
	glVertex3f(-5,5,-40);
	glVertex3f(10,5,-40);
	glVertex3f(10,5,-25);
	glVertex3f(-5,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//toko 4
    glColor3ub(80,150,10);
	glVertex3f(-5,-5,-25);
	glVertex3f(10,-5,-25);
	glVertex3f(10,5,-25);
	glVertex3f(-5,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//toko 4
    glColor3ub(80,150,10);
	glVertex3f(10,-5,-25);
	glVertex3f(10,-5,-40);
	glVertex3f(10,5,-40);
	glVertex3f(10,5,-25);
	glEnd();
    glBegin(GL_POLYGON);//pintu toko 4
    glColor3ub(100,125,125);
	glVertex3f(-2,-5,-25);
	glVertex3f(8,-5,-25);
	glVertex3f(8,3,-25);
	glVertex3f(-2,3,-25);
	glEnd();
    glBegin(GL_LINES);//pintu toko 4
    glColor3ub(0,0,0);
	glVertex3f(2.5,-5,-25);
	glVertex3f(2.5,3,-25);
	glEnd();
	 glBegin(GL_POLYGON);//karpet
    glColor3ub(100,200,255);
	glVertex3f(-40,-5,20);
	glVertex3f(-30,-5,20);
	glVertex3f(-30,-5,5);
	glVertex3f(-40,-5,5);
	glEnd();

    glBegin(GL_POLYGON);//SOFA 1 ALAS
    glColor3ub(100,5,5);
	glVertex3f(-40,-3,20);
	glVertex3f(-30,-3,20);
	glVertex3f(-30,-3,17);
	glVertex3f(-40,-3,17);
	glEnd();
    glBegin(GL_POLYGON);//SOFA 1 DEPAN
    glColor3ub(100,5,5);
	glVertex3f(-40,-5,17);
	glVertex3f(-30,-5,17);
	glVertex3f(-30,-3,17);
	glVertex3f(-40,-3,17);
	glEnd();
    glBegin(GL_POLYGON);//SOFA 1 BELAKANG
    glColor3ub(100,5,5);
	glVertex3f(-40,-5,20);
	glVertex3f(-30,-5,20);
	glVertex3f(-30,0,20);
	glVertex3f(-40,0,20);
	glEnd();

    glBegin(GL_POLYGON);//MEJA
    glColor3ub(100,5,5);
	glVertex3f(-40,-3,15);
	glVertex3f(-30,-3,15);
	glVertex3f(-30,-3,10);
	glVertex3f(-40,-3,10);
	glEnd();
    glBegin(GL_POLYGON);//MEJA
    glColor3ub(100,5,5);
	glVertex3f(-40,-5,15);
	glVertex3f(-30,-5,15);
	glVertex3f(-30,-3,15);
	glVertex3f(-40,-3,15);
	glEnd();
    glBegin(GL_POLYGON);//MEJA
    glColor3ub(100,5,5);
	glVertex3f(-40,-5,10);
	glVertex3f(-30,-5,10);
	glVertex3f(-30,-3,10);
	glVertex3f(-40,-3,10);
	glEnd();

    glBegin(GL_POLYGON);//SOFA
    glColor3ub(100,5,5);
	glVertex3f(-40,-3,8);
	glVertex3f(-30,-3,8);
	glVertex3f(-30,-3,5);
	glVertex3f(-40,-3,5);
	glEnd();
	    glBegin(GL_POLYGON);//SOFA
    glColor3ub(100,5,5);
	glVertex3f(-40,-5,8);
	glVertex3f(-30,-5,8);
	glVertex3f(-30,-3,8);
	glVertex3f(-40,-3,8);
	glEnd();
	    glBegin(GL_POLYGON);//SOFA
    glColor3ub(100,5,5);
	glVertex3f(-40,-5,5);
	glVertex3f(-30,-5,5);
	glVertex3f(-30,0,5);
	glVertex3f(-40,0,5);
	glEnd();

//---------------------------------
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

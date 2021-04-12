#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<windows.h>
// Visual C++ 2015  ±iÖö«Â B03505002
double total_time = 30.0;
double stay_time = 3.0;
GLubyte Team[15] = { 'T','H','E',' ','G','R','E','E','N',' ','T','E','A','M' };
GLubyte Win[8] = { 'W',' ','I',' ','N','!','!','!' };
GLubyte ball[10] = { 'V','O','L','L','E','Y', 'B','A','L','L' };

double pi = acos(-1);
double ch = pi / 180.0;
double s45 = sin(pi / 4), c45 = cos(pi / 4), s30 = sin(pi / 6), c30 = cos(pi / 6), s20 = sin(pi / 9), c20 = cos(pi / 9);
double s15 = sin(pi / 12), c15 = cos(pi / 12), s9 = sin(pi / 20), c9 = cos(pi / 20);

void DrawCircle(float p[2], float ra, float c[3], int mode, int l, int w);
void DrawCircle(float x, float y, float ra, float c[3], int mode, int l, int w);
void DrawCircle(double x, double y, double ra, double r, double g, double b, int mode, int l, int w);
void DrawCircle(double x, double y, double ra, int mode, int l);

void DrawRect(float p[2], float s, float l, float h, float c[3], int mode, int w);
void DrawRect(float x, float y, float l, float h, float c[3], int mode, int w);
void DrawRect(float p[2], float o[2], float s, float l, float h, float c[3], int mode, int w);
void DrawRect(double x, double y, double l, double h, double r, double g, double b, int mode, int w);

void DrawMan(double a[22]);
void DrawMan1(double xx, double yy, int mode, int no);
void DrawMan2(double xx, double yy, int mode, int no);
void DrawMan1(double xx, double yy, int mode1, int mode2, int no);

void getPA(double xx, double yy, int mode, double* p);
void getPB(double xx, double yy, int mode, double* p);

void Ground(double t);
void ManA1(double t);
void ManA2(double t);
void ManA3(double t);
void ManA4(double t);
void ManA5(double t);
void ManA6(double t);
void ManB1(double t);
void ManB2(double t);
void ManB3(double t);
void ManB4(double t);
void ManB5(double t);
void ManB6(double t);
void Ball(double t);
void Word(double t);
void End(double t);

void Volley(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	const double tt = (glutGet(GLUT_ELAPSED_TIME) / 1000.0);
	const double t = tt - 3;
	printf("%f\n",t);
	if (t < 0)
	{
		glClearColor(0.0, 0.0, 0.0, 0.0);
		
		DrawRect(300, 220.0, 600.0, 350.0, 1.0, 1.0, 1.0, 2, 10);
		DrawCircle(450.0, 440.0, 100.0, 0.0, 0.0, 1.0, 1, 64, 10);
		DrawCircle(520.0, 350.0, 100.0, 1.0, 1.0, 0.0, 1, 64, 10);
		DrawCircle(600.0, 440.0, 100.0, 0.0, 0.0, 0.0, 1, 64, 10);
		DrawCircle(680.0, 350.0, 100.0, 0.0, 1.0, 0.0, 1, 64, 10);
		DrawCircle(750.0, 440.0, 100.0, 1.0, 0.0, 0.0, 1, 64, 10);
		GLint xl = 50, yl = 150;
		for (int i = 1; i < 11; i++)
		{
			glColor3f(1.0*(i / 11.0), 1.0*((11 - i) / 11.0), 0.0);
			glRasterPos2i(325+xl*i, yl);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, ball[i - 1]);
		}

		glFlush();

	}
	if(t>0 && t < total_time)
	{
		glClearColor(1.0, 1.0, 1.0, 0.0);
		Ground(t);
		ManA1(t);
		ManA2(t);
		ManA3(t);
		ManA4(t);
		ManA5(t);
		ManA6(t);
		ManB2(t);
		ManB3(t);
		ManB4(t);
		ManB5(t);
		ManB6(t);
		ManB1(t);
		Ball(t);
		Word(t);
	}
	if (t > total_time)
	{
		End(t);
	}
	
	glutSwapBuffers();

}

static void idle(void);
static void resize(int width, int height);
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1200, 600);
	glutCreateWindow("B03505002 ±iÖö«Â Moving Square");

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1200.0, 0.0, 600.0);

	glEnable(GL_LINE_SMOOTH);
	glutReshapeFunc(resize);
	glutIdleFunc(idle);
	glutDisplayFunc(Volley);

	glutMainLoop();
}
static void idle(void)
{
	glutPostRedisplay();
}
static void resize(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}



void Ground(double t)
{
	if (t < total_time)
	{
		DrawRect(0.0, 50.0, 1200.0, 2.0, 0.0, 0.0, 0.0, 2, 10);
		DrawRect(150.0, 50.0, 900.0, 5.0, 0.0, 0.0, 0.0, 2, 10);
		DrawRect(450.0, 50.0, 300.0, 5.0, 0.3, 0.3, 0.3, 2, 10);

		DrawRect(595.0, 50.0, 10.0, 180.0, 0.2, 0.2, 0.6, 2, 10);
		DrawCircle(600.0, 230.0, 5.0, 0.2, 0.2, 0.6, 2, 16, 1);
	}
}
void ManA1(double t)
{
	glLineWidth(4);
	glColor3d(0.0, 0.0, 1.0 );

	double t1,t2 ;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22],p1[22],p2[22];
	
	if (t < 0.25)
	{
		t2 = t * 4;
		t1 = (1 - t2);
		getPA( 70.0, 53.0, 1, p1);
		getPA(150.0, 53.0, 2, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 0.5)
	{
		t2 = (t - 0.25) * 4;
		t1 = (1 - t2);
		getPA(150.0, 53.0, 2, p1);
		getPA(200.0, 53.0, 22, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 0.5 + stay_time)
	{
		getPA(200.0, 53.0, 22, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 1 + stay_time)
	{
		t2 = (t-0.5 - stay_time) * 2;
		t1 = (1 - t2);
		getPA(200.0, 53.0, 22, p1);
		getPA(220.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 11.0 + 2 * stay_time)
	{
		getPA(220.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 11.2 + 2 * stay_time)
	{
		t2 = (t - 11 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPA(220.0, 53.0, 1, p1);
		getPA(220.0, 53.0, 10, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 11.2 + 3 * stay_time)
	{
		getPA(220.0, 53.0, 10, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 11.4 + 3 * stay_time)
	{
		t2 = (t - 11.2 - 3 * stay_time) * 5;
		t1 = (1 - t2);
		getPA(220.0, 53.0, 10, p1);
		getPA(220.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	
	else if(t < total_time)
	{
		getPA(220.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManA2(double t) 
{
	glLineWidth(4);
	glColor3d(1.0, 2.0 / 8.0, 2.0 / 8.0);

	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 5.7 + 2 * stay_time)
	{
		getPA(490.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 5.9 + 2 * stay_time)
	{
		t2 = (t - 5.7 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPA(490.0, 53.0, 1, p1);
		getPA(490.0, 53.0, 202, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 6.0 + 2 * stay_time)
	{
		t2 = (t - 5.9 - 2 * stay_time) * 10;
		t1 = (1 - t2);
		getPA(490.0, 53.0, 202, p1);
		getPA(490.0, 53.0, 222, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 6.2 + 2 * stay_time)
	{
		t2 = (t - 6.0 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPA(490.0, 53.0, 222, p1);
		getPA(490.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < total_time)
	{
		getPA(490.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManA3(double t)
{
	glLineWidth(4);
	glColor3d(1.0, 3.0 / 8.0, 3.0 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 10 + 2 * stay_time)
	{
		getPA(480.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 10.2 + 2 * stay_time)
	{
		t2 = (t - 10 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPA(480.0, 53.0, 1, p1);
		getPA(480.0, 53.0, 0, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 10.4 + 2 * stay_time)
	{
		t2 = (t - 10.2 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPA(480.0, 53.0, 0, p1);
		getPA(480.0, 53.0, 7, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 10.6 + 2 * stay_time)
	{
		t2 = (t - 10.4 - 2 * stay_time) * 2;
		t1 = (1 - t2);
		getPA(480.0, 53.0, 7, p1);
		getPA(480.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < total_time)
	{
		getPA(480.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManA4(double t)
{
	glLineWidth(4);
	glColor3d(1.0, 4.0 / 8.0, 4.0 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 0)
	{
		
	}
	
	else if (t < total_time)
	{
		getPA(300.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManA5(double t)
{
	glLineWidth(4);
	glColor3d(1.0, 5.0 / 8.0, 5.0 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 0)
	{

	}
	else if (t < total_time)
	{
		getPA(320.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManA6(double t)
{
	glLineWidth(4);
	glColor3d(1.0, 6.0 / 8.0, 6.0 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 4.8 + stay_time)
	{
		getPA(540.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 5 + stay_time)
	{
		t2 = (t - 4.8 - stay_time) * 5;
		t1 = (1 - t2);
		getPA(540.0, 53.0, 1, p1);
		getPA(540.0, 53.0, 9, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 5 + 2*stay_time)
	{
		t2 = (t - 5 -  stay_time) * 5;
		t1 = (1 - t2);
		getPA(540.0, 53.0, 9, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 5.2 + 2 * stay_time)
	{
		t2 = (t - 5 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPA(540.0, 53.0, 9, p1);
		getPA(540.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 5.6 + 2 * stay_time)
	{
		t2 = (t - 5.2 - 2 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPA(540.0, 53.0, 1, p1);
		getPA(540.0, 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 6 + 2 * stay_time)
	{
		t2 = (t - 5.6 - 2 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPA(540.0, 53.0, 11, p1);
		getPA(p1[20], 53.0, 12, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 6.4 + 2 * stay_time)
	{
		t2 = (t - 6 - 2 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPA(510.0, 53.0, 12, p1);
		getPA(p1[16], 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 6.8 + 2 * stay_time)
	{
		t2 = (t - 6.4 - 2 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPA(480.0, 53.0, 11, p1);
		getPA(p1[20], 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < total_time)
	{
		getPA(450.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}


void ManB1(double t)
{
	glLineWidth(4);
	glColor3d(1.0 / 8.0, 1.0, 1.0 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 10.1 + 2 * stay_time)
	{
		getPB(650.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 10.5 + 2 * stay_time)
	{
		t2 = (t - 10.1 - 2 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPB(650.0, 53.0, 1, p1);
		getPB(650.0, 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 10.9 + 2 * stay_time)
	{
		t2 = (t - 10.5 - 2 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPB(650.0, 53.0, 11, p1);
		getPB(p1[20], 53.0, 12, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 11.2 + 2 * stay_time)
	{
		t2 = (t - 10.9 - 2 * stay_time) * (1.0/0.3);
		t1 = (1 - t2);
		getPB(680.0, 53.0, 12, p1);
		getPB(p1[16], 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 11.2 + 3 * stay_time)
	{
		getPB(710.0, 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 11.7 + 3 * stay_time)
	{
		t2 = (t - 11.2 - 3 * stay_time) * 2;
		t1 = (1 - t2);
		getPB(710.0, 53.0, 11, p1);
		getPB(p1[20], 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 12.2 + 3 * stay_time)
	{
		t2 = (t - 11.7 - 3 * stay_time) * 2;
		t1 = (1 - t2);
		getPB(740.0, 53.0, 1, p1);
		getPB(740.0, 53.0, -1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 12.2 + 4 * stay_time)
	{
		getPB(740.0, 53.0, -1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 12.7 + 4 * stay_time)
	{
		t2 = (t - 12.2 - 4 * stay_time) * 2;
		t1 = (1 - t2);
		getPB(740.0, 53.0, -1, p1);
		getPB(740.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < total_time)
	{
		getPB(740.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManB2(double t)
{
	glLineWidth(4);
	glColor3d(2.0 / 8.0, 1.0, 2.0 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 2.9 + stay_time)
	{
		getPB(690.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 3.1 + stay_time)
	{
		t2 = (t - 2.9 - stay_time) * 5;
		t1 = (1 - t2);
		getPB(690.0, 53.0, 1, p1);
		getPB(690.0, 53.0, 5, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 3.2 + stay_time)
	{
		t2 = (t - 3.1 - stay_time) * 10;
		t1 = (1 - t2);
		getPB(690.0, 53.0, 5, p1);
		getPB(690.0, 53.0, 6, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 3.4 + stay_time)
	{
		t2 = (t - 3.2 - stay_time) * 5;
		t1 = (1 - t2);
		getPB(690.0, 53.0, 6, p1);
		getPB(690.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < total_time)
	{
		getPB(690.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManB3(double t)
{
	glLineWidth(4);
	glColor3d(3.0 / 8.0, 1.0, 3.0 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 3.6 + stay_time)
	{
		getPB(720.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 3.7 + stay_time)
	{
		t2 = (t - 3.6 - stay_time) * 10;
		t1 = (1 - t2);
		getPB(720.0, 53.0, 1, p1);
		getPB(720.0, 53.0, 0, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 3.8 + stay_time)
	{
		t2 = (t - 3.7 - stay_time) * 10;
		t1 = (1 - t2);
		getPB(720.0, 53.0, 0, p1);
		getPB(720.0, 53.0, 2, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 4.0 + stay_time)
	{
		t2 = (t - 3.8 - stay_time) * 5;
		t1 = (1 - t2);
		getPB(720.0, 53.0, 2, p1);
		getPB(720.0, 53.0, 22, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 4.1 + stay_time)
	{
		t2 = (t - 4.0 - stay_time) * 10;
		t1 = (1 - t2);
		getPB(720.0, 53.0, 22, p1);
		getPB(720.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < total_time)
	{
		getPB(720.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManB4(double t)
{
	glLineWidth(4);
	glColor3d(4.0 / 8.0, 1.0, 4.0 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 8 + 2 * stay_time)
	{
		getPB(825.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}

	else if (t < 8.2 + 2 * stay_time)
	{
		t2 = (t - 8.0 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPB(825.0, 53.0, 1, p1);
		getPB(825.0, 53.0, 5, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 8.3 + 2 * stay_time)
	{
		t2 = (t - 8.2 - 2 * stay_time) * 10;
		t1 = (1 - t2);
		getPB(825.0, 53.0, 5, p1);
		getPB(825.0, 53.0, 6, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 8.5 + 2 * stay_time)
	{
		t2 = (t - 8.3 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPB(825.0, 53.0, 6, p1);
		getPB(825.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < total_time)
	{
		getPB(825.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManB5(double t)
{
	glLineWidth(4);
	glColor3d(5.0 / 8.0, 1.0, 5.0 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];

	if (t < 6.8 + 2 * stay_time)
	{
		getPB(1025.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 7.2 + 2 * stay_time)
	{
		t2 = (t - 6.8 - 2 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPB(1025.0, 53.0, 1, p1);
		getPB(950.0, 53.0, 8, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 7.6 + 2 * stay_time)
	{
		t2 = (t - 7.2 - 2 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPB(950.0, 53.0, 8, p1);
		getPB(930.0, 53.0, 88, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 8.1 + 2 * stay_time)
	{
		t2 = (t - 7.6 - 2 * stay_time) * 2;
		t1 = (1 - t2);
		getPB(930.0, 53.0, 88, p1);
		getPB(930.0, 53.0, 888, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 9.1 + 2 * stay_time)
	{
		t2 = (t - 8.1 - 2 * stay_time) * 1;
		t1 = (1 - t2);
		getPB(930.0, 53.0, 888, p1);
		getPB(910.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < total_time)
	{
		getPB(910.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void ManB6(double t)
{
	glLineWidth(4);
	glColor3d(2.5 / 8.0, 1.0, 2.5 / 8.0);
	double t1, t2;
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double man[22], p1[22], p2[22];
	//965
	if (t < 0.5 + stay_time)
	{
		getPB(900.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 0.7 + stay_time)
	{
		t2 = (t-0.5 - stay_time) * 5;
		t1 = (1 - t2);
		getPB(900.0, 53.0, 1, p1);
		getPB(900.0, 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 1.1 + stay_time)
	{
		t2 = (t - 0.7 - stay_time) * 2.5;
		t1 = (1 - t2);
		getPB(900.0, 53.0, 11, p1);
		getPB(p1[20], 53.0, 12, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 1.5 + stay_time)
	{
		t2 = (t - 1.1 - stay_time) * 2.5;
		t1 = (1 - t2);
		getPB(930.0, 53.0, 12, p1);
		getPB(p1[16], 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 1.9 + stay_time)
	{
		t2 = (t - 1.5 - stay_time) * 2.5;
		t1 = (1 - t2);
		getPB(960.0, 53.0, 11, p1);
		getPB(p1[20], 53.0,12, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 2.0 + stay_time)
	{
		t2 = (t - 1.9 - stay_time) * 10;
		t1 = (1 - t2);
		getPB(990.0, 53.0, 12, p1);
		getPB(990, 53.0, 3, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 2.2 + stay_time)
	{
		t2 = (t - 2.0 - stay_time) * 5;
		t1 = (1 - t2);
		getPB(990.0, 53.0, 3, p1);
		getPB(990.0, 53.0, 4, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 2.4 + stay_time)
	{
		t2 = (t - 2.2 - stay_time) * 5;
		t1 = (1 - t2);
		getPB(990.0, 53.0, 4, p1);
		getPB(990.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 7.6 + 2 * stay_time)
	{
		getPB(990, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 7.8 + 2 * stay_time)
	{
		t2 = (t - 7.6 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPB(990.0, 53.0, 1, p1);
		getPB(960.0, 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 8 + 2 * stay_time)
	{
		t2 = (t - 7.8 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPB(960.0, 53.0, 11, p1);
		getPB(p1[16]-30, 53.0, 12, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 8.2 + 2 * stay_time)
	{
		t2 = (t - 8 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPB(930.0, 53.0, 12, p1);
		getPB(p1[20]-30, 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 8.4 + 2 * stay_time)
	{
		t2 = (t - 8.2 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPB(900.0, 53.0, 11, p1);
		getPB(p1[16]-30, 53.0, 12, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 8.6 + 2 * stay_time)
	{
		t2 = (t - 8.4 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPB(870.0, 53.0, 12, p1);
		getPB(p1[20]-30, 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 8.8 + 2 * stay_time)
	{
		t2 = (t - 8.6 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		getPB(840.0, 53.0, 11, p1);
		getPB(p1[16]-30, 53.0, 12, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 9.3 + 2 * stay_time)
	{
		t2 = (t - 8.8 - 2 * stay_time) * 2;
		t1 = (1 - t2);
		getPB(810.0, 53.0, 12, p1);
		getPB(780.0, 53.0, 202, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 9.8 + 2 * stay_time)
	{
		t2 = (t - 9.3 - 2 * stay_time) * 2;
		t1 = (1 - t2);
		getPB(780.0, 53.0, 202, p1);
		getPB(750.0, 53.0, 222, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 10.3 + 2 * stay_time)
	{
		t2 = (t - 9.8 - 2 * stay_time) * 2;
		t1 = (1 - t2);
		getPB(750.0, 53.0, 222, p1);
		getPB(730.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 10.7 + 2 * stay_time)
	{
		t2 = (t - 10.3 - 2 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPB(730.0, 53.0, 1, p1);
		getPB(730.0, 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 11.2 + 2 * stay_time)
	{
		t2 = (t - 10.7 - 2 * stay_time) * 2;
		t1 = (1 - t2);
		getPB(730.0, 53.0, 11, p1);
		getPB(p1[20], 53.0, 12, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 11.2 + 3 * stay_time)
	{
		getPB(760.0, 53.0, 12, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 11.5 + 3 * stay_time)
	{
		t2 = (t - 11.2 - 3 * stay_time) * (1.0/0.3);
		t1 = (1 - t2);
		getPB(760.0, 53.0, 12, p1);
		getPB(p1[16], 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 11.9 + 3 * stay_time)
	{
		t2 = (t - 11.5 - 3 * stay_time) * 2.5;
		t1 = (1 - t2);
		getPB(790.0, 53.0, 11, p1);
		getPB(p1[20], 53.0, 12, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 12.2 + 3 * stay_time)
	{
		t2 = (t - 11.9 - 3 * stay_time) * (1.0/0.3);
		t1 = (1 - t2);
		getPB(820.0, 53.0, 12, p1);
		getPB(p1[16], 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}
	else if (t < 12.2 + 4 * stay_time)
	{
		getPB(850.0, 53.0, 11, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	else if (t < 12.7 + 4 * stay_time)
	{
		t2 = (t - 12.2 - 4 * stay_time) * 2;
		t1 = (1 - t2);
		getPB(850.0, 53.0, 11, p1);
		getPB(p1[20], 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = t1*(p1[i]) + t2*(p2[i]); }
	}

	else if (t < total_time)
	{
		getPB(880.0, 53.0, 1, p2);
		for (int i = 0; i < 22; i++) { man[i] = p2[i]; }
	}
	DrawMan(man);
}
void Ball(double t)
{
	glLineWidth(4);
	
	double t1, t2;
	double x, y, p1[22],p2[22];
	if (t < 0.5)
	{
		t2 = t  * 2;
		t1 = (1 - t2);
		getPA(70.0, 53.0, 1, p1);
		getPA(200.0, 53.0, 22, p2);
		x = t1*(p1[12]) + t2*(p2[12]+10);
		y = p1[13] + p2[13] * sin(t2*pi*0.85);
	}
	else if (t < 0.5 + stay_time)
	{
		x = 250;
		y = 240;
	}
	else if (t < 2.0 + stay_time)
	{
		t2 = (t-0.5 - stay_time) * (1/1.5);
		t1 = (1 - t2);
		getPA(200.0, 53.0, 22, p1);
		x = t1*(p1[12]) + t2*(920) + 15;
		y = p1[13] + (150+p1[13]) * sin(t2*pi*1.08) + 30;
	}
	else if (t < 3.0 + stay_time)
	{
		t2 = (t - 2.0 - stay_time) * 1;
		t1 = (1 - t2);
		getPB(990.0, 53.0, 3, p1);
		x = t1*(p1[12]) + t2*(650)+10;
		y = p1[13] + 200 * sin(t2*pi*0.87) +25;
	}
	else if (t < 4.0 + stay_time)
	{
		t2 = (t - 3.0 - stay_time) * 1;
		t1 = (1 - t2);
		x = t1*(650) + t2*(665) + 10;
		y = 150 + 200 * sin(t2*pi*0.95) + 25;
	}
	else if (t < 5.0 + stay_time)
	{
		t2 = (t - 4.0 - stay_time) * 1;
		t1 = (1 - t2);
		x = t1*(675) + t2*(550);
		y = 205 + 110 * sin(t2*pi*1) + 25;
	}
	else if (t < 5.0 + 2 * stay_time)
	{
		x = 550;
		y = 230;
	}
	else if (t < 6.0 + 2 * stay_time)
	{
		t2 = (t - 5.0 - 2 * stay_time) * 1;
		t1 = (1 - t2);
		x = t1*(550) + t2*(550);
		y = 205 + 110 * sin(t2*pi*1) + 25;
	}
	else if (t < 7.0 + 2 * stay_time)
	{
		t2 = (t - 6.0 - 2 * stay_time) * 1;
		t1 = (1 - t2);
		x = t1*(550) + t2*(800);
		y = 230 + 150 * sin(t2*pi * 1) ;
	}
	else if (t < 7.2 + 2 * stay_time)
	{
		t2 = (t - 7.0 - 2 * stay_time) * 5;
		t1 = (1 - t2);
		x = t1*(800) + t2*(860);
		y = t1*(230) + t2*(85);
	}
	else if (t < 8.2 + 2 * stay_time)
	{
		t2 = (t - 7.2 - 2 * stay_time) * 1;
		t1 = (1 - t2);
		x = t1*(860) + t2*(800);
		y = 85 + 200 * sin(t2*pi * 0.85);
	}
	else if (t < 9.7 + 2 * stay_time)
	{
		t2 = (t - 8.2 - 2 * stay_time) * (1/1.5);
		t1 = (1 - t2);
		x = t1*(800) + t2*(720);
		y = 175 + 150 * sin(t2*pi * 0.85);
	}
	else if (t < 11.2 + 2 * stay_time)
	{
		t2 = (t - 9.7 - 2 * stay_time) * (1/1.5);
		t1 = (1 - t2);
		x = t1*(715) + t2*(260);
		y = 80 + 210 * sin(t1*pi * 0.7);
	}
	else if (t < 11.2 + 3 * stay_time)
	{
		x = 260;
		y = 80 ;
	}
	else if (t < 12.2 + 3 * stay_time)
	{
		t2 = (t - 11.2 - 3 * stay_time) * 1;
		t1 = (1 - t2);
		x = t1*(260) + t2*(720);
		y = 80 + 250 * sin(t2*pi * 0.85);
	}
	else if (t < 12.2 + 4 * stay_time)
	{
		x = 720;
		y = 195;
	}
	else if (t < 13.2 + 4 * stay_time)
	{
		t2 = (t - 12.2 - 4 * stay_time) * 1;
		t1 = (1 - t2);
		x = t1*(720) + t2*(570);
		y = 195 + 65 * sin(t2*pi * 0.7);
	}
	else if (t < 13.4 + 4 * stay_time)
	{
		t2 = (t - 13.2 - 4 * stay_time) * 5;
		t1 = (1 - t2);
		x = 570;
		y = t1*(195) + t2*(70);
	}
	else if (t < total_time)
	{
		x = 570.0;
		y = 70.0;
	}
	glColor3d(0.0, 0.0, 1.0);
	DrawCircle(x, y, 15, 2, 32);
	glColor3d(1.0, 1.0, 0.0);
	DrawCircle(x, y, 5, 2, 32);
}
void Word(double t)
{
	GLint xl = 50, yl = 500;
	if (t>0.5 && t < 0.5 + stay_time)
	{
		GLubyte A[17] = { 'G','I','F','T',' ','F','R','O','M',' ','T','H','E',' ','S','U','N' };
		for (int i = 1; i < 18; i++)
		{
			glColor3f(1.0, 1.0*((17 - i) / 17.0), 0.0);
			glRasterPos2i(100 + xl*i, yl);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, A[i - 1]);
		}
	}
	else if (t > 5.0 + stay_time &&t < 5.0 + 2 * stay_time)
	{
		GLubyte A[9] = { 'I','R','O','N',' ','H','E','A','D' };
		for (int i = 1; i < 10; i++)
		{
			glColor3f(1.0*((9 - i) / 11.0), 1.0*((9 - i) / 11.0), 1.0*((9 - i) / 11.0));
			glRasterPos2i(100 + xl*i, yl);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, A[i - 1]);
		}
	}
	else if (t > 11.2 + 2 * stay_time && t < 11.2 + 3 * stay_time)
	{
		GLubyte A[17] = { 'G','O','L','D','E','N',' ','R','I','G','H','T',' ','F','O','O','T' };
		for (int i = 1; i < 18; i++)
		{
			glColor3f(0.5, 0.5, 1.0*( i / 30.0));
			glRasterPos2i(100 + xl*i, yl);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, A[i - 1]);
		}
	}
	else if (t > 12.2 + 3 * stay_time && t < 12.2 + 4 * stay_time)
	{
		GLubyte A[14] = { 'F','I','N','I','S','H','I','N','G',' ','M','O','V','E' };
		for (int i = 1; i < 15; i++)
		{
			glColor3f(1.0*((i+15) / 30.0), 0.0, 0.0);
			glRasterPos2i(100 + xl*i, yl);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, A[i - 1]);
		}
	}
	else if (t > 13.4 + 4 * stay_time && t < total_time)
	{
		for (int i = 1; i < 16; i++)
		{
			glColor3f(0.0,1.0*((i + 15) / 30.0) , 0.0);
			glRasterPos2i(100 + xl*i, yl);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Team[i - 1]);
		}
		for (int i = 1; i < 9; i++)
		{
			glColor3f(1.0*((i + 15) / 30.0), 1.0*((i + 15) / 30.0), 0.0);
			glRasterPos2i(100 + xl*i, yl-100);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Win[i - 1]);
		}
	}
	glFlush();
}
void End(double t)
{
	
	GLint xl = 50, yl = 500;
	for (int i = 1; i < 16; i++)
	{
		glColor3f(0.0, 1.0*((i + 15) / 30.0), 0.0);
		glRasterPos2i(100 + xl*i, yl);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Team[i - 1]);
	}
	for (int i = 1; i < 9; i++)
	{
		glColor3f(1.0*((i + 15) / 30.0), 1.0*((i + 15) / 30.0), 0.0);
		glRasterPos2i(100 + xl*i, yl - 100);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, Win[i - 1]);
	}
	glFlush();
	double man[22], p[22];
	glColor3f(1.0 / 8.0, 1.0, 1.0 / 8.0);
	getPB(650.0, 50.0*(sin(t)*sin(t))+100, 1000, p);
	DrawMan(p);
	glColor3f(2.0 / 8.0, 2.0, 2.0 / 8.0);
	getPB(675.0, 50.0*(sin(t)*sin(t))+177, 1000, p);
	DrawMan(p);
	glColor3f(3.0 / 8.0, 3.0, 3.0 / 8.0);
	getPB(625.0, 50.0*(sin(t)*sin(t))+158, 1000, p);
	DrawMan(p);
	glColor3f(4.0 / 8.0, 4.0, 4.0 / 8.0);
	getPB(525.0, 50.0*(sin(t)*sin(t))+194, 1000, p);
	DrawMan(p); 
	glColor3f(5.0 / 8.0, 5.0, 5.0 / 8.0);
	getPB(500.0, 50.0*(sin(t)*sin(t))+149, 1000, p);
	DrawMan(p);
	glColor3f(2.5 / 8.0, 1.0, 2.5 / 8.0);
	getPB(590.0, 50.0*(sin(t)*sin(t))+147, 1000, p);
	DrawMan(p);

	
}


void DrawCircle(float p[2], float ra, float c[3], int mode, int l, int w)
{
	glLineWidth(w);
	glColor3f(c[0], c[1], c[2]);
	if (mode == 1) { glBegin(GL_LINE_LOOP); }
	else { glBegin(GL_TRIANGLE_FAN); }

	for (int i = 0; i < l; i++)
	{
		glVertex2i(p[0] + ra*cos(((2 * pi) / l)*i), p[1] + ra*sin(((2 * pi) / l)*i));
	}
	glEnd();
	glFlush();
}
void DrawCircle(float x, float y, float ra, float c[3], int mode, int l, int w)
{
	glLineWidth(w);
	glColor3f(c[0], c[1], c[2]);
	if (mode == 1) { glBegin(GL_LINE_LOOP); }
	else { glBegin(GL_TRIANGLE_FAN); }

	for (int i = 0; i < l; i++)
	{
		glVertex2i(x + ra*cos(((2 * pi) / l)*i), y + ra*sin(((2 * pi) / l)*i));
	}
	glEnd();
	glFlush();
}
void DrawCircle(double x, double y, double ra, double r, double g, double b, int mode, int l, int w)
{
	glLineWidth(w);
	glColor3d(r, g, b);
	if (mode == 1)
	{
		glBegin(GL_LINE_LOOP);
	}
	else
	{
		glBegin(GL_TRIANGLE_FAN);
	}

	for (int i = 0; i < l; i++)
	{
		glVertex2i(x + ra*cos(((2 * pi) / l)*i), y + ra*sin(((2 * pi) / l)*i));
	}
	glEnd();
	glFlush();
}
void DrawCircle(double x, double y, double ra, int mode, int l)
{
	if (mode == 1)
	{
		glBegin(GL_LINE_LOOP);
	}
	else
	{
		glBegin(GL_TRIANGLE_FAN);
	}

	for (int i = 0; i < l; i++)
	{
		glVertex2i(x + ra*cos(((2 * pi) / l)*i), y + ra*sin(((2 * pi) / l)*i));
	}
	glEnd();
	glFlush();
}

void DrawRect(float p[2], float s, float l, float h, float c[3], int mode, int w)
{
	s = s * (pi / 180);
	glLineWidth(w);
	glColor3f(c[0], c[1], c[2]);

	if (mode == 1) { glBegin(GL_LINE_LOOP); }
	else if (mode == 2) { glBegin(GL_TRIANGLE_FAN); }

	float a, b;
	for (int i = 1; i < 5; i++)
	{
		if (i == 1) { a = p[0] + (l / 2); b = p[1] + (h / 2); }
		else if (i == 2) { a = p[0] + (l / 2); b = p[1] - (h / 2); }
		else if (i == 3) { a = p[0] - (l / 2); b = p[1] + (h / 2); }
		else if (i == 4) { a = p[0] - (l / 2); b = p[1] - (h / 2); }
		glVertex2f(p[0] + (a - p[0])*cos(s) - (b - p[1])*sin(s), p[1] + (a - p[0])*sin(s) + (b - p[1])*cos(s));
	}
	glEnd();
	glFlush();
}
void DrawRect(float x, float y, float l, float h, float c[3], int mode, int w)
{
	glLineWidth(w);
	glColor3f(c[0], c[1], c[2]);
	if (mode == 1)
	{
		glBegin(GL_LINE_LOOP);
	}
	else
	{
		glBegin(GL_TRIANGLE_FAN);
	}

	glVertex2f(x, y);
	glVertex2f(x + l, y);
	glVertex2f(x + l, y + h);
	glVertex2f(x, y + h);

	glEnd();
	glFlush();
}
void DrawRect(float p[2], float o[2], float s, float l, float h, float c[3], int mode, int w)
{
	glLineWidth(w);
	glColor3f(c[0], c[1], c[2]);
	if (mode == 1)
	{
		glBegin(GL_LINE_LOOP);
	}
	else
	{
		glBegin(GL_TRIANGLE_FAN);
	}

	glVertex2f(o[0] + (p[0] - o[0])*cos(s) - (p[1] - o[1])*sin(s), o[1] + (p[0] - o[0])*sin(s) + (p[1] - o[1])*cos(s));
	glVertex2f(o[0] + (p[0] + l - o[0])*cos(s) - (p[1] - o[1])*sin(s), o[1] + (p[0] + l - o[0])*sin(s) + (p[1] - o[1])*cos(s));
	glVertex2f(o[0] + (p[0] + l - o[0])*cos(s) - (p[1] + h - o[1])*sin(s), o[1] + (p[0] + l - o[0])*sin(s) + (p[1] + h - o[1])*cos(s));
	glVertex2f(o[0] + (p[0] - o[0])*cos(s) - (p[1] + h - o[1])*sin(s), o[1] + (p[0] - o[0])*sin(s) + (p[1] + h - o[1])*cos(s));

	glEnd();
	glFlush();
}
void DrawRect(double x, double y, double l, double h, double r, double g, double b, int mode, int w)
{
	glLineWidth(w);
	glColor3d(r, g, b);
	if (mode == 1)
	{
		glBegin(GL_LINE_LOOP);
	}
	else
	{
		glBegin(GL_TRIANGLE_FAN);
	}

	glVertex2d(x, y);
	glVertex2d(x + l, y);
	glVertex2d(x + l, y + h);
	glVertex2d(x, y + h);

	glEnd();
	glFlush();
}

void DrawMan(double a[22])
{
	glBegin(GL_LINES);
	glVertex2d(a[0], a[1]); glVertex2d(a[4], a[5]);
	glEnd();
	DrawCircle(a[4], a[5], 17, 2, 32);
	glBegin(GL_LINE_STRIP);
	glVertex2d(a[8], a[9]); glVertex2d(a[6], a[7]); glVertex2d(a[2], a[3]); glVertex2d(a[10], a[11]); glVertex2d(a[12], a[13]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(a[16], a[17]); glVertex2d(a[14], a[15]); glVertex2d(a[0], a[1]); glVertex2d(a[18], a[19]); glVertex2d(a[20], a[21]);
	glEnd();
	glFlush();
}
//double b1x, b1y, b2x, b2y, b3x, b3y, lax, lay, rax, ray, lhx, lhy, rhx, rhy, lnx, lny, rnx, rny, lfx, lfy, rfx, rfy;
//b1x = a[0]; b1y = a[1];
//b2x = a[2]; b2y = a[3];
//b3x = a[4]; b3y = a[5];
//lax = a[6]; lay = a[7];
//lhx = a[8]; lhy = a[9];
//rax = a[10]; ray = a[11];
//rhx = a[12]; rhy = a[13];
//lnx = a[14]; lny = a[15];
//lfx = a[16]; lfy = a[17];
//rnx = a[18]; rny = a[19];
//rfx = a[20]; rfy = a[21];

void DrawMan1(double xx, double yy, int mode, int no)
{

	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double b1x, b1y, b2x, b2y, b3x, b3y, lax, lay, rax, ray, lhx, lhy, rhx, rhy, lnx, lny, rnx, rny, lfx, lfy, rfx, rfy;
	glLineWidth(4);
	glColor3d(1.0, no / 8.0, no / 8.0);

	if (mode == 0)
	{

	}
	if (mode == 1)
	{
		b1x = xx - l*s20 + l*sin(15 * ch);
		b1y = yy + l*cos(20 * ch) + l*cos(15 * ch);
		b2x = b1x + a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x + c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x + l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax + l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x + l*sin(15 * ch);
		ray = b2y - l*cos(15 * ch);
		rhx = rax + l*cos(30 * ch);
		rhy = ray + l*sin(30 * ch);

		lnx = b1x + l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx - l*sin(15 * ch);
		lfy = lny - l*cos(15 * ch);
		rnx = b1x + l*sin(20 * ch);
		rny = b1y - l*cos(20 * ch);
		rfx = rnx - l*sin(15 * ch);
		rfy = rny - l*cos(15 * ch);
	}
	if (mode == 2)
	{
		b1x = xx;
		b1y = yy + 90;
		b2x = b1x - a*sin(9 * ch);
		b2y = b1y + a*cos(9 * ch);
		b3x = b1x - c*sin(9 * ch);
		b3y = b1y + c*cos(9 * ch);

		lax = b2x - l;
		lay = b2y;
		lhx = lax + l*sin(30 * ch);
		lhy = lay + l*cos(30 * ch);
		rax = b2x + l*cos(15 * ch);
		ray = b2y + l*sin(15 * ch);
		rhx = rax + l*sin(30 * ch);
		rhy = ray + l*cos(30 * ch);

		lnx = b1x + l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx - l*cos(30 * ch);
		rfy = rny - l*sin(30 * ch);
	}

	glBegin(GL_LINES);
	glVertex2d(b1x, b1y); glVertex2d(b3x, b3y);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 32; i++) { glVertex2i(b3x + hr*cos(((2 * pi) / 32)*i), b3y + hr*sin(((2 * pi) / 32)*i)); }
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(lhx, lhy); glVertex2d(lax, lay); glVertex2d(b2x, b2y); glVertex2d(rax, ray); glVertex2d(rhx, rhy);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex2d(lfx, lfy); glVertex2d(lnx, lny); glVertex2d(b1x, b1y); glVertex2d(rnx, rny); glVertex2d(rfx, rfy);
	glEnd();
	glFlush();
}
void DrawMan2(double xx, double yy, int mode, int no)
{

	int l = 30, hr = 17, b = 50;

	double m, n, x = xx - l*s20 + l*s15, y = yy + l*c20 + l*c15;
	glLineWidth(4);
	glColor3d(no / 8.0, 1.0, no / 8.0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 32; i++)
	{
		glVertex2i(x - b*s15 - (hr / 2.0)*s15 + hr*cos(((2 * pi) / 32)*i), y + b*c15 + (hr / 2.0)*c15 + hr*sin(((2 * pi) / 32)*i));
	}
	glEnd();

	glBegin(GL_LINES);
	glVertex2d(x, y);
	glVertex2d(x - b*s15, y + b*c15);
	glEnd();

	glBegin(GL_LINE_STRIP);
	m = x - (b - 7)*s15; n = y + (b - 7)*c15;
	glVertex2d(m - l*s15 - l*c30, n - l*c15 + l*s30);
	glVertex2d(m - l*s15, n - l*c15);
	glVertex2d(m, n);
	glVertex2d(m - l*s15, n - l*c15);
	glVertex2d(m - l*s15 - l*c30, n - l*c15 + l*s30);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2d(x - l*s20 + l*s15, y - l*c20 - l*c15);
	glVertex2d(x - l*s20, y - l*c20);
	glVertex2d(x, y);
	glVertex2d(x - l*s20, y - l*c20);
	glVertex2d(x - l*s20 + l*s15, y - l*c20 - l*c15);
	glEnd();

	glFlush();
}

void DrawMan1(double xx, double yy, int mode1, int mode2, int no)
{

	int l = 30, hr = 17, b = 50;
	double m, n, x = xx - l*s20 + l*s15, y = yy + l*c20 + l*c15;
	glLineWidth(4);
	glColor3d(1.0, no / 8.0, no / 688.0);
	if (mode1 == 1)
	{
		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < 32; i++)
		{
			glVertex2i(x + b*s15 + (hr / 2.0)*s15 + hr*cos(((2 * pi) / 32)*i), y + b*c15 + (hr / 2.0)*c15 + hr*sin(((2 * pi) / 32)*i));
		}
		glEnd();

		glBegin(GL_LINES);
		glVertex2d(x, y);
		glVertex2d(x + b*s15, y + b*c15);
		glEnd();

		glBegin(GL_LINE_STRIP);
		m = x + (b - 7)*s15; n = y + (b - 7)*c15;
		glVertex2d(m + l*s15 + l*c30, n - l*c15 + l*s30);
		glVertex2d(m + l*s15, n - l*c15);
		glVertex2d(m, n);
		glVertex2d(m + l*s15, n - l*c15);
		glVertex2d(m + l*s15 + l*c30, n - l*c15 + l*s30);
		glEnd();

		glBegin(GL_LINE_STRIP);
		glVertex2d(x + l*s20 - l*s15, y - l*c20 - l*c15);
		glVertex2d(x + l*s20, y - l*c20);
		glVertex2d(x, y);
		glVertex2d(x + l*s20, y - l*c20);
		glVertex2d(x + l*s20 - l*s15, y - l*c20 - l*c15);
		glEnd();

		glFlush();
	}
}

void getPA(double xx, double yy, int mode, double* p)
{
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double b1x, b1y, b2x, b2y, b3x, b3y, lax, lay, rax, ray, lhx, lhy, rhx, rhy, lnx, lny, rnx, rny, lfx, lfy, rfx, rfy;
	if (mode == 0)
	{
		b1x = xx ;
		b1y = yy + 2 * l*cos(45 * ch);
		b2x = b1x + a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x + c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x ;
		lay = b2y - l;
		lhx = lax + l*cos(30 * ch);
		lhy = lay - l*sin(30 * ch);

		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x + l*sin(45 * ch);
		lny = b1y - l*cos(45 * ch);
		lfx = lnx - l*sin(45 * ch);
		lfy = lny - l*cos(45 * ch);

		rnx = b1x + l*sin(45 * ch);
		rny = b1y - l*cos(45 * ch);
		rfx = rnx - l*sin(45 * ch);
		rfy = rny - l*cos(45 * ch);
	}
	if (mode == 1)
	{
		b1x = xx - l*s20 + l*sin(15 * ch);
		b1y = yy + l*cos(20 * ch) + l*cos(15 * ch);
		b2x = b1x + a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x + c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x + l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax + l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x + l*sin(15 * ch);
		ray = b2y - l*cos(15 * ch);
		rhx = rax + l*cos(30 * ch);
		rhy = ray + l*sin(30 * ch);

		lnx = b1x + l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx - l*sin(15 * ch);
		lfy = lny - l*cos(15 * ch);
		rnx = b1x + l*sin(20 * ch);
		rny = b1y - l*cos(20 * ch);
		rfx = rnx - l*sin(15 * ch);
		rfy = rny - l*cos(15 * ch);
	}
	if (mode == 2)
	{
		b1x = xx;
		b1y = yy + 90;
		b2x = b1x - a*sin(9 * ch);
		b2y = b1y + a*cos(9 * ch);
		b3x = b1x - c*sin(9 * ch);
		b3y = b1y + c*cos(9 * ch);

		lax = b2x - l;
		lay = b2y;
		lhx = lax + l*sin(30 * ch);
		lhy = lay + l*cos(30 * ch);
		rax = b2x + l*cos(15 * ch);
		ray = b2y + l*sin(15 * ch);
		rhx = rax + l*sin(30 * ch);
		rhy = ray + l*cos(30 * ch);

		lnx = b1x + l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx - l*cos(30 * ch);
		rfy = rny - l*sin(30 * ch);
	}
	if (mode == 3)
	{
		b1x = xx;
		b1y = yy + 2 * l*cos(45 * ch);
		b2x = b1x + a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x + c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x + l*cos(45 * ch);
		lay = b2y - l*sin(45 * ch);
		lhx = lax + l*cos(45 * ch);
		lhy = lay - l*sin(45 * ch);

		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x + l*sin(45 * ch);
		lny = b1y - l*cos(45 * ch);
		lfx = lnx - l*sin(45 * ch);
		lfy = lny - l*cos(45 * ch);

		rnx = b1x + l*sin(45 * ch);
		rny = b1y - l*cos(45 * ch);
		rfx = rnx - l*sin(45 * ch);
		rfy = rny - l*cos(45 * ch);
	}
	if (mode == 4)
	{
		b1x = xx - l*sin(9 * ch) + l*sin(9 * ch);
		b1y = yy + l*cos(9 * ch) + l*cos(9 * ch);

		b2x = b1x ;
		b2y = b1y + a;
		b3x = b1x ;
		b3y = b1y + c;

		lax = b2x + l;
		lay = b2y ;
		lhx = lax + l;
		lhy = lay ;
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x + l*sin(9 * ch);
		lny = b1y - l*cos(9 * ch);
		lfx = lnx - l*sin(9 * ch);
		lfy = lny - l*cos(9 * ch);
		rnx = b1x + l*sin(9 * ch);
		rny = b1y - l*cos(9 * ch);
		rfx = rnx - l*sin(9 * ch);
		rfy = rny - l*cos(9 * ch);
	}
	if (mode == 5)
	{
		b1x = xx - l*s20 + l*sin(15 * ch);
		b1y = yy + l*cos(20 * ch) + l*cos(15 * ch);
		b2x = b1x + a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x + c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x + l;
		lay = b2y ;
		lhx = lax - l*sin(15 * ch);
		lhy = lay + l*cos(15 * ch);
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x + l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx - l*sin(15 * ch);
		lfy = lny - l*cos(15 * ch);
		rnx = b1x + l*sin(20 * ch);
		rny = b1y - l*cos(20 * ch);
		rfx = rnx - l*sin(15 * ch);
		rfy = rny - l*cos(15 * ch);
	}
	if (mode == 6)
	{
		b1x = xx - l*sin(9 * ch) + l*sin(9 * ch);
		b1y = yy + l*cos(9 * ch) + l*cos(9 * ch);

		b2x = b1x - 5;
		b2y = b1y + a - 10;
		b3x = b1x-10;
		b3y = b1y + c;

		lax = b2x + l*sin(15 * ch);
		lay = b2y + l*cos(15 * ch);
		lhx = lax + l*sin(15 * ch);
		lhy = lay + l*cos(15 * ch);
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x + l*sin(9 * ch);
		lny = b1y - l*cos(9 * ch);
		lfx = lnx - l*sin(9 * ch);
		lfy = lny - l*cos(9 * ch);
		rnx = b1x + l*sin(9 * ch);
		rny = b1y - l*cos(9 * ch);
		rfx = rnx - l*sin(9 * ch);
		rfy = rny - l*cos(9 * ch);
	}
	if (mode == 7)
	{
		b1x = xx;
		b1y = yy + 110;
		b2x = b1x ;
		b2y = b1y + a;
		b3x = b1x ;
		b3y = b1y + c;

		lax = b2x + l*sin(15 * ch);
		lay = b2y + l*cos(15 * ch);
		lhx = lax + (l+10)*sin(15 * ch);
		lhy = lay + (l+10)*cos(15 * ch);
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x + l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx - l*sin(15 * ch);
		rfy = rny - l*cos(15 * ch);
	}
	if (mode == 8)
	{
		b1x = xx ;
		b1y = yy + 50;
		b2x = b1x + a*cos(15 * ch);
		b2y = b1y - a*sin(15 * ch);
		b3x = b1x + c*cos(15 * ch);
		b3y = b1y - c*sin(15 * ch)+5;

		lax = b2x + l*cos(30 * ch);
		lay = b2y - l*sin(30 * ch);
		lhx = lax + l*cos(15 * ch);
		lhy = lay - l*sin(15 * ch);
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x - l*cos(15 * ch);
		lny = b1y + l*sin(15 * ch);
		lfx = lnx - l*cos(30 * ch);
		lfy = lny + l*sin(30 * ch);
		rnx = b1x - l*cos(20 * ch);
		rny = b1y + l*sin(20 * ch);
		rfx = rnx - l*cos(45 * ch);
		rfy = rny + l*sin(45 * ch);
	}
	if (mode == 9)
	{
		b1x = xx - l*sin(9 * ch) + l*sin(9 * ch);
		b1y = yy + l*cos(9 * ch) + l*cos(9 * ch)+50;

		b2x = b1x - 5;
		b2y = b1y + a - 10;
		b3x = b1x - 10;
		b3y = b1y + c;

		lax = b2x - l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax ;
		lhy = lay - l;
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x + l*sin(9 * ch);
		lny = b1y - l*cos(9 * ch);
		lfx = lnx - l*sin(9 * ch);
		lfy = lny - l*cos(9 * ch);
		rnx = b1x + l*sin(9 * ch);
		rny = b1y - l*cos(9 * ch);
		rfx = rnx - l*sin(9 * ch);
		rfy = rny - l*cos(9 * ch);
	}
	if (mode == 10)
	{
		b1x = xx - l*s20 + l*sin(15 * ch);
		b1y = yy + l*cos(20 * ch) + l*cos(15 * ch);
		b2x = b1x - a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x - c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x + l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax + l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x + l*sin(15 * ch);
		ray = b2y - l*cos(15 * ch);
		rhx = rax + l*cos(30 * ch);
		rhy = ray + l*sin(30 * ch);

		lnx = b1x + l*sin(45 * ch);
		lny = b1y - l*cos(45 * ch);
		lfx = lnx + l*sin(45 * ch);
		lfy = lny - l*cos(45 * ch);
		rnx = b1x + l*sin(20 * ch);
		rny = b1y - l*cos(20 * ch);
		rfx = rnx - l*sin(15 * ch);
		rfy = rny - l*cos(15 * ch);
	}
	if (mode == 22)
	{
		b1x = xx;
		b1y = yy + 90;
		b2x = b1x - a*sin(9 * ch);
		b2y = b1y + a*cos(9 * ch);
		b3x = b1x - c*sin(9 * ch);
		b3y = b1y + c*cos(9 * ch);

		lax = b2x + l*cos(30 * ch);
		lay = b2y + l*sin(30 * ch);
		lhx = lax + l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x + l*sin(45 * ch);
		ray = b2y - l*cos(45 * ch);
		rhx = rax + l*cos(45 * ch);
		rhy = ray + l*sin(45 * ch);

		lnx = b1x + l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx - l*cos(30 * ch);
		rfy = rny - l*sin(30 * ch);
	}
	if (mode == 11)
	{
		b1x = xx - l*sin(30 * ch) ;
		b1y = yy + l*cos(30 * ch) + l;
		b2x = b1x + a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x + c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x + l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax + l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x + l*sin(15 * ch);
		ray = b2y - l*cos(15 * ch);
		rhx = rax + l*cos(30 * ch);
		rhy = ray + l*sin(30 * ch);

		lnx = b1x + l*sin(30 * ch);
		lny = b1y - l*cos(30 * ch);
		lfx = lnx;
		lfy = lny - l;

		rnx = b1x;
		rny = b1y - l;
		rfx = rnx - l*cos(60 * ch);
		rfy = rny - l*sin(60 * ch);
	}
	if (mode == 12)
	{
		b1x = xx - l*sin(30 * ch);
		b1y = yy + l*cos(30 * ch) + l;
		b2x = b1x + a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x + c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x + l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax + l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x + l*sin(15 * ch);
		ray = b2y - l*cos(15 * ch);
		rhx = rax + l*cos(30 * ch);
		rhy = ray + l*sin(30 * ch);

		rnx = b1x + l*sin(30 * ch);
		rny = b1y - l*cos(30 * ch);
		rfx = rnx;
		rfy = rny - l;

		lnx = b1x;
		lny = b1y - l;
		lfx = lnx - l*cos(60 * ch);
		lfy = lny - l*sin(60 * ch);
	}
	if (mode == 202)
	{
		b1x = xx;
		b1y = yy + 110;
		b2x = b1x - a*sin(9 * ch);
		b2y = b1y + a*cos(9 * ch);
		b3x = b1x - c*sin(9 * ch);
		b3y = b1y + c*cos(9 * ch);

		lax = b2x - l;
		lay = b2y;
		lhx = lax + l*sin(30 * ch);
		lhy = lay + l*cos(30 * ch);
		rax = b2x + l*cos(15 * ch);
		ray = b2y + l*sin(15 * ch);
		rhx = rax + l*sin(30 * ch);
		rhy = ray + l*cos(30 * ch);

		lnx = b1x + l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx - l*cos(30 * ch);
		rfy = rny - l*sin(30 * ch);
	}
	if (mode == 222)
	{
		b1x = xx;
		b1y = yy + 110;
		b2x = b1x - a*sin(9 * ch);
		b2y = b1y + a*cos(9 * ch);
		b3x = b1x - c*sin(9 * ch);
		b3y = b1y + c*cos(9 * ch);

		lax = b2x + l*cos(30 * ch);
		lay = b2y + l*sin(30 * ch);
		lhx = lax + l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x + l*sin(45 * ch);
		ray = b2y - l*cos(45 * ch);
		rhx = rax + l*cos(45 * ch);
		rhy = ray + l*sin(45 * ch);

		lnx = b1x + l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx - l*cos(30 * ch);
		rfy = rny - l*sin(30 * ch);
	}


	p[0] = b1x;
	p[1] = b1y;
	p[2] = b2x;
	p[3] = b2y;
	p[4] = b3x;
	p[5] = b3y;
	p[6] = lax;
	p[7] = lay;
	p[8] = lhx;
	p[9] = lhy;
	p[10] = rax;
	p[11] = ray;
	p[12] = rhx;
	p[13] = rhy;
	p[14] = lnx;
	p[15] = lny;
	p[16] = lfx;
	p[17] = lfy;
	p[18] = rnx;
	p[19] = rny;
	p[20] = rfx;
	p[21] = rfy;

}
void getPB(double xx, double yy, int mode, double* p)
{
	int l = 30, hr = 17, a = 40, c = (50 + (hr / 2.0));
	double b1x, b1y, b2x, b2y, b3x, b3y, lax, lay, rax, ray, lhx, lhy, rhx, rhy, lnx, lny, rnx, rny, lfx, lfy, rfx, rfy;
	if (mode == -1)
	{
		b1x = xx + l*s20 - l*sin(15 * ch);
		b1y = yy + l*cos(20 * ch) + l*cos(15 * ch);
		b2x = b1x ;
		b2y = b1y + a;
		b3x = b1x ;
		b3y = b1y + c;

		lax = b2x - l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax - l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x - l*sin(60 * ch);
		ray = b2y + l*cos(60 * ch);
		rhx = rax - l*sin(15 * ch);
		rhy = ray + l*cos(15 * ch);

		lnx = b1x - l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx + l*sin(15 * ch);
		lfy = lny - l*cos(15 * ch);
		rnx = b1x - l*sin(20 * ch);
		rny = b1y - l*cos(20 * ch);
		rfx = rnx + l*sin(15 * ch);
		rfy = rny - l*cos(15 * ch);
	}
	if (mode == 0)
	{
		b1x = xx;
		b1y = yy + 2 * l*cos(45 * ch);
		b2x = b1x - a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x - c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x;
		lay = b2y - l;
		lhx = lax - l*cos(30 * ch);
		lhy = lay - l*sin(30 * ch);

		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x - l*sin(45 * ch);
		lny = b1y - l*cos(45 * ch);
		lfx = lnx + l*sin(45 * ch);
		lfy = lny - l*cos(45 * ch);

		rnx = b1x - l*sin(45 * ch);
		rny = b1y - l*cos(45 * ch);
		rfx = rnx + l*sin(45 * ch);
		rfy = rny - l*cos(45 * ch);
	}
	if (mode == 1)
	{
		b1x = xx + l*s20 - l*sin(15 * ch);
		b1y = yy + l*cos(20 * ch) + l*cos(15 * ch);
		b2x = b1x - a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x - c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x - l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax - l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x - l*sin(15 * ch);
		ray = b2y - l*cos(15 * ch);
		rhx = rax - l*cos(30 * ch);
		rhy = ray + l*sin(30 * ch);

		lnx = b1x - l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx + l*sin(15 * ch);
		lfy = lny - l*cos(15 * ch);
		rnx = b1x - l*sin(20 * ch);
		rny = b1y - l*cos(20 * ch);
		rfx = rnx + l*sin(15 * ch);
		rfy = rny - l*cos(15 * ch);
	}
	if (mode == 2)
	{
		b1x = xx;
		b1y = yy + 90;
		b2x = b1x + a*sin(9 * ch);
		b2y = b1y + a*cos(9 * ch);
		b3x = b1x + c*sin(9 * ch);
		b3y = b1y + c*cos(9 * ch);

		lax = b2x + l;
		lay = b2y;
		lhx = lax - l*sin(30 * ch);
		lhy = lay + l*cos(30 * ch);
		rax = b2x - l*cos(15 * ch);
		ray = b2y + l*sin(15 * ch);
		rhx = rax - l*sin(30 * ch);
		rhy = ray + l*cos(30 * ch);

		lnx = b1x - l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx + l*cos(30 * ch);
		rfy = rny - l*sin(30 * ch);
	}
	if (mode == 3)
	{
		b1x = xx;
		b1y = yy + 2 * l*cos(45 * ch);
		b2x = b1x - a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x - c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x - l*cos(45 * ch);
		lay = b2y - l*sin(45 * ch);
		lhx = lax - l*cos(45 * ch);
		lhy = lay - l*sin(45 * ch);

		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x - l*sin(45 * ch);
		lny = b1y - l*cos(45 * ch);
		lfx = lnx + l*sin(45 * ch);
		lfy = lny - l*cos(45 * ch);

		rnx = b1x - l*sin(45 * ch);
		rny = b1y - l*cos(45 * ch);
		rfx = rnx + l*sin(45 * ch);
		rfy = rny - l*cos(45 * ch);
	}
	if (mode == 4)
	{
		b1x = xx + l*sin(9 * ch) - l*sin(9 * ch);
		b1y = yy + l*cos(9 * ch) + l*cos(9 * ch);

		b2x = b1x;
		b2y = b1y + a;
		b3x = b1x;
		b3y = b1y + c;

		lax = b2x - l;
		lay = b2y;
		lhx = lax - l;
		lhy = lay;
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x - l*sin(9 * ch);
		lny = b1y - l*cos(9 * ch);
		lfx = lnx + l*sin(9 * ch);
		lfy = lny - l*cos(9 * ch);
		rnx = b1x - l*sin(9 * ch);
		rny = b1y - l*cos(9 * ch);
		rfx = rnx + l*sin(9 * ch);
		rfy = rny - l*cos(9 * ch);
	}
	if (mode == 5)
	{
		b1x = xx + l*s20 - l*sin(15 * ch);
		b1y = yy + l*cos(20 * ch) + l*cos(15 * ch);
		b2x = b1x - a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x - c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x - l;
		lay = b2y;
		lhx = lax + l*sin(15 * ch);
		lhy = lay + l*cos(15 * ch);
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x - l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx + l*sin(15 * ch);
		lfy = lny - l*cos(15 * ch);
		rnx = b1x - l*sin(20 * ch);
		rny = b1y - l*cos(20 * ch);
		rfx = rnx + l*sin(15 * ch);
		rfy = rny - l*cos(15 * ch);
	}
	if (mode == 6)
	{
		b1x = xx + l*sin(9 * ch) - l*sin(9 * ch);
		b1y = yy + l*cos(9 * ch) + l*cos(9 * ch);

		b2x = b1x + 5;
		b2y = b1y + a - 10;
		b3x = b1x + 10;
		b3y = b1y + c;

		lax = b2x - l*sin(15 * ch);
		lay = b2y + l*cos(15 * ch);
		lhx = lax - l*sin(15 * ch);
		lhy = lay + l*cos(15 * ch);
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x - l*sin(9 * ch);
		lny = b1y - l*cos(9 * ch);
		lfx = lnx + l*sin(9 * ch);
		lfy = lny - l*cos(9 * ch);
		rnx = b1x - l*sin(9 * ch);
		rny = b1y - l*cos(9 * ch);
		rfx = rnx + l*sin(9 * ch);
		rfy = rny - l*cos(9 * ch);
	}
	if (mode == 7)
	{
		b1x = xx;
		b1y = yy + 110;
		b2x = b1x;
		b2y = b1y + a;
		b3x = b1x;
		b3y = b1y + c;

		lax = b2x - l*sin(15 * ch);
		lay = b2y + l*cos(15 * ch);
		lhx = lax - (l + 10)*sin(15 * ch);
		lhy = lay + (l + 10)*cos(15 * ch);
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x - l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx + l*sin(15 * ch);
		rfy = rny - l*cos(15 * ch);
	}
	if (mode == 8)
	{
		b1x = xx;
		b1y = yy + 50;
		b2x = b1x - a*cos(15 * ch);
		b2y = b1y - a*sin(15 * ch);
		b3x = b1x - c*cos(15 * ch);
		b3y = b1y - c*sin(15 * ch) + 5;

		lax = b2x - l*cos(30 * ch);
		lay = b2y - l*sin(30 * ch);
		lhx = lax - l*cos(15 * ch);
		lhy = lay - l*sin(15 * ch);
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x + l*cos(15 * ch);
		lny = b1y + l*sin(15 * ch);
		lfx = lnx + l*cos(30 * ch);
		lfy = lny + l*sin(30 * ch);
		rnx = b1x + l*cos(20 * ch);
		rny = b1y + l*sin(20 * ch);
		rfx = rnx + l*cos(45 * ch);
		rfy = rny + l*sin(45 * ch);
	}
	if (mode == 22)
	{
		b1x = xx;
		b1y = yy + 90;
		b2x = b1x + a*sin(9 * ch);
		b2y = b1y + a*cos(9 * ch);
		b3x = b1x + c*sin(9 * ch);
		b3y = b1y + c*cos(9 * ch);

		lax = b2x - l*cos(30 * ch);
		lay = b2y + l*sin(30 * ch);
		lhx = lax - l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x - l*sin(45 * ch);
		ray = b2y - l*cos(45 * ch);
		rhx = rax - l*cos(45 * ch);
		rhy = ray + l*sin(45 * ch);

		lnx = b1x - l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx + l*cos(30 * ch);
		rfy = rny - l*sin(30 * ch);
	}
	if (mode == 11)
	{
		b1x = xx + l*sin(30 * ch);
		b1y = yy + l*cos(30 * ch) + l;
		b2x = b1x - a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x - c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x - l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax - l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x - l*sin(15 * ch);
		ray = b2y - l*cos(15 * ch);
		rhx = rax - l*cos(30 * ch);
		rhy = ray + l*sin(30 * ch);

		lnx = b1x - l*sin(30 * ch);
		lny = b1y - l*cos(30 * ch);
		lfx = lnx;
		lfy = lny - l;

		rnx = b1x;
		rny = b1y - l;
		rfx = rnx + l*sin(30 * ch);
		rfy = rny - l*cos(30 * ch);
	}
	if (mode == 12)
	{
		b1x = xx + l*sin(30 * ch);
		b1y = yy + l*cos(30 * ch) + l;
		b2x = b1x - a*sin(15 * ch);
		b2y = b1y + a*cos(15 * ch);
		b3x = b1x - c*sin(15 * ch);
		b3y = b1y + c*cos(15 * ch);

		lax = b2x - l*sin(15 * ch);
		lay = b2y - l*cos(15 * ch);
		lhx = lax - l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x - l*sin(15 * ch);
		ray = b2y - l*cos(15 * ch);
		rhx = rax - l*cos(30 * ch);
		rhy = ray + l*sin(30 * ch);

		rnx = b1x - l*sin(30 * ch);
		rny = b1y - l*cos(30 * ch);
		rfx = rnx;
		rfy = rny - l;

		lnx = b1x;
		lny = b1y - l;
		lfx = lnx + l*cos(60 * ch);
		lfy = lny - l*sin(60 * ch);
	}
	if (mode == 88)
	{
		b1x = xx;
		b1y = yy + 25;
		b2x = b1x - a*cos(5 * ch);
		b2y = b1y - a*sin(5 * ch);
		b3x = b1x - c*cos(5 * ch);
		b3y = b1y - c*sin(5 * ch);

		lax = b2x - l*cos(30 * ch);
		lay = b2y - l*sin(30 * ch);
		lhx = lax - l;
		lhy = lay ;
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x + l*cos(30 * ch);
		lny = b1y - l*sin(30 * ch);
		lfx = lnx + l*cos(15 * ch);
		lfy = lny - l*sin(15 * ch);
		rnx = b1x + l*cos(45 * ch);
		rny = b1y - l*sin(45 * ch);
		rfx = rnx + l*cos(20 * ch);
		rfy = rny - l*sin(20 * ch);
	}
	if (mode == 888)
	{
		b1x = xx;
		b1y = yy + 30;
		b2x = b1x - a;
		b2y = b1y ;
		b3x = b1x - c;
		b3y = b1y ;

		lax = b2x ;
		lay = b2y - l;
		lhx = lax - l;
		lhy = lay;
		rax = lax;
		ray = lay;
		rhx = lhx;
		rhy = lhy;

		lnx = b1x ;
		lny = b1y - l;
		lfx = lnx + l;
		lfy = lny ;
		rnx = lnx;
		rny = lny;
		rfx = lfx;
		rfy = lfy;
	}
	if (mode == 202)
	{
		b1x = xx;
		b1y = yy + 110;
		b2x = b1x + a*sin(9 * ch);
		b2y = b1y + a*cos(9 * ch);
		b3x = b1x + c*sin(9 * ch);
		b3y = b1y + c*cos(9 * ch);

		lax = b2x + l;
		lay = b2y;
		lhx = lax - l*sin(30 * ch);
		lhy = lay + l*cos(30 * ch);
		rax = b2x - l*cos(15 * ch);
		ray = b2y + l*sin(15 * ch);
		rhx = rax - l*sin(30 * ch);
		rhy = ray + l*cos(30 * ch);

		lnx = b1x - l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx + l*cos(30 * ch);
		rfy = rny - l*sin(30 * ch);
	}
	if (mode == 222)
	{
		b1x = xx;
		b1y = yy + 110;
		b2x = b1x + a*sin(9 * ch);
		b2y = b1y + a*cos(9 * ch);
		b3x = b1x + c*sin(9 * ch);
		b3y = b1y + c*cos(9 * ch);

		lax = b2x - l*cos(30 * ch);
		lay = b2y + l*sin(30 * ch);
		lhx = lax - l*cos(30 * ch);
		lhy = lay + l*sin(30 * ch);
		rax = b2x - l*sin(45 * ch);
		ray = b2y - l*cos(45 * ch);
		rhx = rax - l*cos(45 * ch);
		rhy = ray + l*sin(45 * ch);

		lnx = b1x - l*sin(20 * ch);
		lny = b1y - l*cos(20 * ch);
		lfx = lnx;
		lfy = lny - l;
		rnx = b1x;
		rny = b1y - l;
		rfx = rnx + l*cos(30 * ch);
		rfy = rny - l*sin(30 * ch);
	}

	if (mode == 1000)
	{
		b1x = xx ;
		b1y = yy ;
		b2x = b1x ;
		b2y = b1y + a;
		b3x = b1x ;
		b3y = b1y + c;

		lax = b2x - l*sin(30 * ch);
		lay = b2y + l*cos(30 * ch);
		lhx = lax ;
		lhy = lay + l;

		rax = b2x + l*sin(30 * ch);
		ray = b2y + l*cos(30 * ch);
		rhx = rax ;
		rhy = ray + l;

		lnx = b1x - l*sin(9 * ch);
		lny = b1y - l*cos(9 * ch);
		lfx = lnx - l*sin(9 * ch);
		lfy = lny - l*cos(9 * ch);
		rnx = b1x + l*sin(9 * ch);
		rny = b1y - l*cos(9 * ch);
		rfx = rnx + l*sin(9 * ch);
		rfy = rny - l*cos(9 * ch);
	}

	p[0] = b1x;
	p[1] = b1y;
	p[2] = b2x;
	p[3] = b2y;
	p[4] = b3x;
	p[5] = b3y;
	p[6] = lax;
	p[7] = lay;
	p[8] = lhx;
	p[9] = lhy;
	p[10] = rax;
	p[11] = ray;
	p[12] = rhx;
	p[13] = rhy;
	p[14] = lnx;
	p[15] = lny;
	p[16] = lfx;
	p[17] = lfy;
	p[18] = rnx;
	p[19] = rny;
	p[20] = rfx;
	p[21] = rfy;

}
// header files
#include "globalHeaders.h"

// global variable declarations
BOOL bFullScreen = FALSE;
float angle = 0.0f;
// Entry-point function
int main(int argc, char* argv[])
{
	// local function declarations
	int initialize(void);
	void resize(int, int);
	void display(void);
	void keyboard(unsigned char, int, int);
	void mouse(int, int, int, int);
	void uninitialize(void);

	// code
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Ojaswita Vinay Patil");

	initialize();

	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutCloseFunc(uninitialize);

	glutMainLoop();

	return(0);
}

int initialize(void)
{
	// code
	glClearColor(
		0.0f,									//red
		0.0f,									//green
		0.0f,									//blue
		1.0f 									//alpha
	);
	// Enable depth testing
    glEnable(GL_DEPTH_TEST);

	return(0);
}

void resize(int width, int height)
{
	// code
	glViewport(0, 0, width, height);
	// Set up the projection matrix for 3D viewing
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0); // FOV, aspect ratio, near and far planes
    glMatrixMode(GL_MODELVIEW); // Switch back to modelview matrix
}

void display(void)
{
	// code
	//------------------------DRAW--------------------------
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Load the identity matrix to reset transformations
    glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -10.0f);

	if(angle < 360.0f)
		angle = angle + 0.1f;
	else  
		angle = 0.0f;
			
	glRotatef(angle, 1.0f, 0.0f, 0.0f);
	glRotatef(angle, 0.0f, 1.0f, 0.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);

	// Draw the cube with separate colors for each face
	glBegin(GL_QUADS);  // Draw each face of the cube as a quadrilateral

	// Front face (Red)
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom-left
	glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom-right
	glVertex3f( 1.0f,  1.0f,  1.0f);  // Top-right
	glVertex3f(-1.0f,  1.0f,  1.0f);  // Top-left

	// Back face (Green)
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom-left
	glVertex3f(-1.0f,  1.0f, -1.0f);  // Top-left
	glVertex3f( 1.0f,  1.0f, -1.0f);  // Top-right
	glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom-right

	// Top face (Blue)
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f,  1.0f, -1.0f);  // Back-left
	glVertex3f(-1.0f,  1.0f,  1.0f);  // Front-left
	glVertex3f( 1.0f,  1.0f,  1.0f);  // Front-right
	glVertex3f( 1.0f,  1.0f, -1.0f);  // Back-right

	// Bottom face (Yellow)
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);  // Back-left
	glVertex3f( 1.0f, -1.0f, -1.0f);  // Back-right
	glVertex3f( 1.0f, -1.0f,  1.0f);  // Front-right
	glVertex3f(-1.0f, -1.0f,  1.0f);  // Front-left

	// Right face (Cyan)
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom-front
	glVertex3f( 1.0f,  1.0f, -1.0f);  // Top-front
	glVertex3f( 1.0f,  1.0f,  1.0f);  // Top-back
	glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom-back

	// Left face (Magenta)
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom-back
	glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom-front
	glVertex3f(-1.0f,  1.0f,  1.0f);  // Top-front
	glVertex3f(-1.0f,  1.0f, -1.0f);  // Top-back

	glEnd();  // End drawing the cube face

	glutSwapBuffers();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	// code
	switch (key)
	{
	case 27:
		glutLeaveMainLoop();
		break;
	case 'F':
	case 'f':
		if (bFullScreen == FALSE)
		{
			glutFullScreen();
			bFullScreen = TRUE;
		}
		else
		{
			glutLeaveFullScreen();
			bFullScreen = FALSE;
		}
		break;
	default:
		break;
    }
}

void mouse(int button, int state, int x, int y)
{
	// code
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		glutLeaveMainLoop();
		break;
	default:
		break;
	}
}

void uninitialize(void)
{
	// code
}

#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

float alfa = 0.0f, beta = 0.5f, radius = 100.0f;
float camX, camY, camZ;


void spherical2Cartesian() {

	camX = radius * cos(beta) * sin(alfa);
	camY = radius * sin(beta);
	camZ = radius * cos(beta) * cos(alfa);
}


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}

#include <stdlib.h>
#include <time.h>

struct TreePosition {
    float x, z;
};

const int NUM_TREES = 100;
TreePosition treePositions[NUM_TREES];
bool treesInitialized = false;

void initTrees() {
    srand(time(NULL));
    for (int i = 0; i < NUM_TREES; i++) {
        treePositions[i].x = (float)(rand() % 200 - 100);
        treePositions[i].z = (float)(rand() % 200 - 100);
    }
    treesInitialized = true;
}

void drawTree(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0, z);
    
    // Desenha o tronco como um cilindro 3D
    glColor3f(0.5f, 0.25f, 0.0f);
    glPushMatrix();
        // O cilindro é gerado ao longo do eixo Z; para alinhá-lo verticalmente (eixo Y),
        // realizamos uma rotação de -90 graus em torno do eixo X.
        glRotatef(-90, 1.0f, 0.0f, 0.0f);
        GLUquadric* quad = gluNewQuadric();
        gluCylinder(quad, 1.0, 1.0, 5, 20, 20); // base, topo, altura, slices, stacks
        gluDeleteQuadric(quad);
    glPopMatrix();
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glPushMatrix();
        glTranslatef(0.0f, 5.0f, 0.0f); // posiciona a copa no topo do tronco
        glRotatef(-90, 1.0f, 0.0f, 0.0f);  // rotaciona o cone para que fique na vertical
        glutSolidCone(5.0, 10, 20, 20);
    glPopMatrix();
    
    glPopMatrix();
}

void drawRandomTrees() {
    if (!treesInitialized)
        initTrees();
    for (int i = 0; i < NUM_TREES; i++) {
        drawTree(treePositions[i].x, treePositions[i].z);
    }
}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(camX, camY, camZ,
		0.0, 0.0, 0.0,
		0.0f, 1.0f, 0.0f);

	glColor3f(0.2f, 0.8f, 0.2f);
	glBegin(GL_TRIANGLES);
		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);

		glVertex3f(100.0f, 0, -100.0f);
		glVertex3f(-100.0f, 0, 100.0f);
		glVertex3f(100.0f, 0, 100.0f);
	glEnd();

	drawRandomTrees();
	
	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {

	switch (c) {

	case 27: // Escape key
		exit(0);
		break;

	case '1':
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;

	case '2':
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		break;

	case '3':
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		break;

	default:
		break;
	}
	glutPostRedisplay();

}


void processSpecialKeys(int key, int xx, int yy) {

	switch (key) {

	case GLUT_KEY_RIGHT:
		alfa -= 0.1; break;

	case GLUT_KEY_LEFT:
		alfa += 0.1; break;

	case GLUT_KEY_UP:
		beta += 0.1f;
		if (beta > 1.5f)
			beta = 1.5f;
		break;

	case GLUT_KEY_DOWN:
		beta -= 0.1f;
		if (beta < -1.5f)
			beta = -1.5f;
		break;

	case GLUT_KEY_PAGE_DOWN: radius -= 1.0f;
		if (radius < 1.0f)
			radius = 1.0f;
		break;

	case GLUT_KEY_PAGE_UP: radius += 1.0f; break;
	}
	spherical2Cartesian();
	glutPostRedisplay();

}


void printInfo() {

	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));

	printf("\nUse Arrows to move the camera up/down and left/right\n");
	printf("Home and End control the distance from the camera to the origin");
}


int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	
// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	spherical2Cartesian();

	printInfo();

// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}

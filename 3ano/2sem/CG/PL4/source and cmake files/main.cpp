// #include <stdio.h>

// #ifdef __APPLE__
// #include <GLUT/glut.h>
// #else
// #include <GL/glew.h>
// #include <GL/glut.h>
// #endif

// #define _USE_MATH_DEFINES
// #include <math.h>

// float alfa = 0.0f, beta = 0.0f, radius = 5.0f;
// float camX, camY, camZ;


// void spherical2Cartesian() {

// 	camX = radius * cos(beta) * sin(alfa);
// 	camY = radius * sin(beta);
// 	camZ = radius * cos(beta) * cos(alfa);
// }


// void changeSize(int w, int h) {

// 	// Prevent a divide by zero, when window is too short
// 	// (you cant make a window with zero width).
// 	if(h == 0)
// 		h = 1;

// 	// compute window's aspect ratio 
// 	float ratio = w * 1.0 / h;

// 	// Set the projection matrix as current
// 	glMatrixMode(GL_PROJECTION);
// 	// Load Identity Matrix
// 	glLoadIdentity();
	
// 	// Set the viewport to be the entire window
//     glViewport(0, 0, w, h);

// 	// Set perspective
// 	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

// 	// return to the model view matrix mode
// 	glMatrixMode(GL_MODELVIEW);
// }


// /*----------------------------------------------------------------------------------- 
// 	Draw Cylinder with strips and fans

// 	  parameters: radius, height, sides

// 	  strips são os lados do cilindro e fans são os topos e fundos do cilindro
// -----------------------------------------------------------------------------------*/


// void cylinder0(float radius, float height, int sides) {

// 	int i;
// 	float step;

// 	step = 360.0/sides;

// 	glColor3f(1,0,0);
// 	glBegin(GL_TRIANGLE_FAN);

// 		glVertex3f(0,height*0.5,0);
// 		for (i=0; i <= sides; i++) {
// 			glVertex3f(cos(i * step * M_PI/180.0)*radius,height*0.5,-sin(i * step *M_PI/180.0)*radius);
// 		}
// 	glEnd();

// 	glColor3f(0,1,0);
// 	glBegin(GL_TRIANGLE_FAN);

// 		glVertex3f(0,-height*0.5,0);
// 		for (i=0; i <= sides; i++) {
// 			glVertex3f(cos(i * step * M_PI/180.0)*radius,-height*0.5,sin(i * step *M_PI/180.0)*radius);
// 		}
// 	glEnd();

// 	glColor3f(0,0,1);
// 	glBegin(GL_TRIANGLE_STRIP);

// 		for (i=0; i <= sides; i++) {
// 			glVertex3f(cos(i * step * M_PI/180.0)*radius, height*0.5,-sin(i * step *M_PI/180.0)*radius);
// 			glVertex3f(cos(i * step * M_PI/180.0)*radius,-height*0.5,-sin(i * step *M_PI/180.0)*radius);
// 		}
// 	glEnd();
// }


// /*-----------------------------------------------------------------------------------
// 	Draw Cylinder

// 		parameters: radius, height, sides

// -----------------------------------------------------------------------------------*/


// void cylinder(float radius, float height, int sides) {

// 	int i;
// 	float step;

// 	step = 360.0 / sides;

// 	glBegin(GL_TRIANGLES);

// 	// top
// 	for (i = 0; i < sides; i++) {
// 		glVertex3f(0, height*0.5, 0);
// 		glVertex3f(cos(i * step * M_PI / 180.0)*radius, height*0.5, -sin(i * step *M_PI / 180.0)*radius);
// 		glVertex3f(cos((i+1) * step * M_PI / 180.0)*radius, height*0.5, -sin((i + 1) * step *M_PI / 180.0)*radius);
// 	}

// 	// bottom
// 	for (i = 0; i < sides; i++) {
// 		glVertex3f(0, -height*0.5, 0);
// 		glVertex3f(cos((i + 1) * step * M_PI / 180.0)*radius, -height*0.5, -sin((i + 1) * step *M_PI / 180.0)*radius);
// 		glVertex3f(cos(i * step * M_PI / 180.0)*radius, -height*0.5, -sin(i * step *M_PI / 180.0)*radius);
// 	}

// 	// body
// 	for (i = 0; i <= sides; i++) {

// 		glVertex3f(cos(i * step * M_PI / 180.0)*radius, height*0.5, -sin(i * step *M_PI / 180.0)*radius);
// 		glVertex3f(cos(i * step * M_PI / 180.0)*radius, -height*0.5, -sin(i * step *M_PI / 180.0)*radius);
// 		glVertex3f(cos((i + 1) * step * M_PI / 180.0)*radius, height*0.5, -sin((i + 1) * step *M_PI / 180.0)*radius);

// 		glVertex3f(cos(i * step * M_PI / 180.0)*radius, -height*0.5, -sin(i * step *M_PI / 180.0)*radius);
// 		glVertex3f(cos((i + 1) * step * M_PI / 180.0)*radius, -height*0.5, -sin((i + 1) * step *M_PI / 180.0)*radius);
// 		glVertex3f(cos((i + 1) * step * M_PI / 180.0)*radius, height*0.5, -sin((i + 1) * step *M_PI / 180.0)*radius);
// 	}
// 	glEnd();
// }


// void renderScene(void) {

// 	// clear buffers
// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// 	// set the camera
// 	glLoadIdentity();
// 	gluLookAt(camX, camY, camZ,
// 		0.0, 0.0, 0.0,
// 		0.0f, 1.0f, 0.0f);

// 	cylinder(1,2,10);

// 	// End of frame
// 	glutSwapBuffers();
// }


// void processKeys(unsigned char c, int xx, int yy) {

// // put code to process regular keys in here

// }


// void processSpecialKeys(int key, int xx, int yy) {

// 	switch (key) {

// 	case GLUT_KEY_RIGHT:
// 		alfa -= 0.1; break;

// 	case GLUT_KEY_LEFT:
// 		alfa += 0.1; break;

// 	case GLUT_KEY_UP:
// 		beta += 0.1f;
// 		if (beta > 1.5f)
// 			beta = 1.5f;
// 		break;

// 	case GLUT_KEY_DOWN:
// 		beta -= 0.1f;
// 		if (beta < -1.5f)
// 			beta = -1.5f;
// 		break;

// 	case GLUT_KEY_PAGE_DOWN: radius -= 0.1f;
// 		if (radius < 0.1f)
// 			radius = 0.1f;
// 		break;

// 	case GLUT_KEY_PAGE_UP: radius += 0.1f; break;
// 	}
// 	spherical2Cartesian();
// 	glutPostRedisplay();

// }


// void printInfo() {

// 	printf("Vendor: %s\n", glGetString(GL_VENDOR));
// 	printf("Renderer: %s\n", glGetString(GL_RENDERER));
// 	printf("Version: %s\n", glGetString(GL_VERSION));

// 	printf("\nUse Arrows to move the camera up/down and left/right\n");
// 	printf("Page Up and Page Down control the distance from the camera to the origin");
// }


// int main(int argc, char **argv) {

// // init GLUT and the window
// 	glutInit(&argc, argv);
// 	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
// 	glutInitWindowPosition(100,100);
// 	glutInitWindowSize(800,800);
// 	glutCreateWindow("CG@DI-UM");
		
// // Required callback registry 
// 	glutDisplayFunc(renderScene);
// 	glutReshapeFunc(changeSize);
	
// // Callback registration for keyboard processing
// 	glutKeyboardFunc(processKeys);
// 	glutSpecialFunc(processSpecialKeys);

// 	// init GLEW
// #ifndef __APPLE__
// 	glewInit();
// #endif


// //  OpenGL settings
// 	glEnable(GL_DEPTH_TEST);
// 	glEnable(GL_CULL_FACE);
// 	glPolygonMode(GL_FRONT, GL_LINE);

// 	spherical2Cartesian();

// 	printInfo();

// // enter GLUT's main cycle
// 	glutMainLoop();
	
// 	return 1;
// }

#include <stdio.h>
#include <vector>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

float alfa = 0.0f, beta = 0.0f, radius = 5.0f;
float camX, camY, camZ;

GLuint verticesVBO, indicesVBO;
int vertexCount, indexCount;

void spherical2Cartesian() {
    camX = radius * cos(beta) * sin(alfa);
    camY = radius * sin(beta);
    camZ = radius * cos(beta) * cos(alfa);
}

void changeSize(int w, int h) {
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 1.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void prepareCylinder(float radius, float height, int sides) {
    std::vector<float> vertices; // vetor para armazenar os vértices
    std::vector<unsigned int> indices; // armazenamento dos indices dos vértices para facilitar o acesso

    float step = 360.0f / sides; // ângulo entre cada lado (arco ??)

    // Top center vertex
    vertices.push_back(0.0f);
    vertices.push_back(height * 0.5f);
    vertices.push_back(0.0f);

    // Bottom center vertex
    vertices.push_back(0.0f);
    vertices.push_back(-height * 0.5f);
    vertices.push_back(0.0f);

    // Generate vertices for the sides
    for (int i = 0; i <= sides; ++i) {
        float angle = i * step * M_PI / 180.0f;
        float x = cos(angle) * radius;
        float z = -sin(angle) * radius;

        // Top vertex
        vertices.push_back(x);
        vertices.push_back(height * 0.5f);
        vertices.push_back(z);

        // Bottom vertex
        vertices.push_back(x);
        vertices.push_back(-height * 0.5f);
        vertices.push_back(z);
    }

    // Generate indices for the top and bottom faces
    for (int i = 0; i < sides; ++i) {
        // Top face
        indices.push_back(0);
        indices.push_back(2 + 2 * i);
        indices.push_back(2 + 2 * (i + 1));

        // Bottom face
        indices.push_back(1);
        indices.push_back(2 + 2 * (i + 1) + 1);
        indices.push_back(2 + 2 * i + 1);
    }

    // Generate indices for the sides
    for (int i = 0; i < sides; ++i) {
        indices.push_back(2 + 2 * i);
        indices.push_back(2 + 2 * (i + 1));
        indices.push_back(2 + 2 * i + 1);

        indices.push_back(2 + 2 * (i + 1));
        indices.push_back(2 + 2 * (i + 1) + 1);
        indices.push_back(2 + 2 * i + 1);
    }

    vertexCount = vertices.size() / 3; // isto serve para a reutilização dos pontos na construção dos triângulos
    indexCount = indices.size();

    // Generate and bind the VBO for vertices
    glGenBuffers(1, &verticesVBO);
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Generate and bind the VBO for indices
    glGenBuffers(1, &indicesVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesVBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camX, camY, camZ, 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);

    // Bind the vertex buffer and set the vertex pointer
    glBindBuffer(GL_ARRAY_BUFFER, verticesVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    // Bind the index buffer and draw the cylinder
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesVBO);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);

    glutSwapBuffers();
}

void processSpecialKeys(int key, int xx, int yy) {
    switch (key) {
        case GLUT_KEY_RIGHT: alfa -= 0.1; break;
        case GLUT_KEY_LEFT: alfa += 0.1; break;
        case GLUT_KEY_UP:
            beta += 0.1f;
            if (beta > 1.5f) beta = 1.5f;
            break;
        case GLUT_KEY_DOWN:
            beta -= 0.1f;
            if (beta < -1.5f) beta = -1.5f;
            break;
        case GLUT_KEY_PAGE_DOWN:
            radius -= 0.1f;
            if (radius < 0.1f) radius = 0.1f;
            break;
        case GLUT_KEY_PAGE_UP: radius += 0.1f; break;
    }
    spherical2Cartesian();
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("CG@DI-UM - VBO Cylinder");

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutSpecialFunc(processSpecialKeys);

#ifndef __APPLE__
    glewInit();
#endif

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glPolygonMode(GL_FRONT, GL_LINE);

    // Prepare the cylinder data and create VBOs
    prepareCylinder(1.0f, 2.0f, 10);

    spherical2Cartesian();
    glutMainLoop();

    return 1;
}
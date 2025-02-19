#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

float cam_radius = 8.0f;
float cam_theta = M_PI/4; // ângulo horizontal em radianos
float cam_phi   = M_PI/4; // ângulo vertical em radianos

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


void drawCylinder(float radius, float height, int slices) {
    float angle = 2.0f * M_PI / slices;
    float x, z;

    // Define a cor vermelha para o cilindro
    glColor3f(1.0f, 0.0f, 0.0f);

    // Desenha o corpo lateral do cilindro com duas triângulos por fatia
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < slices; i++) {
        float a = i * angle;
        float aNext = (i + 1) * angle;
        
        // Primeiro triângulo da fatia
        glVertex3f(radius * cos(a),      0, radius * sin(a));
        glVertex3f(radius * cos(a), height, radius * sin(a));
        glVertex3f(radius * cos(aNext), height, radius * sin(aNext));
        
        // Segundo triângulo da fatia
        glVertex3f(radius * cos(aNext), height, radius * sin(aNext));
        glVertex3f(radius * cos(aNext),      0, radius * sin(aNext));
        glVertex3f(radius * cos(a),      0, radius * sin(a));
    }
    glEnd();

    // Desenha a base inferior usando GL_TRIANGLE_FAN
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, 0, 0); // Centro da base inferior
    for (int i = 0; i <= slices; i++) {
        float a = i * angle;
        glVertex3f(radius * cos(a), 0, radius * sin(a));
    }
    glEnd();

    // Desenha a base superior usando GL_TRIANGLE_FAN
    // Inverte a ordem dos vértices para que a face fique voltada para cima
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0, height, 0); // Centro da base superior
    for (int i = slices; i >= 0; i--) {
        float a = i * angle;
        glVertex3f(radius * cos(a), height, radius * sin(a));
    }
    glEnd();
}


void renderScene(void) {
    // Limpa os buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Define o modo de desenho para wireframe (para faces frontais e traseiras)
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // Se preferir preenchido, utilize:
    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // Cálculo da posição da câmera a partir de coordenadas esféricas
    float eyeX = cam_radius * sin(cam_phi) * cos(cam_theta);
    float eyeY = cam_radius * cos(cam_phi);
    float eyeZ = cam_radius * sin(cam_phi) * sin(cam_theta);
    
    // Define a câmera
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, eyeZ, 
              0.0, 0.0, 0.0,   // ponto observado
              0.0, 1.0, 0.0);  // vetor "up"
 
    // Desenha o cilindro
    drawCylinder(1, 2, 100);
 
    // Finaliza o frame
    glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {
	
}

void processSpecialKeys(int key, int xx, int yy) {
	// Utilize as teclas seta para mover a câmera
    switch (key) {
        case GLUT_KEY_LEFT:
            cam_theta -= 0.05f;
            break;
        case GLUT_KEY_RIGHT:
            cam_theta += 0.05f;
            break;
        case GLUT_KEY_UP:
            cam_phi -= 0.05f;
            if (cam_phi < 0.05f)
                cam_phi = 0.05f;
            break;
        case GLUT_KEY_DOWN:
            cam_phi += 0.05f;
            if (cam_phi > M_PI - 0.05f)
                cam_phi = M_PI - 0.05f;
            break;
    }
    // Redesenhar a cena
    glutPostRedisplay();
}


int main(int argc, char **argv) {

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	
// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}

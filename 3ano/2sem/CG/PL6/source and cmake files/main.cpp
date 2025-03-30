#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>

#include <devIL/il.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

// Parâmetros iniciais da câmera
float camX = 0, camY = 30, camZ = 40;
int startX, startY, tracking = 0;
int alpha = 0, beta = 45, r = 50;

// Variáveis globais para o terreno
GLuint terrainVBO;
float *terrainVertices = NULL;
int gridWidth = 0, gridHeight = 0;
int numStrips = 0, verticesPerStrip = 0, totalVertices = 0;
  
// Função que retorna a altura (y) para o vértice (i,j)
// escala 0–255 para 0–30 metros
float h(int i, int j, const unsigned char *heightData) {
    int index = j * gridWidth + i;
    return (heightData[index] / 255.0f) * 30.0f;
}

void changeSize(int w, int h) {
    if(h == 0)
        h = 1;
    float ratio = w * 1.0f / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void drawTerrain() {
    // Ativa estados necessários
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    
    GLfloat light_position[] = { 0.0f, 1.0f, 1.0f, 0.0f };
    GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    
    glLightfv(GL_LIGHT_POSITION, light_position);
    glLightfv(GL_LIGHT_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT_SPECULAR, light_specular);
    glLightfv(GL_LIGHT_AMBIENT, light_ambient);
    
    // Renderiza o terreno usando VBOs
    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);
    glVertexPointer(3, GL_FLOAT, 0, 0);
    
    // Desenha cada triangle strip (um por linha da grade, exceto a última)
    for (int j = 0; j < numStrips; j++) {
        int first = j * verticesPerStrip;
        glDrawArrays(GL_TRIANGLE_STRIP, first, verticesPerStrip);
    }
    
    glDisableClientState(GL_VERTEX_ARRAY);
}

void renderScene(void) {
    float pos[4] = {-1.0, 1.0, 1.0, 0.0};

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glLoadIdentity();
    gluLookAt(camX, camY, camZ,
              0.0, 0.0, 0.0,
              0.0f, 1.0f, 0.0f);
    
    drawTerrain();
    
    // Apenas para teste: desenha um teapot se desejar
    // glutWireTeapot(2.0);

    glutSwapBuffers();
}

void processKeys(unsigned char key, int xx, int yy) {
    // Processamento do teclado (pode ser implementado conforme necessário)
}

void processMouseButtons(int button, int state, int xx, int yy) {
    if (state == GLUT_DOWN)  {
        startX = xx;
        startY = yy;
        if (button == GLUT_LEFT_BUTTON)
            tracking = 1;
        else if (button == GLUT_RIGHT_BUTTON)
            tracking = 2;
        else
            tracking = 0;
    }
    else if (state == GLUT_UP) {
        if (tracking == 1) {
            alpha += (xx - startX);
            beta += (yy - startY);
        }
        else if (tracking == 2) {
            r -= yy - startY;
            if (r < 3)
                r = 3;
        }
        tracking = 0;
    }
}

void processMouseMotion(int xx, int yy) {
    int deltaX, deltaY;
    int alphaAux, betaAux;
    int rAux;
    
    if (!tracking)
        return;
    
    deltaX = xx - startX;
    deltaY = yy - startY;
    
    if (tracking == 1) {
        alphaAux = alpha + deltaX;
        betaAux = beta + deltaY;
        if (betaAux > 85)
            betaAux = 85;
        else if (betaAux < -85)
            betaAux = -85;
        rAux = r;
    }
    else if (tracking == 2) {
        alphaAux = alpha;
        betaAux = beta;
        rAux = r - deltaY;
        if (rAux < 3)
            rAux = 3;
    }
    camX = rAux * sin(alphaAux * M_PI / 180.0) * cos(betaAux * M_PI / 180.0);
    camZ = rAux * cos(alphaAux * M_PI / 180.0) * cos(betaAux * M_PI / 180.0);
    camY = rAux * sin(betaAux * M_PI / 180.0);
}

void init() {
    unsigned int t, tw, th;
    unsigned char *imageData;
    ILuint imgID;
    
    // Inicializa DevIL
    ilInit();
    
    // Carrega a imagem do height map (substitua "heightmap.png" pelo seu arquivo)
    ilGenImages(1, &imgID);
    ilBindImage(imgID);
    if(!ilLoadImage("heightmap.png")) {
        printf("Erro ao carregar a imagem do height map\n");
        exit(1);
    }
    // Converte a imagem para um formato de 1 canal (luminância)
    ilConvertImage(IL_LUMINANCE, IL_UNSIGNED_BYTE);
    
    // Obtém as dimensões da imagem
    gridWidth = ilGetInteger(IL_IMAGE_WIDTH);
    gridHeight = ilGetInteger(IL_IMAGE_HEIGHT);
    imageData = ilGetData();
    
    // Calcula quantos triangle strips e quantos vértices por strip
    numStrips = gridHeight - 1;
    verticesPerStrip = gridWidth * 2; // cada strip une duas linhas da grade
    
    totalVertices = numStrips * verticesPerStrip;
    // Aloca array para os vértices (x,y,z para cada vértice)
    terrainVertices = new float[totalVertices * 3];
    
    // Preenche o array de vértices
    // Para cada par de linhas j e j+1
    int index = 0;
    for (int j = 0; j < gridHeight - 1; j++) {
        for (int i = 0; i < gridWidth; i++) {
            // Vértice da linha j
            terrainVertices[index++] = i; // x
            terrainVertices[index++] = h(i, j, imageData); // y: altura do pixel escalada
            terrainVertices[index++] = j; // z
            
            // Vértice da linha j+1
            terrainVertices[index++] = i; // x
            terrainVertices[index++] = h(i, j+1, imageData);
            terrainVertices[index++] = j+1; // z
        }
    }
    
    // Gera e transfere os dados para o VBO do terreno
    glGenBuffers(1, &terrainVBO);
    glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);
    glBufferData(GL_ARRAY_BUFFER, totalVertices * 3 * sizeof(float), terrainVertices, GL_STATIC_DRAW);
    
    // Libera a memória do array se desejado (os dados já estão no VBO)
    delete [] terrainVertices;
}

int main(int argc, char **argv) {
    // Inicializa GLUT e cria a janela
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(320,320);
    glutCreateWindow("CG@DI-UM");
    
    // Registra callbacks
    glutDisplayFunc(renderScene);
    glutIdleFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutKeyboardFunc(processKeys);
    glutMouseFunc(processMouseButtons);
    glutMotionFunc(processMouseMotion);
    
    init();
    
    // Entra no loop principal do GLUT
    glutMainLoop();
    
    return 0;
}


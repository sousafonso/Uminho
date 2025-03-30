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

// Parâmetros iniciais da câmera (posição e orientação de primeira pessoa)
float camX = 10.0f, camY = 0.0f, camZ = 10.0f;  // posição inicial
float camYaw = -90.0f, camPitch = 0.0f;          // ângulos de orientação (em graus)
float eyeHeight = 2.0f;                          // altura em relação ao terreno
float moveSpeed = 0.5f, lookSpeed = 2.0f;

// Variáveis para controle do mouse (opcional, se desejar implementar look-around com mouse)
int startX, startY, tracking = 0;
int alpha = 0, beta = 45, r = 50;  // estes podem ser removidos se não usados para orbit

// Variáveis globais para o terreno
GLuint terrainVBO;
float *terrainVertices = NULL;
int gridWidth = 0, gridHeight = 0;
int numStrips = 0, verticesPerStrip = 0, totalVertices = 0;
unsigned char *heightMapData = NULL;  // guarda os dados do height map

// Função que retorna a altura (y) para o vértice (i,j)
// escala 0–255 para 0–30 metros
float h(int i, int j, const unsigned char *heightData) {
    int index = j * gridWidth + i;
    return (heightData[index] / 255.0f) * 30.0f;
}

// Função para obter a altura no mundo (x,z) a partir do height map
float getHeightAt(float x, float z) {
    int i = (int)x, j = (int)z;
    if(i < 0 || i >= gridWidth || j < 0 || j >= gridHeight)
        return 0.0f;
    return h(i, j, heightMapData);
}

// Função que retorna a altura de um ponto qualquer do terreno (interpolação linear)
float hf(float px, float pz) {
    int x1 = floor(px), x2 = x1 + 1;
    int z1 = floor(pz), z2 = z1 + 1;

    float fz = pz - z1;
    float fx = px - x1;

    // Interpolação nas direções X e Z
    float h_x1_z = h(x1, z1, heightMapData) * (1 - fz) + h(x1, z2, heightMapData) * fz;
    float h_x2_z = h(x2, z1, heightMapData) * (1 - fz) + h(x2, z2, heightMapData) * fz;

    // Interpolação final para o ponto (px, pz)
    return h_x1_z * (1 - fx) + h_x2_z * fx;
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
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Atualiza a altura da câmera para seguir o terreno
    camY = hf(camX, camZ) + eyeHeight;
    
    // Calcula o vetor "front" a partir do yaw e pitch
    float frontX = cos(camYaw * M_PI/180.0f) * cos(camPitch * M_PI/180.0f);
    float frontY = sin(camPitch * M_PI/180.0f);
    float frontZ = sin(camYaw * M_PI/180.0f) * cos(camPitch * M_PI/180.0f);
    
    glLoadIdentity();
    gluLookAt(camX, camY, camZ,
              camX + frontX, camY + frontY, camZ + frontZ,
              0.0f, 1.0f, 0.0f);
    
    drawTerrain();
    
    glutSwapBuffers();
}

void processKeys(unsigned char key, int xx, int yy) {
    // Calcula o vetor "front"
    float frontX = cos(camYaw * M_PI/180.0f) * cos(camPitch * M_PI/180.0f);
    float frontZ = sin(camYaw * M_PI/180.0f) * cos(camPitch * M_PI/180.0f);
    // Vetor "right" (produto vetorial entre front e up=(0,1,0))
    float rightX = frontZ;
    float rightZ = -frontX;
    
    switch(key) {
        // Movimento para frente e para trás
        case 'w':
        case 'W':
            camX += moveSpeed * frontX;
            camZ += moveSpeed * frontZ;
            break;
        case 's':
        case 'S':
            camX -= moveSpeed * frontX;
            camZ -= moveSpeed * frontZ;
            break;
        // Movimento lateral
        case 'a':
        case 'A':
            camX -= moveSpeed * rightX;
            camZ -= moveSpeed * rightZ;
            break;
        case 'd':
        case 'D':
            camX += moveSpeed * rightX;
            camZ += moveSpeed * rightZ;
            break;
        // Alteração da visão com setas (alternativamente, use outras teclas)
        case 27: // ESC para sair
            exit(0);
            break;
    }
    glutPostRedisplay();
}

void processSpecialKeys(int key, int xx, int yy) {
    // Usa as setas para alterar os ângulos de orientação
    switch(key) {
        case GLUT_KEY_LEFT:
            camYaw -= lookSpeed;
            break;
        case GLUT_KEY_RIGHT:
            camYaw += lookSpeed;
            break;
        case GLUT_KEY_UP:
            camPitch += lookSpeed;
            if(camPitch > 89.0f)
                camPitch = 89.0f;
            break;
        case GLUT_KEY_DOWN:
            camPitch -= lookSpeed;
            if(camPitch < -89.0f)
                camPitch = -89.0f;
            break;
    }
    glutPostRedisplay();
}

void init() {
    unsigned int t, tw, th;
    ILuint imgID;
    unsigned char *imageData;
    
    // Inicializa DevIL
    ilInit();
    
    // Carrega a imagem do height map (substitua "terreno.jpg" pelo seu arquivo)
    ilGenImages(1, &imgID);
    ilBindImage(imgID);
    if(!ilLoadImage("terreno.jpg")) {
        printf("Erro ao carregar a imagem do height map\n");
        exit(1);
    }
    // Converte a imagem para um formato de 1 canal (luminância)
    ilConvertImage(IL_LUMINANCE, IL_UNSIGNED_BYTE);
    
    // Obtém as dimensões da imagem e guarda os dados para uso na câmera
    gridWidth = ilGetInteger(IL_IMAGE_WIDTH);
    gridHeight = ilGetInteger(IL_IMAGE_HEIGHT);
    heightMapData = ilGetData();
    
    // Calcula quantos triangle strips e vértices por strip
    numStrips = gridHeight - 1;
    verticesPerStrip = gridWidth * 2; // cada strip une duas linhas da grade
    totalVertices = numStrips * verticesPerStrip;
    
    // Aloca array para os vértices (x,y,z para cada vértice)
    terrainVertices = new float[totalVertices * 3];
    
    // Preenche o array de vértices para cada par de linhas (j e j+1)
    int index = 0;
    for (int j = 0; j < gridHeight - 1; j++) {
        for (int i = 0; i < gridWidth; i++) {
            // Vértice da linha j
            terrainVertices[index++] = i;                           // x
            terrainVertices[index++] = h(i, j, heightMapData);        // y: altura escalada
            terrainVertices[index++] = j;                           // z
            
            // Vértice da linha j+1
            terrainVertices[index++] = i;                           // x
            terrainVertices[index++] = h(i, j+1, heightMapData);      // y
            terrainVertices[index++] = j+1;                         // z
        }
    }
    
    // Gera e transfere os dados para o VBO do terreno
    glGenBuffers(1, &terrainVBO);
    glBindBuffer(GL_ARRAY_BUFFER, terrainVBO);
    glBufferData(GL_ARRAY_BUFFER, totalVertices * 3 * sizeof(float), terrainVertices, GL_STATIC_DRAW);
    
    // Libera a memória do array (os dados já estão no VBO)
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
    glutSpecialFunc(processSpecialKeys);
    
    init();
    
    // Entra no loop principal do GLUT
    glutMainLoop();
    
    return 0;
}

#include "SOIL/SOIL.h"
#include <GL/freeglut.h> 
#include <stdlib.h> 
#include <stdio.h>
#include "Sprite.h"
#include "Sprite.cpp"

Sprite* background;
Sprite* player;
GLuint texture;


#pragma warning(disable: 4996)

const bool LoadTextures()
{
  background = new Sprite(1);
  background->SetFrameSize(256.0f, 256.0f);
  background->SetNumberOfFrames(1);
  background->AddTexture("Assets/bw.png", false);
  background->IsVisible(true);
  background->IsActive(true);
  background->SetVelocity(-50.0f);
 
  
  return true;
}

const bool initGL() {

    glEnable(GL_TEXTURE_2D);
    glClearColor(0.0f, 0.0f ,0.0f , 1.0f);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glDisable(GL_DEPTH_TEST);
    return true;
}

void StartGame() {
    LoadTextures();
}
void Render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    background->Render();
    glutSwapBuffers();
}

void Update(const float p_deltaTime) {
    background->Update(p_deltaTime);
}

void GameLoop(const float p_deltatTime) {
    Update(p_deltatTime);
    Render();
}
int main(int argc, char** argv)
{   
    glutInit(&argc, argv);
    glutCreateWindow("Sky Golem");
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(50, 50);
    initGL();
    StartGame();
    int previousTime = glutGet(GLUT_ELAPSED_TIME);
    while (1){
        int currentTime = glutGet(GLUT_ELAPSED_TIME);
			float deltaTime = (float)(currentTime - previousTime) / 1000;
			previousTime = currentTime;
			GameLoop(deltaTime);
    }
   
	return 0;
}

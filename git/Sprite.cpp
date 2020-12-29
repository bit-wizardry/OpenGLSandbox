#include "SOIL/SOIL.h"
#include "stdlib.h"
#include "Sprite.h"
//#include <GL/freeglut.h>

Sprite::Sprite(const unsigned int p_numberOfTextures)
{  
  m_textures = new GLuint[p_numberOfTextures];
  m_textureIndex = 0;
  m_currentFrame = 0;
  m_numberOfFrames = 0;
  m_animationDelay = 0.25f;
  m_animationElapsed = 0.0f;
  m_position.x = 0.0f;
  m_position.y = 0.0f;
  m_size.height = 0.0f;
  m_size.width = 0.0f;
  m_velocity = 0.0f;
  
  m_isCollideable = true;
  m_flipHorizontal = false;
  m_flipVertical = false;
  m_isVisible = false;
  m_isActive = false;
  m_isSpriteSheet = false;
}

Sprite::~Sprite()
{
  delete[] m_textures;
}

const bool Sprite::AddTexture(const char* p_imageName, const bool p_useTransparency) {
  
  GLuint texture = SOIL_load_OGL_texture(p_imageName, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0);
  
  if (texture == 0)
  {
    return false;
  }
  m_textures[m_textureIndex] = texture;
  m_textureIndex++;
  if (m_textureIndex == 1 && m_numberOfFrames > 1) {
    m_isSpriteSheet = true;
  }
  else
  {
    m_isSpriteSheet = false;
  }
  m_useTransparency = p_useTransparency;
  return true;
}
  void Sprite::Render() {
    if (m_isVisible){

    if (m_useTransparency) {
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    glBindTexture(GL_TEXTURE_2D, GetCurrentFrame());
    glBegin(GL_QUADS);
    GLfloat x = m_position.x;
    GLfloat y = m_position.y;
    GLfloat w = m_size.width;
    GLfloat h = m_size.height;
    GLfloat texWidth = (GLfloat)m_textureIndex / (GLfloat)m_numberOfFrames;
    GLfloat texHeight = 1.0f;
    GLfloat u = 0.0f;
    GLfloat v = 0.0f;
    if (m_textureIndex < m_numberOfFrames){
      u = (GLfloat)m_currentFrame * texWidth;
    }
    glTexCoord2f(u,v); glVertex2f(x,y);
    glTexCoord2f(u + texWidth, v); glVertex2f(x + w, y);
    glTexCoord2f(u + texWidth, v + texHeight); glVertex2f(x + w, y + h);
    glTexCoord2f(u, v + texHeight); glVertex2f(x, y + h);
    glEnd();
    if (m_useTransparency) {
      glDisable(GL_BLEND);
    }
  }
  }

void Sprite::Update(const float p_deltaTime) {
  float dt = p_deltaTime;

  if (m_isActive) {
    m_animationElapsed += dt;
    if (m_animationElapsed >= m_animationDelay) {
      m_currentFrame++;
      if (m_currentFrame >= m_numberOfFrames) m_currentFrame = 0;
      m_animationElapsed = 0.0f;
    }
    m_position.x = m_position.x + m_velocity * dt;
  }
}
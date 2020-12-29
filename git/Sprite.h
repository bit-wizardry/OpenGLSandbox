#pragma once
#include "SOIL/SOIL.h"
#include <GL/freeglut.h>

class Sprite {
    public:

    struct Point {
        GLfloat x;
        GLfloat y;
    };

    struct Size {
        GLfloat width;
        GLfloat height;
    };
    struct Rect {
        GLfloat top;
        GLfloat bottom;
        GLfloat left;
        GLfloat right;
    };

    protected:
    GLuint* m_textures;
    unsigned int m_textureIndex;
    unsigned int m_currentFrame;
    unsigned int m_numberOfFrames;
    GLfloat m_animationDelay;
    GLfloat m_animationElapsed;

    Point m_position;
    Size m_size;
    GLfloat m_velocity;

    bool m_isCollideable;
    bool m_flipHorizontal;
    bool m_flipVertical;
    bool m_isVisible;
    bool m_isActive;
    bool m_useTransparency;
    bool m_isSpriteSheet;

    public:
    Sprite (const unsigned int m_pNumberOfTextures);
    ~Sprite();

    void Update(const float p_deltaTime);
    void Render();

    const bool AddTexture(const char* p_fileName, const bool p_useTransparency = true);

    const GLuint GetCurrentFrame() {
        if (m_isSpriteSheet){
            return m_textures[0];
        }
        else {
            return m_textures[m_currentFrame];
        }
        
    }

        void SetPosition (const GLfloat p_x, const GLfloat p_y) { m_position.x = p_x; m_position.y = p_y; }
        void SetPosition(const Point p_position) { m_position = p_position; }
        const Point GetPosition() { return m_position; }
        const Size GetSize() const { return m_size; }
        void SetFrameSize(const GLfloat p_width, const GLfloat p_height) { m_size.width = p_width; m_size.height = p_height; }
        void SetVelocity(const GLfloat p_velocity) { m_velocity = p_velocity; }
        void SetNumberOfFrames(const unsigned int p_frames) { m_numberOfFrames = p_frames;  }
        const bool isCollideable() const { return m_isCollideable; }
        void IsCollideable(const bool p_value) { m_isCollideable = p_value;  }
        void FlipHorizontal(const bool p_value) { m_flipHorizontal = p_value; }
        void FlipVertical(const bool p_value) { m_flipVertical = p_value; }
        void IsActive(const bool p_value) { m_isActive = p_value; }
        const bool IsActive() const { return m_isActive; }
        void IsVisible(const bool p_value) { m_isVisible = p_value; }
        const bool IsVisible() const { return m_isVisible; }
        void UseTransparency(const bool p_value) { m_useTransparency = p_value; }
        // void Render() {
        //         if (m_isVisible)
        //         {
        //           if (m_useTransparency)
        //           {
        //             glEnable(GL_BLEND);
        //             glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        //           }
                  
        //           glBindTexture(GL_TEXTURE_2D, GetCurrentFrame());
                  
        //           glBegin(GL_QUADS);
                  
        //           GLfloat x = m_position.x;
        //           GLfloat y = m_position.y;
                  
        //           GLfloat w = m_size.width;
        //           GLfloat h = m_size.height;
                  
        //           GLfloat texWidth = (GLfloat)m_textureIndex / (GLfloat)m_numberOfFrames;
        //           GLfloat texHeight = 1.0f;
        //           GLfloat u = 0.0f;
        //           GLfloat v = 0.0f;
        //           if (m_textureIndex < m_numberOfFrames)
        //           {
        //             u = (GLfloat)m_currentFrame * texWidth;
        //           }
        //           glTexCoord2f(u, v); glVertex2f(x, y);
        //           glTexCoord2f(u + texWidth, v); glVertex2f(x + w, y);
        //           glTexCoord2f(u + texWidth, v + texHeight); glVertex2f(x + w, y + h);
        //           glTexCoord2f(u, v + texHeight); glVertex2f(x, y + h);
                  
        //           glEnd();
                  
        //           if (m_useTransparency)
        //           {
        //             glDisable(GL_BLEND);
        //           }
        //         }
        //       }

// void Update(const float p_deltaTime) {
//     float dt = p_deltaTime;

//     if (m_isActive) {

//       m_animationElapsed += dt;
       
//        if  (m_animationElapsed >= m_animationDelay) {
            
//             m_currentFrame++;
            
//             if (m_currentFrame >= m_numberOfFrames) m_currentFrame = 0;
              
//               m_animationElapsed = 0.0f;
//         }
//         m_position.x = m_position.x + m_velocity * dt;
//     }
// }

// void Render() {
//   if (m_isVisible){
//     if (m_useTransparency){
//       glEnable(GL_BLEND);
//       glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//     }
//     glBindTexture(GL_TEXTURE_2D, GetCurrentFrame());

//     glBegin(GL_QUADS);

//     GLfloat x = m_position.x;
//     GLfloat y = m_position.y;

//     GLfloat w = m_size.width;
//     GLfloat h = m_size.height;

//     GLfloat texWidth = (GLfloat)m_textureIndex / (GLfloat)m_numberOfFrames;
//     GLfloat texHeight = 1.0f;
//     GLfloat u = 0.0f;
//     GLfloat v = 0.0f;
//     if (m_textureIndex < m_numberOfFrames) {
//       u = (GLfloat)m_currentFrame * texWidth;
//     }
//     glTexCoord2f(u, v); glVertex2f(x, y);
//     glTexCoord2f(u + texWidth, v); glVertex2f(x + w, y);
//     glTexCoord2f(u + texWidth, v + texHeight); glVertex2f(x + w, y + h);
//     glTexCoord2f(u,v + texHeight); glVertex2f(x, y + h);

//     glEnd();

//     if (m_useTransparency) {
//       glDisable(GL_BLEND);
//     }
//   }
// }


};





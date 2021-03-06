//----------------------------------------------------------------------------------------------------------------------
/// @file GLTexture.h
/// @class GLTextureLib
/// @author Declan Russell
/// @date 28/04/2015
/// @version 1.0
/// @brief Simple class for loading in and managing OpenGL textures
//----------------------------------------------------------------------------------------------------------------------

#ifndef GLTEXTURE_H
#define GLTEXTURE_H

#ifdef DARWIN
    #include <GLFW/glfw3.h>
    #include <OpenGL/gl3.h>
#else
    #include <GL/glew.h>
    #include <GL/gl.h>
#endif

#include "AbstractOpenGLObject.h"

class GLTexture : public AbstractOpenGlObject
{
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Constructor that creates our texture on our GPU
    /// @brief See OpenGL documentation for detail about texture paramiters
    //----------------------------------------------------------------------------------------------------------------------
    GLTexture(GLenum _target, GLint _level, GLint _internalFormat, GLsizei _width, GLsizei _height, GLint _border, GLenum _format, GLenum _type, const GLvoid * _data);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Constructor that creates a cube map texture on our GPU
    /// @brief See OpenGL documentation for detail about texture paramiters
    //----------------------------------------------------------------------------------------------------------------------
    GLTexture(GLenum _target, GLint _level, GLint _internalFormat, GLsizei _width, GLsizei _height, GLint _border, GLenum _format, GLenum _type, const GLvoid * _front, const GLvoid * _back, const GLvoid * _top, const GLvoid * _bottom, const GLvoid * _left, const GLvoid * _right);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief our destrutor that removes our texture
    //----------------------------------------------------------------------------------------------------------------------
    ~GLTexture();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief set our texture integer paramiters same as glTexParamiteri see OpenGL documentation for more info
    //----------------------------------------------------------------------------------------------------------------------
    void setTexParamiteri(GLenum _pname, GLint _param);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief set our texture float paramiters same as glTexParamiterf see OpenGL documentation for more info
    //----------------------------------------------------------------------------------------------------------------------
    void setTexParamiterf(GLenum _pname, GLfloat _param);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief resizes our texture
    /// @param _width - width to resize texture
    /// @param _height - height to resize texture
    //----------------------------------------------------------------------------------------------------------------------
    void resize(GLsizei _width,GLsizei _height = 0);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief set the data of our textue
    /// @param _data - data to set to texture
    //----------------------------------------------------------------------------------------------------------------------
    void setData(const GLvoid * _data, GLsizei _width = -1,GLsizei _height = -1);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief set the data for a cube map texture
    //----------------------------------------------------------------------------------------------------------------------
    void setData(const GLvoid * _front, const GLvoid * _back, const GLvoid * _top, const GLvoid * _bottom, const GLvoid * _left, const GLvoid * _right, GLsizei _width = -1,GLsizei _height = -1);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief binds our texture and set active texture
    /// @param _loc - active texture location to bind to
    //----------------------------------------------------------------------------------------------------------------------
    void bind(unsigned int _loc);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief binds our texture
    //----------------------------------------------------------------------------------------------------------------------
    void bind();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief unbinds our texture
    //----------------------------------------------------------------------------------------------------------------------
    void unbind();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief accessor to the handle of our texture
    //----------------------------------------------------------------------------------------------------------------------
    inline GLuint getHandle(){return m_handle;}
    //----------------------------------------------------------------------------------------------------------------------
private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief default construtor never to be used.
    //----------------------------------------------------------------------------------------------------------------------
    GLTexture(){}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief bool to define if our texture is a cube map
    //----------------------------------------------------------------------------------------------------------------------
    bool m_isCubeMap;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief LOD detail number
    //----------------------------------------------------------------------------------------------------------------------
    GLint m_level;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief internal format
    //----------------------------------------------------------------------------------------------------------------------
    GLint m_internalFormat;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief width of our texture
    //----------------------------------------------------------------------------------------------------------------------
    GLsizei m_width;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief height of our texture
    //----------------------------------------------------------------------------------------------------------------------
    GLsizei m_height;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief border size of our texture
    //----------------------------------------------------------------------------------------------------------------------
    GLint m_border;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief format of our texture
    //----------------------------------------------------------------------------------------------------------------------
    GLenum m_format;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief type of pixel data
    //----------------------------------------------------------------------------------------------------------------------
    GLenum m_type;
    //----------------------------------------------------------------------------------------------------------------------
};

#endif // GLTEXTURE_H

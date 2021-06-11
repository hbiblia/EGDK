#include "ermine_backend_opengl.h"

void ermine_backend_clear_color(ermine_color color)
{
    float r = (float)color.r/255;
    float g = (float)color.g/255;
    float b = (float)color.b/255;
    float a = (float)color.a/255;

    glClearColor(r,g,b,a);
}

void ermine_backend_clear_screen_buffers(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ermine_backend_load_identity(void)
{
    #if defined(BACKEND_OPENGL_11)
        glLoadIdentity();
    #endif
}

void ermine_backend_push_matrix(void)
{
    #if defined(BACKEND_OPENGL_11)
        glPushMatrix();
    #endif
}

void ermine_backend_pop_matrix(void)
{
    #if defined(BACKEND_OPENGL_11)
        glPopMatrix();
    #endif
}

void ermine_backend_mult_matrix(float *matf)
{
    #if defined(BACKEND_OPENGL_11)
        glMultMatrixf(matf);
    #endif
}

void ermine_backend_matrix_mode(ermine_matrix_mode mode)
{
    #if defined(BACKEND_OPENGL_11)
        switch(mode)
        {
            case ERMINE_GFX_PROJECTION: glMatrixMode(GL_PROJECTION); break;
            case ERMINE_GFX_MODELVIEW: glMatrixMode(GL_MODELVIEW); break;
            case ERMINE_GFX_TEXTURE: glMatrixMode(GL_TEXTURE); break;
            default: break;
        }
    #endif
}

void ermine_backend_translatef(float x, float y, float z)
{
    #if defined(BACKEND_OPENGL_11)
        glTranslatef(x,y,z);
    #endif
}

void ermine_backend_rotatef(float angle, float x, float y, float z)
{
    #if defined(BACKEND_OPENGL_11)
        glRotatef(angle, x, y, z);
    #endif
}

void ermine_backend_scalef(float x, float y, float z)
{
    #if defined(BACKEND_OPENGL_11)
        glScalef(x,y,z);
    #endif
}

void ermine_backend_ortho(double left, double right, double bottom, double top, double znear, double zfar)
{
    #if defined(BACKEND_OPENGL_11)
        glOrtho(left, right, bottom, top, znear, zfar);
    #endif
}

void ermine_backend_frustum(double left, double right, double bottom, double top, double znear, double zfar)
{
    #if defined(BACKEND_OPENGL_11)
        glFrustum(left, right, bottom, top, znear, zfar);
    #endif
}

void ermine_backend_viewport(int x, int y, int width, int height)
{
    glViewport(x, y, width, height);
}

void ermine_backend_begin(ermine_primitives_mode mode)
{
    #if defined(BACKEND_OPENGL_11)
        switch(mode)
        {
            case ERMINE_GFX_LINES: glBegin(GL_LINES); break;
            case ERMINE_GFX_TRIANGLES: glBegin(GL_TRIANGLES); break;
            case ERMINE_GFX_QUADS: glBegin(GL_QUADS); break;
            default: break;
        }
    #endif
}

void ermine_backend_end(void)
{
    #if defined(BACKEND_OPENGL_11)
        glEnd();
    #endif
}

void ermine_backend_vertex2i(int x, int y)
{
    #if defined(BACKEND_OPENGL_11)
        glVertex2i(x,y);
    #endif
}

void ermine_backend_vertex2f(float x, float y)
{
    #if defined(BACKEND_OPENGL_11)
        glVertex2f(x,y);
    #endif
}

void ermine_backend_vertex3f(float x, float y, float z)
{
    #if defined(BACKEND_OPENGL_11)
        glVertex3f(x,y,z);
    #endif
}

void ermine_backend_texcoord2f(float x, float y)
{
    #if defined(BACKEND_OPENGL_11)
        glTexCoord2f(x,y);
    #endif
}

void ermine_backend_normal3f(float x, float y, float z)
{
    #if defined(BACKEND_OPENGL_11)
        glNormal3f(x,y,z);
    #endif
}

void ermine_backend_color4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    #if defined(BACKEND_OPENGL_11)
        glColor4ub(r,g,b,a);
    #endif
}

void ermine_backend_color3f(float r, float g, float b)
{
    #if defined(BACKEND_OPENGL_11)
        glColor3f(r,g,b);
    #endif
}

void ermine_backend_color4f(float r, float g, float b, float a)
{
    #if defined(BACKEND_OPENGL_11)
        glColor4f(r,g,b,a);
    #endif
}

void ermine_backend_texture_enable(unsigned int id)
{
    #if defined(BACKEND_OPENGL_11)
        glEnable(GL_TEXTURE_2D);
    #endif
}

void ermine_backend_texture_disable(void)
{
    #if defined(BACKEND_OPENGL_11)
        glDisable(GL_TEXTURE_2D);
    #endif
}
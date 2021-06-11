#ifndef ERMINE_BACKEND_OPENGL_H
#define ERMINE_BACKEND_OPENGL_H
#include <stdio.h>
// #include <epoxy/gl.h>
#include "ermine_gfx_color.h"
#include "ermine_gfx.h"

void ermine_backend_clear_color(ermine_color color);
void ermine_backend_clear_screen_buffers(void);

void ermine_backend_load_identity(void);
void ermine_backend_push_matrix(void);
void ermine_backend_pop_matrix(void);
void ermine_backend_mult_matrix(float *matf);
void ermine_backend_matrix_mode(ermine_matrix_mode mode);

void ermine_backend_translatef(float x, float y, float z);
void ermine_backend_rotatef(float angle, float x, float y, float z);
void ermine_backend_scalef(float x, float y, float z);

void ermine_backend_ortho(double left, double right, double bottom, double top, double znear, double zfar);
void ermine_backend_frustum(double left, double right, double bottom, double top, double znear, double zfar);
void ermine_backend_viewport(int x, int y, int width, int height);
void ermine_backend_begin(ermine_primitives_mode mode);
void ermine_backend_end(void);

void ermine_backend_vertex2i(int x, int y);
void ermine_backend_vertex2f(float x, float y);
void ermine_backend_vertex3f(float x, float y, float z);
void ermine_backend_texcoord2f(float x, float y);
void ermine_backend_normal3f(float x, float y, float z);
void ermine_backend_color4ub(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void ermine_backend_color3f(float r, float g, float b);
void ermine_backend_color4f(float r, float g, float b, float a);

void ermine_backend_texture_enable(unsigned int id);
void ermine_backend_texture_disable(void);

#endif

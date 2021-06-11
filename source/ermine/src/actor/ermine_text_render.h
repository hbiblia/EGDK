#pragma once
#ifndef __ERMINE_TEXT_RENDER_H__
#define __ERMINE_TEXT_RENDER_H__
#include "ermine_actor.h"
#include "../ermine.h"

G_BEGIN_DECLS

// -----------------------
// --- DEFINE ABS
// -----------------------

typedef struct _ErmineTextRenderPrivate ErmineTextRenderPrivate;

#define ERMINE_TYPE_TEXT_RENDER ermine_text_render_get_type()
G_DECLARE_FINAL_TYPE(ErmineTextRender, ermine_text_render, ERMINE, TEXT_RENDER, ErmineActor)

struct _ErmineTextRenderPrivate
{
    ErmineActor parent_instance;
    Font font;
    Color color;
    char *str;
    int fontSize;
    float spacing;
    Vector2 size;
    bool wordWrap;
    bool dynamic;
};

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_text_render_new(Scene *scene, const char *str);
ErmineActor *ermine_text_render_with_new(Scene *scene, const char *str, int fontSize, Color color);

void ermine_text_font_size_set(ErmineActor *self, int fontSize);
int ermine_text_font_size_get(ErmineActor *self);

void ermine_text_color_set(ErmineActor *self, Color color);
Color ermine_text_color_get(ErmineActor *self);

void ermine_text_set(ErmineActor *self, const char *str);
const char *ermine_text_get(ErmineActor *self);

void ermine_text_font_set(ErmineActor *self, const char *key);
Font ermine_text_font_get(ErmineActor *self);

void ermine_text_spacing_set(ErmineActor *self, float spacing);
float ermine_text_spacing_get(ErmineActor *self);

Vector2 ermine_text_size_get(ErmineActor *self);
void ermine_text_size_set(ErmineActor *self, Vector2 size);

void ermine_text_wrap_set(ErmineActor *self, bool wordWrap);
bool ermine_text_wrap_get(ErmineActor *self);

void ermine_text_dynamic_set(ErmineActor *self, bool dynamic);
bool ermine_text_dynamic_get(ErmineActor *self);

Vector2 ermine_text_measure(ErmineActor *self);

G_END_DECLS

#endif
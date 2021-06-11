#pragma once
#ifndef __ERMINE_SHAPE_RECT_H__
#define __ERMINE_SHAPE_RECT_H__
#include "ermine_shape_class.h"
#include "../ermine.h"

G_BEGIN_DECLS

// -----------------------
// --- DEFINE ABS
// -----------------------

typedef struct _ErmineShapeRectPrivate ErmineShapeRectPrivate;

#define ERMINE_TYPE_SHAPE_RECT ermine_shape_rect_get_type()
G_DECLARE_FINAL_TYPE(ErmineShapeRect, ermine_shape_rect, ERMINE, SHAPE_RECT, ErmineShape)

struct _ErmineShapeRectPrivate{
    ErmineActor parent_instance;
    int w, h;
    Color color;
};

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_shape_rect_new(Scene *scene, int w, int h, Color color);

void ermine_shape_rect_size_set(ErmineActor *self, int w, int h);
Vector2 ermine_shape_rect_size_get(ErmineActor *self);

G_END_DECLS

#endif
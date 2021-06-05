#pragma once
#ifndef __ERMINE_SHAPE_CIRCLE_H__
#define __ERMINE_SHAPE_CIRCLE_H__
#include "eshape_class.h"
#include "ermine.h"

G_BEGIN_DECLS

// -----------------------
// --- DEFINE ABS
// -----------------------

typedef struct _ErmineShapeCirclePrivate ErmineShapeCirclePrivate;

#define ERMINE_TYPE_SHAPE_CIRCLE ermine_shape_circle_get_type()
G_DECLARE_FINAL_TYPE(ErmineShapeCircle, ermine_shape_circle, ERMINE, SHAPE_CIRCLE, ErmineActor)

struct _ErmineShapeCirclePrivate{
    ErmineActor parent_instance;
    float radius;
    int segments;
    Color color;
};

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_shape_circle_new(Scene *scene, float radius, Color color);

void ermine_shape_circle_size_set(ErmineActor *self, float radius);
float ermine_shape_circle_size_get(ErmineActor *self);

void ermine_shape_circle_segments_set(ErmineActor *self, int segments);
int ermine_shape_circle_segments_get(ErmineActor *self);

G_END_DECLS

#endif
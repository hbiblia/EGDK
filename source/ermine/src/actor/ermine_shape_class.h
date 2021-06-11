#pragma once
#ifndef __ERMINE_SHAPE_CLASS_H__
#define __ERMINE_SHAPE_CLASS_H__
#include <stdio.h>
#include "ermine_actor.h"
#include "../ermine.h"

G_BEGIN_DECLS

// -----------------------
// --- DEFINE ABS
// -----------------------

typedef struct _ErmineShape ErmineShape;
typedef struct _ErmineShapeClass ErmineShapeClass;
typedef struct _ErmineShapePrivate ErmineShapePrivate;

#define ERMINE_TYPE_SHAPE ermine_shape_get_type()
G_DECLARE_DERIVABLE_TYPE(ErmineShape, ermine_shape, ERMINE, SHAPE, ErmineActor)

struct _ErmineShapePrivate
{
    ErmineActor parent_instance;
    Color color;
    Color linecolor;
};
struct _ErmineShapeClass
{
    ErmineActorClass parent_class;
};

// -----------------------
// --- METHODS
// -----------------------
void ermine_shape_color_set(ErmineActor *self, Color color);
Color ermine_shape_color_get(ErmineActor *self);

void ermine_shape_line_color_set(ErmineActor *self, Color color);
Color ermine_shape_line_color_get(ErmineActor *self);

G_END_DECLS

#endif
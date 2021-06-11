#pragma once
#ifndef __ERMINE_EACTOR_H__
#define __ERMINE_EACTOR_H__
#include <stdio.h>
#include "ermine_object.h"
#include "../ermine.h"

G_BEGIN_DECLS

// -----------------------
// --- DEFINE ABS
// -----------------------

typedef struct _ErmineActor ErmineActor;
typedef struct _ErmineActorClass ErmineActorClass;
typedef struct _ErmineActorPrivate ErmineActorPrivate;

#define ERMINE_TYPE_ACTOR ermine_actor_get_type()
G_DECLARE_DERIVABLE_TYPE(ErmineActor, ermine_actor, ERMINE, ACTOR, ErmineObject)

struct _ErmineActorPrivate
{
    ErmineObject parent_instance;
    // type
    TACTOR_TYPE type;
    char *tag;
    int flag;
    int index_render;
    //
    bool IsVisible;
    // transform
    Vector2 position;
    Vector2 scale;
    Vector2 pivot;
    float rotation;
    // Total de Size + Pos
    Rectangle BoundingBox;
    // state collision
    int state_collision;
};
struct _ErmineActorClass
{
    ErmineObjectClass parent_class;
};

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_actor_new(void);

TACTOR_TYPE ermine_actor_type_get(ErmineActor *self);
void ermine_actor_type_set(ErmineActor *self, TACTOR_TYPE type);

void ermine_actor_position_set(ErmineActor *self, Vector2 position);
Vector2 ermine_actor_position_get(ErmineActor *self);

void ermine_actor_position_x_set(ErmineActor *self, float v);
void ermine_actor_position_y_set(ErmineActor *self, float v);

void ermine_actor_pivot_set(ErmineActor *self, Vector2 pivot);
Vector2 ermine_actor_pivot_get(ErmineActor *self);

void ermine_actor_position_x_add(ErmineActor *self, float v);

void ermine_actor_position_y_add(ErmineActor *self, float v);

void ermine_actor_position_add(ErmineActor *self, Vector2 v);

void ermine_actor_bounding_box_set(ErmineActor *self, Rectangle box);
Rectangle ermine_actor_bounding_box_get(ErmineActor *self);

void ermine_actor_scale_set(ErmineActor *self, Vector2 scale);
Vector2 ermine_actor_scale_get(ErmineActor *self);

void ermine_actor_rotation_set(ErmineActor *self, float rotation);
float ermine_actor_rotation_get(ErmineActor *self);

void ermine_actor_tag_set(ErmineActor *self, const char *tag);
const char *ermine_actor_tag_get(ErmineActor *self);

void ermine_actor_flag_set(ErmineActor *self, const int flag);
const int ermine_actor_flag_get(ErmineActor *self);

void ermine_actor_collision_state_set(ErmineActor *self, COLLISION_STATE state);
int ermine_actor_collision_state_get(ErmineActor *self);

void ermine_actor_render_index_set(ErmineActor *self, int render);
int ermine_actor_render_index_get(ErmineActor *self);

void ermine_actor_visible_set(ErmineActor *self, bool visible);
bool ermine_actor_visible_get(ErmineActor *self);

G_END_DECLS

#endif
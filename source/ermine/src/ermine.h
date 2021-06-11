#ifndef ERMINE_H
#define ERMINE_H
#include <stdio.h>
#include <stdbool.h>
#include <glib.h>
#include <glib-object.h>
#include "raylib.h"

typedef void (*SEventFunc)(GArray *, const char *);
typedef struct _ErmineActor ErmineActor;
typedef struct _ErmineObject ErmineObject;

typedef enum
{
    OnSystemUpdate,
    OnSystemRender,
    N_SYSTEM
} SYSTEM_EVENT;

typedef enum
{
    TACTOR_EMPTY,
    TACTOR_SHAPE_RECT,
    TACTOR_SHAPE_CIRCLE,
    TACTOR_TEXTURE,
    TACTOR_SPRITE,
    TACTOR_TEXT,
    N_ACTORST
} TACTOR_TYPE;

typedef enum
{
    COLLISION_BEGIN = 1,
    COLLISION_STAY,
    COLLISION_END,
    N_COLLISION_STATE
} COLLISION_STATE;

typedef enum
{
    FLAG_1 = 0x031,
    FLAG_2,
    FLAG_3,
    FLAG_4,
    FLAG_5,
} FLAGS_DEFAULT;

typedef struct
{
    GArray *children;
    bool bVisible;
    int id;
} Scene;

typedef struct
{
    SYSTEM_EVENT event;
    SEventFunc func;
    char *key;
} SEventData;

// -------------------------
// ACTORS
// -------------------------
// Buscamos todos los Actor que tengan un Tag x
#define GetActorWithTag(Entitys, Tag)                                  \
    for (int i = 0; i < Entitys->len; i++)                             \
    {                                                                  \
        ErmineActor *Other = g_array_index(Entitys, ErmineActor *, i); \
        if (strcmp(ermine_actor_tag_get(Other), Tag) == 0)             \
        {

#define EndGetActorWithTag() \
    }                        \
    }

#define GetActorWithFlag(Entitys, flag)                                \
    for (int i = 0; i < Entitys->len; i++)                             \
    {                                                                  \
        ErmineActor *Other = g_array_index(Entitys, ErmineActor *, i); \
        if (ermine_actor_flag_get(Other) == flag)                      \
        {

#define EndGetActorWithFlag() \
    }                         \
    }

// -------------------------
// SCENE
// -------------------------
Scene *ermine_scene_new(void);
Scene *ermine_scene_get_id(int id);

// -------------------------
// STAGE
// -------------------------
void ermine_stage_init(const char *title, int w, int h, char *argv[]);
void ermine_stage_set(Scene *scene);
void ermine_stage_set_color(Color color);
void ermine_stage_main(void);

void system_new(SYSTEM_EVENT event, const char *key, SEventFunc func);
void system_emit(Scene *scene, SYSTEM_EVENT event);
void system_remove(SYSTEM_EVENT event, const char *key);
void system_clear(SYSTEM_EVENT event);
void system_clear_all(void);

// -------------------------
// SYSTEM MACRO_FUNC
// -------------------------
#define _CUSTOM "CCSYS"
#define StartSystem                                                   \
    for (int i = 0; i < entitys->len; i++)                            \
    {                                                                 \
        ErmineActor *self = g_array_index(entitys, ErmineActor *, i); \
        if (g_object_get_data(self, name))                            \
        {
#define EndSystem \
    }             \
    }
#define _get_component() g_object_get_data(self, name);
#define ermine_system_set(actor, system, ...) g_object_set_data(actor, _CUSTOM system, __VA_ARGS__);
#define ermine_system(event, name, func) system_new(event, _CUSTOM name, func);

// -------------------------
// RESOURCE
// -------------------------
void resource_load_font(const char *key, const char *fileName);
void resource_load_sound(const char *key, const char *fileName);
void resource_load_texture(const char *key, const char *fileName);

Font resource_get_font(const char *key);
Texture2D resource_get_texture(const char *key);
Sound resource_get_sound(const char *key);

// -------------------------
// ACTOR API
// -------------------------
ErmineObject *ermine_object_new(void);

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

ErmineActor *ermine_sprite_new(Scene *scene, const char *key);

ErmineActor *ermine_shape_rect_new(Scene *scene, int w, int h, Color color);
void ermine_shape_rect_size_set(ErmineActor *self, int w, int h);
Vector2 ermine_shape_rect_size_get(ErmineActor *self);

ErmineActor *ermine_shape_circle_new(Scene *scene, float radius, Color color);
void ermine_shape_circle_size_set(ErmineActor *self, float radius);
float ermine_shape_circle_size_get(ErmineActor *self);
void ermine_shape_circle_segments_set(ErmineActor *self, int segments);
int ermine_shape_circle_segments_get(ErmineActor *self);

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

bool ermine_collision_check(ErmineActor *Actor, ErmineActor *Other, COLLISION_STATE state);

#endif
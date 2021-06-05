#ifndef ERMINE_H
#define ERMINE_H
#include <stdio.h>
#include <stdbool.h>
#include <glib.h>
#include "raylib.h"

typedef void (*SEventFunc)(GArray *, const char *);
typedef struct _ErmineActor ErmineActor;

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
}FLAGS_DEFAULT;

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

// -- - EXPAND
#include "scene.h"
#include "resource.h"
#include "actor/eactor.h"

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

#endif
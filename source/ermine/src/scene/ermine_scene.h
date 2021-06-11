#ifndef SCENE_H
#define SCENE_H
#include "ermine.h"

// priv - esto lo realizan automatico
void ermine_scene_add_children(Scene *scene, ErmineActor *self);
void ermine_scene_remove_children(Scene *scene, ErmineActor *self);
void ermine_scene_clear_all(void);

#endif

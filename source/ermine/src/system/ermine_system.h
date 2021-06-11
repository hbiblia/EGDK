#ifndef SYSTEM_H
#define SYSTEM_H
#include "ermine.h"

//
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

#endif
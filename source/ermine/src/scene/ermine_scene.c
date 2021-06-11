#include "ermine_scene.h"

static GList *scenes_manager = NULL;
static int scenes_len = 0;

Scene *ermine_scene_new(void)
{
    Scene *scene = (Scene *)g_malloc(sizeof(Scene));
    scene->children = g_array_sized_new(false, false, sizeof(ErmineActor *), 100000);
    scene->id = scenes_len;
    scenes_manager = g_list_append(scenes_manager, scene);
    scenes_len++;
    return scene;
}

void ermine_scene_add_children(Scene *scene, ErmineActor *self)
{
    g_array_append_val(scene->children, self);
}

void ermine_scene_remove_children(Scene *scene, ErmineActor *self)
{
    int id = 0;
    scene->children = g_array_remove_index(scene->children, id);
}

Scene *ermine_scene_get_id(const int id)
{
    for (GList *l = scenes_manager; l != NULL; l = l->next)
    {
        Scene *tmp = l->data;
        if (tmp->id == id)
        {
            return tmp;
        }
    }
    return NULL;
}

void ermine_scene_clear_all(void)
{
    for (GList *l = scenes_manager; l != NULL; l = l->next)
    {
        Scene *tmp = l->data;
        g_array_unref(tmp->children);
        g_free(tmp);
    }
    g_list_free(scenes_manager);
}
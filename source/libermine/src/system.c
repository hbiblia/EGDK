#include "system.h"

// system reg data
static GHashTable *ht_system;
static int bInitSystem = 0;

void system_new(SYSTEM_EVENT event, const char *key, SEventFunc func)
{
    if (!bInitSystem)
    {
        ht_system = g_hash_table_new(g_str_hash, g_str_equal);
        bInitSystem = 1;
    }

    SEventData *data = (SEventData *)g_malloc(sizeof(SEventData));
    data->event = event;
    data->func = func;
    data->key = g_strdup(key);

    g_hash_table_insert(ht_system, key, data);
}

void system_emit(Scene *scene, SYSTEM_EVENT event)
{
    GList *list = g_hash_table_get_values(ht_system);
    for (GList *l = list; l != NULL; l = l->next)
    {
        SEventData *data = l->data;
        if (data->event == event)
        {
            data->func(scene->children, data->key);
        }
    }
    g_list_free(list);
}

void system_remove(SYSTEM_EVENT event, const char *key)
{
    SEventData *data = g_hash_table_lookup(ht_system, key);
    g_free(data);
}

void system_clear(SYSTEM_EVENT event)
{
    GList *list = g_hash_table_get_values(ht_system);
    for (GList *l = list; l != NULL; l = l->next)
    {
        SEventData *data = l->data;
        if (data->event == event)
        {
            g_free(l->data);
        }
    }
}

void system_clear_all(void)
{
    for (int i = 0; i < N_SYSTEM; i++)
    {
        system_clear(i);
    }
}

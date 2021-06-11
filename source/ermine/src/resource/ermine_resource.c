#include "ermine_resource.h"

#define MAX_RESOURCE_SINGLE 1000
static int id_resource_texture = 0;
static int id_resource_sound = 0;
static int id_resource_font = 0;
// 
static char *path[N_PATHS];

//
GHashTable *table_resource;

typedef struct
{
    Texture2D texture[MAX_RESOURCE_SINGLE];
    Sound sound[MAX_RESOURCE_SINGLE];
    Font font[MAX_RESOURCE_SINGLE];
} Resource;

Resource RData = {0};

// Init
void resource_init(const char *path_str)
{
    table_resource = g_hash_table_new(g_str_hash, g_str_equal);

    path[P_PATH] = g_strdup(path_str);
    path[P_ENGINE_CONTENT] = g_build_filename(path[P_PATH], "Content",NULL);
    path[P_ENGINE_CONTENT_FONT] = g_build_filename(path[P_ENGINE_CONTENT], "Fonts", NULL);
    path[P_ENGINE_CONTENT_SOUND] = g_build_filename(path[P_ENGINE_CONTENT], "Sound", NULL);
    path[P_ENGINE_CONTENT_TEXTURE] = g_build_filename(path[P_ENGINE_CONTENT],"Texture", NULL);

    resource_load_font("Roboto-Medium", g_build_filename(path[P_ENGINE_CONTENT_FONT], "Roboto","Roboto-Medium.ttf", NULL));
    resource_load_font("Roboto-Black", g_build_filename(path[P_ENGINE_CONTENT_FONT],"Roboto","Roboto-Black.ttf", NULL));
}

void resource_close(void)
{
    resource_free_texture();
    resource_free_sound();
    resource_free_font();
}

// Texture
void resource_load_texture(const char *key, const char *fileName)
{
    Texture2D texture = LoadTexture(fileName);
    if (texture.width != 0 && texture.height != 0)
    {
        g_hash_table_insert(table_resource, key, id_resource_texture);
        RData.texture[id_resource_texture] = texture;
        id_resource_texture++;
    }
}

Texture2D resource_get_texture(const char *key)
{
    int id = g_hash_table_lookup(table_resource, key);
    return RData.texture[id];
}

void resource_free_texture(void)
{
    for (int i = 0; i < id_resource_texture; i++)
    {
        UnloadTexture(RData.texture[i]);
    }
} 

// Sound
void resource_load_sound(const char *key, const char *fileName)
{
    Sound sound = LoadSound(fileName);
    if (sound.sampleCount != 0)
    {
        g_hash_table_insert(table_resource, key, id_resource_sound);
        RData.sound[id_resource_sound] = sound;
        id_resource_sound++;
    }
}
Sound resource_get_sound(const char *key)
{
    int id = g_hash_table_lookup(table_resource, key);
    return RData.sound[id];
}
void resource_free_sound(void)
{
    for (int i = 0; i < id_resource_sound; i++)
    {
        UnloadSound(RData.sound[i]);
    }
} 

// Font
void resource_load_font(const char *key, const char *fileName)
{
    Font font = LoadFont(fileName);
    if (font.baseSize != 0)
    {
        g_hash_table_insert(table_resource, key, id_resource_font);
        RData.font[id_resource_font] = font;
        id_resource_font++;
    }
}
Font resource_get_font(const char *key)
{
    int id = g_hash_table_lookup(table_resource, key);
    return RData.font[id];
}
void resource_free_font(void)
{
    for (int i = 0; i < id_resource_font; i++)
    {
        UnloadFont(RData.font[i]);
    }
} 
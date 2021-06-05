#ifndef RESOURCE_H
#define RESOURCE_H
#include "ermine.h"

void resource_init(void);
void resource_close(void);

// Texture
void resource_load_texture(const char *key, const char *fileName);
Texture2D resource_get_texture(const char *key);
void resource_free_texture(void);

// Sound
void resource_load_sound(const char *key, const char *fileName);
Sound resource_get_sound(const char *key);
void resource_free_sound(void);

// Font
void resource_load_font(const char *key, const char *fileName);
Font resource_get_font(const char *key);
void resource_free_font(void);

#endif

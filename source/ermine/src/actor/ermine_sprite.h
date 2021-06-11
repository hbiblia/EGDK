#ifndef ESPRITE_H
#define ESPRITE_H
#include "../ermine.h"
#include "ermine_texture_class.h"

G_BEGIN_DECLS

// -----------------------
// --- DEFINE ABS
// -----------------------
typedef struct _ErmineSpritePrivate ErmineSpritePrivate;

#define ERMINE_TYPE_SPRITE ermine_sprite_get_type()
G_DECLARE_FINAL_TYPE(ErmineSprite, ermine_sprite, ERMINE, SPRITE, ErmineTexture)

struct _ErmineSpritePrivate{
    ErmineTexture parent_instance;
};

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_sprite_new(Scene *scene, const char *key);

G_END_DECLS

#endif // ESPRITE_H

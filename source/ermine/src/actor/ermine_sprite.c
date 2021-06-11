#include "ermine_sprite.h"
#include "system/ermine_system.h"
#include "raylib.h"

// -----------------------
// --- INIT-SYSTEM_METHODS
// -----------------------
static void system_update(GArray *entitys)
{
    for (int i = 0; i < entitys->len; i++)
    {
        ErmineActor *self = g_array_index(entitys, ErmineActor *, i);
        if (ermine_actor_type_get(self) == TACTOR_SPRITE)
        {
            if (!ermine_actor_visible_get(self))
                break;

            Vector2 size = ermine_texture_size_get(self);
            ermine_texture_rect1_set(self, (Rectangle){0, 0, size.x, size.y});
            ermine_texture_rect2_set(self, (Rectangle){0, 0, size.x, size.y});

            Vector2 pos = ermine_actor_position_get(self);
            ermine_actor_bounding_box_set(self, (Rectangle){pos.x, pos.y, size.x, size.y});
        }
    }
}

// -----------------------
// --- INIT-CLASS
// -----------------------
struct _ErmineSprite
{
    ErmineTexture parent;
};

G_DEFINE_TYPE_WITH_PRIVATE(ErmineSprite, ermine_sprite, ERMINE_TYPE_TEXTURE);

static void ermine_sprite_class_init(ErmineSpriteClass *klass)
{
    ErmineActorClass *obj_class = ERMINE_ACTOR_GET_CLASS(klass);
    system_new(OnSystemUpdate, "sprite0", system_update);
}
static void ermine_sprite_init(ErmineSprite *self)
{
}

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_sprite_new(Scene *scene, const char *key)
{
    ErmineSprite *self = g_object_new(ERMINE_TYPE_SPRITE, NULL);

    Texture2D test = resource_get_texture(key);

    ermine_actor_type_set(self, TACTOR_SPRITE);
    ermine_texture_set(self, test);
    ermine_texture_tint_set(self, WHITE);
    ermine_actor_bounding_box_set(self, (Rectangle){0, 0, test.width, test.height});
    ermine_actor_anchor_set(self, (Vector2){0.5, 0.5});
    ermine_scene_add_children(scene, self);

    return self;
}
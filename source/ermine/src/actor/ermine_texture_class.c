#include "ermine_texture_class.h"

G_DEFINE_TYPE_WITH_PRIVATE(ErmineTexture, ermine_texture, ERMINE_TYPE_ACTOR);

// -----------------------
// --- INIT-SYSTEM_METHODS
// -----------------------
static void system_draw(GArray *entitys)
{
    for (int i = 0; i < entitys->len; i++)
    {
        ErmineActor *self = g_array_index(entitys, ErmineActor *, i);
        if (ermine_actor_type_get(self) == TACTOR_TEXTURE || 
            ermine_actor_type_get(self) == TACTOR_SPRITE)
        {
            Color color = ermine_texture_tint_get(self);
            Rectangle src = ermine_texture_rect1_get(self);
            Rectangle des = ermine_texture_rect2_get(self);
            Vector2 pivot = ermine_actor_pivot_get(self);
            Vector2 pos   = ermine_actor_position_get(self);
            Texture2D texture = ermine_texture_get(self);
            float rotation = ermine_actor_rotation_get(self);
            
            des.x = pos.x;
            des.y = pos.y;

            DrawTexturePro(texture, src, des, pivot, rotation, color);
        }
    }
}

// -----------------------
// --- INIT-CLASS
// -----------------------
static void ermine_texture_class_init(ErmineTextureClass *klass)
{
    ErmineActorClass *obj = ERMINE_ACTOR_GET_CLASS(klass);
    system_new(OnSystemRender, "texture0", system_draw);
}
static void ermine_texture_init(ErmineTexture *self)
{
    ErmineTextureClass *klass = ERMINE_ACTOR(self);
}

// -----------------------
// --- METHODS
// -----------------------
void ermine_texture_tint_set(ErmineActor *self, Color tint_color)
{
    ErmineTexturePrivate *priv = ermine_texture_get_instance_private(self);
    priv->tint = tint_color;
}

Color ermine_texture_tint_get(ErmineActor *self)
{
    ErmineTexturePrivate *priv = ermine_texture_get_instance_private(self);
    return priv->tint;
}

void ermine_texture_set(ErmineActor *self, Texture2D texture)
{
    ErmineTexturePrivate *priv = ermine_texture_get_instance_private(self);
    priv->texture = texture;
}

Texture2D ermine_texture_get(ErmineActor *self)
{
    ErmineTexturePrivate *priv = ermine_texture_get_instance_private(self);
    return priv->texture;
}

Vector2 ermine_texture_size_get(ErmineActor *self)
{
    ErmineTexturePrivate *priv = ermine_texture_get_instance_private(self);
    return (Vector2){priv->texture.width, priv->texture.height};
}

void ermine_texture_rect1_set(ErmineActor *self, Rectangle source)
{
    ErmineTexturePrivate *priv = ermine_texture_get_instance_private(self);
    priv->src = source;
}

Rectangle ermine_texture_rect1_get(ErmineActor *self)
{
    ErmineTexturePrivate *priv = ermine_texture_get_instance_private(self);
    return priv->src;
}

void ermine_texture_rect2_set(ErmineActor *self, Rectangle dest)
{
    ErmineTexturePrivate *priv = ermine_texture_get_instance_private(self);
    priv->des = dest;
}

Rectangle ermine_texture_rect2_get(ErmineActor *self)
{
    ErmineTexturePrivate *priv = ermine_texture_get_instance_private(self);
    return priv->des;
}
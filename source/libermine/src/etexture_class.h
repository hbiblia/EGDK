#pragma once
#ifndef __ERMINE_TEXTURE_CLASS_H__
#define __ERMINE_TEXTURE_CLASS_H__
#include <ermine.h>

G_BEGIN_DECLS

// -----------------------
// --- DEFINE ABS
// -----------------------

typedef struct _ErmineTexture ErmineTexture;
typedef struct _ErmineTextureClass ErmineTextureClass;
typedef struct _ErmineTexturePrivate ErmineTexturePrivate;

#define ERMINE_TYPE_TEXTURE ermine_texture_get_type()
G_DECLARE_DERIVABLE_TYPE(ErmineTexture, ermine_texture, ERMINE, TEXTURE, ErmineActor)

struct _ErmineTexturePrivate
{
    ErmineActor parent_instance;
    Color tint;
    Texture2D texture;
    Rectangle src;
    Rectangle des;
};
struct _ErmineTextureClass
{
    ErmineActorClass parent_class;
};

// -----------------------
// --- METHODS
// -----------------------
void ermine_texture_tint_set(ErmineActor *self, Color tint_color);
Color ermine_texture_tint_get(ErmineActor *self);

void ermine_texture_set(ErmineActor *self, Texture2D texture);
Texture2D ermine_texture_get(ErmineActor *self);

Vector2 ermine_texture_size_get(ErmineActor *self);

void ermine_texture_rect1_set(ErmineActor *self, Rectangle source);
Rectangle ermine_texture_rect1_get(ErmineActor *self);

void ermine_texture_rect2_set(ErmineActor *self, Rectangle dest);
Rectangle ermine_texture_rect2_get(ErmineActor *self);

G_END_DECLS

#endif
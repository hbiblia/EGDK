#include "eshape_class.h"

G_DEFINE_TYPE_WITH_PRIVATE(ErmineShape, ermine_shape, ERMINE_TYPE_ACTOR);

// -----------------------
// --- INIT-CLASS
// -----------------------
static void ermine_shape_class_init(ErmineShapeClass *klass)
{
    ErmineActorClass *obj = ERMINE_ACTOR_GET_CLASS(klass);
}
static void ermine_shape_init(ErmineShape *self)
{
    ErmineShapeClass *klass = ERMINE_ACTOR(self);
}

// -----------------------
// --- METHODS
// -----------------------
void ermine_shape_color_set(ErmineActor *self, Color color)
{
    ErmineShapePrivate *priv = ermine_shape_get_instance_private(self);
    priv->color = color;
}

Color ermine_shape_color_get(ErmineActor *self)
{
    ErmineShapePrivate *priv = ermine_shape_get_instance_private(self);
    return priv->color;
}


void ermine_shape_line_color_set(ErmineActor *self, Color color)
{
    ErmineShapePrivate *priv = ermine_shape_get_instance_private(self);
    priv->linecolor = color;
}

Color ermine_shape_line_color_get(ErmineActor *self)
{
    ErmineShapePrivate *priv = ermine_shape_get_instance_private(self);
    return priv->linecolor;
}

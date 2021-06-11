#include "ermine_actor.h"

G_DEFINE_TYPE_WITH_PRIVATE(ErmineActor, ermine_actor, ERMINE_TYPE_OBJECT);

// -----------------------
// --- INIT-CLASS
// -----------------------
static void ermine_actor_class_init(ErmineActorClass *klass)
{
    ErmineObjectClass *obj = G_OBJECT_CLASS(klass);
}
static void ermine_actor_init(ErmineActor *self)
{
    ErmineActorClass *klass = ERMINE_ACTOR(self);
    ermine_actor_tag_set(self, "none");
    ermine_actor_visible_set(self, true);
}

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_actor_new(void)
{
    return g_object_new(ERMINE_TYPE_ACTOR, NULL);
}

void ermine_actor_type_set(ErmineActor *self, TACTOR_TYPE type)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    priv->type = type;
}

TACTOR_TYPE ermine_actor_type_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->type;
}

void ermine_actor_position_set(ErmineActor *self, Vector2 position)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    priv->position = position;

    ermine_actor_bounding_box_set(self, (Rectangle){position.x, position.y, priv->BoundingBox.width, priv->BoundingBox.height});
}

Vector2 ermine_actor_position_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->position;
}

void ermine_actor_position_x_set(ErmineActor *self, float v)
{
    Vector2 pos = ermine_actor_position_get(self);
    ermine_actor_position_set(self, (Vector2){v, pos.y});
}

void ermine_actor_position_y_set(ErmineActor *self, float v)
{
    Vector2 pos = ermine_actor_position_get(self);
    ermine_actor_position_set(self, (Vector2){pos.x, v});
}

void ermine_actor_position_x_add(ErmineActor *self, float v)
{
    Vector2 pos = ermine_actor_position_get(self);
    ermine_actor_position_set(self, (Vector2){pos.x + v, pos.y});
}
void ermine_actor_position_y_add(ErmineActor *self, float v)
{
    Vector2 pos = ermine_actor_position_get(self);
    ermine_actor_position_set(self, (Vector2){pos.x, pos.y + v});
}
void ermine_actor_position_add(ErmineActor *self, Vector2 v)
{
    Vector2 pos = ermine_actor_position_get(self);
    ermine_actor_position_set(self, (Vector2){pos.x + v.x, pos.y + v.y});
}

void ermine_actor_pivot_set(ErmineActor *self, Vector2 pivot)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    priv->pivot = pivot;
}

Vector2 ermine_actor_pivot_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->pivot;
}

void ermine_actor_anchor_set(ErmineActor *self, Vector2 anchor)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    Rectangle box = priv->BoundingBox;
    ermine_actor_pivot_set(self, (Vector2){box.width * anchor.x, box.height * anchor.y});
}

void ermine_actor_scale_set(ErmineActor *self, Vector2 scale)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    priv->scale = scale;
}

Vector2 ermine_actor_scale_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->scale;
}

void ermine_actor_rotation_set(ErmineActor *self, float rotation)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    priv->rotation = rotation;
}

float ermine_actor_rotation_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->rotation;
}

void ermine_actor_bounding_box_set(ErmineActor *self, Rectangle box)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    Vector2 pivot = ermine_actor_pivot_get(self);
    box.x = box.x - pivot.x;
    box.y = box.y - pivot.y;
    priv->BoundingBox = box;
}

Rectangle ermine_actor_bounding_box_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->BoundingBox;
}

void ermine_actor_tag_set(ErmineActor *self, const char *tag)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    g_free(priv->tag);
    priv->tag = g_strdup(tag);
}

const char *ermine_actor_tag_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->tag;
}

void ermine_actor_flag_set(ErmineActor *self, const int flag)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    priv->flag = flag;
}

const int ermine_actor_flag_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->flag;
}

void ermine_actor_collision_state_set(ErmineActor *self, COLLISION_STATE state)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    priv->state_collision = state;
}

int ermine_actor_collision_state_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->state_collision;
}

void ermine_actor_render_index_set(ErmineActor *self, int render)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    priv->index_render = render;
}

int ermine_actor_render_index_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->index_render;
}

void ermine_actor_visible_set(ErmineActor *self, bool visible)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    priv->IsVisible = visible;
}

bool ermine_actor_visible_get(ErmineActor *self)
{
    ErmineActorPrivate *priv = ermine_actor_get_instance_private(self);
    return priv->IsVisible;
}
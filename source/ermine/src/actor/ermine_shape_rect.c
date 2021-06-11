#include "ermine_shape_rect.h"
#include "system/ermine_system.h"
#include "raylib.h"

// -----------------------
// --- INIT-SYSTEM_METHODS
// -----------------------
static void system_draw(GArray *entitys)
{
    for (int i = 0; i < entitys->len; i++)
    {
        ErmineActor *self = g_array_index(entitys, ErmineActor *, i);
        if (ermine_actor_type_get(self) == TACTOR_SHAPE_RECT)
        {
            if (!ermine_actor_visible_get(self))
                break;

            Color color = ermine_shape_color_get(self);
            Vector2 size = ermine_shape_rect_size_get(self);
            Vector2 pos = ermine_actor_position_get(self);
            Vector2 pivot = ermine_actor_pivot_get(self);
            float rotation = ermine_actor_rotation_get(self);

            Rectangle rec = (Rectangle){pos.x, pos.y, size.x, size.y};
            ermine_actor_bounding_box_set(self, rec);

            DrawRectanglePro(rec, pivot, rotation, color);
        }
    }
}
static void system_update(GArray *entitys)
{
    //
}

// -----------------------
// --- INIT-CLASS
// -----------------------
struct _ErmineShapeRect
{
    ErmineActor parent;
};

G_DEFINE_TYPE_WITH_PRIVATE(ErmineShapeRect, ermine_shape_rect, ERMINE_TYPE_SHAPE);

static void ermine_shape_rect_class_init(ErmineShapeRectClass *klass)
{
    ErmineActorClass *obj_class = ERMINE_ACTOR_GET_CLASS(klass);

    system_new(OnSystemRender, "shape_rect0", system_draw);
    system_new(OnSystemUpdate, "shape_rect1", system_update);
}
static void ermine_shape_rect_init(ErmineShapeRect *self)
{
}

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_shape_rect_new(Scene *scene, int w, int h, Color color)
{
    ErmineShapeRect *self = g_object_new(ERMINE_TYPE_SHAPE_RECT, NULL);

    ermine_actor_type_set(self, TACTOR_SHAPE_RECT);
    ermine_shape_rect_size_set(self, w, h);
    ermine_shape_color_set(self, color);
    ermine_actor_bounding_box_set(self, (Rectangle){0, 0, w, h});
    ermine_actor_anchor_set(self, (Vector2){0.5, 0.5});
    ermine_scene_add_children(scene, self);

    return self;
}

void ermine_shape_rect_size_set(ErmineActor *self, int w, int h)
{
    ErmineShapeRectPrivate *priv = ermine_shape_rect_get_instance_private(self);
    priv->w = w;
    priv->h = h;
}

Vector2 ermine_shape_rect_size_get(ErmineActor *self)
{
    ErmineShapeRectPrivate *priv = ermine_shape_rect_get_instance_private(self);
    return (Vector2){priv->w, priv->h};
}
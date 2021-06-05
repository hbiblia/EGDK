#include "eshape_circle.h"
#include "system.h"
#include "raylib.h"

// -----------------------
// --- INIT-SYSTEM_METHODS
// -----------------------
static void system_draw(GArray *entitys)
{
    for (int i = 0; i < entitys->len; i++)
    {
        ErmineActor *self = g_array_index(entitys, ErmineActor *, i);
        if (ermine_actor_type_get(self) == TACTOR_SHAPE_CIRCLE)
        {
            if (!ermine_actor_visible_get(self))
                break;
                
            Color color = ermine_shape_color_get(self);
            Color lcolor = ermine_shape_line_color_get(self);
            Vector2 pos = ermine_actor_position_get(self);
            Vector2 pivot = ermine_actor_pivot_get(self);
            float rotation = ermine_actor_rotation_get(self);
            float size = ermine_shape_circle_size_get(self);
            int segments = ermine_shape_circle_segments_get(self);
            Vector2 center = (Vector2){pos.x - pivot.x, pos.y - pivot.y};
            float new_rotation = (360 + rotation);
            ermine_actor_bounding_box_set(self, (Rectangle){pos.x, pos.y, size, size});

            DrawCircleSector(center, size, new_rotation, rotation, segments, color);
            DrawCircleSectorLines(center, size, new_rotation, rotation - 0.1, segments, lcolor);
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
struct _ErmineShapeCircle
{
    ErmineActor parent;
};

G_DEFINE_TYPE_WITH_PRIVATE(ErmineShapeCircle, ermine_shape_circle, ERMINE_TYPE_ACTOR);

static void ermine_shape_circle_class_init(ErmineShapeCircleClass *klass)
{
    ErmineActorClass *obj_class = ERMINE_ACTOR_GET_CLASS(klass);

    system_new(OnSystemRender, "shape_circle0", system_draw);
    system_new(OnSystemUpdate, "shape_circle1", system_update);
}
static void ermine_shape_circle_init(ErmineShapeCircle *self)
{
}

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_shape_circle_new(Scene *scene, float radius, Color color)
{
    ErmineShapeCircle *self = g_object_new(ERMINE_TYPE_SHAPE_CIRCLE, NULL);

    ermine_actor_type_set(self, TACTOR_SHAPE_CIRCLE);
    ermine_shape_circle_size_set(self, radius);
    ermine_shape_color_set(self, color);
    ermine_shape_circle_segments_set(self, 17);
    ermine_actor_bounding_box_set(self, (Rectangle){0, 0, radius, radius});
    ermine_actor_anchor_set(self, (Vector2){0.5, 0.5});
    ermine_scene_add_children(scene, self);

    return self;
}

void ermine_shape_circle_size_set(ErmineActor *self, float radius)
{
    ErmineShapeCirclePrivate *priv = ermine_shape_circle_get_instance_private(self);
    priv->radius = radius;
}

float ermine_shape_circle_size_get(ErmineActor *self)
{
    ErmineShapeCirclePrivate *priv = ermine_shape_circle_get_instance_private(self);
    return priv->radius;
}

void ermine_shape_circle_segments_set(ErmineActor *self, int segments)
{
    ErmineShapeCirclePrivate *priv = ermine_shape_circle_get_instance_private(self);
    priv->segments = segments;
}

int ermine_shape_circle_segments_get(ErmineActor *self)
{
    ErmineShapeCirclePrivate *priv = ermine_shape_circle_get_instance_private(self);
    return priv->segments;
}
#include "etext_render.h"
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
        if (ermine_actor_type_get(self) == TACTOR_TEXT)
        {
            if (!ermine_actor_visible_get(self))
                break;

            Color color = ermine_text_color_get(self);
            Vector2 pos = ermine_actor_position_get(self);
            Vector2 pivot = ermine_actor_pivot_get(self);
            Vector2 size = ermine_text_size_get(self);
            Font font = ermine_text_font_get(self);
            bool wrap = ermine_text_wrap_get(self);
            bool dynamic = ermine_text_dynamic_get(self);
            float font_size = ermine_text_font_size_get(self);
            float rotation = ermine_actor_rotation_get(self);
            int spacing = ermine_text_spacing_get(self);
            const char *str = ermine_text_get(self);
            Vector2 text_size = ermine_text_measure(self);

            Rectangle rect = {0};
            if (dynamic)
                rect = (Rectangle){pos.x, pos.y, text_size.x + font_size, text_size.y};
            else
            {
                rect = (Rectangle){pos.x, pos.y, size.x, size.y};
            }
            ermine_actor_bounding_box_set(self, rect);
            DrawTextRec(font, str, rect, font_size, spacing, wrap, color);
        }
    }
}

// -----------------------
// --- INIT-CLASS
// -----------------------
struct _ErmineTextRender
{
    ErmineActor parent;
};

G_DEFINE_TYPE_WITH_PRIVATE(ErmineTextRender, ermine_text_render, ERMINE_TYPE_ACTOR);

static void ermine_text_render_class_init(ErmineTextRenderClass *klass)
{
    ErmineActorClass *obj_class = ERMINE_ACTOR_GET_CLASS(klass);

    system_new(OnSystemRender, "text_render0", system_draw);
}
static void ermine_text_render_init(ErmineTextRender *self)
{
}

// -----------------------
// --- METHODS
// -----------------------
ErmineActor *ermine_text_render_new(Scene *scene, const char *str)
{
    ErmineTextRender *self = ermine_text_render_with_new(scene, str, 20, WHITE);
    return self;
}

ErmineActor *ermine_text_render_with_new(Scene *scene, const char *str, int fontSize, Color color)
{
    ErmineTextRender *self = g_object_new(ERMINE_TYPE_TEXT_RENDER, NULL);
    ermine_actor_type_set(self, TACTOR_TEXT);
    ermine_text_dynamic_set(self, true);
    ermine_text_font_set(self, "Roboto-Medium");
    ermine_text_font_size_set(self, fontSize);
    ermine_text_color_set(self, color);
    ermine_text_wrap_set(self, false);
    ermine_text_spacing_set(self, 1);
    ermine_text_set(self, str);
    // --
    Vector2 siz = ermine_text_measure(self);
    ermine_text_size_set(self, (Vector2){siz.x, siz.y});
    ermine_actor_bounding_box_set(self, (Rectangle){0, 0, siz.x, siz.y});
    ermine_actor_anchor_set(self, (Vector2){0.5, 0.5});
    ermine_scene_add_children(scene, self);
    return self;
}

void ermine_text_font_size_set(ErmineActor *self, int fontSize)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    priv->fontSize = fontSize;
}

int ermine_text_font_size_get(ErmineActor *self)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    return priv->fontSize;
}

void ermine_text_color_set(ErmineActor *self, Color color)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    priv->color = color;
}

Color ermine_text_color_get(ErmineActor *self)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    return priv->color;
}

void ermine_text_set(ErmineActor *self, const char *str)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    g_free(priv->str);
    priv->str = g_strdup(str);
}

const char *ermine_text_get(ErmineActor *self)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    return priv->str;
}

void ermine_text_font_set(ErmineActor *self, const char *key)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    priv->font = resource_get_font(key);
}

Font ermine_text_font_get(ErmineActor *self)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    return priv->font;
}

void ermine_text_spacing_set(ErmineActor *self, float spacing)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    priv->spacing = spacing;
}

float ermine_text_spacing_get(ErmineActor *self)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    return priv->spacing;
}

void ermine_text_wrap_set(ErmineActor *self, bool wordWrap)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    priv->wordWrap = wordWrap;
}

bool ermine_text_wrap_get(ErmineActor *self)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    return priv->wordWrap;
}

void ermine_text_dynamic_set(ErmineActor *self, bool dynamic)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    priv->dynamic = dynamic;
}

bool ermine_text_dynamic_get(ErmineActor *self)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    return priv->dynamic;
}

void ermine_text_size_set(ErmineActor *self, Vector2 size)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    priv->size = size;
}

Vector2 ermine_text_size_get(ErmineActor *self)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    return priv->size;
}

Vector2 ermine_text_measure(ErmineActor *self)
{
    ErmineTextRenderPrivate *priv = ermine_text_render_get_instance_private(self);
    return MeasureTextEx(priv->font, priv->str, priv->fontSize, priv->spacing);
}

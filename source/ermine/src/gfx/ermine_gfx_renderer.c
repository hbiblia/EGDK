#include "ermine_gfx.h"

// internal
void ermine_gfx_clear(ermine_color color)
{
    ermine_backend_clear_color(color);
    ermine_backend_clear_screen_buffers();
}

// public
void ermine_gfx_shape_rectangle_draw(Transform transform, int width, int height, ermine_color color)
{
    ermine_backend_texture_enable(ermine_shapes_texture_get().id);
    {
        float px = transform.position.x;
        float py = transform.position.y;
        float pz = transform.position.z;

        ermine_backend_push_matrix();
        ermine_backend_translatef(px, py, pz);

        ermine_backend_begin(ERMINE_GFX_QUADS);
        ermine_backend_normal3f(.0f, .0f, 1.0f);
        ermine_backend_color4ub(color.r, color.g, color.b, color.a);

        ermine_backend_texcoord2f(px / width, py / height);
        ermine_backend_vertex2f(.0f, .0f);

        ermine_backend_texcoord2f(px / width, (py + height) / height);
        ermine_backend_vertex2f(.0f, height);

        ermine_backend_texcoord2f((px + width) / width, (py + height) / height);
        ermine_backend_vertex2f(width, height);

        ermine_backend_texcoord2f((px + width) / width, py / height);
        ermine_backend_vertex2f(width, .0f);

        ermine_backend_end();
        ermine_backend_pop_matrix();
    }
    ermine_backend_texture_disable();
}

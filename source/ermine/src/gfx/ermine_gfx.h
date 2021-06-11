
#include "ermine_gfx_color.h"
#include "ermine_backend_opengl.h"

typedef enum ermine_primitives_mode
{
    ERMINE_GFX_LINES        = 0x0001,
    ERMINE_GFX_TRIANGLES    = 0x0002,
    ERMINE_GFX_QUADS        = 0x0007
} ermine_primitives_mode;

typedef enum ermine_matrix_mode
{
    ERMINE_GFX_PROJECTION   = 0x0001,
    ERMINE_GFX_MODELVIEW    = 0x0002,
    ERMINE_GFX_TEXTURE      = 0x0003
} ermine_matrix_mode;
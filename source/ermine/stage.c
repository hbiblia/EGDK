#include "stage.h"
#include "system.h"
#include "scene.h"

static int scene_select_id;
static bool bSelectScene;
static Color background;

static void _ermine_stage_close()
{
    ermine_scene_clear_all();
    resource_close();
    system_clear_all();
    CloseWindow();
}

void ermine_stage_init(const char *title, int w, int h)
{
    InitAudioDevice();
    
    InitWindow(w, h, title);
    SetTargetFPS(60);
    resource_init();

    background = BLACK;

    resource_load_font("Roboto-Medium", "Content/Fonts/Roboto/Roboto-Medium.ttf");
    resource_load_font("Roboto-Black", "Content/Fonts/Roboto/Roboto-Black.ttf");
}

void ermine_stage_set(Scene *scene)
{
    scene_select_id = scene->id;
    bSelectScene = true;
}

void ermine_stage_set_color(Color color)
{
    background = color;
}

void ermine_stage_main(void)
{
    while (!WindowShouldClose())
    {
        Scene *scene_tmp = ermine_scene_get_id(scene_select_id);

        if (bSelectScene)
            system_emit(scene_tmp, OnSystemUpdate);

        BeginDrawing();
        {
            ClearBackground(background);
            if (bSelectScene)
                system_emit(scene_tmp, OnSystemRender);

            // DrawFPS(10,10);
        }
        EndDrawing();
    }

    _ermine_stage_close();
}

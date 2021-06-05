
#include <stdio.h>
#include "ermine/ermine.h"
#include "actor/eshape_rect.h"
#include "actor/eshape_circle.h"
#include "actor/esprite.h"
#include "actor/etext_render.h"
#include "system.h"
#include "collision.h"

ErmineActor *act_scoreA, *act_scoreB, *act_gameover;
int scoreA = 0, scoreB = 0;
bool bGameOver = false;

// Component
typedef struct
{
    Vector2 velocity;
    Vector2 direccion;
} ComponentBall;

// Sistema
void system_PadController(GArray *entitys, const char *name)
{
    StartSystem
    {
        Rectangle pad = ermine_actor_bounding_box_get(self);
        if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && pad.y >= 15)
        {
            ermine_actor_position_y_add(self, -5);
        }
        if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && pad.y <= (GetScreenHeight() - 115))
        {
            ermine_actor_position_y_add(self, 5);
        }
    }
    EndSystem
}

void system_BallSystem(GArray *entitys, const char *name)
{
    float delta = GetFrameTime();

    StartSystem
    {
        ComponentBall *cBall = _get_component();
        Rectangle boundBall = ermine_actor_bounding_box_get(self);
        int w = GetScreenWidth();
        int h = GetScreenHeight();

        // GameOver
        if (IsKeyDown(KEY_ENTER) && bGameOver)
        {
            ermine_actor_visible_set(act_gameover, false);
            bGameOver = false;
            cBall->direccion = (Vector2){1, 1};
            scoreB = scoreA = 0;
        }

        // ----------------------------------
        // Bounce Ball World
        if (boundBall.x >= w || boundBall.x <= 0)
        {
            if (boundBall.x <= 0)
                scoreB++;
            if (boundBall.x >= w)
                scoreA++;

            ermine_actor_position_set(self, (Vector2){800 / 2, 600 / 2});
            PlaySound(resource_get_sound("hitHurt"));

            if (scoreA >= 5 || scoreB >= 5)
            {
                bGameOver = true;
                ermine_actor_visible_set(act_gameover, true);
                cBall->direccion = (Vector2){0};
                return;
            }

            cBall->direccion.x *= -1;
        }
        if (boundBall.y >= h || boundBall.y <= 0)
            cBall->direccion.y *= -1;

        // ----------------------------------
        // Collision Ball == Pad^
        // ----------------------------------
        float size = ermine_shape_circle_size_get(self);
        GetActorWithFlag(entitys, FLAG_1);
        {
            if (ermine_collision_check(self, Other, COLLISION_BEGIN) == true)
            {
                Rectangle pad = ermine_actor_bounding_box_get(Other);
                cBall->direccion.x *= -1;
                cBall->velocity.y = (boundBall.y - pad.y) + GetRandomValue(200, 250);
                PlaySound(resource_get_sound("hit"));
            }
        }
        EndGetActorWithFlag();

        // ----------------------------------
        // Move Ball
        float vx = cBall->velocity.x * cBall->direccion.x * delta;
        float vy = cBall->velocity.y * cBall->direccion.y * delta;
        ermine_actor_position_add(self, (Vector2){vx, vy});
        ermine_text_set(act_scoreA, TextFormat("%d", scoreA));
        ermine_text_set(act_scoreB, TextFormat("%d", scoreB));
    }
    EndSystem
}

int main(int argc, char *argv[])
{
    ermine_system(OnSystemUpdate, "PadController", system_PadController);
    ermine_system(OnSystemUpdate, "BallSystem", system_BallSystem);

    ermine_stage_init("Ermine - Pong", 800, 600);
    {
        resource_load_sound("hit", "example/resource/hit.wav");
        resource_load_sound("hitHurt", "example/resource/hitHurt.wav");

        Scene *scene = ermine_scene_new();
        ermine_stage_set(scene);
        {
            // HUD
            act_scoreA = ermine_text_render_with_new(scene, "0", 70, WHITE);
            ermine_actor_position_set(act_scoreA, (Vector2){(800 / 2 - 32 / 2) - 150, 20});

            act_scoreB = ermine_text_render_with_new(scene, "0", 70, WHITE);
            ermine_actor_position_set(act_scoreB, (Vector2){(800 / 2 - 32 / 2) + 150, 20});

            act_gameover = ermine_text_render_with_new(scene, "Press any key to begin", 40, RED);
            Vector2 ss = ermine_text_measure(act_gameover);
            ermine_actor_position_set(act_gameover, (Vector2){(800 / 2 - ss.x / 2), 400 / 2 + 70});
            ermine_actor_visible_set(act_gameover, false);

            for (int i = 0; i < 13; i++)
            {
                ErmineActor *line = ermine_shape_rect_new(scene, 25, 25, WHITE);
                ermine_actor_position_set(line, (Vector2){800 / 2, (i * 50) + 25});
                ermine_actor_render_index_set(line, -1);
            }

            // Game
            ErmineActor *player = ermine_shape_rect_new(scene, 25, 100, BLUE);
            ermine_actor_position_set(player, (Vector2){25, 300});
            ermine_actor_flag_set(player, FLAG_1);
            ermine_system_set(player, "PadController", true);

            ErmineActor *IA = ermine_shape_rect_new(scene, 25, 100, GREEN);
            ermine_actor_position_set(IA, (Vector2){800 - 25, 300});
            ermine_actor_flag_set(IA, FLAG_1);
            ermine_system_set(IA, "PadController", true);

            ErmineActor *pelota = ermine_shape_circle_new(scene, 10, YELLOW);
            ermine_actor_position_set(pelota, (Vector2){800 / 2, 595 / 2});
            ermine_system_set(pelota, "BallSystem", &(ComponentBall){.velocity = {200, 200}, .direccion = {1, -1}});
        }
    }
    ermine_stage_main();
    return 0;
}
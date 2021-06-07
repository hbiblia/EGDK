#include "collision.h"

static bool circle_rectangle(Rectangle boxA, Rectangle boxB)
{
    float tx = boxA.x;
    float ty = boxA.y;

    if (boxA.x < boxB.x)
        tx = boxB.x;
    else if (boxA.x > boxB.x + boxB.width)
        tx = boxB.x + boxB.width;
    if (boxA.y < boxB.y)
        ty = boxB.y;
    else if (boxA.y > boxB.y + boxB.height)
        ty = boxB.y + boxB.height;

    float dx = boxA.x - tx;
    float dy = boxA.y - ty;
    float dc = sqrt((dx * dx) + (dy * dy));
    return (dc <= boxA.width ? true : false);
}

static int distance_check(ErmineActor *Actor, ErmineActor *Other)
{
    Rectangle boxA = ermine_actor_bounding_box_get(Actor);
    Rectangle boxB = ermine_actor_bounding_box_get(Other);

    int a = boxA.x - boxB.x;
    int b = boxA.y - boxB.y;
    return sqrt((a * a) + (b * b));
}

// -- ----------------------------
bool _collision_global_check(ErmineActor *Actor, ErmineActor *Other)
{
    int tA = ermine_actor_type_get(Actor);
    int tB = ermine_actor_type_get(Other);
    Rectangle bA = ermine_actor_bounding_box_get(Actor);
    Rectangle bB = ermine_actor_bounding_box_get(Other);

    if (tA == TACTOR_SHAPE_CIRCLE && tB == TACTOR_SHAPE_RECT)
    {
        return circle_rectangle(bA, bB);
    }
}

// -- ----------------------------
bool ermine_collision_check(ErmineActor *Actor, ErmineActor *Other, COLLISION_STATE state)
{
#define collision_get ermine_actor_collision_state_get
#define collision_set ermine_actor_collision_state_set

    // int dpoint = distance_check(Actor, Other);
    bool r = _collision_global_check(Actor, Other);

    if (r == false && collision_get(Actor) == COLLISION_BEGIN)
    {
        collision_set(Actor, COLLISION_STAY);
    }
    if (r == true && collision_get(Actor) == 0)
    {
        collision_set(Actor, COLLISION_BEGIN);
    }
    if (collision_get(Actor) == COLLISION_END)
    {
        collision_set(Actor, 0);
    }
    if (r == false && collision_get(Actor) == COLLISION_STAY)
    {
        collision_set(Actor, COLLISION_END);
    }

    return collision_get(Actor) == state;
}

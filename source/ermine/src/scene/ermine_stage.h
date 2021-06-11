#ifndef STAGE_H
#define STAGE_H
#include "ermine.h"

void ermine_stage_init(const char *title, int w, int h, char *argv[]);

void ermine_stage_set(Scene *scene);

void ermine_stage_set_color(Color color);

void ermine_stage_main(void);

#endif
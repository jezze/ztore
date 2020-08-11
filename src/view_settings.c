#include <stdlib.h>
#include "define.h"
#include "backend.h"
#include "box.h"
#include "text.h"
#include "menu.h"
#include "view.h"
#include "ztore.h"

static struct view view;

struct area
{

    struct box box;
    unsigned int selectable;

};

static void area_draw(struct box *box)
{

    struct box box2;

    box2.x = box->x + 4;
    box2.y = box->y + 4;
    box2.w = box->w - 8;
    box2.h = box->h - 8;

    backend_rect(box2.x, box2.y, box2.w, box2.h);

}

static struct area areas[8];

static void area_init(struct area *area, int mw, int mh, int x, int y, int w, int h, unsigned int selectable)
{

    unsigned int ow = 4;
    unsigned int oh = 4;
    unsigned int col = (mw - ow) / 6;
    unsigned int row = (mh - oh) / 6;

    area->box.x = col * x + ow;
    area->box.y = row * y + oh;
    area->box.w = col * w;
    area->box.h = row * h;

}

static void place(unsigned int w, unsigned int h)
{

    area_init(&areas[0], w, h, 0, 0, 6, 1, 1);
    area_init(&areas[1], w, h, 0, 1, 6, 2, 1);
    area_init(&areas[2], w, h, 0, 3, 6, 1, 1);
    area_init(&areas[3], w, h, 0, 4, 3, 1, 1);
    area_init(&areas[4], w, h, 3, 4, 3, 1, 1);
    area_init(&areas[5], w, h, 0, 5, 6, 1, 1);

}

static void render(unsigned int ticks)
{

    area_draw(&areas[0].box);
    area_draw(&areas[1].box);
    area_draw(&areas[2].box);
    area_draw(&areas[3].box);
    area_draw(&areas[4].box);
    area_draw(&areas[5].box);

}

static void button(unsigned int key)
{

    switch (key)
    {

    case KEY_B:
        view_quit("settings");

        break;

    }

}

static void load(void)
{

    ztore_setview(place, render, button);

}

static void config(char *key, void *value)
{

}

void view_settings_setup(void)
{

    view_init(&view, load, config);
    view_register("settings", &view);

}


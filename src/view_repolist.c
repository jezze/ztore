#include <stdlib.h>
#include <stdio.h>
#include "define.h"
#include "box.h"
#include "text.h"
#include "list.h"
#include "view.h"
#include "db.h"
#include "ztore.h"
#include "widget.h"
#include "selection.h"

static struct view view;
static struct widget_area areas[4];
static struct widget_text texts[8];
static struct selection selection;
static char all[16];
static char new[16];
static char updated[16];
static char installed[16];
static struct db_applist applist;

static void place(unsigned int w, unsigned int h)
{

    widget_area_place(&areas[0], 0, 0, w, h);
    widget_area_place(&areas[1], 0, 0, w, h);
    widget_area_place(&areas[2], 0, 0, w, h);
    widget_area_place(&areas[3], 0, 0, w, h);
    widget_text_placein(&texts[0], &areas[0].size);
    widget_text_placein(&texts[1], &areas[0].size);
    widget_text_placein(&texts[2], &areas[1].size);
    widget_text_placein(&texts[3], &areas[1].size);
    widget_text_placein(&texts[4], &areas[2].size);
    widget_text_placein(&texts[5], &areas[2].size);
    widget_text_placein(&texts[6], &areas[3].size);
    widget_text_placein(&texts[7], &areas[3].size);

}

static void render(unsigned int ticks)
{

    widget_area_render(selection.active->data);
    widget_text_render(&texts[0]);
    widget_text_render(&texts[1]);
    widget_text_render(&texts[2]);
    widget_text_render(&texts[3]);
    widget_text_render(&texts[4]);
    widget_text_render(&texts[5]);
    widget_text_render(&texts[6]);
    widget_text_render(&texts[7]);

}

static void button(unsigned int key)
{

    selection_setclosest(&selection, key);

    if (key == KEY_A && selection_isactive(&selection, &areas[0].item))
    {

        db_freeapps(&applist);
        db_loadapps(&applist);
        view_config("applist", "list", &applist);
        selection_select(&selection, key, "repolist", "applist");

    }

    if (key == KEY_A && selection_isactive(&selection, &areas[1].item))
    {

        db_freeapps(&applist);
        db_loadappswithstate(&applist, 3);
        view_config("applist", "list", &applist);
        selection_select(&selection, key, "repolist", "applist");

    }

    if (key == KEY_A && selection_isactive(&selection, &areas[2].item))
    {

        db_freeapps(&applist);
        db_loadappswithstate(&applist, 1);
        view_config("applist", "list", &applist);
        selection_select(&selection, key, "repolist", "applist");

    }

    if (key == KEY_A && selection_isactive(&selection, &areas[3].item))
    {

        db_freeapps(&applist);
        db_loadappswithstate(&applist, 2);
        view_config("applist", "list", &applist);
        selection_select(&selection, key, "repolist", "applist");

    }

    selection_return(&selection, key, "repolist");

}

static void load(void)
{

    snprintf(all, 16, "%u items", db_countapps());
    snprintf(new, 16, "%u items", db_countappswithstate(1));
    snprintf(updated, 16, "%u items", db_countappswithstate(2));
    snprintf(installed, 16, "%u items", db_countappswithstate(3));
    ztore_setview(place, render, button);

    selection.active = selection.list.head;

}

void view_repolist_setup(void)
{

    view_init(&view, "repolist", load, 0);
    view_register(&view);
    widget_area_init(&areas[0], 0, 0, 8, 1);
    widget_area_init(&areas[1], 0, 1, 8, 1);
    widget_area_init(&areas[2], 0, 2, 8, 1);
    widget_area_init(&areas[3], 0, 3, 8, 1);
    widget_text_init(&texts[0], TEXT_COLOR_SELECT, TEXT_ALIGN_LEFT, "All");
    widget_text_init(&texts[1], TEXT_COLOR_NORMAL, TEXT_ALIGN_RIGHT, all);
    widget_text_init(&texts[2], TEXT_COLOR_SELECT, TEXT_ALIGN_LEFT, "Installed");
    widget_text_init(&texts[3], TEXT_COLOR_NORMAL, TEXT_ALIGN_RIGHT, installed);
    widget_text_init(&texts[4], TEXT_COLOR_SELECT, TEXT_ALIGN_LEFT, "New");
    widget_text_init(&texts[5], TEXT_COLOR_NORMAL, TEXT_ALIGN_RIGHT, new);
    widget_text_init(&texts[6], TEXT_COLOR_SELECT, TEXT_ALIGN_LEFT, "Updated");
    widget_text_init(&texts[7], TEXT_COLOR_NORMAL, TEXT_ALIGN_RIGHT, updated);
    list_add(&selection.list, &areas[0].item);
    list_add(&selection.list, &areas[1].item);
    list_add(&selection.list, &areas[2].item);
    list_add(&selection.list, &areas[3].item);

}


#define WIDGET_TYPE_NONE                0
#define WIDGET_TYPE_AREA                1
#define WIDGET_TYPE_SLIDER              2
#define WIDGET_TYPE_TEXT                3

struct widget_area
{

    struct box unit;
    unsigned int selectable;

};

struct widget_slider
{

    int min;
    int max;
    int value;

};

struct widget_text
{

    unsigned int color;
    unsigned int align;
    char *data;

};

struct widget
{

    unsigned int type;
    struct list_item item;
    struct box size;

    union
    {

        struct widget_area area;
        struct widget_slider slider;
        struct widget_text text;

    } payload;

};

void widget_area_place(struct widget *widget, struct box *box);
void widget_area_render(struct widget *widget, unsigned int ticks);
void widget_area_init(struct widget *widget, int x, int y, int w, int h);
void widget_slider_place(struct widget *widget, struct box *box);
void widget_slider_render(struct widget *widget, unsigned int ticks);
void widget_slider_init(struct widget *widget, int min, int max, int value);
void widget_text_place(struct widget *widget, struct box *box);
void widget_text_render(struct widget *widget, unsigned int ticks);
void widget_text_init(struct widget *widget, unsigned int color, unsigned int align, char *data);

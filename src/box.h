struct box
{

    unsigned int x;
    unsigned int y;
    unsigned int w;
    unsigned int h;

};

void box_setpartsize(struct box *box, unsigned int pw, unsigned int ph, unsigned int x, unsigned int y, unsigned int w, unsigned int h);
void box_init(struct box *box);

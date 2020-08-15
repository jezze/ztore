int backend_font_getascent(void);
void backend_font_getmetrics(char c, int *minx, int *maxx, int *miny, int *maxy, int *advance);
void backend_paint_glyph(char c, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int color);
void backend_paint_slider(int x, int y, int w, int h);
void backend_paint_selection(int x, int y, int w, int h);
void backend_pollevent(void (*quit)(void), void (*button)(unsigned int key));
void backend_waitevent(void (*quit)(void), void (*button)(unsigned int key));
void backend_render(unsigned int ticks, void (*place)(unsigned int w, unsigned int h), void (*render)(unsigned int ticks));
unsigned int backend_ticks(void);
void backend_delay(unsigned int ms);
void backend_play(char *name);
void backend_loadbackground(char *name);
void backend_loadsample(char *name, char *path);
void backend_loadfont(char *name);
void backend_unloadbackground(void);
void backend_unloadsample(char *name);
void backend_unloadfont(void);
void backend_init(void);
void backend_destroy(void);

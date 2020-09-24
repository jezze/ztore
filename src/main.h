void main_configview(char *name, char *key, void *value);
void main_initview(char *name, char *parentname);
void main_destroyview(char *name);
void main_registerview(struct view *view);
void main_exec(char id[6], char *sha1);
void main_select(struct view *view, char *match, char *to);
void main_unselect(struct view *view);
void main_goprev(struct view *view, char *id);
void main_gonext(struct view *view, char *id);
void main_button(unsigned int button);
void main_quit(void);

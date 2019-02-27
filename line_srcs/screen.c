#include "../line_incs/line.h"

void get_window_size(t_edit *edit)
{
    edit->screencol = tgetnum("co");
    edit->screenrow = tgetnum("li");
}


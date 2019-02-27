#include "../line_incs/line.h"


/*
** movement of  cursor;
*/

void move_cursor_right(t_edit *edit)
{
    tputs(tgetstr("nd",NULL),1, term_putc);
    edit->cur_col++;
}

void move_cursor_left(t_edit *edit)
{
    if (edit->cur_col == 0 && edit->cur_col == 0)
        return;
    tputs(tgetstr("le",NULL),1, term_putc);
  
    edit->cur_col--;
}

int term_putc(int c)
{
    write(1,&c,1);
    return 0;
}
#include "../line_incs/line.h"


/*
** movement of  cursor;
*/

void save_cursor_pos()
{
    ft_putstr(tgetstr("sc",NULL));

}

void recall_last_cursor_pos()
{
    ft_putstr(tgetstr("rc",NULL));
}


void move_cursor_right(t_edit *edit)
{
    ft_putstr(tgetstr("nd",NULL));
    edit->cur_col++;
}

void move_cursor_left(t_edit *edit)
{
    ft_putstr(tgetstr("le",NULL));
    edit->cur_col--;
}

void move_cursor_newline(t_edit *edit)
{
    tputs(tgetstr("nl",NULL),0, term_putc);
    edit->cur_col = 0;
    edit->cur_row++;
}

void move_cursor_home(t_edit *edit)
{
    tputs(tgetstr("ho",NULL),0, term_putc);
    edit->cur_col = 0;
    edit->cur_row++;
}

int term_putc(int c)
{
    write(1,&c,1);
    return 0;
}
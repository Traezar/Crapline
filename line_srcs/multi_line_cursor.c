#include "../line_incs/line.h"

void move_killzone_up(t_edit *edit)
{
    if(edit->killzone == 0)
        return ;
    ft_putstr(tgetstr("up",NULL));
    edit->killzone--;
    save_cursor_pos();
    return;
}

void move_killzone_down(t_edit *edit)
{
    if(edit->killzone == edit->linemax - 1)
        return ;
        ft_putstr(tgetstr("do",NULL));
    edit->killzone++;
    save_cursor_pos();
    return;
}
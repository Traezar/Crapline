#include "../line_incs/line.h"

void arrow_up(t_edit *edit)
{
    (void)edit;
}
void arrow_down(t_edit *edit)
{
        (void)edit;
}
void arrow_left(t_edit *edit)
{
         if (edit->buffpos == 0)
        return; 
        edit->cur_col--;
        edit->buffpos--;
        //ft_putstr(tgoto(tgetstr("cm",NULL), (edit->cur_col),(edit->cur_row)));
        ft_putstr(tgetstr("le",NULL));       
}
void arrow_right(t_edit *edit)
{
        if (edit->buffpos == edit->printlen)
        return;
        edit->cur_col++;
        edit->buffpos++;
        ft_putstr(tgetstr("nd",NULL)); 
}

void arrow_backspace(t_edit *edit)
{
        size_t cursor_to_null;

        if (edit->buffpos == 0)
        return;           
        edit->buffpos--;
        edit->cur_col--;    
        cursor_to_null = ft_strlen(edit->line + edit->buffpos) + 1;
        ft_memmove( edit->line + edit->buffpos, edit->line + edit->buffpos + 1,cursor_to_null);
        ft_putstr((tgetstr("le",NULL)));
        edit->printlen--;

}
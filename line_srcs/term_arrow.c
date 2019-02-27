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
       if (edit->cur_col != 0)
       {
               edit->buffpos--;
               edit->cur_col--;
              // printf("the cursor is (%d,%d)\n", (edit->cur_row),(edit->cur_col));
              // ft_putstr(tgoto(tgetstr("CM",NULL),(edit->cur_row),(edit->cur_col)));
             // tputs(tgetstr("cl",NULL),1, term_putc);
               ft_putstr(tgetstr("le",NULL));
       } 
        
}
void arrow_right(t_edit *edit)
{
        if (edit->cur_col != 4096)
       {
               edit->buffpos++;
               edit->cur_col++;
              // printf("the cursor is (%d,%d)\n", (edit->cur_row),(edit->cur_col));
               ft_putstr(tgetstr("nd",NULL));
               //ft_putstr(tgoto(tgetstr("cm",NULL),(edit->cur_row),(edit->cur_col)));
       } 
}

void arrow_backspace(t_edit *edit)
{
        size_t cursor_to_null;

         if (edit->buffpos != 0)
        {
                edit->buffpos--;
                edit->cur_col--;
        }    
        cursor_to_null = ft_strlen(edit->line + edit->buffpos) + 1;
        ft_memmove( edit->line + edit->buffpos,edit->line + edit->buffpos + 1,cursor_to_null);
        ft_putstr(tgoto(tgetstr("cm",NULL),(edit->cur_row),(edit->cur_col)));

 
}
#include "../line_incs/line.h"

void put_prompt_line(t_edit *edit)
{
    tputs("21sh>",0,term_putc);
    edit->cur_col = 5;
}
void refresh_line_after_prompt(t_edit *edit)
{
    tputs(tgetstr("cr",NULL),0,term_putc);
    put_prompt_line(edit);
    tputs(tgetstr("ce",NULL),0,term_putc);
}
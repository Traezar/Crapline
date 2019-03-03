#include "../line_incs/line.h"

t_ctrl g_kctrl[] =
{
    {K_UP, arrow_up},
    {K_DOWN, arrow_down},
    {K_LEFT, arrow_left},
    {K_RIGHT, arrow_right},
    {K_BS, arrow_backspace}
};

void process_input(long num,int len, t_edit *edit)
{
    int cast;
    int i;
    size_t cursor_to_null;

    cast = (int)num;
    if (len == 1)
    {
        if (num != 127 && num != '\n')
            add_to_buffer(num,edit);
        else if (num != '\n')
            arrow_backspace(edit);
    }
        
    else if (len == 3)
    {
        i = -1;
        while(++i < 4)
        {
            if (num == g_kctrl[i].value)
            g_kctrl[i].f(edit);
        }
    }
    else if (len == 4)
    {
        cursor_to_null = ft_strlen(edit->line + edit->buffpos);
        ft_memmove( edit->line + edit->buffpos,edit->line + edit->buffpos + 1,cursor_to_null);
        edit->printlen--;
    }
}

void add_to_buffer (int num,t_edit *edit)
{
    size_t cursor_to_null;

    cursor_to_null = ft_strlen(edit->line + edit->buffpos);
    ft_memmove( edit->line + edit->buffpos + 1,edit->line + edit->buffpos, cursor_to_null);
    tputs(tgetstr("nd",NULL),0,term_putc);
    edit->line[edit->buffpos] = num;
    edit->buffpos++;
    edit->cur_col++;
    edit->printlen++;
}

char *complete_the_string(t_edit *edit)
{
    t_edit *cur;
    char *comp;

    cur = init_buffer();
    tputs(tgetstr("do",NULL),0,term_putc); //moves down one row same column;
    tputs(tgetstr("cr",NULL),0,term_putc); //moves cursor to the left margin
    put_prompt_line(edit);
    save_cursor_pos();
    cur->quote = edit->quote;
    comp =complete_buffer(cur);
    free(cur->return_str);
    free(cur);
    return(ft_strjoin(edit->line,comp));
}
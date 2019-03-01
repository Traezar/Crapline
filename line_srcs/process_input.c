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
   // printf("%d\n", num);
    if (len == 1)
    {
        if (num != 127)
        add_to_buffer(num,edit);
        else
            arrow_backspace(edit);
    }
        
    else if (len == 3)
    {
        i = -1;
        //printf("\n%ld\n",num); 
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
    else
    printf("\nSOMETHIGNSEDLSE\n"); 

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
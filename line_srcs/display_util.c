#include "../line_incs/line.h"

void enable_raw_mode()
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &raw);
    g_original = raw;
    raw.c_lflag &= ~(ECHO| ICANON);
    raw.c_cc[VMIN] = 1;
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disable_raw_mode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_original);
}

void print_display(t_edit *edit)
{
    unsigned int row;
    unsigned int col;
    
    row = edit->linemax;
    col = edit->cur_col;
    while(--row > 0)
    {
       
        ft_putstr(tgetstr("cr",NULL));
        ft_putstr(tgetstr("ce",NULL));
        
        ft_putstr(tgetstr("up",NULL));    
    }
  
    ft_putstr(tgetstr("cr",NULL));
    while (row < edit->linemax)
    {
          
        ft_putstr(tgetstr("cd",NULL));
        put_prompt_line(row);
        edit->cur_col =1;
        tputs(edit->array[row]->line,0,term_putc);
        row++;
        if (edit->linemax != 1 && row != edit->linemax)
            move_cursor_newline(edit);
    }
}
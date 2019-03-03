#include "../line_incs/line.h"

void print_the_buffer(t_edit *edit)
{
    char *s;
    unsigned int i;

    s = edit->line;
    i = 0;
    while(s[i] != '\0')
    {
        if (edit->buffpos == i && edit->buffpos == edit->cur_col)
        {
            tputs(tgetstr("mr",NULL),0,term_putc);
            write(1, &s[i],1);
            tputs(tgetstr("me",NULL),0,term_putc);
        }
        else
            write(1,&s[i],1);
        i++;
    }
}

char *read_stdin(t_edit *edit)
{
    long num = 0;
    int len;
    
    while(1)
    {
        num = 0;
        
        print_the_buffer(edit);
        recall_last_cursor_pos();
        len = read(STDIN_FILENO, &num, 4);
        process_input(num, len, edit);
        if ((int)num == '\n')
        {
           edit->quote = quotes_are_closed(edit->line);
           if ( edit->quote == 0)
            return(ft_strdup(edit->line));
           else  
            while(quotes_are_closed(edit->return_str) != 0)
            {
                free(edit->return_str);
                edit->return_str= complete_the_string(edit);
            }
           return(edit->return_str);
        } 
        save_cursor_pos();
        refresh_line_after_prompt(edit);
    }
}

char *complete_buffer(t_edit *edit)
{
    long num = 0;
    int len;
    
    while(1)
    {
        num = 0;
        
        print_the_buffer(edit);
        recall_last_cursor_pos();
        len = read(STDIN_FILENO, &num, 4);
        process_input(num, len, edit);
        if ((int)num == '\n')
           return(edit->line);
        save_cursor_pos();
        refresh_line_after_prompt(edit);
    }
}


#include "../line_incs/line.h"

int main (void)
{
    t_edit *line;
    char *ret;

    line = init_buffer();
    init_terminal_data(line);
    enable_raw_mode();
    ret = read_stdin(line);
    disable_raw_mode();
    printf("\nThe line is : {%s}", ret);
    free(line);
        return 0;
}
t_edit *init_buffer()
{
    t_edit *new;

    new = malloc(sizeof(t_edit));
        ft_bzero(new->line,4096);
    new->cur_col = 5;
    new->cur_row = 0;
    new->buffpos = 0;
    new->return_str = ft_strnew(1);
    ft_bzero(new->return_str,1);
    return (new);
}

void init_terminal_data (t_edit *line)
{
    char *term;
    char *tmp;
    int work;

    tmp = NULL;
    if (!(term = getenv("TERM")))
        perror_exit("Environment variable term does not exist\n");
    work = tgetent(term,line->term);
    if (work == 0)
        perror_exit("Terminal pointed to by $(TERM) is shit\n");
    else if (work == -1)
        perror_exit("Term database is fucked\n");
    tputs(tgetstr("nw",NULL),0,term_putc);
    put_prompt_line(line);
    tputs(tgetstr("sc",NULL),0,term_putc);
    get_window_size(line);
    return;
}
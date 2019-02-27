#include "../line_incs/line.h"

int main (void)
{
    t_edit *line;

    line = init_terminal_data();
    enable_raw_mode();
    read_stdin(line);
    disable_raw_mode();
    return 0;
}

t_edit *init_terminal_data ()
{
    char *term;
    char *tmp;
    int work;
    t_edit *ret;

    tmp = NULL;
    if (!(term = getenv("TERM")))
        perror_exit("Environment variable term does not exist\n");
    ret = malloc(sizeof(t_edit));
    work = tgetent(term,ret->term);
    if (work == 0)
        perror_exit("Terminal pointed to by $(TERM) is shit\n");
    else if (work == -1)
        perror_exit("Term database is fucked\n");
    tputs(tgetstr("ti",NULL),0,term_putc);
    tputs(tgetstr("cd",NULL),0,term_putc);
    get_window_size(ret);
    ft_bzero(ret->line,4096);
    ret->cur_col = 0;
    ret->cur_row = 0;
    ret->buffpos = 0;
    return(ret);
}
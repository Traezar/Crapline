#ifndef LINE_H
#define LINE_H
#include "unistd.h"
#include "termios.h"
#include "term.h"
#include "stdlib.h"
#include "stdio.h"
#include "curses.h"
#include "../libft/includes/libft.h"

#define K_UP 4283163
#define K_DOWN 4348699
#define K_LEFT 4479771
#define K_RIGHT 4414235
#define K_DEL 2117294875
#define K_BS 127
#define NEWLINE 10
#define PROMPT_LEN 5


typedef struct s_edit
{
    struct termios *original;
    char *term;
    unsigned int    cur_row;
    unsigned int    cur_col;
    unsigned int    screenrow;
    unsigned int    screencol;
    char            line[4096];
    unsigned int    buffpos;
    unsigned int    printlen;
    int             quote;
    char *         return_str;
} t_edit;

typedef struct s_tracker
{
    unsigned int sgl:1;
    unsigned int dbl:1;
    unsigned int bck:1;
} t_tracker;

typedef struct dispatch_ctrl
{
    long value;
    void(*f)(t_edit *edit);
} t_ctrl;


struct termios g_original;
/*
** line.c
*/
void init_terminal_data (t_edit *line);
t_edit *init_buffer();
/*
** term_arrow.c
*/

void arrow_up(t_edit *edit);
void arrow_down(t_edit *edit);
void arrow_left(t_edit *edit);
void arrow_right(t_edit *edit);
void arrow_backspace(t_edit *edit);

/*
** display_util.c void clear_screen()
*/
void enable_raw_mode();
void disable_raw_mode();

/*
** cursor.c
*/
void move_cursor_right( t_edit *edit);
void move_cursor_left(t_edit *edit);
int term_putc(int c);
void save_cursor_pos();
void recall_last_cursor_pos();

/*
** cursor_helper_1.c
*/

/*
** prompt.c
*/
void put_prompt_line(t_edit *edit);
void refresh_line_after_prompt(t_edit *edit);

/*
** screen.c
*/
void get_window_size(t_edit *edit);

/*
** stdin_handler.c
*/
void print_the_buffer(t_edit *edit);
char *read_stdin(t_edit *edit);
char *complete_buffer(t_edit *edit);



/*
** quotes.c
*/
int quotes_are_closed(char *str);
/*
** error.c
*/
void perror_exit(char *str);

/*
** process_input.c
*/
void process_input(long num, int len, t_edit *edit);
void add_to_buffer (int num,t_edit *edit);
char *complete_the_string(t_edit *edit);

/*
** dispatch tables used.
*/


#endif
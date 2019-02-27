#include "../line_incs/line.h"

void print_the_buffer(t_edit *edit)
{
    char *s;
    unsigned int i;

    s = edit->line;
    i = 0;
    while(s[i] != '\0')
    {
        if (i == edit->cur_col)
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


void read_stdin(t_edit *edit)
{
    long num =0;
    int len;
    int print_len;
    int i;

    while(1)
    {
        num = 0;
        len = read(STDIN_FILENO, &num, 4);
        {
            //printf("\n(%ld)\n", num);
            //printf("(%c)\n", (int)num);
            //printf("%d\n",len);

            i =0;
            process_input(num, len, edit);
            tputs(tgetstr("cl",NULL),1, term_putc);
           // printf("21sh>");
            print_len = ft_strlen(edit->line);
            //printf("\nThe value is of the buffer length is: (%d)\n",print_len);
            tputs(tgetstr("ce",NULL),1, term_putc);
            print_the_buffer(edit);
            //printf("\nthe cursor is (%d,%d)\n", (edit->cur_row),(edit->cur_col));                
            //print image. save cursor position. clear line. move cursor back.
        }
        if ((int)num == 'q')
            break;
    }
    (void)edit;
}


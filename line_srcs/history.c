//this is for hstory

#ifndef DIRENT_H
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

#ifndef LINE_H
#include "../line_incs/line.h"
#endif

void read_file_to_array(t_edit *edit, int fd)
{
    int i;
    int ret;

    i =0;
   while ((ret = get_next_line(fd,edit->history + i)) == 1 && i < 499)
            i++;
    edit->hcount = i;
    edit->hmax = i + 1;
    if (ret == -1)
        perror_exit("GNL ret -1 . Hong Gan\n");
}

void import_history(t_edit *edit)
{
    DIR *dirptr;
    int file_desc;

    dirptr = opendir("./misc");
    if(dirptr == NULL)
    {
        if((file_desc = mkdir("./misc", 0755)) == -1)
            perror_exit("MKDIR FAIL GGWP\n");
    }
    file_desc = open("./misc/history.txt", O_RDWR|O_CREAT, S_IRWXU);
    edit->history = malloc((sizeof(char *) * 500));
    read_file_to_array(edit,file_desc);
    return;
}

// save a copy of the readline output to history. everytime the newline str is hit, send the combined return str to history [499]
void update_history(t_edit *edit)
{
       DIR *dirptr;
    int file_desc;

    dirptr = opendir("./misc");
    file_desc = open("./misc/history.txt", O_APPEND|O_RDWR, S_IRWXU);
    write(file_desc, edit->return_str, ft_strlen(edit->return_str));
    write(file_desc,"\n",1);
    close(file_desc);
    closedir(dirptr);
    return;

}

void history_up(t_edit *edit)// this command puts the previous entry int the history table into the the buffer; if it is multi line go to returnstr;
{
    char *str;
    
    str = edit->array[edit->killzone]->line;
    edit->hcount--;
    ft_bzero(str,1024);
    str = ft_strcpy(str, edit->history[edit->hcount]);
    edit->array[edit->killzone]->buffpos = ft_strlen(str);
    edit->array[edit->killzone]->printlen = ft_strlen(str);
    edit->cur_col = ft_strlen(str);
}

void history_down(t_edit *edit)// this command puts the next entry into the buffer;
{
    char *str;

    str = edit->array[edit->killzone]->line;
    edit->hcount++;
    ft_bzero(str,1024);
    str = ft_strcpy(str, edit->history[edit->hcount]);
    edit->array[edit->killzone]->buffpos = ft_strlen(str);
    edit->array[edit->killzone]->printlen = ft_strlen(str);
    edit->cur_col = ft_strlen(str);
}

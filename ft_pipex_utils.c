#include "ft_pipex.h"

int error(char *msg)
{
    ft_printf("%s %s\n",msg,strerror(errno));
    return 1;
}

int fdesc(char mode,char *file)
{
    int fd = -1;
    if(mode == 'r')
    {
        fd=open(file, O_RDONLY);
        if(fd == -1 || access(file,R_OK) == -1)
         return error("you can't read from this file:(");
    }
       
    if(mode == 'w')
    {
        fd=open(file, O_WRONLY);
         if(fd == -1 || access(file,W_OK) == -1)
            return error("you can't write in this file:( ");
    }
    return fd;
}
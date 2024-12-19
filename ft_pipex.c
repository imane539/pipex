#include "ft_pipex.h"
int main(int ac , char **av)
{
    if(ac != 5)
    return 0;
    // char *cmd1,*cmd2;
    int pipefd[2];

    if(pipe(pipefd) == -1)
        ft_printf("failed to create a pipe :( %s\n",strerror(errno));

    if(access(av[1],R_OK) == -1)
        ft_printf("you can't read from this file:( %s\n",strerror(errno));

    else
        pipefd[0]=open(av[1],O_RDONLY);

    


    
    if(access(av[4],W_OK) == -1)
        ft_printf("you can't write in this file:( %s\n",strerror(errno));

    else
    pipefd[1]=open(av[4],O_RDONLY);

}
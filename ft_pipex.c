#include "ft_pipex.h"
int error(char *msg)
{
    ft_printf("%s %s\n",msg,strerror(errno));
    return 0;
}
int main(int ac , char **av)
{
    if(ac != 5)
    return 0;
    // char *cmd1,*cmd2;
    int pipefd[2];
    int fd0,fd1;
/* ******************** create a pipe ***************************** */
    if(pipe(pipefd) == -1)
       return error("failed to create a pipe :( ");


/* ****************** open the file1 to read *************************** */
    fd0=open(av[1],O_RDONLY | O_CREAT); 
    if(access(av[1],R_OK) == -1)
       return error("you can't read from this file:( ");

    else
    {
       fd0=open(av[1],O_RDONLY); 
       ft_printf("%d",fd0);
    }
        

    


/* ****************** open the file1 to write *************************** */
    
    if(access(av[4],W_OK) == -1)
       return error("you can't write in this file:( ");

    else
    fd1=open(av[4],O_RDONLY);

}

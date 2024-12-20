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
    int id,id1;
/* ******************** create a pipe ***************************** */
    if(pipe(pipefd) == -1)
       return error("failed to create a pipe :( ");


/* ****************** open the file1 to read *************************** */ 
    if(access(av[1],R_OK) == -1)
       return error("you can't read from this file:( ");

    else
    {
       fd0=open(av[1],O_RDONLY); 
       dup2(fd0,STDIN_FILENO);
    }
    id = fork();  
    if(id == -1)
    return error("failed to create a child :( "); 
        //child1
    if(id == 0)
    {
        
    }
    else {
/* ****************** open the file1 to write *************************** */
    
    if(access(av[4],W_OK) == -1)
       return error("you can't write in this file:( ");

    else
    {
        fd1=open(av[4],O_WRONLY);
        dup2(fd1,STDOUT_FILENO);
    }
    

        
        id1 = fork();
        if(id1 == -1)
             return error("failed to create a child 2:( "); 
        //child2

        if(id == 0)
        {

        }
        //parent
        else{

        }
    }
    




}

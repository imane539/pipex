#include "ft_pipex.h"

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
    // fd0=open(av[1],O_CREAT | O_RDONLY);
    // if(fd0 == -1 && access(av[1],R_OK) == -1)
    //      return error("you can't read from this file:(");
    
    if((fd0 = fdesc('r',av[1]) ) == 1)
        return 1;
     //create new child
    id = fork();  
    if(id == -1)
    return error("failed to create a child :( "); 
        //child1
       if(id == 0)
        {
            if(dup2(fd0,STDIN_FILENO) == -1)
                return error("failed to duplicate fd0:(");
            else
            {
                    
            }

        }   
 
   
/* ****************** open the file1 to write *************************** */
    if((fd1 = fdesc('w',av[4])) == 1)
            return 1;

    id1 = fork();
    if(id1 == -1)
             return error("failed to create a child 2:( "); 
    //child2

    if(id == 0)
    { 
         if(dup2(fd1,STDOUT_FILENO) == -1)
                return error("failed to duplicate fd1:(");

        else
        {
            
        }
    }
  
   
        //parent
  
    




}

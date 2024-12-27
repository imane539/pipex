#include "ft_pipex.h"

int main(int ac , char **av,char **envp)
{
    if(ac != 5)
    return 0;
    // char *cmd1;
    int pipefd[2];
    int fd0,fd1;
    int id,id1;
    char **argv;
    size_t size;
     char *path;
    char *tes;
    
    tes=ft_strdup("/usr/bin/");
    if(pipe(pipefd) == -1)
       return error("failed to create a pipe :( ");

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
            close(fd0);
            if(dup2(pipefd[1],STDOUT_FILENO) == -1)
                return error("failed to duplicate pipefd1:(");
                        argv=ft_split(av[2],' ');
                        size = ft_strlen("/usr/bin/") + ft_strlen(argv[0]) + 1;
                        path = ft_strlcat(tes,argv[0],size);
                        if(execve(path,argv,envp) == -1)
                            return error("failed to exec :( "); 
        }   
 else
 {
/* ****************** open the file1 to write *************************** */
        close(pipefd[1]);

    if((fd1 = fdesc('w',av[4])) == 1)
            return 1;
    id1 = fork();
    if(id1 == -1)
             return error("failed to create a child 2:( "); 
    //child2
    if(id1 == 0)
    { 
         if(dup2(pipefd[0],STDIN_FILENO) == -1)
                return error("failed to duplicate pipefd0:(");
      
             if(dup2(fd1,STDOUT_FILENO) == -1)
                    return error("failed to duplicate fd1:(");
                    //  close(pipefd[0]);
                        argv=ft_split(av[3],' ');
                        size = ft_strlen("/usr/bin/") + ft_strlen(argv[0]) + 1;
                        path = ft_strlcat(tes,argv[0],size);
                       
                        if(execve(path,argv,envp) == -1)
                            return error("failed to exec :( "); 
        
    }
  
   
        //parent
  
    


 }

}

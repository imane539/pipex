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
            if(dup2(pipefd[1],STDOUT_FILENO) == -1)
                return error("failed to duplicate fd0:(");
            else
            {
                        close(pipefd[1]);
                        argv=ft_split(av[2],' ');
                        size = ft_strlen("/usr/bin/") + ft_strlen(argv[0]) + 1;
                        // char *path;
                        // char *tes=ft_strdup("/usr/bin/");
                        path = ft_strlcat(tes,argv[0],size);
                        if(execve(path,argv,envp) == -1)
                            return error("failed to exec :( "); 
            }

        }   
 else
 {

/* ****************** open the file1 to write *************************** */
    if((fd1 = fdesc('w',av[4])) == 1)
            return 1;
    id1 = fork();
    if(id1 == -1)
             return error("failed to create a child 2:( "); 
    //child2
    if(id == 0)
    { 
         if(dup2(pipefd[0],STDIN_FILENO) == -1)
                return error("failed to duplicate fd1:(");

        else
        {
                        close(pipefd[0]);
                        char *test[4];
                        read(0,test,4);
                        ft_printf("%s",tes);
                        argv=ft_split(av[4],' ');
                        size = ft_strlen("/usr/bin/") + ft_strlen(argv[0]) + 1;
                        path = ft_strlcat(tes,argv[0],size);

                        if(execve(path,argv,envp) == -1)
                            return error("failed to exec :( "); 
        }
    }
  
   
        //parent
  
    


 }

}

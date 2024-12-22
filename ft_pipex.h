
#ifndef FT_PIPEX_H
# define FT_PIPEX_H

#include "ft_printf.h"
#include <errno.h>
# include <fcntl.h>
int error(char *msg);
int fdesc(char mode,char *file);
#endif
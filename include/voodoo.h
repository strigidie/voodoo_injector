#ifndef VOODOO_H
# define VOODOO_H

#include <errno.h>
#include <elf.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum __attribute__((packed)) e_return_code
{
    RETURN_ERROR = -1,
    RETURN_SUCCESS = 0
} t_return_code;

t_return_code
elf_check_magic( const int fd );

typedef struct s_args
{
    const int argc;
    const char * const * argv;
    const char * const * envp;
} t_args;


#endif

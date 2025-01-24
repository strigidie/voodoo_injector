#ifndef VOODOO_CSTD_H
# define VOODOO_CSTD_H

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

#endif

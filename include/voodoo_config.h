#ifndef VOODOO_CONFIG_H
# define VOODOO_CONFIG_H

#include "voodoo_cstd.h"

typedef struct s_args
{
    const uint8_t argc;
    const char * const * argv;
    const char * const * envp;
} t_args;

typedef enum __attribute__((packed)) e_config_flag
{
    VERBOSE
} t_config_flag;

typedef enum __attribute__((packed)) e_config_target_type 
{
    FD,
    PID
} t_config_process_type;

typedef struct s_config
{
    const t_config_flag flags;
    const uint8_t target;
    const uint8_t payload;
    const t_config_process_type target_type; 
    const t_config_process_type payload_type; 
} t_config;

t_return_code
config_init( const t_args args, t_config * config );

#endif

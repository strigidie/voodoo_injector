#include "voodoo_config.h"

static void flag_target_file( t_config * config )
{
}

static void flag_target_pid( t_config * config )
{
}

static void flag_payload_file( t_config * config)
{
}

static void flag_payload_pid( t_config * config )
{
}

static void flag_verbose( t_config * config )
{
}

// It's, of couse, better to have a hash table instead of a generic array...
typedef struct s_flag
{
    const char * flag;
    const void ( *flag_func )( t_config* );
} t_flag;

const t_flag flag_ftable[] = {
    { "--target-file",  &flag_target_file },
    { "--payload-file", &flag_payload_file },
    { "--target-pid",   &flag_target_pid },
    { "--payload-pid",  &flag_payload_pid },
    { "--verbose",      &flag_verbose }
};

t_return_code config_init( const t_args args, t_config * config )
{
    for (size_t i = 1; i < args.argc; ++i )
    {
        printf("%s ", args.argv[i]);
    }
    printf("\n");

    return RETURN_SUCCESS;
}
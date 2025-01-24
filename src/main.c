#include "voodoo.h"

int
main( const int argc,
      const char * const * argv,
      const char * const * envp )
{
    const t_args args = { argc, argv, envp };
    
    t_config config;
    if ( config_init( args, &config ) != RETURN_SUCCESS )
    {
        // USAGE
        return EXIT_FAILURE;
    }

    /*if ( injector_run( config ) != RETURN_SUCCESS)
    {
        return EXIT_FAILURE;
    }*/

    return EXIT_SUCCESS;
}

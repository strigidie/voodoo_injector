#include "voodoo.h"

int
main(const int argc, const char * const * argv, const char * const * envp)
{
    const int fd = open("foo.elf", O_APPEND | O_RDWR);
    t_return_code flag = elf_check_magic(fd);
    return EXIT_SUCCESS;
}

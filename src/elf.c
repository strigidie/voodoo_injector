#include "voodoo.h"

t_return_code
elf_check_magic( const int fd )
{
    const off_t fd_offset = lseek( fd, 0x0, SEEK_CUR );
    if ( fd_offset == (off_t)-1 )
    {
        perror("Error getting current file offset");
        return RETURN_ERROR;
    }  

    if ( fcntl(fd, F_GETFD) == -1 )
    {
        perror("Invalid file descriptor");
        return RETURN_ERROR;
    }
    
    if ( lseek( fd, 0x0, SEEK_SET ) == -1 )
    {
        perror("Error seeking on file descriptor");
        return RETURN_ERROR;
    }

    const uint8_t e_magic[] = { 0x7f, 0x45, 0x4c, 0x46 };
    const size_t e_magic_size = sizeof(e_magic);
    
    uint8_t fd_magic[ e_magic_size ];
    if ( read( fd, fd_magic, e_magic_size ) != e_magic_size )
    {
        perror("Error reading from file descriptor");
        return RETURN_ERROR;
    }
    
    if ( lseek( fd, fd_offset, SEEK_SET ) == -1 )
    {
        perror("Error restoring file offset");
        return RETURN_ERROR;
    }
    
    if ( memcmp( fd_magic, e_magic, e_magic_size ) != 0 )
        return RETURN_ERROR;

    return RETURN_SUCCESS;
}

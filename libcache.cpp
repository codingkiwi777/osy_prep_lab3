#include "libcache.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdio>

void cache_access(const char *path) 
{
    if (access(path, R_OK) == 0) 
    {
        printf("Soubor %s lze číst: ANO\n", path);
    }
    else 
    {
        printf("Soubor %s lze číst: NE\n", path);
    }
}

void cache_stat(const char *path) 
{
    struct stat sb;
    
    if (stat(path, &sb) == -1) 
    {
        printf("Chyba: nelze získat informace o souboru %s\n", path);
        return;
    }
    
    printf("Velikost: %ld bajtů\n", sb.st_size);
    printf("UID: %d\n", sb.st_uid);
    printf("GID: %d\n", sb.st_gid);
    printf("Počet hardlinků: %ld\n", sb.st_nlink);
}

void cache_lstat(const char *path) 
{
    struct stat sb;
    
    if (lstat(path, &sb) == -1) 
    {
        printf("Chyba: nelze získat informace o souboru %s\n", path);
        return;
    }
    
    if (S_ISLNK(sb.st_mode))
    {
        printf("Typ souboru: symbolický odkaz\n");
    } 
    else if (S_ISREG(sb.st_mode)) 
    {
        printf("Typ souboru: běžný soubor\n");
    } 
    else 
    {
        printf("Typ souboru: jiný\n");
    }
    
    printf("Velikost: %ld bajtů\n", sb.st_size);
}

void cache_fstat(const char *path)
{
    int fd = open(path, O_RDONLY);
    
    if (fd == -1) 
    {
        printf("Chyba: nelze otevřít soubor %s\n", path);
        return;
    }
    
    struct stat sb;
    
    if (fstat(fd, &sb) == -1)
    {
        printf("Chyba: nelze získat informace o souboru\n");
        close(fd);
        return;
    }
    
    printf("Velikost souboru: %ld bajtů\n", sb.st_size);
    printf("Číslo inodu: %ld\n", sb.st_ino);
    
    close(fd);
}

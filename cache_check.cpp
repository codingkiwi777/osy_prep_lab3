#include "libcache.h"
#include <cstdio>
#include <cstring>

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        printf("Použití: %s <přepínač> <cesta_k_souboru>\n", argv[0]);
        printf("Přepínače:\n");
        printf("  -a  : cache_access\n");
        printf("  -s  : cache_stat\n");
        printf("  -l  : cache_lstat\n");
        printf("  -f  : cache_fstat\n");
        return 1;
    }
    
    const char *option = argv[1];
    const char *path = argv[2];
    
    if (strcmp(option, "-a") == 0)
    {
        cache_access(path);
    } 
    else if (strcmp(option, "-s") == 0) 
    {
        cache_stat(path);
    } 
    else if (strcmp(option, "-l") == 0) 
    {
        cache_lstat(path);
    } 
    else if (strcmp(option, "-f") == 0) 
    {
        cache_fstat(path);
    } else 
    {
        printf("Neznámý přepínač: %s\n", option);
        return 1;
    }
    
    return 0;
}

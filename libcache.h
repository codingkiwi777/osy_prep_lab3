#ifndef LIBCACHE_H
#define LIBCACHE_H

void cache_access(const char *path);
void cache_stat(const char *path);
void cache_lstat(const char *path);
void cache_fstat(const char *path);

#endif

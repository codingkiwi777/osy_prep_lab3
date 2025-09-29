lab 3 prep osy

• každá úroveň 3 typy oprávnění:
	r (read), w (write), x (execute)
• každý soubor tři úrovně přístupových práv:
	Owner (rwx), Group (rx), Others (r)
• Metadata souboru:
	Velikost, UID, GID, Počet hardlinků, Inode číslo, Typ souboru, Časy
• 4 hlavni funkce:
	access() - kontrola přístupových práv
	stat() - kompletní informace o souboru (symlinku)
	lstat() - vrací jen info o samotném odkazu 
	fstat() - stav otevřeného souboru, musíš nejdřív soubor otevřít pomocí open(), dostaneš číslo (např. 3), a pak voláš fstat(3, ...)
  priklad fstatu:
	int fd = open("/home/user/soubor.txt", O_RDONLY);
	fstat(fd, &info);  // používáš číslo, ne cestu!
	close(fd);
• symbolický odkaz = symlink

kompilace:
• g++ -fPIC -shared -o libcache.so libcache.cpp
• g++ -o cache_check cache_check.cpp -L. -lcache
• export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

# Vytvoř testovací soubor
echo "test obsah" > test.txt

# Vytvoř symbolický odkaz
ln -s test.txt odkaz.txt

# Testuj jednotlivé funkce
./cache_check -a test.txt
./cache_check -s test.txt
./cache_check -l odkaz.txt
./cache_check -f test.txt

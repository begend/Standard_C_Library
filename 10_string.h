string.h
字符串

一，内存操作函数

void *memcpy(void *des, const void *src, size_t n);
从src中复制n个字符到des中，des和src不能重叠，返回des指针

void *memmove(void *des, const void *src, size_t n);
将src中n个字符先复制到临时数组中，再复制到des中，des和src可以重叠，返回des指针

int memcmp(const void *s1, const void *s2, size_t n);
将s1的前n个字符与s2的前n个字符进行比较，s1较大返回正值，较小返回负值，相等返回0
可以简单的看作返回s1 - s2

void *memchr(const void *s, int c, size_t n);
搜索s前n个字符中c第一次出现的位置，成功返回被搜索到的字符的指针，否则返回空指针

void *memset(void *s, int c, size_t n);
将字符c复制到s中前n个字符中，常用于初始化内存，返回s指针

二，字符串操作函数

char *strcpy(char *des, const char *src);
将src字符串复制到des中，des和src不能重叠，返回des指针

char *strncpy(char *des, const char *src, size_t n);
将src中最多n个字符复制到des中，des和src不能重叠，返回des指针

char *strcat(char *des, const char *src);
将src字符串追加到des字符串的尾部，des和src不能重叠

char *strncat(char *des, const char *src, size_t n);
将src字符串最多n个字符追加到des字符串的尾部，des和src不能重叠

int strcmp(const char *s1, const char *s2);
比较s1和s2，s1较大返回正值，较小返回负值，相等返回0，可以简单看作返回s1 - s2

int strncmp(const char *s1, const char *s2, size_t n);
比较s1和s2前n个字符，其余与strcmp一样

char *strchr(const char *s, int c);
搜索字符串s中第一次出现c的位置，成功返回该被搜索到的字符的指针，否则返回空指针

char *strrchr(const char *s, int c);
搜索字符串s中最后一次出现c的位置，成功返回该被搜索到的字符的指针，否则返回空指针

char *strstr(const char *s1, const char *s2);
搜索字符串s1中第一次出现s2字符串的位置，成功返回s2在s1中出现的指针，否则返回空指针

size_t strlen(const char *s);
返回字符串s的长度，不包括结尾的'\0'符


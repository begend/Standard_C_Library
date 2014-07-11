stddef.h
标准定义

ptrdiff_t	指针距离差
size_t		数量，sizeof()函数返回的结果就是size_t型，一般size_t是unsigned int
			这个量和NULL是使用最多次数的两个量，另外两个没怎么用过

wchar_t		中文这样的区域字符长
NULL		空指针，等于0，宏中的声明 NULL 的方式很特别，有
#define NULL (char *) 0
#define NULL (int *) 0
#define NULL (long *) 0
不过最安全的定义是
#define NULL (void *) 0
事实上 void* 也是新规定的可以作为一般指针类型，以前还是用 char* 来作为一般标准的
也可以简单的使用0


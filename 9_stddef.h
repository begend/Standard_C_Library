stddef.h
C标准定义

重复的定义了在其他头文件中也已经定义过的宏，作为一个集中的存储库

ptrdiff_t	指针距离差，有符号整数类型
size_t		数量，sizeof的返回类型，无符号整数
wchar_t		最大扩展字符集的编码类型

NULL		空指针，等于0，宏中的声明 NULL 的方式很特别，有
#define NULL (char *) 0
#define NULL (int *) 0
#define NULL (long *) 0
不过最安全的定义是
#define NULL (void *) 0
void*是新规定的一般指针类型，以前一般用char*，也可以简单的使用0

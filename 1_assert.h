assert.h
断言

习惯于使用assert函数会使你变成编程高手

void assert(int expression);
expression为0时该函数会使程序中断
只要在头文件定义 NDEBUG 宏即可使assert不再作用

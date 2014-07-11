setjmp.h
跳转

这可不是 goto，这比goto高端多了
通过 jmp_buf 数据结构，longjmp和setjmp函数来实现在两个函数之间的跳转
而不必通过正常的return返回

int setjmp(jmp_buf env);

首先被调用，将当前进程堆栈中上下文环境保存在jmp_buf结构中

int longjmp(jmp_buf env, int val);

在之后某处被调用，参数中的buf是之前setjmp中保存的
到此处longjmp函数将ret返回给setjmp，而setjmp的返回值就是ret
以此可知这次返回到setjmp的函数是这个longjmp，因为longjmp中的ret和setjmp返回的值一样

但是到达longjmp函数之前的内存和寄存器中的数据并不会回滚，而是仍然保持现在的状态
C++(高级语言)中的 try 和 catch 关键字就是由这个方式实现的

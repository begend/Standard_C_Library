setjmp.h
跳转

这可不是goto，这是远程goto

通过数据结构jmp_buf，longjmp和setjmp函数实现在两个函数之间远程跳转
而不必通过正常的return返回

jmp_buf 要定义为全局变量或静态变量，使调用setjmp和longjmp的函数都能看到

int setjmp(jmp_buf env);
在longjmp之前调用，将当前进程堆栈中上下文环境保存在jmp_buf结构中
初次设置时setjmp返回0，之后再从longjmp跳转到setjmp处时返回longjmp中的参数val

int longjmp(jmp_buf env, int val);
在setjmp之后调用，跳转到之前setjmp设置的env处，并且令第二次调用的setjmp返回val值
若有多个longjmp，则可以通过setjmp返回值的不同来判断返回的是哪个longjmp

再次回到setjmp函数后，进程中内存和寄存器中的变量数据并不会回滚，仍保持已经改变的状态
比如
static jmp_buf jbuf;
void test_jump(int value)
{
	printf("test jump: %d\n", value);
	longjmp(jbuf, value);
}
int main()
{
	int ret;
	if((ret = setjmp(jbuf)) != 0)
		printf("jump return: %d\n", ret);
	else{
		printf("first time setjmp\n");
		test_jump(3);
	}
	return(0);
}
该例中第一次调用setjmp返回0，进程进入else分支
执行到test_jump中的longjmp时跳转到setjmp，这一次返回值为longjmp中的参数value

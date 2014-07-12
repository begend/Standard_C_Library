errno.h
库函数错误

一，errno变量
C标准库为每个用户进程维护一个全局变量errno，实际是一个int变量
当一个库函数出错时会把errno置为一个小于0的错误编码，正确则为0
如果顺序相邻的两个库函数都出错了，后一个的errno编码值会覆盖前一个
errno的错误编码有 
EDOM	表示定义域出错，即调用函数的传入参数不对
ERANGE	表示值域出错，即结果出错(可能太大或太小以至于溢出)

二，错误信息
void perror(const char *mes);
输出mes字符串和当前errno代表的错误类型
比如这样
errno = 0;
double y = sqrt(x);	//x是-1，无法开方
if(errno != 0)		//检查errno值，不为0则表示调用sqrt时出错
	perror("sqrt error");	
//perror实际会输出“sqrt error: domain error”
//后面增加的domain error是根据errno得到的出错信息

errno.h
错误

errno和perror，其中errno是一个int值
当调用某个库函数出错，errno的值会变为一个非0值，而未出错时是0值

errno出错时的值变为 EDOM 和 ERANGE 
EDOM	表示定义域出错，即调用函数的传入参数不对
ERANGE	表示值域出错，即结果出错(可能太大或太小以至于溢出)

void perror(const char *mes);
输出mes字符串和当前errno代表的错误类型

比如下面这样
errno = 0;
double y = sqrt(x);	//x是-1，无法开方
if(errno != 0)		//检查errno值，不为0则表示调用sqrt时出错
	perror("sqrt error");	
	//perror实际会输出“sqrt error: domain error”
	//后面增加的domain error是根据errno得到的出错信息



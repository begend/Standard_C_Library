signal.h
信号

信号是多进程编程和网络编程的基础

SIG_DFL			操作系统接收到信号时执行默认动作			
SIG_ERR			操作系统接收到信号时出错
SIG_IGN			操作系统接收到信号时忽略

SIGABRT			异常终止信号
SIGFPE			错误算数信号
SIGILL			无效函数映像信号
SIGINT			中断信号，键盘Ctrl+C或Delete可以发送该信号给终端
SIGSEGV			存储器无效访问信号
SIGTERM			终止信号
SIGQUIT			退出信号，键盘Ctrl+\可以发送该信号给终端

void (*signal(int sig, void (*func)(int)))(int);
该函数接受一个sig信号值，一个func处理信号函数，并返回之前该信号的处理函数指针
其中处理信号函数func是一个有一个int参数，无返回值的函数
SIG_DFL SIG_ERR SIG_IGN 三个参数可以直接用在参数func中
表示对于sig信号，不需要处理信号函数，而是用默认，出错或忽略三种系统动作来处理

int raise(int sig);
把信号sig发送给调用该函数的进程

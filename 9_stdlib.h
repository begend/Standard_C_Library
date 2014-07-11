stdlib.h
库补充

EXIT_FAILURE	失败状态 1
EXIT_SUCCESS	成功状态 0
RAND_MAX		随机数最大值

一，转化函数

double atof(const char *nptr);	将字符串转化为浮点数
int atoi(const char *nptr);		将字符串转化为整数
long atol(const char *nptr);	将字符串转化为长整型
int rand(void);					以一个内部变量为种子的伪随机数序列
								这个内部变量有一个初始默认值
								返回值在 0 ~ RAND_MAX 之间
void srand(unsigned int seed);	为内部变量设置一个新的种子，从而使序列不同
								之后再调用rand函数可以得到不同的序列

二，内存函数

void *malloc(size_t size);
为一个对象分配空间，空间不做任何处理，成功返回该空间指针，否则返回空指针

void *calloc(size_t nmemb, size_t size);
为nmemb个对象分配空间，每个对象大小为size，空间中所有位被初始化为0
成功返回空间指针，否则返回空指针

void *realloc(void *ptr, size_t size);
将ptr指向空间的大小改变为size指定的大小，原本空间中的数据保留

void free(void *ptr);
释放ptr指向的空间

三，环境通信函数

void abort(void);
使程序异常终止

int atexit(void (*func)(void));
将func函数注册为程序正常结束时被调用的函数，成功返回0，不成功返回非0值

void exit(int status);
首先调用所有atexit中注册过的函数，清空缓冲区中数据，关闭所有打开的流，删除临时文件
最后终止程序，并向操作系统返回一个状态值，0为正常终止，非0为不正常

char *getenv(const char *name);
在系统环境变量中搜索与name匹配的串，返回匹配到的串的指针

int system(const char *string);
向系统发出shell命令，命令可用返回一个非0值，否则返回0

四，排序搜索函数

void *besearch(const void *key, const void *base, size_t nmemb,
		size_t size, int (*compar)(const void *, const void *));
对已序序列从首元素base开始进行二分搜索，查找与key匹配的元素
元素数量为nmemb，元素大小为size，匹配方式为compar指向的函数
查找成功返回与key相等的元素指针，否则返回空指针

void qsort(void *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *));
对序列从首元素base开始进行快速排序，元素数量为nmemb，元素大小为size
compar指向比较大小函数 int (*compare)(const void *a, const void *b);
排序总是按照升序准则排序

在C++的sort函数中的比较函数 bool compare(const T &a, const T &b);中
return(a < b)希望按照从小到大排序
即 if(a < b) return(true); else return(false);
在qsort中也一样，return(a - b)希望按照从小到大排序
即 if(a < b) return(-1); else if(a == b) return(0); else return(1);
即a - b为负数表示a比较小，b比较大，而大的应该在序列的后面，因为是升序原则

int abs(int j);						返回j的绝对值

div_t div(int numer, int denom);	
返回分子numer除以分母denom所得的商和余数，div_t 包含两个量quot(商)，rem(余数)


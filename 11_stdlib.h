stdlib.h
库补充

大杂烩头文件

size_t			数量
wchar_t			最大扩展字符集字符类型
div_t			函数div的返回数据类型，该数据结构中包括商和余数，都是有符号整型
ldiv_t			函数ldiv的返回数据类型，该数据结构中包括商和余数，都是有符号长整型

NULL			空指针
EXIT_FAILURE	失败状态 1
EXIT_SUCCESS	成功状态 0
RAND_MAX		随机数最大值
MB_CUR_MAX		扩展字符集中最大多字节数目


一，字符转化函数
double atof(const char *nptr);	
将字符串nptr转化为浮点数
int atoi(const char *nptr);
将字符串nptr转化为整型
long int atol(const char *nptr);
将字符串nptr转化为长整型
double strtod(const char *nptr, char **endptr);
将字符串nptr转化为浮点数返回，其中endptr若不为空，则会存储三个字符串
第一部分是nptr序列中的初始部分，可能包含空白字符例如空格
第二部分是nptr序列中的浮点数部分
第三部分是nptr序列中无法被识别的字符
long int strtol(const char *nptr, char **endptr, int base);
将字符串nptr转化为base进制的长整型返回，其中endptr若不为空，则会存储三个字符串
第一部分是nptr序列中的初始化部分，可能包含空白字符例如空格
第二部分是nptr序列中的base进制的长整型
第三部分是nptr序列中无法被识别的字符
unsigned long int strtoul(const char *nptr, char **endptr, int base);
与strtol类似

二，伪随机函数
int rand(void);
以一个内部变量为种子的伪随机数产生函数，这个内部变量有一个初始默认值
产生在 0 ~ RAND_MAX 之间的一个整数
void srand(unsigned int seed);
为rand函数的内部变量设置一个新的种子，从而使序列不同
然后再调用rand函数可以得到不同的序列

三，内存管理函数
void *malloc(size_t size);
为一个对象分配空间，空间不做任何处理，成功返回该空间指针，否则返回空指针
void *calloc(size_t nmemb, size_t size);
为nmemb个对象分配空间，每个对象大小为size，空间中所有位被初始化为0
成功返回空间指针，否则返回空指针
void *realloc(void *ptr, size_t size);
将ptr指向空间的大小改变为size指定的大小，原本空间中的数据保留
void free(void *ptr);
释放ptr指向的空间

四，系统函数
void abort(void);
使程序异常终止
int atexit(void (*func)(void));
将func函数注册为程序正常结束时被调用的函数，成功返回0，不成功返回非0值
void exit(int status);
首先调用所有atexit中注册过的函数，清空缓冲区中数据，关闭所有打开的流，删除临时文件
最后终止程序，并向操作系统返回一个状态值，0为正常终止，非0为不正常
char *getenv(const char *name);
在系统环境变量中搜索与name匹配的串，返回匹配到的串的指针，若搜索不到则返回空指针
int system(const char *string);
向系统发出shell命令，命令可用返回一个非0值，否则返回0

四，查找和排序函数
void *besearch(const void *key, const void *base, size_t nmemb,
		size_t size, int (*compar)(const void *, const void *));
对已序序列从首元素base开始进行二分搜索，查找与key匹配的元素
元素数量为nmemb，元素大小为size，匹配方式为compar指向的函数
查找成功返回与key相等的元素指针，否则返回空指针
其中compar(const void *key, const void *a)返回 *key-*a 的结果
分别是小于0，等于0或者大于0，从而表示key小于a，key等于a或者key大于a

void qsort(void *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *));
对序列从首元素base开始进行快速排序，元素数量为nmemb，元素大小为size
compar指向比较大小函数，排序总是按照升序准则进行从小到大的排序
其中*compare(const void *a, const void *b)返回 *a - *b 的结果
分别是小于0，等于0或者大于0，从而表示a小于b，a等于b或者a大于b
在C++的sort中，比较函数
bool compare(const T &a, const T &b){return(a < b);}希望将序列从小到大排序
在qsort中也一样，比较函数
int compare(const void *a, const void *b){return(*a - *b);}希望按照从小到大排序

五，整数算数函数
int abs(int x);
返回x的绝对值
div_t div(int numer, int denom);	
返回分子numer除以分母denom所得的商和余数，div_t包含两个量quot(商)，rem(余数)
long int labs(long int x);
返回长整型x的绝对值
ldiv_t ldiv(long int numer, long int denom);
返回分子numer除以分母denom所得的商和余数，ldiv_t包含两个量quot(商)，rem(余数)

六，多字节字符函数
int mblen(const char *s, size_t n);
返回多字节字符串s的字符串长度
int mbtowc(wchar_t *pwc, const char *s, size_t n);
返回多字节字符串s的字符串长度，最多检测s中的n个多字节字符
并将多字节字符编码存储在pwc中
int wctomb(char *s, wchar_t wchar);
返回表示多字节字符串s需要的字节数，多字节字符对应wchar的编码
size_t mbstowcs(wchar_t *pwcs, const char *s, size_t n);
将字符串s转化为多字节字符编码存储在pwcs中，最多转化n个，返回转化的字符数，出错返回0
size_t wcstombs(char *s, const wchar_t *pwcs, size_t n);
将多字节字符串pwcs转化为初始字符串存储在s中，最多转化n个，相当于mbstowcs的逆运算

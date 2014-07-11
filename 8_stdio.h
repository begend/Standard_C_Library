stdio.h
IO

这是最流行的库(每种语言都是IO库最常用)，以下进行系统的介绍：

size_t			数量
fpos_t			文件定位符量

FILE *			文件指针，用于操作文件流
_IOFBF			完全缓冲方式
_IOLBF			行缓冲方式
_IONBF			无缓冲方式
BUFSIZ			setbuf函数使用的缓冲的大小
EOF				文件结束符，定义为-1，表示文件指针到达文件结尾
FOPEN_MAX		同时打开文件数目的大小
SEEK_CUR		文件定位符当前位置
SEEK_END		文件结尾位置
SEEK_SET		文件开头位置
TMP_MAX			创建临时文件的最大数俩
stderr			标准错误流
stdin			标准输入流
stdout			标准输出流
任何程序开始之后会自动打开这三个标准流，不需要用fopen这类函数进行显示的打开
可以直接向三个标准流输入输出，三个标准流的文件描述符file description是0，1，2

一，开关设置函数

int remove(const char *filename);	
删除文件，成功返回0，失败返回-1

int rename(const char *oldname, const char *newname);	
重命名文件，成功返回0，失败返回-1

FILE *tmpfile(void);
创建临时二进制文件，成功返回该文件指针，关闭该文件时自动删除，创建不成功返回空指针

char *tmpnam(char *s);
由现有的字符串s(一般是现有的文件名)生成一临时文件名
同一个s调用tmpnam不能超过 TMP_MAX 次

int fclose(FILE *stream);
关闭文件流，成功返回0，不成功返回 EOF

int fflush(FILE *stream);
刷新文件流，成功返回0，不成功返回 EOF

FILE *fopen(const char *filename, const char *mode);
打开文件，mode为打开方式，分为以下几种模式
"r" "w" "a" "rb" "wb" "ab" "r+" "w+" "a+" "rb+" "wb+" "ab+"
成功返回该文件指针，否则返回空指针

FILE *freopen(const char *filename, const char *mode, FILE *stream);
打开并重定向文件流，成功返回参数中的stream值，失败返回空指针

int setvbuf(FILE *stream, char *buf, int mode, size_t size);
该函数只在stream刚打开一个文件且未对其做任何操作之前使用，即打开文件后立刻使用该函数
通过参数mode设置该文件stream的缓冲方式，有以下几个模式
_IOFBF 完全缓冲
_IOLBF 行缓冲
_IONBF 无缓冲
通过参数buf给文件stream分配缓冲区，同时参数size表示这个数组的大小
若buf为空指针则自动分配缓冲区
该函数成功返回0，否则返回非0值

void setbuf(FILE *stream, char *buf);
与setvbuf函数功能基本相同
当buf不为空指针，该函数使用 _IOFBF 完全缓冲方式，缓冲区size大小为 BUFSIZ
当buf为空指针，该函数使用 _IONBF 无缓冲方式

int fileno(FILE *fp);
通过FILE指针获取该文件的文件描述符

二，文件输入输出

int fprintf(FILE *stream, const char *format, ...);
int printf(const char *format, ...);
int sprintf(char *s, const char *format, ...);
fprintf将format格式的字符串输出到文件流stream中
printf输出到 stdout
sprintf输出到字符数粗s中，成功返回输出的字符数目，否则返回负值
输出格式有下面几种：
"%10s" "%10f" 右对齐10个距离的字符串	"%-10s" "%-10f" 左对齐10个距离的字符串
"%+d" "%+f" 正数前面多输出一个+，负数会自己输出-
"%#d" "%#f" 对于c，s，d，u类无影响，对o类前面加一个 0 表示自己是八进制
			对于x类前面加 0x 表示自己是十六进制
			对于e，g，f类小数位上有不为0的数字时才输出小数点后部分
"%010d" "%010f" 对于10个距离对其的数字类使用'0'作为填充字符
"% 10d" "% 10f" 对于10个距离对其的数字类使用' '作为填充字符
"%d" 十进制
"%o" "%u" "%x" "%X" 都是非负数形式，分别是八进制，十进制
					十六进制大小写'a'-'z'和'A'-'Z'的区别
"%ld" "%lld" "%lo" "%llo" "%lu" "%llu" "%lx" "%llx"
一个l是 long，两个l是 long long，对应整数也可以加l和ll，比如 10l，1020ll
"%f" 输出double类型 "%lf" "%llf"输出 long double 和 long long double 类型
小数点精度按照"%.2f"这样输出，保留小数点后2位					
也可以按照"%.*f"这样输出，*星号是下一个int数字作为精度(就是变量)
对应double也可以加f，比如 10.0f
"%e" "%E" 科学计数法
"%g" "%G" 指定有效数字的表示
"%c" "%s" 字符和字符串
"%p" 指针，一般和"%#x"的表示是一样的，前面加 0x，并且是十六进制数字
"%n" 一个指向整型变量的指针，该变量记录到目前为止通过调用fprintf所写的字符总数
不转换参数，不管你看没看懂，反正我是不懂
"%%" 单纯的输出'%'字符

int fscanf(FILE *stream, const char *format, ...);
int scanf(const char *format, ...);
int sscanf(char *s, const char *format, ...);
和fprintf，printf，sprintf相对应，成功返回读取字符数量，否则返回 EOF

int vfprintf(FILE *stream, const char *format, va_list arg);
int vprintf(const char *format, va_list arg);
int vsprintf(char *s, const char *format, va_list arg);
va_list 类型的变量arg是printf类和scanf类可变参数长度函数的实际实现方式，少用

三，字符和字符串输入输出

int fgetc(FILE *stream);
int getc(FILE *stream);	//不安全
从stream读取一个字符，成功返回该字符，不成功或结束返回 EOF

char *fgets(char *s, int n, FILE *stream);
从stream读取数量少于n的字符串，读入到s中，读取最长n-1的字符串，最后还要'\0'
返回实际读取长度，成功返回字符串指针s，不成功返回空指针

int fputc(int c, FILE *stream);
int putc(int c, FILE *stream);
向stream写入c，成功返回写入的字符，否则返回 EOF

int fputs(const char *s, FILE *stream);
向stream写入字符串s，成功返回写入的字符数，否则返回 EOF

int getchar(void);
从终端读取一个字符，成功返回该字符，否则返回 EOF，等价于fgetc(stdin);

int gets(char *s);
等效于fgets(char *s, Inf, stdin);但是由于没有限制读入字符的数量，会被入侵

int puts(const char *s);
等效于fputs(const char *s, FILE *stream);可以使用

int ungetc(int c, FILE *stream);
把字符c退回到文件流stream中，下次重新读入c，成功返回退回字符，否则返回 EOF

以下两个用于二进制文件操作
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
从(二进制)文件流stream中读取最多nmemb个元素到ptr指向的数组，元素的大小由size指定
成功返回实际读取元素的数目，否则可能比nmemb小

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
从ptr指向数组读取最多nmemb个元素，写入(二进制)文件流stream中，元素大小由size指定
成功返回写入元素数目，否则可能比nmemb小

四，文件定位函数

int fgetpos(FILE *stream, fpos_t *pos);
将文件stream当前的文件定位符存储在pos指向的变量中，成功返回0，否则返回非0并置errno

int fsetpos(FILE *stream, fpos_t *pos);
将文件stream的当前文件定位符设置为pos所指变量，成功返回0，否则返回非0并置errno

int fseek(FILE *stream, long offset, int whence);
设置stream的文件定位符，设置为whence加offset
whence可选择 SEEK_SET(文件起始)，SEEK_CUR(当前文件定位符)，SEEK_END(文件结尾)
成功返回0，否则返回非0

long ftell(FILE *stream);
成功返回当前文件定位符，否则返回-1l并设置errno

void rewind(FILE *stream);
将文件定位符重设到起始处，等效于fseek(FILE *stream, 0l, SEEK_SET);

事实上fseek，ftell，rewind三个函数与fgetpos，fsetpos函数的作用可以相互替代
fseek，ftell，rewind函数是早期的库函数，文件定位符是 long 型，文件大小有限制
fgetpos，fsetpos更新，fpos_t 支持任意大小的文件定位符，但很多人习惯使用前面三种函数

void clearerr(FILE *stream);
清除stream一切文件结束符和错误指示符

int feof(FILE *stream);
测试文件定位符是否已到达结束位置，若已到达返回真值，否则返回0

int ferror(FILE *stream);
若stream出错返回会非0值，否则返回0


ctype.h
类型判定

一，字符判定函数

int isprint(int c);		终端可显示字符，即打印字符，包括' '
int isspace(int c);		终端不显示字符，即空白字符，也包括' '，还有'\n' '\t'等
int iscntrl(int c);		控制字符，有
报警符'\a' 退格符'\b' 回车符'\r' 换页符'\f' 水平制表符'\t' 换行符'\n' 垂直制表符'\v'
int isgraph(int c);		除过' '外的打印字符
int ispunct(int c);		标点，'.' '+'等
int isalnum(int c);		字母和数字
int isxdigit(int c);	十六位进制数字'A'-'Z' 'a'-'z' '0'-'9'
int isdigit(int c);		数字'0'-'9'
int isalpha(int c);		字母
int isupper(int c);		大写字母
int islower(int c);		小写字母
以上函数符合判断返回非0值，表示 true，否则返回0，表示 false

二，字符转化函数

int tolower(int c);		转化为小写字母
int toupper(int c);		转化为大写字母
函数返回相应的转化后的大小写字母，若原本就是该形式则返回原字符



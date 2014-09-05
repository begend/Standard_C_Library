math.h
数学

数学函数实现所需要的时间几乎占据了C标准库所有函数实现的一半
因为数值计算确实太难

特殊编码NaN和Inf
NaN		Not a Number，表示定义域错误，即传入函数的参数并非一个合法数字
Inf		无穷大，表示值域错误，即函数计算的结果超出值域

一，三角函数
double acos(double x);				计算余弦值为x的反余弦函数arccos
定义域[-1, 1]，值域[0, PI]
double asin(double x);				计算正弦值为x的反正弦函数arcsin
定义域[-1, 1]，值域[-PI/2, PI/2]
double atan(double x);				计算正切值为x的反正切函数arctan
值域[-PI/2, PI/2]
double atan2(double y, double x);	计算正切值为y/x的反正切函数arctan
y和x不能同时为0，值域[-PI/2, PI/2]
double cos(double x);				计算弧度为x的余弦函数cos
值域[-1, 1]
double sin(double x);				计算弧度为x的正弦函数sin
值域[-1, 1]
double tan(double x);				计算弧度为x的正切函数tan
double cosh(double x);				计算弧度为x的双曲余弦
double sinh(double x);				计算弧度为x的双曲正弦
double tanh(double x);				计算弧度为x的双曲正切

二，指数与对数函数
double exp(double x);
计算以自然对数e为底x为指数的指数值
double frexp(double value, int *exp);
将value化为x*(2^exp)，返回x，exp存储在exp参数中
double ldexp(double x, int exp);
计算x*(2^exp)，与frexp互为逆运算
double log(double x);
计算以自然对数e为底x的对数值
double log10(double x);
计算以10为底x的对数值
double modf(double value, double *iptr);
将value分为整数和小数两部分，返回小数部分，整数部分存放在iptr中
double pow(double x, double y);
计算x^y
double sqrt(double x);
计算x的非负平方根，即x的开方

三，取整，取余和绝对值函数
double ceil(double x);				计算不小于x的最小整数，即向上取整
double floor(double x);				计算不大于x的最大整数，即向下取整
double fabs(double x);				计算x的绝对值
double fmod(double x, double y);	计算x/y的浮点余数

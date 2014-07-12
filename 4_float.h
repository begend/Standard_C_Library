float.h
精度

只有那些最复杂的数值计算才会需要这个头文件

一个浮点数是由正负号，有效数字，小数位数，基数，指数，精度等组成的
这些量也有相关的极值范围

以下FLT代表float浮点数，DBL代表double高精度数

FLT_ROUNDS			浮点加法的舍入模式
-1	不能确定
0	向0舍入
1	最近舍入
2	向正无穷大舍入
3	向负无穷大舍入

FLT_RADIX			基数最小值2
FLT_MANT_DIG		有效位数
DBL_MANT_DIG		
LDBL_MANT_DIG

FLT_DIG				小数位数
DBL_DIG			
LDBL_DIG

FLT_MIN_EXP			最小负整数
DBL_MIN_EXP			
LDBL_MIN_EXP

FLT_MIN_10_EXP		以10为底的指数为最小负整数的值
DBL_MIN_10_EXP	
LDBL_MIN_10_EXP	

FLT_MAX_EXP			最大整数
DBL_MAX_EXP
LDBL_MAX_EXP

FLT_MAX_10_EXP		以10为底的指数为最大整数的值
DBL_MAX_10_EXP
LDBL_MAX_10_EXP

FLT_MAX				最大浮点数
DBL_MAX
LDBL_MAX

FLT_EPSILON			比1大的最小浮点数
DBL_EPSILON			
LDBL_EPSILON

FLT_MIN				最小正浮点数
DBL_MIN
LDBL_MIN

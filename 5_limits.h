limits.h
极值范围

C标准库规定的各个变量的极值范围
但在实际机器上范围可能更大，比如在我的机器上int与long范围都是2^32

signed char
-127 to 127					: SCHAR_MIN to SCHAR_MAX//128 = 2^7
(note, not -128 to 127; this accommodates 1's-complement platforms)

unsigned char
0 to 255					: 0 to UCHAR_MAX		//256 = 2^8

char
-127 to 127 or 0 to 255		: CHAR_MIN to CHAR_MAX
(depends on default char signedness)

(signed) short (int)
-32767 to 32767				: SHRT_MIN to SHRT_MAX	//32768 = 2^15

unsigned short (int)
0 to 65535					: 0 to USHRT_MAX		//65536 = 2^16

(signed) int
-32767 to 32767				: INT_MIN to INT_MAX

unsigned int
0 to 65535					: 0 to UINT_MAX

(signed) long (int)
-2147483647 to 2147483647	: LONG_MIN to LONG_MAX	//2147483648 = 2^31

unsigned long (int)
0 to 4294967295				: 0 to ULONG_MAX		//4294967295 = 2^32

(signed) long long (int)
-9223372036854775807 to 9223372036854775807
							: LLONG_MIN to LLONG_MAX//9223372036854775808 = 2^63		
unsigned long long (int)
0 to 18446744073709551615	: 0 to ULLONG_MAX		//18446744073709551616 = 2^64

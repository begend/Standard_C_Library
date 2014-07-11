//xctype.c
#ifndef CTYPE_MINE
#include "ctype_mine.h"
#endif
#include <limits.h>

#if EOF != -1 
#undef EOF
#define EOF -1
#endif
#if UCHAR_MAX != 255
#undef UCHAR_MAX
#define UCHAR_MAX 255
#endif

#define XDI (_DI | _XD)
#define XLO (_LO | _XD)
#define XUP (_UP | _XD)

static const short ctyp_tab[257] = {0, //EOF
	_BB, _BB, _BB, _BB, _BB, _BB, _BB, _BB,
	_BB, _CN, _CN, _CN, _CN, _CN, _BB, _BB,
	_BB, _BB, _BB, _BB, _BB, _BB, _BB, _BB,
	_BB, _BB, _BB, _BB, _BB, _BB, _BB, _BB,
	_SP, _PU, _PU, _PU, _PU, _PU, _PU, _PU,
	_PU, _PU, _PU, _PU, _PU, _PU, _PU, _PU,
	XDI, XDI, XDI, XDI, XDI, XDI, XDI, XDI, 
	XDI, XDI, _PU, _PU, _PU, _PU, _PU, _PU,
	_PU, XUP, XUP, XUP, XUP, XUP, XUP, _UP,
	_UP, _UP, _UP, _UP, _UP, _UP, _UP, _UP,
	_UP, _UP, _UP, _UP, _UP, _UP, _UP, _UP,
	_UP, _UP, _UP, _PU, _PU, _PU, _PU, _PU,
	_PU, XLO, XLO, XLO, XLO, XLO, XLO, _LO,
	_LO, _LO, _LO, _LO, _LO, _LO, _LO, _LO,
	_LO, _LO, _LO, _LO, _LO, _LO, _LO, _LO,
	_LO, _LO, _LO, _PU, _PU, _PU, _PU, _BB
};

const short *_Ctype = &ctyp_tab[1];

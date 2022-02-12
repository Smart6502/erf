#pragma once
#include <stdint.h>

typedef int16_t erf_tok_t;
typedef int32_t erf_st_t;
#ifdef __LP64__
typedef int64_t erf_int_t;
typedef double erf_flt_t;
#else
typedef int32_t erf_int_t;
typedef float erf_flt_t;
#endif
typedef uintptr_t erf_ptr_t;

typedef struct
{
	union
	{
		erf_int_t ni;
		erf_flt_t nf;
		erf_ptr_t np;
	} dat;
	int cet;
} erf_cell_t;

typedef struct
{
	erf_cell_t *cells;
	erf_int_t ptr;
	erf_int_t lim;
} erf_stk_t;

typedef struct
{
	erf_stk_t *stk;
} erf_env_t;

erf_stk_t *erf_create_stk (erf_int_t lim);
void erf_destroy_stk (erf_stk_t *stk);

erf_env_t *erf_create_environ (erf_int_t stk_lim);
void erf_destroy_environ (erf_env_t *env);

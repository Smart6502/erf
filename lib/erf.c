#include "erf.h"
#include <stdlib.h>

erf_stk_t *erf_create_stk (erf_int_t lim)
{
	erf_stk_t *stk = malloc ( sizeof(erf_stk_t));
	erf_stk_t sstk = {
		.cells = malloc ( sizeof(erf_cell_t) * lim),
		.ptr = 0,
		.lim = lim
	};
	*stk = sstk;
	return stk;
}

erf_st_t erf_push_stk (erf_stk_t *stk, erf_cell_t cell)
{
	if (stk->lim > stk->ptr + 1)
	{
		stk->cells[stk->ptr++] = cell;
		return 0;
	}
	return 1;
}

erf_cell_t erf_pop_stk (erf_stk_t *stk)
{
	if (stk->ptr > 0)
		return stk->cells[--stk->ptr];

	erf_cell_t cell = {
		.cet = 0
	};

	return cell;
}

void erf_destroy_stk (erf_stk_t *stk)
{
	free (stk->cells);
	free (stk);
}

erf_env_t *erf_create_environ (erf_int_t stk_lim)
{
	erf_env_t *env = malloc ( sizeof (erf_env_t));

	env->stk = erf_create_stk (stk_lim);

	return env;
}

void erf_destroy_environ (erf_env_t *env)
{
	erf_destroy_stk (env->stk);
	free (env);
}

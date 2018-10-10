#include <purescript.h>

PURS_FFI_FUNC_6(Data_Unfoldable_unfoldrArrayImpl, isNothing, fromJust, fst, snd, f, b, {
	purs_vec_t * result = (purs_vec_t *) purs_vec_new();
	while (1) {
		const purs_any_t * maybe = purs_any_app(f, b);
		if (purs_any_is_true(purs_any_app(isNothing, maybe))) {
			break;
		}
		const purs_any_t * tuple = purs_any_app(fromJust, maybe);
		purs_vec_push_mut(result, purs_any_app(fst, tuple));
		b = (purs_any_t *)purs_any_app(snd, tuple);
	}
	return purs_any_array_new(result);
});

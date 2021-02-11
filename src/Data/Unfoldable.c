#include <purescript.h>

PURS_FFI_FUNC_6(Data_Unfoldable_unfoldrArrayImpl, isNothing, fromJust, fst, snd, f, b) {
	purs_vec_t *result = (purs_vec_t *) purs_vec_new();
	int b_has_changed = 0;
	while (1) {
		purs_any_t maybe = purs_any_app(f, b);
		if (purs_any_is_true(purs_any_app(isNothing, maybe))) {
			PURS_ANY_RELEASE(maybe);
			break;
		}
		purs_any_t tuple = purs_any_app(fromJust, maybe);
		PURS_ANY_RELEASE(maybe);
		purs_vec_push_mut(result, purs_any_app(fst, tuple));
		if (b_has_changed) {
		    PURS_ANY_RELEASE(b);
		}
		b = purs_any_app(snd, tuple);
		b_has_changed = 1;
		PURS_ANY_RELEASE(tuple);
	}
	return purs_any_array(result);
}

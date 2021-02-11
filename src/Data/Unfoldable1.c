#include <purescript.h>

PURS_FFI_FUNC_6(Data_Unfoldable1_unfoldr1ArrayImpl, isNothing, fromJust, fst, snd, f, b) {
	purs_vec_t *result = (purs_vec_t *) purs_vec_new();
	int b_has_changed = 0;
	while (1) {
		purs_any_t tuple = purs_any_app(f, b);
		purs_vec_push_mut(result, purs_any_app(fst, tuple));

		purs_any_t maybe = purs_any_app(snd, tuple);
		PURS_ANY_RELEASE(tuple);

		if (purs_any_is_true(purs_any_app(isNothing, maybe))) {
			PURS_ANY_RELEASE(maybe);
			break;
		}
		if (b_has_changed) {
		    PURS_ANY_RELEASE(b);
		}
		b = purs_any_app(fromJust, maybe);
		b_has_changed = 1;
		PURS_ANY_RELEASE(maybe);
	}
	return purs_any_array(result);
}

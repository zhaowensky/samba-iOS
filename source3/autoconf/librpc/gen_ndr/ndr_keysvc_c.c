/* client functions auto-generated by pidl */

#include "includes.h"
#include <tevent.h>
#include "lib/util/tevent_ntstatus.h"
#include "autoconf/librpc/gen_ndr/ndr_keysvc.h"
#include "autoconf/librpc/gen_ndr/ndr_keysvc_c.h"

/* keysvc - client functions generated by pidl */

struct dcerpc_keysvc_Unknown0_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_keysvc_Unknown0_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_keysvc_Unknown0_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct keysvc_Unknown0 *r)
{
	struct tevent_req *req;
	struct dcerpc_keysvc_Unknown0_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_keysvc_Unknown0_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = NULL;

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_keysvc,
			NDR_KEYSVC_UNKNOWN0, state, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_keysvc_Unknown0_r_done, req);

	return req;
}

static void dcerpc_keysvc_Unknown0_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_keysvc_Unknown0_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_keysvc_Unknown0_r_state *state =
		tevent_req_data(req,
		struct dcerpc_keysvc_Unknown0_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_keysvc_Unknown0_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct keysvc_Unknown0 *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_keysvc,
			NDR_KEYSVC_UNKNOWN0, mem_ctx, r);

	return status;
}

struct dcerpc_keysvc_Unknown0_state {
	struct keysvc_Unknown0 orig;
	struct keysvc_Unknown0 tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_keysvc_Unknown0_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_keysvc_Unknown0_send(TALLOC_CTX *mem_ctx,
					       struct tevent_context *ev,
					       struct dcerpc_binding_handle *h)
{
	struct tevent_req *req;
	struct dcerpc_keysvc_Unknown0_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_keysvc_Unknown0_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_keysvc_Unknown0_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_keysvc_Unknown0_done, req);
	return req;
}

static void dcerpc_keysvc_Unknown0_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_keysvc_Unknown0_state *state = tevent_req_data(
		req, struct dcerpc_keysvc_Unknown0_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_keysvc_Unknown0_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_keysvc_Unknown0_recv(struct tevent_req *req,
				     TALLOC_CTX *mem_ctx,
				     WERROR *result)
{
	struct dcerpc_keysvc_Unknown0_state *state = tevent_req_data(
		req, struct dcerpc_keysvc_Unknown0_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_keysvc_Unknown0(struct dcerpc_binding_handle *h,
				TALLOC_CTX *mem_ctx,
				WERROR *result)
{
	struct keysvc_Unknown0 r;
	NTSTATUS status;

	/* In parameters */

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_keysvc_Unknown0_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}


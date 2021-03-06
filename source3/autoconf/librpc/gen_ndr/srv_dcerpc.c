/*
 * Unix SMB/CIFS implementation.
 * server auto-generated by pidl. DO NOT MODIFY!
 */

#include "includes.h"
#include "ntdomain.h"
#include "autoconf/librpc/gen_ndr/srv_dcerpc.h"


/* Tables */
static struct api_struct api_dcerpc_cmds[] = 
{
};

void dcerpc_get_pipe_fns(struct api_struct **fns, int *n_fns)
{
	*fns = api_dcerpc_cmds;
	*n_fns = sizeof(api_dcerpc_cmds) / sizeof(struct api_struct);
}

NTSTATUS rpc_dcerpc_init(const struct rpc_srv_callbacks *rpc_srv_cb)
{
	return rpc_srv_register(SMB_RPC_INTERFACE_VERSION, "dcerpc", "dcerpc", &ndr_table_dcerpc, api_dcerpc_cmds, sizeof(api_dcerpc_cmds) / sizeof(struct api_struct), rpc_srv_cb);
}

NTSTATUS rpc_dcerpc_shutdown(void)
{
	return rpc_srv_unregister(&ndr_table_dcerpc);
}

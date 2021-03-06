
/* Python wrapper functions auto-generated by pidl */
#include <Python.h>
#include "includes.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "autoconf/librpc/gen_ndr/ndr_policyagent.h"
#include "autoconf/librpc/gen_ndr/ndr_policyagent_c.h"

staticforward PyTypeObject policyagent_InterfaceType;

void initpolicyagent(void);static PyTypeObject *ClientConnection_Type;

const struct PyNdrRpcMethodDef py_ndr_policyagent_methods[] = {
	{ NULL }
};

static PyObject *interface_policyagent_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_policyagent);
}

#define PY_DOC_POLICYAGENT "IPSec Policy Agent"
static PyTypeObject policyagent_InterfaceType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "policyagent.policyagent",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "policyagent(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n"PY_DOC_POLICYAGENT,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_policyagent_new,
};

static PyMethodDef policyagent_methods[] = {
	{ NULL, NULL, 0, NULL }
};

void initpolicyagent(void)
{
	PyObject *m;
	PyObject *dep_samba_dcerpc_base;

	dep_samba_dcerpc_base = PyImport_ImportModule("samba.dcerpc.base");
	if (dep_samba_dcerpc_base == NULL)
		return;

	ClientConnection_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_base, "ClientConnection");
	if (ClientConnection_Type == NULL)
		return;

	policyagent_InterfaceType.tp_base = ClientConnection_Type;

	if (PyType_Ready(&policyagent_InterfaceType) < 0)
		return;
	if (!PyInterface_AddNdrRpcMethods(&policyagent_InterfaceType, py_ndr_policyagent_methods))
		return;

#ifdef PY_POLICYAGENT_PATCH
	PY_POLICYAGENT_PATCH(&policyagent_InterfaceType);
#endif

	m = Py_InitModule3("policyagent", policyagent_methods, "policyagent DCE/RPC");
	if (m == NULL)
		return;

	Py_INCREF((PyObject *)(void *)&policyagent_InterfaceType);
	PyModule_AddObject(m, "policyagent", (PyObject *)(void *)&policyagent_InterfaceType);
#ifdef PY_MOD_POLICYAGENT_PATCH
	PY_MOD_POLICYAGENT_PATCH(m);
#endif

}

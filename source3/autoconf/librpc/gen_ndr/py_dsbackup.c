
/* Python wrapper functions auto-generated by pidl */
#include <Python.h>
#include "includes.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "autoconf/librpc/gen_ndr/ndr_dsbackup.h"
#include "autoconf/librpc/gen_ndr/ndr_dsbackup_c.h"

staticforward PyTypeObject ad_backup_InterfaceType;

staticforward PyTypeObject ad_restore_InterfaceType;

void initdsbackup(void);static PyTypeObject *ClientConnection_Type;

const struct PyNdrRpcMethodDef py_ndr_ad_backup_methods[] = {
	{ NULL }
};

static PyObject *interface_ad_backup_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_ad_backup);
}

#define PY_DOC_AD_BACKUP "Backup support for Active Directory"
static PyTypeObject ad_backup_InterfaceType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "dsbackup.ad_backup",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "ad_backup(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n"PY_DOC_AD_BACKUP,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_ad_backup_new,
};


const struct PyNdrRpcMethodDef py_ndr_ad_restore_methods[] = {
	{ NULL }
};

static PyObject *interface_ad_restore_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return py_dcerpc_interface_init_helper(type, args, kwargs, &ndr_table_ad_restore);
}

#define PY_DOC_AD_RESTORE "Restoring Active Directory backups"
static PyTypeObject ad_restore_InterfaceType = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "dsbackup.ad_restore",
	.tp_basicsize = sizeof(dcerpc_InterfaceObject),
	.tp_doc = "ad_restore(binding, lp_ctx=None, credentials=None) -> connection\n"
"\n"
"binding should be a DCE/RPC binding string (for example: ncacn_ip_tcp:127.0.0.1)\n"
"lp_ctx should be a path to a smb.conf file or a param.LoadParm object\n"
"credentials should be a credentials.Credentials object.\n\n"PY_DOC_AD_RESTORE,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_new = interface_ad_restore_new,
};

static PyMethodDef dsbackup_methods[] = {
	{ NULL, NULL, 0, NULL }
};

void initdsbackup(void)
{
	PyObject *m;
	PyObject *dep_samba_dcerpc_base;

	dep_samba_dcerpc_base = PyImport_ImportModule("samba.dcerpc.base");
	if (dep_samba_dcerpc_base == NULL)
		return;

	ClientConnection_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_base, "ClientConnection");
	if (ClientConnection_Type == NULL)
		return;

	ad_backup_InterfaceType.tp_base = ClientConnection_Type;

	ad_restore_InterfaceType.tp_base = ClientConnection_Type;

	if (PyType_Ready(&ad_backup_InterfaceType) < 0)
		return;
	if (PyType_Ready(&ad_restore_InterfaceType) < 0)
		return;
	if (!PyInterface_AddNdrRpcMethods(&ad_backup_InterfaceType, py_ndr_ad_backup_methods))
		return;

	if (!PyInterface_AddNdrRpcMethods(&ad_restore_InterfaceType, py_ndr_ad_restore_methods))
		return;

#ifdef PY_AD_BACKUP_PATCH
	PY_AD_BACKUP_PATCH(&ad_backup_InterfaceType);
#endif
#ifdef PY_AD_RESTORE_PATCH
	PY_AD_RESTORE_PATCH(&ad_restore_InterfaceType);
#endif

	m = Py_InitModule3("dsbackup", dsbackup_methods, "dsbackup DCE/RPC");
	if (m == NULL)
		return;

	Py_INCREF((PyObject *)(void *)&ad_backup_InterfaceType);
	PyModule_AddObject(m, "ad_backup", (PyObject *)(void *)&ad_backup_InterfaceType);
	Py_INCREF((PyObject *)(void *)&ad_restore_InterfaceType);
	PyModule_AddObject(m, "ad_restore", (PyObject *)(void *)&ad_restore_InterfaceType);
#ifdef PY_MOD_DSBACKUP_PATCH
	PY_MOD_DSBACKUP_PATCH(m);
#endif

}

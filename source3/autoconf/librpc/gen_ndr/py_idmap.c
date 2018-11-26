
/* Python wrapper functions auto-generated by pidl */
#include <Python.h>
#include "includes.h"
#include <pytalloc.h>
#include "librpc/rpc/pyrpc.h"
#include "librpc/rpc/pyrpc_util.h"
#include "autoconf/librpc/gen_ndr/ndr_idmap.h"
#include "autoconf/librpc/gen_ndr/ndr_idmap_c.h"

#include "librpc/gen_ndr/security.h"
staticforward PyTypeObject unixid_Type;
staticforward PyTypeObject id_map_Type;

void initidmap(void);static PyTypeObject *Object_Type;
static PyTypeObject *dom_sid_Type;

static PyObject *py_unixid_get_id(PyObject *obj, void *closure)
{
	struct unixid *object = (struct unixid *)pytalloc_get_ptr(obj);
	PyObject *py_id;
	py_id = PyInt_FromLong(object->id);
	return py_id;
}

static int py_unixid_set_id(PyObject *py_obj, PyObject *value, void *closure)
{
	struct unixid *object = (struct unixid *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&PyInt_Type, value, return -1;);
	object->id = PyInt_AsLong(value);
	return 0;
}

static PyObject *py_unixid_get_type(PyObject *obj, void *closure)
{
	struct unixid *object = (struct unixid *)pytalloc_get_ptr(obj);
	PyObject *py_type;
	py_type = PyInt_FromLong(object->type);
	return py_type;
}

static int py_unixid_set_type(PyObject *py_obj, PyObject *value, void *closure)
{
	struct unixid *object = (struct unixid *)pytalloc_get_ptr(py_obj);
	if (PyLong_Check(value)) {
		object->type = PyLong_AsLongLong(value);
	} else if (PyInt_Check(value)) {
		object->type = PyInt_AsLong(value);
	} else {
		PyErr_Format(PyExc_TypeError, "Expected type %s or %s",\
		  PyInt_Type.tp_name, PyLong_Type.tp_name);
		return -1;
	}
	return 0;
}

static PyGetSetDef py_unixid_getsetters[] = {
	{ discard_const_p(char, "id"), py_unixid_get_id, py_unixid_set_id },
	{ discard_const_p(char, "type"), py_unixid_get_type, py_unixid_set_type },
	{ NULL }
};

static PyObject *py_unixid_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct unixid, type);
}

static PyObject *py_unixid_ndr_pack(PyObject *py_obj)
{
	struct unixid *object = (struct unixid *)pytalloc_get_ptr(py_obj);
	DATA_BLOB blob;
	enum ndr_err_code err;
	err = ndr_push_struct_blob(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_push_flags_fn_t)ndr_push_unixid);
	if (err != NDR_ERR_SUCCESS) {
		PyErr_SetNdrError(err);
		return NULL;
	}

	return PyString_FromStringAndSize((char *)blob.data, blob.length);
}

static PyObject *py_unixid_ndr_unpack(PyObject *py_obj, PyObject *args, PyObject *kwargs)
{
	struct unixid *object = (struct unixid *)pytalloc_get_ptr(py_obj);
	DATA_BLOB blob;
	int blob_length = 0;
	enum ndr_err_code err;
	const char * const kwnames[] = { "data_blob", "allow_remaining", NULL };
	PyObject *allow_remaining_obj = NULL;
	bool allow_remaining = false;

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s#|O:__ndr_unpack__",
		discard_const_p(char *, kwnames),
		&blob.data, &blob_length,
		&allow_remaining_obj)) {
		return NULL;
	}
	blob.length = blob_length;

	if (allow_remaining_obj && PyObject_IsTrue(allow_remaining_obj)) {
		allow_remaining = true;
	}

	if (allow_remaining) {
		err = ndr_pull_struct_blob(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_unixid);
	} else {
		err = ndr_pull_struct_blob_all(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_unixid);
	}
	if (err != NDR_ERR_SUCCESS) {
		PyErr_SetNdrError(err);
		return NULL;
	}

	Py_RETURN_NONE;
}

static PyObject *py_unixid_ndr_print(PyObject *py_obj)
{
	struct unixid *object = (struct unixid *)pytalloc_get_ptr(py_obj);
	PyObject *ret;
	char *retstr;

	retstr = ndr_print_struct_string(pytalloc_get_mem_ctx(py_obj), (ndr_print_fn_t)ndr_print_unixid, "unixid", object);
	ret = PyString_FromString(retstr);
	talloc_free(retstr);

	return ret;
}

static PyMethodDef py_unixid_methods[] = {
	{ "__ndr_pack__", (PyCFunction)py_unixid_ndr_pack, METH_NOARGS, "S.ndr_pack(object) -> blob\nNDR pack" },
	{ "__ndr_unpack__", (PyCFunction)py_unixid_ndr_unpack, METH_VARARGS|METH_KEYWORDS, "S.ndr_unpack(class, blob, allow_remaining=False) -> None\nNDR unpack" },
	{ "__ndr_print__", (PyCFunction)py_unixid_ndr_print, METH_VARARGS, "S.ndr_print(object) -> None\nNDR print" },
	{ NULL, NULL, 0, NULL }
};


static PyTypeObject unixid_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "idmap.unixid",
	.tp_getset = py_unixid_getsetters,
	.tp_methods = py_unixid_methods,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_unixid_new,
};


static PyObject *py_id_map_get_sid(PyObject *obj, void *closure)
{
	struct id_map *object = (struct id_map *)pytalloc_get_ptr(obj);
	PyObject *py_sid;
	if (object->sid == NULL) {
		py_sid = Py_None;
		Py_INCREF(py_sid);
	} else {
		py_sid = pytalloc_reference_ex(dom_sid_Type, object->sid, object->sid);
	}
	return py_sid;
}

static int py_id_map_set_sid(PyObject *py_obj, PyObject *value, void *closure)
{
	struct id_map *object = (struct id_map *)pytalloc_get_ptr(py_obj);
	talloc_unlink(pytalloc_get_mem_ctx(py_obj), object->sid);
	if (value == Py_None) {
		object->sid = NULL;
	} else {
		object->sid = NULL;
		PY_CHECK_TYPE(dom_sid_Type, value, return -1;);
		if (talloc_reference(pytalloc_get_mem_ctx(py_obj), pytalloc_get_mem_ctx(value)) == NULL) {
			PyErr_NoMemory();
			return -1;
		}
		object->sid = (struct dom_sid *)pytalloc_get_ptr(value);
	}
	return 0;
}

static PyObject *py_id_map_get_xid(PyObject *obj, void *closure)
{
	struct id_map *object = (struct id_map *)pytalloc_get_ptr(obj);
	PyObject *py_xid;
	py_xid = pytalloc_reference_ex(&unixid_Type, pytalloc_get_mem_ctx(obj), &object->xid);
	return py_xid;
}

static int py_id_map_set_xid(PyObject *py_obj, PyObject *value, void *closure)
{
	struct id_map *object = (struct id_map *)pytalloc_get_ptr(py_obj);
	PY_CHECK_TYPE(&unixid_Type, value, return -1;);
	if (talloc_reference(pytalloc_get_mem_ctx(py_obj), pytalloc_get_mem_ctx(value)) == NULL) {
		PyErr_NoMemory();
		return -1;
	}
	object->xid = *(struct unixid *)pytalloc_get_ptr(value);
	return 0;
}

static PyObject *py_id_map_get_status(PyObject *obj, void *closure)
{
	struct id_map *object = (struct id_map *)pytalloc_get_ptr(obj);
	PyObject *py_status;
	py_status = PyInt_FromLong(object->status);
	return py_status;
}

static int py_id_map_set_status(PyObject *py_obj, PyObject *value, void *closure)
{
	struct id_map *object = (struct id_map *)pytalloc_get_ptr(py_obj);
	if (PyLong_Check(value)) {
		object->status = PyLong_AsLongLong(value);
	} else if (PyInt_Check(value)) {
		object->status = PyInt_AsLong(value);
	} else {
		PyErr_Format(PyExc_TypeError, "Expected type %s or %s",\
		  PyInt_Type.tp_name, PyLong_Type.tp_name);
		return -1;
	}
	return 0;
}

static PyGetSetDef py_id_map_getsetters[] = {
	{ discard_const_p(char, "sid"), py_id_map_get_sid, py_id_map_set_sid },
	{ discard_const_p(char, "xid"), py_id_map_get_xid, py_id_map_set_xid },
	{ discard_const_p(char, "status"), py_id_map_get_status, py_id_map_set_status },
	{ NULL }
};

static PyObject *py_id_map_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	return pytalloc_new(struct id_map, type);
}

static PyObject *py_id_map_ndr_pack(PyObject *py_obj)
{
	struct id_map *object = (struct id_map *)pytalloc_get_ptr(py_obj);
	DATA_BLOB blob;
	enum ndr_err_code err;
	err = ndr_push_struct_blob(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_push_flags_fn_t)ndr_push_id_map);
	if (err != NDR_ERR_SUCCESS) {
		PyErr_SetNdrError(err);
		return NULL;
	}

	return PyString_FromStringAndSize((char *)blob.data, blob.length);
}

static PyObject *py_id_map_ndr_unpack(PyObject *py_obj, PyObject *args, PyObject *kwargs)
{
	struct id_map *object = (struct id_map *)pytalloc_get_ptr(py_obj);
	DATA_BLOB blob;
	int blob_length = 0;
	enum ndr_err_code err;
	const char * const kwnames[] = { "data_blob", "allow_remaining", NULL };
	PyObject *allow_remaining_obj = NULL;
	bool allow_remaining = false;

	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s#|O:__ndr_unpack__",
		discard_const_p(char *, kwnames),
		&blob.data, &blob_length,
		&allow_remaining_obj)) {
		return NULL;
	}
	blob.length = blob_length;

	if (allow_remaining_obj && PyObject_IsTrue(allow_remaining_obj)) {
		allow_remaining = true;
	}

	if (allow_remaining) {
		err = ndr_pull_struct_blob(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_id_map);
	} else {
		err = ndr_pull_struct_blob_all(&blob, pytalloc_get_mem_ctx(py_obj), object, (ndr_pull_flags_fn_t)ndr_pull_id_map);
	}
	if (err != NDR_ERR_SUCCESS) {
		PyErr_SetNdrError(err);
		return NULL;
	}

	Py_RETURN_NONE;
}

static PyObject *py_id_map_ndr_print(PyObject *py_obj)
{
	struct id_map *object = (struct id_map *)pytalloc_get_ptr(py_obj);
	PyObject *ret;
	char *retstr;

	retstr = ndr_print_struct_string(pytalloc_get_mem_ctx(py_obj), (ndr_print_fn_t)ndr_print_id_map, "id_map", object);
	ret = PyString_FromString(retstr);
	talloc_free(retstr);

	return ret;
}

static PyMethodDef py_id_map_methods[] = {
	{ "__ndr_pack__", (PyCFunction)py_id_map_ndr_pack, METH_NOARGS, "S.ndr_pack(object) -> blob\nNDR pack" },
	{ "__ndr_unpack__", (PyCFunction)py_id_map_ndr_unpack, METH_VARARGS|METH_KEYWORDS, "S.ndr_unpack(class, blob, allow_remaining=False) -> None\nNDR unpack" },
	{ "__ndr_print__", (PyCFunction)py_id_map_ndr_print, METH_VARARGS, "S.ndr_print(object) -> None\nNDR print" },
	{ NULL, NULL, 0, NULL }
};


static PyTypeObject id_map_Type = {
	PyObject_HEAD_INIT(NULL) 0,
	.tp_name = "idmap.id_map",
	.tp_getset = py_id_map_getsetters,
	.tp_methods = py_id_map_methods,
	.tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
	.tp_basicsize = sizeof(pytalloc_Object),
	.tp_new = py_id_map_new,
};

static PyMethodDef idmap_methods[] = {
	{ NULL, NULL, 0, NULL }
};

void initidmap(void)
{
	PyObject *m;
	PyObject *dep_talloc;
	PyObject *dep_samba_dcerpc_security;

	dep_talloc = PyImport_ImportModule("talloc");
	if (dep_talloc == NULL)
		return;

	dep_samba_dcerpc_security = PyImport_ImportModule("samba.dcerpc.security");
	if (dep_samba_dcerpc_security == NULL)
		return;

	Object_Type = (PyTypeObject *)PyObject_GetAttrString(dep_talloc, "Object");
	if (Object_Type == NULL)
		return;

	dom_sid_Type = (PyTypeObject *)PyObject_GetAttrString(dep_samba_dcerpc_security, "dom_sid");
	if (dom_sid_Type == NULL)
		return;

	unixid_Type.tp_base = Object_Type;

	id_map_Type.tp_base = Object_Type;

	if (PyType_Ready(&unixid_Type) < 0)
		return;
	if (PyType_Ready(&id_map_Type) < 0)
		return;
#ifdef PY_UNIXID_PATCH
	PY_UNIXID_PATCH(&unixid_Type);
#endif
#ifdef PY_ID_MAP_PATCH
	PY_ID_MAP_PATCH(&id_map_Type);
#endif

	m = Py_InitModule3("idmap", idmap_methods, "idmap DCE/RPC");
	if (m == NULL)
		return;

	PyModule_AddObject(m, "ID_UNKNOWN", PyInt_FromLong(ID_UNKNOWN));
	PyModule_AddObject(m, "ID_TYPE_BOTH", PyInt_FromLong(ID_TYPE_BOTH));
	PyModule_AddObject(m, "ID_EXPIRED", PyInt_FromLong(ID_EXPIRED));
	PyModule_AddObject(m, "ID_TYPE_NOT_SPECIFIED", PyInt_FromLong(ID_TYPE_NOT_SPECIFIED));
	PyModule_AddObject(m, "ID_TYPE_UID", PyInt_FromLong(ID_TYPE_UID));
	PyModule_AddObject(m, "ID_MAPPED", PyInt_FromLong(ID_MAPPED));
	PyModule_AddObject(m, "ID_TYPE_GID", PyInt_FromLong(ID_TYPE_GID));
	PyModule_AddObject(m, "ID_UNMAPPED", PyInt_FromLong(ID_UNMAPPED));
	Py_INCREF((PyObject *)(void *)&unixid_Type);
	PyModule_AddObject(m, "unixid", (PyObject *)(void *)&unixid_Type);
	Py_INCREF((PyObject *)(void *)&id_map_Type);
	PyModule_AddObject(m, "id_map", (PyObject *)(void *)&id_map_Type);
#ifdef PY_MOD_IDMAP_PATCH
	PY_MOD_IDMAP_PATCH(m);
#endif

}
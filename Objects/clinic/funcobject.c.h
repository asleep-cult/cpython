/*[clinic input]
preserve
[clinic start generated code]*/

PyDoc_STRVAR(func_new__doc__,
"function(code, globals, name=None, argdefs=None, closure=None)\n"
"--\n"
"\n"
"Create a function object.\n"
"\n"
"  code\n"
"    a code object\n"
"  globals\n"
"    the globals dictionary\n"
"  name\n"
"    a string that overrides the name from the code object\n"
"  argdefs\n"
"    a tuple that specifies the default argument values\n"
"  closure\n"
"    a tuple that supplies the bindings for free variables");

static PyObject *
func_new_impl(PyTypeObject *type, PyCodeObject *code, PyObject *globals,
              PyObject *name, PyObject *defaults, PyObject *closure);

static PyObject *
func_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
    PyObject *return_value = NULL;
    static const char * const _keywords[] = {"code", "globals", "name", "argdefs", "closure", NULL};
    static _PyArg_Parser _parser = {NULL, _keywords, "function", 0};
    PyObject *argsbuf[5];
    PyObject * const *fastargs;
    Py_ssize_t nargs = PyTuple_GET_SIZE(args);
    Py_ssize_t noptargs = nargs + (kwargs ? PyDict_GET_SIZE(kwargs) : 0) - 2;
    PyCodeObject *code;
    PyObject *globals;
    PyObject *name = Py_None;
    PyObject *defaults = Py_None;
    PyObject *closure = Py_None;

    fastargs = _PyArg_UnpackKeywords(_PyTuple_CAST(args)->ob_item, nargs, kwargs, NULL, &_parser, 2, 5, 0, argsbuf);
    if (!fastargs) {
        goto exit;
    }
    if (!PyObject_TypeCheck(fastargs[0], &PyCode_Type)) {
        _PyArg_BadArgument("function", "argument 'code'", (&PyCode_Type)->tp_name, fastargs[0]);
        goto exit;
    }
    code = (PyCodeObject *)fastargs[0];
    if (!PyDict_Check(fastargs[1])) {
        _PyArg_BadArgument("function", "argument 'globals'", "dict", fastargs[1]);
        goto exit;
    }
    globals = fastargs[1];
    if (!noptargs) {
        goto skip_optional_pos;
    }
    if (fastargs[2]) {
        name = fastargs[2];
        if (!--noptargs) {
            goto skip_optional_pos;
        }
    }
    if (fastargs[3]) {
        defaults = fastargs[3];
        if (!--noptargs) {
            goto skip_optional_pos;
        }
    }
    closure = fastargs[4];
skip_optional_pos:
    return_value = func_new_impl(type, code, globals, name, defaults, closure);

exit:
    return return_value;
}

PyDoc_STRVAR(proto_new__doc__,
"prototype(name, qualname=None, module=None, argdefs=None)\n"
"--\n"
"\n"
"Create a function prototype object.\n"
"\n"
"  name\n"
"    a string that specifies the name\n"
"  qualname\n"
"    a string that specifies the qualname, defaults to name\n"
"  module\n"
"    the module\n"
"  argdefs\n"
"    a tuple that specifies the default arguments");

static PyObject *
proto_new_impl(PyTypeObject *type, PyObject *name, PyObject *qualname,
               PyObject *module, PyObject *defaults);

static PyObject *
proto_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
    PyObject *return_value = NULL;
    static const char * const _keywords[] = {"name", "qualname", "module", "argdefs", NULL};
    static _PyArg_Parser _parser = {NULL, _keywords, "prototype", 0};
    PyObject *argsbuf[4];
    PyObject * const *fastargs;
    Py_ssize_t nargs = PyTuple_GET_SIZE(args);
    Py_ssize_t noptargs = nargs + (kwargs ? PyDict_GET_SIZE(kwargs) : 0) - 1;
    PyObject *name;
    PyObject *qualname = Py_None;
    PyObject *module = Py_None;
    PyObject *defaults = Py_None;

    fastargs = _PyArg_UnpackKeywords(_PyTuple_CAST(args)->ob_item, nargs, kwargs, NULL, &_parser, 1, 4, 0, argsbuf);
    if (!fastargs) {
        goto exit;
    }
    name = fastargs[0];
    if (!noptargs) {
        goto skip_optional_pos;
    }
    if (fastargs[1]) {
        qualname = fastargs[1];
        if (!--noptargs) {
            goto skip_optional_pos;
        }
    }
    if (fastargs[2]) {
        module = fastargs[2];
        if (!--noptargs) {
            goto skip_optional_pos;
        }
    }
    defaults = fastargs[3];
skip_optional_pos:
    return_value = proto_new_impl(type, name, qualname, module, defaults);

exit:
    return return_value;
}
/*[clinic end generated code: output=143287fa13c6101b input=a9049054013a1b77]*/

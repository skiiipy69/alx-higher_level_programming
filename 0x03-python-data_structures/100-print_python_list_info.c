#include <stdio.h>
#include <Python.h>

/**
 * print_python_list_info - prints python list info
 *
 * @po: PyObject
 *
 * Return: no return
 */
void print_python_list_info(PyObject *po)
{
	long int size, i;
	PyListObject *list;
	PyObject *item;

	size = Py_SIZE(po);
	printf("[*] Size of the Python List = %ld\n", size);

	list = (PyListObject *)po;
	printf("[*] Allocated = %ld\n", list->allocated);

	for (i = 0; i < size; i++)
	{
		item = PyList_GetItem(po, i);
		printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
	}
}

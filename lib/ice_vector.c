#include <stdio.h>
#include <stdlib.h>
#include "ice_vector.h"
#include "mem_ops.h"

void ice_vector_init(ice_vector *v)
{
	v->limit = ice_vector_LIMIT;
	v->max = 0;
	v->elements = ice_xmallocarray(v->limit, sizeof(void *));
}

int ice_vector_max(ice_vector *v)
{
	return v->max;
}

void ice_vector_resize(ice_vector *v, int limit)
{

 void **elements = ice_xreallocarray(v->elements, limit, sizeof(void *) ); //using OpenBSD function reallocarray() at mem_ops.c

    	if (elements) 
	{
        	v->elements = elements;
        	v->limit = limit;
    	}
}

void ice_vector_write(ice_vector *v, int index, void *element)
{
	if (index >= 0 && index < v->max)
		v->elements[index] = element;
}

void ice_vector_add(ice_vector *v, void *element)
{
	if (v->limit == v->max)
        	ice_vector_resize(v, v->limit * 2);

    	v->elements[v->max++] = element;
}


void *ice_vector_view(ice_vector *v, int index)
{
	if (index >= 0 && index < v->max)
        	return v->elements[index];

	return NULL;
}

void ice_vector_free(ice_vector *v)
{
	ICE_XFREE(v->elements);
}

void ice_vector_remove(ice_vector *v, int index)
{
	int i=0;

	if (index < 0 || index >= v->max)
        	return;

    	v->elements[index] = NULL;


	i = index;
    	while (i < v->max - 1) 
	{
        	v->elements[i] = v->elements[i + 1];
        	v->elements[i + 1] = NULL;
		i++;
    	}

    	v->max--;

    	if (v->max > 0 && v->max == v->limit / 4)
        	ice_vector_resize(v, v->limit / 2);
}



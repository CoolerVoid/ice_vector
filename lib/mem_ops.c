#include "mem_ops.h"

// based in OpenBSD reallocarray() function http://man.openbsd.org/reallocarray.3
void *ice_xmallocarray (size_t nmemb, size_t size) 
{
	if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) && nmemb > 0 && SIZE_MAX / nmemb < size) 
	{
		ICE_DEBUG("integer overflow block");
		return NULL;
	}

	void *ptr = malloc (nmemb*size);

	if (ptr == NULL) 
		return NULL;

	return ptr;
}

// based in OpenBSD reallocarray() function http://man.openbsd.org/reallocarray.3
void *ice_xreallocarray (void *ptr, size_t nmemb, size_t size) 
{
	if ((nmemb >= MUL_NO_OVERFLOW || size >= MUL_NO_OVERFLOW) && nmemb > 0 && SIZE_MAX / nmemb < size) 
	{
		ICE_DEBUG("integer overflow block");
		return NULL;
	}

	void *p = realloc (ptr, nmemb*size);

	if (p == NULL) 
		return NULL;

	return p;
}


static void *ice_xmalloc_fatal(size_t size) 
{
	if ( size == 0 ) 
		return NULL;

	ICE_DEBUG("\n Memory FAILURE...\n");

	exit(1);
}

void ice_xfree(void **ptr) 
{
	assert(ptr);
	if( ptr != NULL )
        {
		free(*ptr);
		*ptr=NULL;	
        }
	
}






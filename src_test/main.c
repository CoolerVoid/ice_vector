#include <stdio.h>
#include <stdlib.h>

#include "../lib/ice_vector.h"

int main(void)
{
    int i=0;

    ice_vector v;
    ice_vector_init(&v);

    ice_vector_add(&v, "Pacman");
    ice_vector_add(&v, "ghost");
    ice_vector_add(&v, "ball");
    ice_vector_add(&v, "triangle");
    ice_vector_add(&v, "square");

    while (i < ice_vector_max(&v))
    {
        printf("%s \n", (char *) ice_vector_give(&v, i));
	i++;
    }

    ice_vector_remove(&v, 4);
    ice_vector_remove(&v, 3);
    ice_vector_remove(&v, 2);
    ice_vector_remove(&v, 1);

    ice_vector_write(&v, 0, "Sonic");
    ice_vector_add(&v, "Mario");

    
    printf("%s \n", (char *) ice_vector_give(&v, 0));
    printf("%s \n", (char *) ice_vector_give(&v, 1));
    
    ice_vector_free(&v);

    return 0;
}

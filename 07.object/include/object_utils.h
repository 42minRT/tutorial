#ifndef OBJECT_UTILS_H
# define OBJECT_UTILS_H

# include <stdlib.h>
# include "structures.h"

void		object_append(t_object **list, t_object *new);
t_object	*object_last(t_object *list);

#endif
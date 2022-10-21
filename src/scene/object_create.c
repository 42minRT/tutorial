#include "../../include/structures.h"
#include "../../include/utils.h"

t_object	*new_object(t_object_type type, void *element)
{
	t_object *new_obj;

	new_obj = (t_object *)malloc(sizeof(t_object));
	if (new_obj == NULL)
		return (NULL);
	new_obj->type = type;
	new_obj->element = element;
	new_obj->next = NULL;
	return (new_obj);
}

t_sphere	*new_sphere(t_point3 center, double radius)
{
	t_sphere *new_sp;
	
	new_sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (new_sp == NULL)
		return (NULL);
	new_sp->center = center;
	new_sp->radius = radius;
	new_sp->radius2 = radius * radius;
	return (new_sp);
}

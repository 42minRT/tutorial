#include "../../include/structures.h"
#include "../../include/vector_utils.h"

t_bool	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vminus(sp->center, ray->origin);
	a = vdot(ray->dir, ray->dir);
	b = 2.0 * vdot(oc, ray->dir);
	c = vdot(oc, oc) - sp->radius2;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}
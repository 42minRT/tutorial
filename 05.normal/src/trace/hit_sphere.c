#include "../../include/structures.h"
#include "../../include/vector_utils.h"

double	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3	co;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	co = vminus(ray->origin, sp->center);
	a = vdot(ray->dir, ray->dir);
	b = 2.0 * vdot(co, ray->dir);
	c = vdot(co, co) - sp->radius2;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-b - sqrt(discriminant)) / (2.0 * a));
}
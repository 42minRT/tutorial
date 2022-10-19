#include "../../include/structures.h"
#include "../../include/vector_utils.h"
#include "../../include/trace.h"

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	t_vec3	co;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;

	co = vminus(ray->origin, sp->center);
	a = vdot(ray->dir, ray->dir);
	half_b = vdot(co, ray->dir);
	c = vdot(co, co) - sp->radius2;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (FALSE);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || root > rec->tmax)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vunit(vminus(rec->p, sp->center));
	set_face_normal(ray, rec);
	return (TRUE);
}
#include "../../../include/utils.h"
#include "../../../include/structures.h"
#include "../../../include//trace.h"

bool	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3  co; //방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double  a;
	double  half_b;
	double  c;
	double  discriminant; //판별식
	double	sqrtd;
	double	root;
	t_sphere	*sp;

	sp = (t_sphere *)world->element;
	co = vminus(ray->orig, sp->center);
	a = vdot(ray->dir, ray->dir);
	half_b = vdot(co, ray->dir);
	c = vlength2(co) - sp->radius2; 
	// discriminant 는 판별식
	discriminant = (half_b * half_b) - (a * c);
	// 판별식이 0보다 크다면 광선이 구를 hit한 것!
	if (discriminant < 0)
		return (false);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (false);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	return (true);
}

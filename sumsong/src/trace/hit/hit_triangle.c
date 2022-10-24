#include "../../../include/structures.h"
#include "../../../include/utils.h"
#include "../../../include/trace.h"

t_bool	hit_triangle(t_object *tr_obj, t_ray *ray, t_hit_record *rec)
{
	t_triangle	*tr;
	t_vec3		normal;
	double		a;
	double		b;
	double		t;

	tr = tr_obj->element;
	normal = vunit(vcross(vminus(tr->dot1, tr->dot2), vminus(tr->dot3, tr->dot2)));
	a = vdot(normal, tr->dot1) - vdot(normal, ray->orig);
	b = vdot(normal, ray->dir);
	if (b < 0.0)
		return (FALSE);
	t = a / b;
	if (t < rec->tmin || rec->tmax < t)
		return (FALSE);
	rec->p = ray_at(ray, t);
	if (vdot(vcross(vminus(tr->dot2, tr->dot1), vminus(tr->dot1, rec->p)), normal) < 0
		|| vdot(vcross(vminus(tr->dot3, tr->dot2), vminus(tr->dot2, rec->p)), normal) < 0
		|| vdot(vcross(vminus(tr->dot1, tr->dot3), vminus(tr->dot3, rec->p)), normal) < 0)
		return (FALSE);
	rec->t = t;
	rec->normal = normal;
	// set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장
	rec->albedo = tr_obj->albedo;
	return (TRUE);
}

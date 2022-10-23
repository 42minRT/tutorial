#include "../../../include/structures.h"
#include "../../../include/vector_utils.h"
#include "../../../include/trace.h"

t_bool	hit_trangle(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_trangle	*trangle;
	t_vec3		face_normal;
	t_vec3		temp_vec1;
	t_vec3		temp_vec2;
	t_vec3		normal1;
	t_vec3		normal2;
	t_vec3		normal3;
	t_vec3		point;
	double		t;

	trangle = world->element;
	temp_vec1 = vminus(trangle->vertex1, trangle->vertex2);
	temp_vec2 = vminus(trangle->vertex3, trangle->vertex2);
	face_normal = vcross(temp_vec1, temp_vec2);
	// backface culling
	if (vdot(ray->dir, face_normal) < 0.0f)
		return (FALSE);
	// 평면과 광선이 수평에 매우 가까울 때
	if (fabs(vdot(ray->dir, face_normal)) < 1e-2f)
		return (FALSE);
	// 광선과 평면의 충돌 위치
	t = vdot((t_vec3)trangle->vertex1, face_normal) - vdot((t_vec3)ray->origin, face_normal);
	if (t < 0.0f)
		return (FALSE);
	// 삼각형 밖에 있을 때
	point = ray_at(ray, t);
	normal1 = vunit(vcross(vminus(trangle->vertex2, trangle->vertex3), vminus(point, trangle->vertex3)));
	normal2 = vunit(vcross(vminus(trangle->vertex3, trangle->vertex1), vminus(point, trangle->vertex1)));
	normal3 = vunit(vcross(vminus(point, trangle->vertex1), vminus(trangle->vertex2, trangle->vertex1)));
	if (vdot(normal1, face_normal) < 0.0f)
		return (FALSE);
	if (vdot(normal2, face_normal) < 0.0f)
		return (FALSE);
	if (vdot(normal3, face_normal) < 0.0f)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(ray, t);
	rec->normal = vunit(face_normal);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}
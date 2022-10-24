#include "../../../include/structures.h"
#include "../../../include/utils.h"
#include "../../../include/trace.h"

t_bool	hit_sphere(t_object *sp_obj, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec3		oc; // 방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double		a;
	double		half_b;
	double		c;
	double		discriminant; // 판별식
	double		sqrtd; // 판별식에 루트 씌운 식
	double		root; // 근

	sp = sp_obj->element;
	// oc = O - C = 광원 - 구의 중심 벡터 = sp.center->광원 방향 벡터
	oc = vminus(ray->orig, sp->center);

	/* 근의 공식
	// a = 광원 단위벡터 ⋅ 광원 단위벡터 내적
	a = vdot(ray->dir, ray->dir);
	// b = 2D ⋅ (O - C) = 2D ⋅ oc
	b = 2.0 * vdot(oc, ray->dir);
	// c = (O - C) ⋅ (O - C) - r^2 = oc ⋅ oc - r^2
	c = vdot(oc, oc) - sp->radius2;
	// discriminant 는 판별식
	discriminant = b * b - 4 * a * c;

	// 판별식이 0보다 크다면 광선이 구를 hit한 것! 0보다 작다면 광선이 구에 닿지 않음!
	if (discriminant < 0) // 판별식이 0보다 작을 때 : 실근 없을 때
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a)); // 두 근 중 작은 근 = 광원에 가까운 근
	*/

	// 짝수 근의 공식으로 수정
	a = vlength2(ray->dir);	// D⋅D = |D|^2
	half_b = vdot(oc, ray->dir); // D⋅(O-C) = D⋅oc
	c = vlength2(oc) - sp->radius2; // (O-C)⋅(O-C)-r^2 = |oc|^2 - r^2
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0) // 구에 닿지 않음
		return (FALSE);
	sqrtd = sqrt(discriminant);
	// 두 실근(t) 중 tmin과 tmax 사이에 있는 근이 있는지 체크, 작은 근부터 체크
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root) // 작은 근 범위 체크
	{
		root = (-half_b + sqrtd) / a; // 큰 근 범위 체크
		if (root < rec->tmin || rec->tmax < root) // 큰 근도 범위 밖이면 시야에 보이지 않음
			return (FALSE);
	}
	rec->t = root; // 범위에 있는 근 기록
	rec->p = ray_at(ray, root); // 교점
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius); // 정규화 법선
	set_face_normal(ray, rec); // rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 t_bool 값으로 저장
	rec->albedo = sp_obj->albedo;
	return (TRUE);
}
#include "../../../include/structures.h"
#include "../../../include/utils.h"

double	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3	oc; // 방향벡터로 나타낸 구의 중심.
	//a, b, c는 각각 t에 관한 2차 방정식의 계수
	double	a;
	double	b;
	double	c;
	double	discriminant; //판별식

	// oc = O - C = 광원 - 구의 중심 벡터 = sp.center->광원 방향 벡터
	oc = vminus(ray->orig, sp->center);
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
}
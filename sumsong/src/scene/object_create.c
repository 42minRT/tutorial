#include "../../include/structures.h"

// 구 생성자 함수
t_sphere	sphere(t_point3 center, double radius)
{
	t_sphere sp;

	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return (sp);
}
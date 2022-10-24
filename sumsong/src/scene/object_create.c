#include "../../include/structures.h"
#include "../../include/scene.h"

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	if (!(new = (t_object *)malloc(sizeof(t_object))))
		return (NULL);
	new->type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	return (new);
}

// 광원 생성자 함수
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light *light;

	if(!(light = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}

// 구 생성자 함수
t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere *sp;

	if(!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}

// 삼각형 생성자 함수
t_triangle	*triangle(t_point3 dot1, t_point3 dot2, t_point3 dot3)
{
	t_triangle	*tri;

	if ((tri = malloc(sizeof(t_triangle))) == NULL)
		return (NULL);
	tri->dot1 = dot1;
	tri->dot2 = dot2;
	tri->dot3 = dot3;
	return (tri);
}
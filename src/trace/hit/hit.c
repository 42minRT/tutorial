#include "../../../include/trace.h"

bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해.
	hit_anything = false;
	while(world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = true;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

// hit_obj는 오브젝트 타입에 맞는 hit함수로 연결해주는 관문
bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	bool	hit_result;

	hit_result = false;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec); 
	return (hit_result);
}

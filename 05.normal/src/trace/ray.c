#include "../../include/trace.h"

t_ray	ray(t_point3 origin, t_vec3 dir)
{
	t_ray ray;

	ray.origin = origin;
	ray.dir = vunit(dir);
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3 at;

	at = vplus(ray->origin, vmult(ray->dir, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;
	t_vec3	temp;

	ray.origin = cam->origin;
	temp = vminus(vplus(vplus(cam->left_bottom,\
					 	vmult(cam->horizontal, u)),\
						vmult(cam->vertical, v)),\
					 	cam->origin);
	ray.dir = vunit(temp);
	return (ray);
}

t_color3	ray_color(t_ray *ray, t_sphere *sphere)
{
	double		t;
	t_color3	white;
	t_color3	sky_blue;
	t_color3	red;
	t_vec3		normal_vector;

	t = hit_sphere(sphere, ray);
	white = color3(1.0, 1.0, 1.0);
	sky_blue = color3(0.5, 0.7, 1.0);
	red = color3(1.0, 0, 0);
	if (t > 0.0)
	{
		normal_vector = vunit(vminus(ray_at(ray, t), sphere->center));
		t_color3 temp_color = color3(normal_vector.x + 1, normal_vector.y + 1, normal_vector.z + 1);
		return (vmult(temp_color, 0.5));
	}
	t = 0.5 * (ray->dir.y + 1.0); 
	return (vplus(vmult(white, 1.0 - t), vmult(sky_blue, t)));
}
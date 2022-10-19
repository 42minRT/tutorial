#include "../../include/print.h"

// ray 생성자
t_ray   ray(t_point3 origin, t_vec3 dir)
{
    t_ray ray;

    ray.origin = origin;
    ray.dir = vunit(dir);
    return (ray);
}

//ray origin point 부터 방향 ray dir * t 만틈 떨어진 곳.
t_point3    ray_at(t_ray *ray, double t)
{
    t_point3 at;
    at = vplus(ray->origin, vmult(ray->dir, t));
    return (at);
}

// primary_ray 생성자
t_ray   ray_primary(t_camera *cam, double u, double v)
{
    t_ray ray;

    ray.origin = cam->origin;
    ray.dir = vunit(
                vminus(
                    vplus(vplus(cam->left_bottom, vmult(cam->horizontal, u)),vmult(cam->vertical, v))
                    , cam->origin));
    return (ray);
}

t_color3    ray_color(t_ray *r)
{
    double t;

    t = 0.5 * (r->dir.y + 1.0);
    return (vplus(vmult(color3(1, 1, 1), 1.0 - t), vmult(color3(0.5, 0.7, 1.0), t)));
}
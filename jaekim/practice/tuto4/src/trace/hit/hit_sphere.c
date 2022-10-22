#include "../../../include/structures.h"
#include "../../../include/utils.h"

t_bool  hit_sphere(t_sphere *sp, t_ray *ray)
{
    t_vec3 oc;
    double a;
    double b;
    double c;
    double discriminant;

    oc = vminus(ray->origin, sp->center);
    a = vdot(ray->dir, ray->dir);
    b = 2.0 * vdot(oc, ray->dir);
    c = vdot(oc, oc) - sp->radius2;
    // 근의 공식의 판별식
    discriminant = b * b - 4 * a * c;

    return (discriminant > 0);
}
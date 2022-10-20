#include "../../../include/structures.h"
#include "../../../include/utils.h"
#include "../../../include/trace.h"

double  hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
    t_vec3 oc;
    double a;
    double half_b;
    double c;
    double discriminant;
    double sqrtd;
    double root;

    oc = vminus(ray->origin, sp->center);
    // vdot 을 vlength2 무관한 식
    a = vlength2(ray->dir);
    half_b = vdot(oc, ray->dir);
    c = vlength2(oc) - sp->radius2;
    discriminant = half_b * half_b - a * c;

    if (discriminant < 0)
        return (FALSE);
    sqrtd = sqrt(discriminant);
    root = (-half_b - sqrtd) / a;
    if (root < rec->tmin || rec->tmax < root)
    {
        root = (-half_b + sqrtd) / a;
        if (root < rec->tmin || rec->tmax < root)
            return (FALSE);
    }
    rec->t = root;
    rec->p = ray_at(ray, root);
    rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
    set_face_normal(ray, rec);
    return (TRUE);
}
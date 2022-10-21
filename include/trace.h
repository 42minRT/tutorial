#ifndef TRACE_H
# define TRACE_H

# include "utils.h"
# include "structures.h"

t_ray		ray(t_point3 orig, t_vec3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_ray *r);
t_color3	ray_sphere_color(t_ray *r, t_object *world);
void		set_face_normal(t_ray *r, t_hit_record *rec);
bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
bool		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);

#endif

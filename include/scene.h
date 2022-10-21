#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas    new_canvas(int  width, int height);
t_camera    new_camera(t_canvas *canvas, t_point3 origin);
t_sphere	*new_sphere(t_point3 center, double radius);
t_object	*new_object(t_object_type type, void *element);

#endif

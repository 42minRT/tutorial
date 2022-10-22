#include "../../include/scene.h"

t_camera    camera(t_canvas *canvas, t_point3 origin)
{
    t_camera cam;
    double focal_len;
    double viewport_height;

    viewport_height = 2.0;
    focal_len = 1.0;
    cam.origin = origin;
    cam.viewport_h = viewport_height;
    cam.viewport_w = viewport_height * canvas->aspect_ratio;
    // 이 아래로 왜 필요한거지?
    cam.focal_len = focal_len;
    cam.horizontal = vec3(cam.viewport_w, 0, 0);
    cam.vertical = vec3(0, cam.viewport_h, 0);
    cam.left_bottom = vminus(vminus(vminus(cam.origin, vdivide(cam.horizontal, 2)),
                                    vdivide(cam.vertical, 2)), vec3(0, 0, focal_len));
    return (cam);
}
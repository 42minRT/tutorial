#include "../../include/scene.h"

// 카메라 생성자 함수
t_camera	camera(t_canvas *canvas, t_point3 orig)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;

	viewport_height = 2.0;
	focal_len = 1.0;		// 초점거리 (카메라 ~ 뷰포트)
	cam.orig = orig;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	// ex) orig이 (0, 0, 0)이라면
	// cam.left_bottom = vec3(0 - (cam.viewport_w / 2), 0 - (cam.viewport_h / 2), 0 - focal_len)
	// 왼쪽 아래 코너점 좌표 : origin - (horizontal / 2) - (vertical / 2) - (vec3(0, 0, focal_len))
	cam.left_bottom = vminus
							(vminus
									(vminus(cam.orig, vdivide(cam.horizontal, 2)),
									vdivide(cam.vertical, 2)),
							vec3(0, 0, focal_len));
	return (cam);
}
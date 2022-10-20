#include "../../include/trace.h"

// ray 생성자(정규화 된 ray)
t_ray		ray(t_point3 orig, t_vec3 dir)
{
	t_ray ray;

	ray.orig = orig;
	ray.dir = vunit(dir);
	return (ray);
}

// ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_point3	ray_at(t_ray *ray, double t)
{
	t_point3 at;

	at = vplus(ray->orig, vmult(ray->dir, t));
	return (at);
}

// primary_ray 생성자
t_ray		ray_primary(t_camera *cam, double u, double v)
{
	t_ray   ray;

	// ray = cam의 orig는 점 (x, y, z)
	ray.orig = cam->orig;
	// left_bottom + u * horizontal + v * vertical - origin 의 단위 벡터.
	ray.dir = vunit(	// 4. cam orig을 시점, 2의 끝점으로 향하는 방향의 단위 벡터
		vminus
			(vplus
			(vplus(cam->left_bottom, vmult(cam->horizontal, u)),	// 1. left_bottom->수평 방향의 벡터
															vmult(cam->vertical, v)),	// 2. 1에서 수직으로 올라간 곳을 향하는 벡터
																					cam->orig));	// 3. 2에서 시작점이 cam orig으로 바뀐 벡터
	return (ray);
}

// 광선이 최종적으로 얻게된 픽셀의 색상 값을 리턴.
t_color3	ray_color(t_ray *ray, t_sphere *sphere)
{
	double			t;
	t_color3		white;
	t_color3		sky;
	t_vec3			n;
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	// t는 광선이 구에 닿을 때 ray.dir에 곱해줄 스칼라 계수 (광선과 교점 사이의 거리)
	// 광선이 구에 안 닿을 때는 -1.0 반환 -> else
	// t = hit_sphere(sphere, ray);
	// 광선이 구에 적중하면 (광선과 구가 교점이 있고, 교점이 카메라 앞쪽이라면!)
	// if (t > 0.0)
	// {
	// 	// 정규화 된 구 표면에서의 법선
	// 	n = vunit(	// 2. 법선 벡터 1을 단위 벡터로 만들어 정규화
	// 				vminus(ray_at(ray, t), sphere->center));
	// 				// 1. 구의 중심->광선이 들어오는 방향으로 가는 벡터 (=법선)
	// 	return (vmult(color3(n.x + 1, n.y + 1, n.z + 1), 0.5));
	// 	// 정규화되어 [-1, 1] 범위이므로 +1로 [0, 2]로 만들고 0.5곱으로 [0, 1] 범위 계수로 변환
	// }

	if (hit_sphere(sphere, ray, &rec))
		return (vmult(vplus(rec.normal, color3(1, 1, 1)), 0.5));
	else
	{
		// ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수(스칼라) t
		t = 0.5 * (ray->dir.y + 1.0);
		// y가 양수일 때 0.5 ~ 1, 0일때 0.5, 음수일 때 0 ~ 0.5
		white = color3(1, 1, 1);
		sky = color3(0.5, 0.7, 1.0);
		// (1-t) * 흰색 + t * 하늘색 : y가 커질수록 하늘색 많이 <-> 작을수록 흰색이 많이
		return (vplus(vmult(white, 1.0 - t), vmult(sky, t)));
	}
}
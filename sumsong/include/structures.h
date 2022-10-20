#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;

// 1. 레이 구조체
typedef struct s_ray t_ray;

// 2. 장면 구조체
typedef struct s_camera t_camera;
typedef struct s_canvas t_canvas;

// 3. 오브젝트 구조체
typedef struct s_sphere t_sphere;

// 4. 식별자 매크로
typedef int				t_bool;
# define FALSE 0
# define TRUE 1

typedef struct s_hit_record t_hit_record;

struct	s_vec3
{
	double x;
	double y;
	double z;
};

struct	s_ray
{
	t_point3	orig; // 광원 원점
	t_vec3		dir; // 광선 단위벡터
};

struct	s_camera
{
	t_point3	orig;  // 카메라 원점(위치)
	double		viewport_h; // 뷰포트 세로길이
	double		viewport_w; // 뷰포트 가로길이
	t_vec3		horizontal; // 수평길이 벡터
	t_vec3		vertical; // 수직길이 벡터
	double		focal_len; // focal length
	t_point3	left_bottom; // 왼쪽 아래 코너점
};

struct	s_canvas
{
	int		width; // canvas width
	int		height; // canvas height;
	double	aspect_ratio; // 종횡비
};

struct	s_sphere
{
	t_point3	center; // 구 중심
	double		radius; // 구 반지름
	double		radius2; // 구 반지름 제곱
};

struct s_hit_record
{
	t_point3	p; // 교점의 좌표
	t_vec3		normal; // 교점에서의 법선
	double		tmin;
	double		tmax;
	double		t; // 광원과 교점 사이의 거리
	t_bool		front_face;
};

#endif
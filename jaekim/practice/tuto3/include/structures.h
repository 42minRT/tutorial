#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec3 t_vec3;
typedef struct s_vec3 t_point3;
typedef struct s_vec3 t_color3;
typedef struct s_ray t_ray;
typedef struct s_camera t_camera;
typedef struct s_canvas t_canvas;

struct s_vec3
{
    double x;
    double y;
    double z;
};

struct s_ray
{
    t_point3 origin;
    t_vec3  dir;
};

struct s_camera
{
    t_point3 origin; // 카메라 원점(위치)
    double viewport_h; // 뷰포트 세로 길이
    double viewport_w; // 뷰포트 가로 길이
    t_vec3 horizontal; // 수평길이 벡터
    t_vec3 vertical; // 수직길이 백터
    double focal_len; // 카메라 초점부터 뷰포트 거리
    t_point3 left_bottom; // 왼쪽 아래 코너점
};

struct s_canvas
{
    int width;
    int height;
    double aspect_ratio;
};

#endif
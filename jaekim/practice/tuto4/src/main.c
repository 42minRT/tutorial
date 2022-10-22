#include "../include/print.h"
#include "../include/scene.h"
#include "../include/trace.h"

int	main(void)
{
    int         i;
    int         j;
    double      u;
    double      v;

    t_color3    pixel_color;
    t_canvas canv;
    t_camera cam;
    t_ray    ray;
    t_sphere sp;

    canv = canvas(400, 300);
    cam = camera(&canv, point3(0, 0, 0));
    // 구 생성자
    sp = sphere(point3(0, 0, -5), 2);
    printf("P3\n%d %d\n255\n", canv.width, canv.height);
    j = canv.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < canv.width)
        {
            u = (double)i / (canv.width - 1);
            v = (double)j / (canv.height - 1);
            ray = ray_primary(&cam, u, v);
            // 구 추가
            pixel_color = ray_color(&ray, &sp);
            write_color(pixel_color);
            ++i;
        }
        --j;
    }

    return (0);
}

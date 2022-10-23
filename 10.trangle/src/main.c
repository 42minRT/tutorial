#include <stdio.h>
#include "../include/structures.h"
#include "../include/vector_utils.h"
#include "../include/object_utils.h"
#include "../include/write_color.h"
#include "../include/scene.h"
#include "../include/trace.h"

t_scene *scene_init(void)
{
    t_scene     *scene;
    t_object    *world;
    t_object    *lights;
    double      ka;

    scene = malloc(sizeof(t_scene));
    if (!scene)
        return (NULL);
    scene->canvas = canvas(400, 300);
    scene->camera = camera(&scene->canvas, point3(0, 0, 0));
    world = object(SP, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0));
    object_append(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0)));
    object_append(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(0.4, 0.2, 0.1)));
    object_append(&world, object(TRANGLE, trangle(point3(-2, 0, -1), point3(2, 1, -1), point3(1, 2, -1)), color3(1, 1, 1)));
    scene->world = world;
    lights = object(LIGHT_POINT, light_point(point3(0, 25, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
    scene->light = lights;
    ka = 0.1;
    scene->ambient = vmult(color3(1, 1, 1), ka);
    return (scene);
}

int	main(void)
{
    int			i;
    int			j;
    double      u;
    double      v;
	t_color3	pixel_color;
    t_object    *world;
    t_scene     *scene;

    scene = scene_init();
    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
    j = scene->canvas.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < scene->canvas.width)
        {
            u = (double)i / (scene->canvas.width - 1);
            v = (double)j / (scene->canvas.height - 1);
            scene->ray = ray_primary(&scene->camera, u, v);
            pixel_color = ray_color(scene);
			write_color(pixel_color);
            ++i;
        }
    --j;
    }
    return (0);
}
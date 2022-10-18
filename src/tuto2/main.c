#include "./include/print.h"

int	main(void)
{
    int         i;
    int         j;
    t_color3    pixel_color;
    double      r;
    double      g;
    double      b;
    int     canvas_width;
    int     canvas_height;

    canvas_width = 256;
    canvas_height = 256;
    printf("P3\n%d %d\n255\n", canvas_width, canvas_height);
    j = canvas_height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < canvas_width)
        {
            r = (double)i / (canvas_width - 1);
            g = (double)j / (canvas_height - 1);
            b = 0.25;
            write_color(pixel_color);
            ++i;
        }
          --j;
    }
    return (0);
}

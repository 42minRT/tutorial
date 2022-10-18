#include <stdio.h>
/* * * * 추가 * * * */
#include "structures.h"
#include "utils.h"
#include "print.h"
/* * * * 추가 끝 * * * */

int main(void)
{
    int         i;
    int         j;
    /* * * * 수정 * * * */
    t_color3    pixel_color;
    /* * * * 수정 끝 * * * */

    ...

        while (i < canvas_width)
        {
            pixel_color.x = (double)i / (canvas_width - 1);
            pixel_color.y = (double)j / (canvas_height - 1);
            pixel_color.z = 0.25;
            write_color(pixel_color);
        ++i;
        }
    ...
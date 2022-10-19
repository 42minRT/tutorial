#include "../../include/scene.h"

t_canvas	canvas(int  width, int height)
{
	t_canvas canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;	// 캔버스의 종횡비
	return (canvas);
}
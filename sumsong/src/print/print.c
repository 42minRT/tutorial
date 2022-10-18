#include <stdio.h>

// [0,1] 로 되어있는 rgb 값을 각각 [0,255]에 맵핑 해서 출력.
int	main(void)
{
    printf("%d %d %d\n", (int)(255.999 * 1),
                        (int)(255.999 * 1),
                        (int)(255.999 * 1));
}
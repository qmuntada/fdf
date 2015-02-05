
#include "libft.h"

double	ft_smoothstep(double edge1, double edge2, double x)
{
	x = ft_clamp((x - edge1) / (edge2 - edge1), 0.0, 1.0);
	return (x * x * (3 - 2 * x));
}

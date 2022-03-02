#include "minirt.h"

int	get_length_dir(char *dir)
{
	int	lenght;

	lenght = ft_strlen(dir);
	if (lenght > 8)
		return (0);
	return (1);
}

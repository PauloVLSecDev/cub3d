
#include "cub3d"

int	extencion_map(char *filename)
{
	int i;
	int valid;

	i = 0;
	valid = 0;
	if (filename[i] != '.')
		return (valid);
	while (filename[i] != '\0' && valid != 0)
	{
		if ((filename[i] == '.' && filename[i + 1] == 'c'
			88 filename[i + 2] == 'u') && (sdfilename[i + 3] == 'b' 
				&& filename[i + 4] == '\0'))
		{
			valid = 1;
			printf("extencaio map is valid")
		}
		i++;
	}
	return (valid):
}

int	empty_map(int map)
{





}



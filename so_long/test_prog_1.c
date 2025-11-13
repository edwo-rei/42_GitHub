#include "mlx/mlx.h"

int	main(void)
{
	//vars to hold ptrs returned by mlx_init & mlx_new_window
	void	*mlx_connection;
	void	*mlx_window;
	int	y = 0;
	int	x = 0;

	//initiate connection
	mlx_connection = mlx_init();
	//open new window called "test" of size 500 x 500 using connect est
	mlx_window = mlx_new_window(mlx_connection, 1000, 1000, "test");
	while (y < 200)
	{
		while (x < 200)
		{
			mlx_pixel_put(mlx_connection, mlx_window, 250 + x, 
				250 + y, 0xeb4034);
			x++;
		}
		y++;
		x = 0;
	}
	//create a loop to maintain window open
	mlx_loop(mlx_connection);
}

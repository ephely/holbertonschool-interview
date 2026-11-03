#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge of a given level
 * @level: The level of the Menger sponge
 */
void menger(int level)
{
	int size, row, col, r, c;
	char symbol;

	if (level < 0)
		return;

	size = (int)(pow(3, level));

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			symbol = '#';
			r = row;
			c = col;

			while (r > 0 || c > 0)
			{
				if (r % 3 == 1 && c % 3 == 1)
				{
					symbol = ' ';
					break;
				}
				r /= 3;
				c /= 3;
			}
			putchar(symbol);
		}
		putchar('\n');
	}
}

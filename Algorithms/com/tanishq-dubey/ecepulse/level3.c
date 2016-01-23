#include "level3.h"
#include <string.h>

int main()
{
	int sudoku[81];
	static const int fill[81] = {0,2,0,5,0,1,4,0,3,1,0,3,0,6,4,0,0,7,0,0,4,3,0,0,0,5,1,4,0,0,0,0,0,5,1,6,0,6,0,0,1,3,0,4,0,7,1,0,0,4,5,3,0,2,0,9,2,1,0,6,0,0,0,8,7,6,4,3,0,1,2,0,0,0,0,0,7,0,6,0,0};
	memcpy(sudoku, fill, sizeof(fill));
	solve(sudoku);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", sudoku[i*9+j]);
		}
		printf("\n");

	}
}
	

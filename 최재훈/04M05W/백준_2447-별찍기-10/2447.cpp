#include <iostream>

void PrintStar(const int row, const int col, const int N)
{
	if ((1 == (row / N) % 3) && (1 == (col / N) % 3))
	{
		printf(" ");
	}
	else
	{
		if (0 == N / 3)
			printf("*");
		else
			PrintStar(row, col, N / 3);
	}
}

int main()
{
	// init
	std::ios::sync_with_stdio(false);

	// input
	int N = 0;
	(void)scanf("%d", &N);

	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			PrintStar(row, col, N);
		}
		printf("\n");
	}

	return 0;
}
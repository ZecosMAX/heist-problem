#include <iostream>

int mindex(int, int, int, int);

int main()
{
	int M, N, K;
	scanf_s("%d %d %d", &M, &N, &K);

	int* M_Dim = new int[M];
	for (int i = 0; i < M; i++)
	{
		scanf_s("%d", &M_Dim[i]);
		M_Dim[i] = i > 0 ? M_Dim[i] + M_Dim[i - 1] : M_Dim[i];
	}
	
	int* matrix = new int[N * K];

	for (int i = 0; i < N * K; i++)
	{
		scanf_s("%d", &matrix[i]);
	}

	int mC = 0;
	int counter = 1;
	int* rooms = new int[N * K / M + 1];
	int rooms_index = 0;
	bool flag = true;
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < K; x++)
		{
			int index = mindex(x, y, N, K);

			if (x < M_Dim[mC])
			{
				flag = flag && !matrix[index];
			}
			else
			{
				mC++;
				if (flag)
				{
					rooms[rooms_index++] = counter;
				}
				flag = true;
				counter++;
				x--;
			}
		}
		if (flag)
		{
			rooms[rooms_index++] = counter;
		}
		flag = true;
		counter++;
		mC = 0;
	}
	rooms[rooms_index] = -1;

	int c = 0;
	printf("%d\n", rooms_index);
	while (rooms[c] != -1)
	{
		printf("%d ", rooms[c++]);
	}
	return 0;
}

int mindex(int x, int y, int N, int K)
{
	return x + (N - 1 - y) * K;
}
/*

3 4 6
3 2 1
0 0 0 1 0 1
0 0 1 0 1 0
1 0 1 0 0 1
0 1 0 1 0 0

*/
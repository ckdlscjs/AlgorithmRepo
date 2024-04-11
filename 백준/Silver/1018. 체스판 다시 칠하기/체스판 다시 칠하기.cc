#pragma once
#include <bits/stdc++.h>
int N, M;
const int MaxN = 55;
int input[MaxN][MaxN];
int result = 987654321;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		std::string str;
		std::cin >> str;
		for (int j = 0; j < M; j++)
			input[i][j] = str[j];
	}
		

	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			for (int chess = 0; chess < 2; chess++)
			{
				int count = 0;
				int board = chess ? 'W' : 'B';
				for (int row = 0; row < 8; row++)
				{
					board = board == 'W' ? 'B' : 'W';
					for (int col = 0; col < 8; col++)
					{
						if (input[i + row][j + col] != board)
							count++;
						board = board == 'W' ? 'B' : 'W';
					}
				}
				result = std::min(result, count);
			}
		}
	}
	std::cout << result;
	return 0;
}
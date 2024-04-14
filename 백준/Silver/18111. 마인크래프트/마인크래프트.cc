//https://www.acmicpc.net/problem/18111
#include <bits/stdc++.h>
#pragma once
//세로N, 가로M큭의 집터를 골랐다, 시작은 0,0 땅의높이를 일정하게바꿔야한다
//1.i,j의 가장위의 블록을 제거해 인벤토리에넣는다 -> 2초
//2.인벤토리의블록을 하나 꺼내 i,j의 가장위의블록에 넣는다 -> 1초
//땅고르기에 걸리는 최소시간과 답이 복수일경우 가장높은 땅의높이를 출력하라
//인벤토리에는 시작시 B개의 블록이 들어있다, 땅의높이는 256을 초과 할 수 없으며 음수가 될 수 없다
const int MaxN = 505;
int N, M, B;
int board[MaxN][MaxN];
std::vector<int> inputs;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> board[i][j];
			inputs.push_back(board[i][j]);
		}
	}
	std::sort(inputs.begin(), inputs.end(), std::greater<>());
	int result = 0;
	int result_sum = 987654321;
	for (int start = 0; start <= 256; start++)
	{
		int amount = B;
		int sum = 0;
		for (int i = 0; i < inputs.size(); i++)
		{
			if (inputs[i] < start)
			{
				amount -= start - inputs[i];
				sum += (start - inputs[i]);
			}
			else if (inputs[i] > start)
			{
				amount += inputs[i] - start;
				sum += (inputs[i] - start) * 2;
			}
		}
		if (amount >= 0)
		{
			if (sum <= result_sum)
			{
				result_sum = sum;
				result = start;
			}
		}
	}
	std::cout << result_sum << ' ' << result;
	
	return 0;
}
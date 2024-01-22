#pragma once
#include <bits/stdc++.h>
int N, M;
std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N;
	int num = 0;
	for (int i = 0; i < N; i++)
	{
		std::cin >> num;
		if (num == 0)
		{
			if (pq.size())
			{
				std::cout << pq.top() << '\n';
				pq.pop();
			}
			else
				std::cout << 0 << '\n';
		}
		else
			pq.push(num);
	}
	return 0;
}
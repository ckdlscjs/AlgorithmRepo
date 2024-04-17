//https://www.acmicpc.net/problem/1966
#pragma once
#include <bits/stdc++.h>
int T;
int N, M;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> T;
	while (T--)
	{
		std::priority_queue<int, std::vector<int>, std::less<int>> pq;
		std::deque<std::pair<int, int>> deq;
		std::cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			int value;
			std::cin >> value;
			deq.push_back({i, value});
			pq.push(value);
		}
		int result = 0;
		while (1)
		{
			std::pair<int, int> cur = deq.front();
			int curvalue = pq.top();
			if (cur.second != curvalue)
			{
				deq.push_back(deq.front());
				deq.pop_front();
			}
			else
			{
				deq.pop_front();
				pq.pop();
				result++;
				if (cur.first == M)
					break;
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}
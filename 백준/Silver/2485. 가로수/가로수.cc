//https://www.acmicpc.net/problem/2485
#pragma once
#include <bits/stdc++.h>
int N;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N;
	int a, b, c;
	int start, end;
	std::cin >> a;
	start = a;
	std::cin >> b;
	int gcd = b - a;
	for (int i = 2; i < N; i++)
	{
		std::cin >> c;
		int max_val = std::max(gcd, c - b);
		int min_val = std::min(gcd, c - b);
		while (max_val % min_val != 0)
		{
			int mod_val = max_val % min_val;
			max_val = min_val;
			min_val = mod_val;
		}
		gcd = min_val;
		a = b;
		b = c;
	}
	end = c;
	std::cout << (end - start) / gcd + 1 - N;
	return 0;
}

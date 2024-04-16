//https://www.acmicpc.net/problem/1929
#pragma once
#include <bits/stdc++.h>

int M, N;
bool Prime[1000005];
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> M >> N;
	Prime[0] = Prime[1] = true;
	for (int i = 0; i < 1000005; i++)
	{
		if (Prime[i])
			continue;
		for (int j = i+i; j < 1000005; j += i)
			Prime[j] = true;
	}
	for (int i = M; i <= N; i++)
		if (!Prime[i])
			std::cout << i << '\n';
	return 0;
}


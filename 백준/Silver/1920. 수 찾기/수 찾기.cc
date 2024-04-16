#pragma once
#include <bits/stdc++.h>
#include "unordered_map"
int N, M;
std::unordered_map<int, int> inputs;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N;
	int input;
	for (int i = 0; i < N; i++)
	{
		std::cin >> input;
		inputs[input] = 1;
	}
	std::cin >> M;
	for (int i = 0; i < M; i++)
	{
		std::cin >> input;
		std::cout << inputs[input] << '\n';
	}
	return 0;
}
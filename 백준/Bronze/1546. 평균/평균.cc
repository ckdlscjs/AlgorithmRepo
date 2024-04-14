//https://www.acmicpc.net/problem/1546
#pragma once
#include<bits/stdc++.h>
int N;
double M;
std::vector<double> inputs;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N;
	while (N--)
	{
		double input;
		std::cin >> input;
		M = std::max(input, M);
		inputs.push_back(input);
	}
	double sum = 0;
	for (double& val : inputs)
	{
		sum += val / M * 100.0f;
	}
	std::cout << sum / inputs.size();
	return 0;
}

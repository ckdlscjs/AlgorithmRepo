//https://www.acmicpc.net/problem/1654
#pragma once
#include <bits/stdc++.h>
int K, N;
std::vector<long long int> wires;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	long long int left = 1;
	long long int right = 0;
	std::cin >> K >> N;
	while (K--)
	{
		long long int wire;
		std::cin >> wire;
		right = std::max(right, wire);
		wires.push_back(wire);
	}
	long long int result = 0;
	while (left <= right)
	{
		int count = 0;
		long long int mid = (left + right) / 2;
		for (const auto& wire : wires)
		{
			count += wire / mid;
		}
		if (N <= count)
		{
			left = mid + 1;
			result = std::max(result, mid);
		}
		else
			right = mid - 1;
	}
	std::cout << result;
	return 0;
}
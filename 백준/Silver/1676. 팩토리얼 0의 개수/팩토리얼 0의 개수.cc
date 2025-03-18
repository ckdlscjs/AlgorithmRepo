#pragma once
#include <bits/stdc++.h>
int N;
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N;
	int num2 = 0;
	int num5 = 0;
	for (int i = N; i > 0; i--)
	{
		int num = i;
		while (!(num % 2))
		{
			num2++;
			num /= 2;
		}
		num = i;
		while (!(num%5))
		{
			num5++;
			num /= 5;
		}
	}
	int result = 0;
	while (num2 && num5)
	{
		num2--;
		num5--;
		result++;
	}
	std::cout << result;
	return 0;
}
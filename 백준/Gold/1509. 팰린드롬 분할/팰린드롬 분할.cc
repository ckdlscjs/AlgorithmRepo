//https://www.acmicpc.net/problem/1509
#pragma once
#include <bits/stdc++.h>
std::string str;
const int MaxN = 2500;
bool Palindrome[MaxN][MaxN];
int dp[MaxN];
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> str;
	for (int i = 1; i <= str.size(); i++)
	{
		Palindrome[i][i] = true;
	}
	for (int i = 1; i <= str.size() - 1; i++)
	{
		if (str[i-1] == str[i])
			Palindrome[i][i + 1] = true;
	}
	for (int size = 3; size <= str.size(); size++)
	{
		for (int i = 1; i + size - 1 <= str.size(); i++)
		{
			int j = i + size - 1;
			if (str[i-1] == str[j-1] && Palindrome[i + 1][j - 1])
				Palindrome[i][j] = true;
		}
	}
	for (int end = 1; end <= str.size(); end++)
	{
		dp[end] = 2e9;
		for (int start = 1; start <= end; start++)
		{
			if (Palindrome[start][end])
				dp[end] = std::min(dp[end], dp[start - 1] + 1);
		}
	}
	std::cout << dp[str.size()];
	return 0;
}

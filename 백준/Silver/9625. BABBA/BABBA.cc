#pragma once
#include <bits/stdc++.h>
int dp[50][2];
int main(void)
{
	int k;
	std::cin >> k;
	dp[0][0] = 1;
	dp[0][1] = 0;
	for (int i = 1; i <= k; i++)
	{
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
	}
	std::cout << dp[k][0] << ' ' << dp[k][1];
	return 0;
}
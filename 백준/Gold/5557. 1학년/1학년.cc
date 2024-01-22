#pragma once
#include <bits/stdc++.h>
int N;
const int MaxN = 105;
int input[MaxN];
long long int dp[MaxN][21];
/*
* 인덱스값과 결과값을 중간계산하면서 카운팅한다 이미 같은인덱스에 같은 sum에 결과값이 있다면 해당값에 대한 인덱스의 끝값까지 
* 체크가 된 것이므로 해당 뿌리를 재확인해도 결과는 바뀌지 않는다고로 1을 증가해 가산시킨다
*/
long long int Check(int idx, int sum)
{
	if (idx >= N - 2)
		return sum == input[N - 1];
	if (sum < 0 || sum > 20)
		return 0;
	if (dp[idx][sum])
		return dp[idx][sum];
	dp[idx][sum] = Check(idx + 1, sum + input[idx + 1]) + Check(idx + 1, sum - input[idx + 1]);
	return dp[idx][sum];
}
int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N;
	for (int i = 0; i < N; i++)
		std::cin >> input[i];
	std::cout << Check(0, input[0]);
	return 0;
}
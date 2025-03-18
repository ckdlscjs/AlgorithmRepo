#include <bits/stdc++.h>
int N, cnt5;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::cin >> N;
	while(N)
	{
	    int cur = N;
	    while(cur % 5 == 0)
	    {
	        cnt5 ++;
	        cur /= 5;
	    }
	    N--;
	}
	std::cout << cnt5;
	return 0;
}
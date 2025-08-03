/*
1.접근방식:

2.시간복잡도:

*/
#include <bits/stdc++.h>
std::bitset<33'554'434> chk;
int num;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	while(std::cin >> num)
	{
	    if(chk[num]) continue;
	    chk[num] = true;
	    std::cout << num << ' ';
	}
	return 0;
}


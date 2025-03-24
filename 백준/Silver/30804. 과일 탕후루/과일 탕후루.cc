#include <bits/stdc++.h>
int N, arr[200'005], chks[10];
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++) std::cin >> arr[i];
    
    int left = 0, right = 0, res = 0, cnts = 0;
    while(left <= right && right < N)
    {
        chks[arr[right]]++;
        if(chks[arr[right]] == 1)
            cnts++;
        while(cnts > 2)
        {
            chks[arr[left]]--;
            if(chks[arr[left]] <= 0)
                cnts--;
            left++;
        }
        res = std::max(res, right-left+1);
        right++;
    }
    std::cout << res;
	return 0;
}
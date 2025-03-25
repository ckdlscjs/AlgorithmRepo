#include <bits/stdc++.h>
int N, arr[500'005];
void MergeSort(int s, int e)
{
    if(s >= e) return;
    int mid = (s + e) / 2;
    MergeSort(s, mid);
    MergeSort(mid+1, e);
    std::vector<int> temp;
    int ls = s, rs = mid+1;
    while(ls <= mid && rs <= e) temp.push_back(arr[ls] <= arr[rs] ? arr[ls++] : arr[rs++]);
    while(ls <= mid) temp.push_back(arr[ls++]);
    while(rs <= e) temp.push_back(arr[rs++]);
    for(int i = 0; i < temp.size(); i++) arr[s+i] = temp[i];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    MergeSort(0, N-1);
    for(int i = 0; i < N; i++) std::cout << arr[i] << ' ';
	return 0;
}
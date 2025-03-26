#include <bits/stdc++.h>
int N, K, arr[5'000'005], temp[5'000'005];
void MergeSort(int s, int e)
{
    if(s >= e) return;
    int mid = (s + e) / 2;
    MergeSort(s, mid);
    MergeSort(mid+1, e);
    int idx = 0, ls = s, rs = mid+1;
    while(ls <= mid && rs <= e) temp[idx++] = (arr[ls] <= arr[rs] ? arr[ls++] : arr[rs++]);
    while(ls <= mid) temp[idx++] = arr[ls++];
    while(rs <= e) temp[idx++] = arr[rs++];
    std::memcpy(arr + s, temp, sizeof(int) * idx);
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> K;
    for(int n = 0; n < N; n++) std::cin >> arr[n];
    MergeSort(0, N-1);
    std::cout << arr[K-1];
	return 0;
}
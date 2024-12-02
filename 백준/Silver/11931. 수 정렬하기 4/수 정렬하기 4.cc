#include <bits/stdc++.h>
int N, arr[1'000'005];
void QuickSort(int start, int end)
{
    if(start >= end) return;
    int pivot = arr[start];
    int left = start + 1;
    int right = end;
    while(left <= right)
    {
        while(left <= right && arr[left] > pivot) left++;
        while(left <= right && pivot >= arr[right]) right--;
        if(left <= right)
        {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    int temp = arr[start];
    arr[start] = arr[right];
    arr[right] = temp;
    QuickSort(start, right-1);
    QuickSort(right+1, end);
}
void MergeSort(int start, int end)
{
    if(start >= end) return;
    int mid = (start + end) / 2;
    MergeSort(start, mid);
    MergeSort(mid+1, end);
    std::vector<int> temp;
    int lidx = start, ridx = mid+1;
    while(lidx <= mid && ridx <= end)
        temp.push_back(arr[lidx] > arr[ridx] ? arr[lidx++] : arr[ridx++]);
    while(lidx <= mid)
        temp.push_back(arr[lidx++]);
    while(ridx <= end)
        temp.push_back(arr[ridx++]);
    lidx = 0;
    for(int i = start; i <= end; i++)
        arr[i] = temp[lidx++];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> N;
    for(int i = 0; i < N; i++)
        std::cin >> arr[i];
    MergeSort(0, N-1);
    for(int i = 0; i < N; i++)
        std::cout << arr[i] << '\n';
    return 0;
}
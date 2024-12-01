#include <bits/stdc++.h>
using namespace std;
int N, arr[1'000'005];
void MergeSort(int s, int e)
{
  if(s >= e)
    return;
  int mid = (s+e) / 2;
  MergeSort(s, mid);
  MergeSort(mid+1, e);
  int ls = s;
  int rs = mid+1;
  std::vector<int> temp;
  while(ls <= mid && rs <= e)
    temp.push_back(arr[ls] <= arr[rs] ? arr[ls++] : arr[rs++]);
  while(ls <= mid)
    temp.push_back(arr[ls++]);
  while(rs <= e)
    temp.push_back(arr[rs++]);
  for(const auto& iter : temp)
    arr[s++] = iter;
}

void QuickSort(int start, int end)
{
  if(start >= end)
    return;
  int pivot = start;
  int val = arr[pivot];
  int left = start + 1;
  int right = end - 1;

  while (left <= right) {
    while (left <= right && arr[left] <= val) left++;
    while (left <= right && arr[right] > val) right--;
    
    if (left <= right) {
      std::swap(arr[left], arr[right]);
    }
  }

  std::swap(arr[start], arr[right]);
  QuickSort(start, right);
  QuickSort(right + 1, end);
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  for(int i = 0; i < N; i++)
    std::cin >> arr[i];
  MergeSort(0, N-1);
  for(int i = 0; i < N; i++)
    std::cout << arr[i] << '\n';
  
  return 0;
}
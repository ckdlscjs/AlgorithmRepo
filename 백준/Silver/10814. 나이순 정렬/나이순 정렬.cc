#include <bits/stdc++.h>
int n;
std::vector<std::pair<int, std::string>> arr;
void MergeSort(int s, int e)
{
  if(s >= e)
    return;
  int mid = (s+e) / 2;
  MergeSort(s, mid);
  MergeSort(mid+1, e);
  int ls = s;
  int rs = mid+1;
  std::vector<std::pair<int, std::string>> temp;
  while(ls <= mid && rs <= e)
    temp.push_back(arr[ls].first <= arr[rs].first ? arr[ls++] : arr[rs++]);
  while(ls <= mid)
    temp.push_back(arr[ls++]);
  while(rs <= e)
    temp.push_back(arr[rs++]);
  for(const auto& iter : temp)
    arr[s++] = iter;
}
int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        int age;
        std::string str;
        std::cin >> age >> str;
        arr.push_back({age, str});
    }
    MergeSort(0, arr.size()-1);
    for(const auto& iter : arr)
    {
        std::cout << iter.first << ' ' <<iter.second <<'\n';
    }
    return 0;
}
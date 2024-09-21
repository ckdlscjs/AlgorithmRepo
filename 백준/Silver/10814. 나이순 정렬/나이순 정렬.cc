#include <bits/stdc++.h>
int n;
std::vector<std::pair<int, std::string>> arr;
bool Compare(const std::pair<int, std::string>&a, const std::pair<int, std::string>& b)
{
    return a.first == b.first ? false : a.first > b.first;
}
void QuickSort(int start, int end)
{
  if(start >= end)
    return;
  int pivot = start;
  std::pair<int, std::string> temp = arr[pivot];
  std::vector<std::pair<int, std::string>> lefts;
  std::vector<std::pair<int, std::string>> rights;
  for(int i = start + 1; i <= end; i++)
  {
      if(Compare(temp, arr[i]))
        lefts.push_back(arr[i]);
      else 
        rights.push_back(arr[i]);
  }
  int idx = start;
  for(int i = 0; i < lefts.size(); i++)
      arr[idx++] = lefts[i];
  pivot = idx;
  arr[idx++] = temp;
  for(int i = 0; i < rights.size(); i++)
      arr[idx++] = rights[i];
  QuickSort(start, pivot-1);
  QuickSort(pivot+1, end);
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
    QuickSort(0, n-1);
    for(const auto& iter : arr)
    {
        std::cout << iter.first << ' ' <<iter.second <<'\n';
    }
    return 0;
}
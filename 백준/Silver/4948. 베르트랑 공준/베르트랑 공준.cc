#include <cstdio>
#include <math.h>
using namespace std;
const int MAX = 300000;
bool arr[MAX];

int main(void)
{
  arr[0] = true;
  arr[1] = true;
  for(int i = 2; i <= sqrt(MAX); i++)
  {
    if(arr[i]) continue;
    int temp = i + i;
    while(temp < MAX)
    {
      arr[temp] = true;
      temp += i;
    }
  }
  int n = 0;
  scanf("%d", &n);
  while(n != 0)
  {
    int count = 0;
    for(int i = n+1; i <= 2*n; i++) if(!arr[i]) count++;
    printf("%d\n",count);
    scanf("%d", &n);
  }
  
}
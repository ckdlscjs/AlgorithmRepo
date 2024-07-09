#include <cstdio>
using namespace std;

int main(void)
{
  int t;
  scanf("%d", &t);
  for(int testCase = 0; testCase < t; testCase++)
  {
    long long int x, y;
    scanf("%lld %lld", &x, &y);
    int count = 0;
    int jump = 1;
    while(1)
    {
      x += jump;
      count++;
      //printf("%d %d:%d\n", x, y, count);
      if(x >= y) break;
      y -= jump;
      count++;
      //printf("%d %d:%d\n", x, y, count);
      if(x >= y) break;
      jump++;
    }
    printf("%d\n", count);
  }
  return 0;
}
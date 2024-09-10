#include <cstdio>


int n;
char inEqual[10];
bool chNum[10];
int ans[10];
bool chFirst = true;
void chInEqual(bool last, int idx)
{
  if(!chFirst) return;
  if(idx > n)
  {
    if(chFirst)
    {
      for(int i = 0; i <= n; i++) printf("%d",ans[i]);
      printf("\n");
      chFirst = false;
    }
  }
  else
  {
    if(!last)
    {
      for(int i = 9; i >= 0; i--)
      {
        if(!chFirst) break;
        if(chNum[i]) continue;
        ans[idx] = i;
        if(inEqual[idx-1] == '>' && ans[idx-1] < ans[idx]) continue;
        if(inEqual[idx-1] == '<' && ans[idx-1] > ans[idx]) continue;
        chNum[i] = true;
        chInEqual(last, idx+1);
        chNum[i] = false;
      }
    }
    else
    {
      for(int i = 0; i <= 9; i++)
      {
        if(!chFirst) break;
        if(chNum[i]) continue;
        ans[idx] = i;
        if(inEqual[idx-1] == '>' && ans[idx-1] < ans[idx]) continue;
        if(inEqual[idx-1] == '<' && ans[idx-1] > ans[idx]) break;
        chNum[i] = true;
        chInEqual(last, idx+1);
        chNum[i] = false;
      }
    }
  }
}

int main(void)
{
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
    char temp;
    scanf(" %c", &temp);
    inEqual[i] = temp;
  }
  chInEqual(false, 0);
  chFirst = true;
  chInEqual(true, 0);
}
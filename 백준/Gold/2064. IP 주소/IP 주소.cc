#include <bits/stdc++.h>
std::vector<int> ip, mask;
int N, maskpos = 35;
std::string prev, nxt;
int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cin >> N;
  std::cin >> prev;
  prev += ".";
  std::string tempip = prev;
  auto pos_ip = tempip.find(".");
  while(pos_ip != std::string::npos)
  {
    int inum = std::stoi(tempip.substr(0, pos_ip));
    tempip = tempip.substr(pos_ip+1);
    pos_ip = tempip.find(".");
    ip.push_back(inum);
  }
  for(int n = 1; n < N; n++)
  {
    std::cin >> nxt;
    nxt += ".";
    std::string temp_prev = prev;
    std::string temp_nxt = nxt;
    auto pos_prev = temp_prev.find(".");
    auto pos_nxt = temp_nxt.find(".");
    int temppos = 0;
    while(pos_prev != std::string::npos && pos_nxt != std::string::npos)
    {
      int pnum = std::stoi(temp_prev.substr(0, pos_prev));
      int nnum = std::stoi(temp_nxt.substr(0, pos_nxt));
      temp_prev = temp_prev.substr(pos_prev+1);
      pos_prev = temp_prev.find(".");
      temp_nxt = temp_nxt.substr(pos_nxt+1);
      pos_nxt = temp_nxt.find(".");
      if(pnum == nnum)
      {
        temppos += 8;
      }
      else
      {
        for(int i = 7; i >= 0; i--)
        {
          if((pnum & (1 << i)) == (nnum & (1 << i))) continue;
          temppos += 7-i;
          break;
        }
        break;
      }
    }
    maskpos = std::min(maskpos, temppos);
    prev = nxt;
  }
  
  int num = 0;
  for(int i = 1; i <= 32; i++)
  {
    int shiftcnt = 7 - ((i-1) % 8);
    if(i <= maskpos)
      num |= 1 << shiftcnt;
    if(shiftcnt%8 == 0)
    {
      mask.push_back(num);
      num = 0;
    }
  }
  std::cout << (int)(ip[0] & mask[0]) << '.' << (int)(ip[1] & mask[1]) <<'.' << (int)(ip[2] & mask[2]) << '.' << (int)(ip[3] & mask[3]) << '\n';
  std::cout <<  mask[0] << '.' << mask[1] <<'.' << mask[2] << '.' <<  mask[3];
  return 0;
}
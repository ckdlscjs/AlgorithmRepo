#include <bits/stdc++.h>
using namespace std;
const int d0[] = {-1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int d1[] = {0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int d2[] = {0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int d3[] = {0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int d4[] = {0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int d5[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int d6[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const int d7[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0};
const int d8[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0};
const int d9[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, 0};
const int d10[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1};
int dim[12], res, cnt;
int ***********arr, ***********dist;
struct Pos
{
  int m, n, o, p, q, r, s, t, u, v, w;
};
std::queue<Pos> q;
void del()
{
  for(int i0 = 0; i0 < dim[0]; i0++)
  {
    for(int i1 = 0; i1 < dim[1]; i1++)
    {
      for(int i2 = 0; i2 < dim[2]; i2++)
      {
        for(int i3 = 0; i3 < dim[3]; i3++)
        {
          for(int i4 = 0; i4 < dim[4]; i4++)
          {
            for(int i5 = 0; i5 < dim[5]; i5++)
            {
              for(int i6 = 0; i6 < dim[6]; i6++)
              {
                for(int i7 = 0; i7 < dim[7]; i7++)
                {
                  for(int i8 = 0; i8 < dim[8]; i8++)
                  {
                    for(int i9 = 0; i9 < dim[9]; i9++)
                    {
                      delete[] arr[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9];
                      delete[] dist[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9];
                    }
                    delete[] arr[i0][i1][i2][i3][i4][i5][i6][i7][i8];
                    delete[] dist[i0][i1][i2][i3][i4][i5][i6][i7][i8];
                  }
                  delete[] arr[i0][i1][i2][i3][i4][i5][i6][i7];
                  delete[] dist[i0][i1][i2][i3][i4][i5][i6][i7];
                }
                delete[] arr[i0][i1][i2][i3][i4][i5][i6];
                delete[] dist[i0][i1][i2][i3][i4][i5][i6];
              }
              delete[] arr[i0][i1][i2][i3][i4][i5];
              delete[] dist[i0][i1][i2][i3][i4][i5];
            }
            delete[] arr[i0][i1][i2][i3][i4];
            delete[] dist[i0][i1][i2][i3][i4];
          }
          delete[] arr[i0][i1][i2][i3];
          delete[] dist[i0][i1][i2][i3];
        }
        delete[] arr[i0][i1][i2];
        delete[] dist[i0][i1][i2];
      }
      delete[] arr[i0][i1];
      delete[] dist[i0][i1];
    }
    delete[] arr[i0];
    delete[] dist[i0];
  }
  delete[] arr;
  delete[] dist;
}
int main() 
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  for(int i = 10; i >= 0; i--) std::cin >> dim[i];
  arr = new int**********[dim[0]];
  dist = new int**********[dim[0]];
  for(int i0 = 0; i0 < dim[0]; i0++)
  {
    arr[i0] = new int*********[dim[1]];
    dist[i0] = new int*********[dim[1]];
    for(int i1 = 0; i1 < dim[1]; i1++)
    {
      arr[i0][i1] = new int********[dim[2]];
      dist[i0][i1] = new int********[dim[2]];
      for(int i2 = 0; i2 < dim[2]; i2++)
      {
        arr[i0][i1][i2] = new int*******[dim[3]];
        dist[i0][i1][i2] = new int*******[dim[3]];
        for(int i3 = 0; i3 < dim[3]; i3++)
        {
          arr[i0][i1][i2][i3] = new int******[dim[4]];
          dist[i0][i1][i2][i3] = new int******[dim[4]];
          for(int i4 = 0; i4 < dim[4]; i4++)
          {
            arr[i0][i1][i2][i3][i4] = new int*****[dim[5]];
            dist[i0][i1][i2][i3][i4] = new int*****[dim[5]];
            for(int i5 = 0; i5 < dim[5]; i5++)
            {
              arr[i0][i1][i2][i3][i4][i5] = new int****[dim[6]];
              dist[i0][i1][i2][i3][i4][i5] = new int****[dim[6]];
              for(int i6 = 0; i6 < dim[6]; i6++)
              {
                arr[i0][i1][i2][i3][i4][i5][i6] = new int***[dim[7]];
                dist[i0][i1][i2][i3][i4][i5][i6] = new int***[dim[7]];
                for(int i7 = 0; i7 < dim[7]; i7++)
                {
                  arr[i0][i1][i2][i3][i4][i5][i6][i7] = new int**[dim[8]];
                  dist[i0][i1][i2][i3][i4][i5][i6][i7] = new int**[dim[8]];
                  for(int i8 = 0; i8 < dim[8]; i8++)
                  {
                    arr[i0][i1][i2][i3][i4][i5][i6][i7][i8] = new int*[dim[9]];
                    dist[i0][i1][i2][i3][i4][i5][i6][i7][i8] = new int*[dim[9]];
                    for(int i9 = 0; i9 < dim[9]; i9++)
                    {
                      arr[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9] = new int[dim[10]];
                      dist[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9] = new int[dim[10]];
                      for(int i10 = 0; i10 < dim[10]; i10++)
                      {
                        std::cin >> arr[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10];
                        dist[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] = 0;
                        if(arr[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] == 1)
                        {
                          q.push({i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10});
                          dist[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] = 1;
                        }
                        if(arr[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] == 1 || arr[i0][i1][i2][i3][i4][i5][i6][i7][i8][i9][i10] == 0)
                          cnt++;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if(cnt == 0)
  {
    std::cout << 0;
    del();
    return 0;
  }
  while(q.size())
  {
    auto iter = q.front();
    q.pop();
    cnt--;
    res = std::max(res, dist[iter.m][iter.n][iter.o][iter.p][iter.q][iter.r][iter.s][iter.t][iter.u][iter.v][iter.w]);
    for(int dir = 0; dir < 22; dir++)
    {
      int nm = iter.m + d0[dir];
      int nn = iter.n + d1[dir];
      int no = iter.o + d2[dir];
      int np = iter.p + d3[dir];
      int nq = iter.q + d4[dir];
      int nr = iter.r + d5[dir];
      int ns = iter.s + d6[dir];
      int nt = iter.t + d7[dir];
      int nu = iter.u + d8[dir];
      int nv = iter.v + d9[dir];
      int nw = iter.w + d10[dir];
      if(
        nm < 0 || nm >= dim[0] ||
        nn < 0 || nn >= dim[1] ||
        no < 0 || no >= dim[2] ||
        np < 0 || np >= dim[3] ||
        nq < 0 || nq >= dim[4] ||
        nr < 0 || nr >= dim[5] ||
        ns < 0 || ns >= dim[6] ||
        nt < 0 || nt >= dim[7] ||
        nu < 0 || nu >= dim[8] ||
        nv < 0 || nv >= dim[9] ||
        nw < 0 || nw >= dim[10] ||
        dist[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] ||
        arr[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] != 0) continue;
      q.push({nm, nn, no, np, nq, nr, ns, nt, nu, nv, nw});
      arr[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] = 1;
      dist[nm][nn][no][np][nq][nr][ns][nt][nu][nv][nw] = dist[iter.m][iter.n][iter.o][iter.p][iter.q][iter.r][iter.s][iter.t][iter.u][iter.v][iter.w] + 1;
    }
  }
  std::cout << (cnt > 0 ? -1 : res-1);
  del();
  return 0;
}
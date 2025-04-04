#include <bits/stdc++.h>
using namespace std;
int N, M;
std::vector<int> A, B;
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    std::cin >> N;
    A.resize(N);
    for(int n = 0; n < N; n++) std::cin >> A[n];
    std::cin >> M;
    B.resize(M);
    for(int m = 0; m < M; m++) std::cin >> B[m];
    std::vector<int> res;
    while(1)
    {
        int a_idx, b_idx;
        while(1)
        {
            if(A.size() == 0 || B.size() == 0) break;
            a_idx = std::max_element(A.begin(), A.end())-A.begin();
            b_idx = std::max_element(B.begin(), B.end())-B.begin();
            if(A[a_idx] == B[b_idx]) break;
            else if(A[a_idx] > B[b_idx]) A.erase(A.begin() + a_idx);
            else B.erase(B.begin() + b_idx);
        }
        if(A.size() == 0 || B.size() == 0) break;
        res.push_back(A[a_idx]);
        A = std::vector<int>(A.begin() + a_idx + 1, A.end());
        B = std::vector<int>(B.begin() + b_idx + 1, B.end());
    }
    std::cout<< res.size() << '\n';
    for(const auto& iter : res)
        std::cout << iter << ' ';
    
    
    return 0;
}

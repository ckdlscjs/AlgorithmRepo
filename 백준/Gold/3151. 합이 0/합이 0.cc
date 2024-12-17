#include <iostream>
#include<algorithm>
#include <vector>
 
using namespace std;
 
vector<int> input;
int n;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        input.push_back(a);
    }
    
    sort(input.begin(), input.end());
    
    long long cnt = 0;
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            long long tempSum = input[i] + input[j];
            
            int lower = lower_bound(input.begin()+j+1, input.end(), -tempSum) - input.begin();
            int upper = upper_bound(input.begin() +j+1, input.end(), -tempSum) - input.begin();;
            cnt += (upper - lower);
        }
    }
        
    cout << cnt;
}
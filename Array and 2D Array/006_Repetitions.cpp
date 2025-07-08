// CSES Problem: Repetitions
// 6. https://cses.fi/problemset/result/12686725/
// YT : https://www.youtube.com/watch?v=LRkZs6CI3Bw

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    int cnt = 1;
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        if(str[i] != str[i-1])
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
        else
            cnt += 1;
    }
    ans = max(ans, cnt);
    cout << ans;

    return 0;
}

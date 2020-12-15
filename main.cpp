#include <bits/stdc++.h>
using namespace std;

void test_case(int t) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = -1e9-7;
    for (auto el : a)
        ans = max(ans, el);
    cout << ans << '\n';
}

void solve() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
        test_case(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
  
    return 0;
}


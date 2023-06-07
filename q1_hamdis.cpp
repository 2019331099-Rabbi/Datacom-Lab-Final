#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

vector <string> codewords;

int findHamDis(string s1, string s2)
{
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) if (s1[i] != s2[i]) cnt++;
    return cnt;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        codewords.push_back(s);
    }

    int minDis = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            minDis = min(minDis, findHamDis(codewords[i], codewords[j]));
        }
    }
    cout << "Minimum hamming distance = " << minDis << endl;
    return 0;
}
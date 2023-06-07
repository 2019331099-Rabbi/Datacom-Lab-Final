#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

bool isEven(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) if (s[i] == '1') cnt++;
    return !(cnt & 1);
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    string dataword;

    cin >> dataword;
    string codeword = isEven(dataword)?(dataword + '0'):(dataword + '1');

    cout << "Dataword = " << dataword << endl;
    cout << "Codeword = " << codeword << endl;

    string codeword1 = codeword;
    if (isEven(codeword1)) cout << codeword1 << " is valid" << endl;
    else cout << codeword1 << " is invalid" << endl;


    string codeword2 = codeword;
    codeword2[0] = (codeword2[0] == '1')?'0':'1';
    if (isEven(codeword2)) cout << codeword2 << " is valid" << endl;
    else cout << codeword2 << " is invalid" << endl;

    return 0;
}
#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

string doxor(string remainder, string divisor)
{
    string result = "";
    for (int i = 1; i < divisor.size(); i++) result += (divisor[i] == remainder[i])?'0':'1';
    return result;
}

string generateCRC(string dataword, string divisor)
{
    string dividend = dataword + string(divisor.size() - 1, '0');
    string remainder = dividend.substr(0, divisor.size());

    int cnt = dividend.size() - divisor.size() + 1, pos = remainder.size();
    while (cnt--) {
        string divisortmp = (remainder[0] == '0')?string(divisor.size(), '0'):divisor;
        remainder = doxor(remainder, divisortmp);
        if (pos < dividend.size()) remainder += dividend[pos];
        pos++;
    }
    return remainder;
}

bool checkCRC(string codeword, string divisor)
{
    string remainder = generateCRC(codeword, divisor);
    return remainder == string(divisor.size() - 1, '0');
}

int main()
{
    RUN_FAST; cin.tie(nullptr);
    string dataword, divisor;

    cin >> dataword >> divisor;

    string crc = generateCRC(dataword, divisor);
    string codeword = dataword + crc;

    cout << "CRC = " << crc << endl;
    cout << "Codeword = " << codeword << endl;

    if (checkCRC(codeword, divisor)) cout << "Dataword accepted: " << dataword << endl;
    else cout << "Dataword discarted" << endl;


    // string codeword1 = codeword;
    // codeword1[0] = '0';
    // if (checkCRC(codeword1, divisor)) cout << "Dataword accepted: " << dataword << endl;
    // else cout << "Dataword discarted" << endl;

    return 0;
}
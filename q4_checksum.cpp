#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 26
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
#define bits 8
using namespace std;

string decToBin(int dec)
{
    string bin = "";
    while (dec) {
        bin += '0' + (dec % 2);
        dec /= 2;
    }
    return bin;
}

int binToDec(string bin)
{
    int dec = 0, len = bin.size();
    for (int i = 0; i < bin.size(); i++) dec += (bin[i] - '0') * (1 << (len - i - 1));
    return dec;
}


string processing(string bin)
{
    vector <string> vs;
    for (int i = 0; i < bin.size(); i += bits) vs.push_back(bin.substr(i, bits));
    
    int sum = 0;
    for (int i = 0; i < vs.size(); i++) reverse(vs[i].begin(), vs[i].end());
    for (int i = 0; i < vs.size(); i++) sum += binToDec(vs[i]);

    return decToBin(sum);
}

int complement(string bin)
{
    bin += string(bits - bin.size(), '0');
    for (int i = 0; i < bin.size(); i++) bin[i] = (bin[i] == '1')?'0':'1';
    reverse(bin.begin(), bin.end());
    return binToDec(bin);
}

int generateChecksum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];

    string bin = processing(decToBin(sum));
    while (true) {
        if (bin.size() <= bits) break;
        bin = processing(bin);
    }

    return complement(bin);
}

int main()
{
    RUN_FAST;
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) cin >> arr[i];
    int checksum = generateChecksum(arr, n);
    cout << "Checksum = " << checksum << endl;

    int newarr[n + 1];
    for (int i = 0; i < n; i++) newarr[i] = arr[i];
    newarr[n] = checksum;

    int newchecksum = generateChecksum(newarr, n + 1);
    if (newchecksum) cout << "Dataword discarted" << endl;
    else cout << "Dataword accepted" << endl;
    return 0;
}
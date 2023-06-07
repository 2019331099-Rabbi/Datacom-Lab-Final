#include <bits/stdc++.h>
#define endl '\n'
#define PI acos(-1)
#define sz 200010
#define inf 1000000009
#define mod 100000000
#define RUN_FAST ios::sync_with_stdio(false);
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    RUN_FAST; cin.tie(nullptr);

    int n = 3;
    int arr[] = {1, 2, 3};
    int newnum = 4;

    print([arr, newnum], n);
}
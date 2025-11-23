#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ld long double

bool search_key(vector<ll> &ht, ll key)
{
    ll m = ht.size();
    ll idx = key % m;

    ll st = idx;

    while (ht[idx] != -1)
    {
        if (ht[idx] == key)
            return true;

        idx = (idx + 1) % m;

        if (idx == st)
            return false;
    }
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> ht = {15, 25, 35, -1, -1};
    ll key = 26;

    if (search_key(ht, key))
        cout << key << " Found\n";
    else
        cout << key << " Not Found\n";
}
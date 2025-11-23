#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ld long double

void insert_key(vector<ll> &ht, ll key)
{
    ll m = ht.size();
    ll idx = key % m;

    ll st = idx;
    while (ht[idx] != -1)
    {
        idx = (idx + 1) % m;

        if (idx == st)
        {
            cout << "Hash table is full " << key << '\n';
            return;
        }
    }
    ht[idx] = key;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll m = 4;
    vector<ll> ht(m, -1);

    vector<ll> key = {10, 20, 5, 17, 22};

    for (ll x : key)
        insert_key(ht, x);

    cout << "Hash Table:\n";
    for (ll i = 0; i < m; i++)
        cout << i << " -> " << ht[i] << '\n';
}
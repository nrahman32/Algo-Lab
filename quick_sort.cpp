#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ld long double

ll partition(vector<ll> &a, ll low, ll high)
{
    ll pivot = a[high];
    ll i = low - 1;

    for (ll j = low; j <= high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void qs(vector<ll> &a, ll low, ll high)
{
    if (low < high)
    {
        ll pi = partition(a, low, high);
        qs(a, low, pi - 1);
        qs(a, pi + 1, high);
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a)
        cin >> i;

    qs(a, 0, n - 1);
    for (auto it : a)
        cout << it << ' ';
}
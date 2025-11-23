#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ld long double

void heapify(vector<ll> &a, ll n, ll i)
{
    ll smallest = i;
    ll left = 2 * i + 1;
    ll right = 2 * i + 2;

    if (left < n and a[left] < a[smallest])
        smallest = left;
    if (right < n and a[right] < a[smallest])
        smallest = right;
    if (smallest != i)
    {
        swap(a[i], a[smallest]);
        heapify(a, n, smallest);
    }
}

void build_min_heap(vector<ll> &a)
{
    ll n = a.size();

    for (ll i = n / 2 - 1; i >= 0; --i)
        heapify(a, n, i);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> a = {7, 3, 9, 1, 6, 2};
    build_min_heap(a);

    for (auto it : a)
        cout << it << ' ';
}
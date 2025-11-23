#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ld long double

void heapify(vector<ll> &a, ll n, ll i)
{
    ll largest = i;
    ll left = 2 * i + 1;
    ll right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void build_max_heap(vector<ll> &a)
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

    vector<ll> a = {3, 9, 2, 1, 4, 5};
    build_max_heap(a);

    for (auto it : a)
        cout << it << ' ';
}

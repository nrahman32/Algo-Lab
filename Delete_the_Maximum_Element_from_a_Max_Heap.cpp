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

void delete_max(vector<ll> &a)
{
    ll n = a.size();
    swap(a[0], a[n - 1]);
    a.pop_back();
    heapify(a, a.size(), 0);
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> a = {50, 40, 30, 10, 20};
    delete_max(a);

    for (auto it : a)
        cout << it << ' ';
}
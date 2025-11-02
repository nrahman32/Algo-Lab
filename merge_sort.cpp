#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define ld long double

void merge(vector<ll> &a, ll low, ll mid, ll high)
{
    vector<ll> temp;
    ll left = low;
    ll right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (a[left] <= a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(a[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(a[right]);
        right++;
    }

    for (ll i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}

void ms(vector<ll> &a, ll low, ll high)
{
    if (low == high)
        return;
    int mid = (low + high) / 2;
    ms(a, low, mid);
    ms(a, mid + 1, high);
    merge(a, low, mid, high);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ms(a, 0, n - 1);
    for (ll i = 0; i < n; ++i)
        cout << a[i] << ' ';
}
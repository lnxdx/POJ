// ITNOA
// O(#tests.(n.log(n) + n.k)) Two Pointers by lnxdx, Mashhad, 2019
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
ll INF = 1e13;
pair<ll, int>psum[N];
ll mabs(ll x)
{
	return x > 0 ? x : -x;
}
int main()
{
	int n, k;
	while (~scanf("%d%d", &n, &k) && n)
	{
		for (int i = 0;i < n;i++)
		{
			int val;
			scanf("%ld", &val);
			psum[i].first = (i ? psum[i - 1].first : 0) + val;
			psum[i].second = i;
		}
		psum[n] = make_pair(0, -1);
		sort(psum, psum + n + 1);
		while (k--)
		{
			ll t;
			scanf("%lld", &t);
			int l, r;
			l = 0;
			r = 1;
			int ansl, ansr;
			ll ans = INF;
			ll tt;
			while (r <= n && ans)
			{
				ll diff = (psum[r].first - psum[l].first);
				if (mabs(diff - t) < ans)
				{
					ansl = psum[l].second;
					ansr = psum[r].second;
					ans = mabs(diff - t);
					tt = diff;
				}
				if (diff<t)
					r++;
				if (diff>t)
					l++;
				if (l == r)
					r++;
			}
			printf("%lld %d %d\n", tt, min(ansl, ansr) + 2, max(ansl, ansr) + 1);
		}
	}
}

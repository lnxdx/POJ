// ITNOA
// O(n.log(n)) Two Pointers by lnxdx, Mashhad, 2019
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e6 + 6;
int a[N];
map<int, int>cnt;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d", a + i);
		cnt[a[i]] = 0;
	}
	int k = cnt.size();
	cnt.clear();
	int l, r;
	l = 0;
	r = 0;
	int c = 0;
	int ans = n;
	while (l < n)
	{
		if (c < k && r < n)
		{
			cnt[a[r]]++;
			if (cnt[a[r]] == 1)
				c++;
			r++;
		}
		else
		{
			if (c == k)
				ans = min(ans, r - l);
			cnt[a[l]]--;
			if (cnt[a[l]] == 0)
				c--;
			l++;
		}
	}
	printf("%d", ans);
}

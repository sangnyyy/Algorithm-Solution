#include <iostream>
using namespace std;

int a[1000001];
int n, b, c;
long long ans;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cin >> b >> c; ans += n;
	for (int i = 1; i <= n; i++)
	{
		a[i] -= b;
		if (a[i] > 0) {
			ans += (a[i] % c == 0 ? a[i] / c : a[i] / c + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}

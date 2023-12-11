#include <iostream>
#include <cmath>
#include <vector>
 
int main()
{
	int n, w, max_u, i, t, k, g, j, d, f, u;
	std::cin >> n;
	std::cin >> k;
	u = 0;
	max_u = -99999999993;
	for (d = 1; d <= n; d++)
	{
		std::cin >> f;
		std::cin >> t;
		if (k < t)
		{
			u = f - (t - k);
		}
		else
		{
			u = f;
		}max_u = std::max(u, max_u);
	}std::cout << max_u;
 
 
}

#include <iostream>
#include <vector>
#include <algorithm>
 
int main()
{
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++)
	{
		int n = 0;
		std::cin >> n;
		std::vector <int> h;
		for (int i = 0; i < n; i++)
		{
			int p = 0;
			std::cin >> p;
			h.push_back(p);
		}
		int m = 1000000001;
		int ans = h[0];
		for (int i = 1; i < n; i++)
		{
			ans = (ans & h[i]);
		}
		std::cout << ans << std::endl;
	}
}

#include <iostream>
#include <vector>
 
 
int main()
{
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w++)
	{
		int n = 0;
		std::cin >> n;
		int p = 0;
		std::vector <int> h;
		for (int i = 0; i < n; i++)
		{
			std::cin >> p;
			h.push_back(p);
		}
		int d = 0;
		int g = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if ((h[i] == 1) && (h[i + 1] == 1))
			{
				g += 5;
				//std::cout << g << " " << h[i];
				//continue;
			}
			else if (h[i] == 1)
			{
				g += 1;
				//std::cout << g << " " << i;
				//continue;
			}
			else if ((h[i] == 0) && (h[i + 1] == 0))
			{
				d += 1;
				break;
			}
		}
		if ((h[n - 1] == 1))
		{
 
			g += 1;
		}
		if (d > 0)
		{
			std::cout << -1 << std::endl;
		}
		else
		{
			std::cout << g << std::endl;
		}
	}
 
}

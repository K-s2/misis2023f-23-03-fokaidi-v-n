#include <iostream>
#include <vector>


int main()
{
	long long n = 0;
	long long t = 1;
	long long c = 0;
	long long m = 0;
	long long p = 0;
	std::cin >> n;
	std::cin >> m;
	std::vector <int> h;
	for (int i = 0; i < m; i++)
	{
		std::cin >> p;
		h.push_back(p);
	}
	for (int i = 0; i < m ; i++)
	{
		//std::cout << t << " " << h[i];
		if (t > h[i])
		{
			c += ((h[i]) + n - t);
			//std::cout << c << 'f' << std::endl;
		}
		else 
		{
			//std::cout << t << ' c ' << h[i] << std::endl;
			c += h[i] - t;
			//std::cout << c << 's' << std::endl;
		}
		t = h[i];
	}
	std::cout << c << std::endl;
}

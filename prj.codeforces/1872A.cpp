#include <iostream>
#include <cmath>
#include <vector>
 
int main()
{
	int d, n;
	double c, a, b, k;
	std::cin >> n;
	for (d = 1; d <= n; d++)
	{
		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
		k = std::abs(a - b) / 2;
		k = k / c;
		std::cout << std::ceil(k)<<std::endl;
	}
}

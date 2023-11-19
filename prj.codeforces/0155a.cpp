#include <iostream>
#include <vector>


int main()
{
	int n = 0;
	std::cin >> n;
	int w = 0;
	std::vector <int> res;
	for (int i = 0; i < n; i++)
	{
		std::cin >> w;
		res.push_back(w);
	}
	int ma = res[0];
	int mi = res[0];
	int c = 0;
	for (int i = 1; i < n; i++)
	{
		if (res[i] > ma)
		{
			ma = res[i];
			c += 1;
		}
		if (res[i] < mi)
		{
			mi = res[i];
			c += 1;
		}
	}
	std::cout << c;
}

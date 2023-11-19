#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n = 0;
	int ma = 0;
	std::cin >> n;
	std::vector<int> h;
	for (int i = 0; i < n; i++) {
		int p = 0;
		std::cin >> p;
		ma = std::max(ma, p);
		h.push_back(p);
	}
	int m2 = 0;
	int te = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] != ma)
		{
			if (m2 < h[i])
			{
				m2 = h[i];
				//std::cout << i << " ";
			}
		}
		else {
			te = i + 1;
		}
	}
	std::cout << te << " " << m2;
}

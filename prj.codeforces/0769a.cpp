#include <iostream>
#include <algorithm>

int main() {
	int n = 0;
	int ma = 0;
	int mi = 23123123123;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int k = 0;
		std::cin >> k;
		ma = std::max(ma, k);
		mi = std::min(mi, k);
	}
	std::cout << ( mi + ma)/2;
}

#include <iostream>
#include <string>

int ssum(int k) {
	int res = 0;
	while (k > 0) {
		res += (k%10);
		k = k / 10;
	}
	return res;
}


int main() {
	int t = 0;
	std::cin >> t;
	for (int w = 0; w < t; w ++){
		int x = 0;
		std::cin >> x;
		int k = 0;
		std::cin >> k;
		int c = 0;
		while (c == 0) {
			if (ssum(x) % k == 0) {
				std::cout << x<<std::endl;
				c += 1;
			}
			else {
				x++;
			}
		}
	}
	return 0;
}

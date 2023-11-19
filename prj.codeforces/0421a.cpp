#include <iostream>
#include <vector>

int main() {
	int n = 0;
	int a = 0;
	int b = 0;
	std::cin >> n;
	std::cin >> a;
	std::cin >> b;
	std::vector<int> h;
	std::vector<int> art;
	std::vector<int> pas;
	for (int i = 0; i < n; i++) {
		h.push_back(0);
	}
	int k = 0;
	for (int i = 0; i < a; i++) {
		std::cin >> k;
		art.push_back(k);
	}
	for (int i = 0; i < b; i++) {
		std::cin >> k;
		pas.push_back(k);
	}
	for (int i = 0; i < a; i++) {
		h[(art[i]) - 1] = 1;
	}
	for (int i = 0; i < b; i++) {
		h[(pas[i]) - 1] = 2;
	}
	for (int i = 0; i < n; i++) {
		std::cout << h[i]<<" ";
	}
}

#include <iostream>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string x, s;
    std::cin >> x >> s;
    for (int i = 0; i < 6; i++) {
        if (x.find(s) != std::string::npos) {
            std::cout << i << std::endl;
            return;
        }
        x += x;
    }
    std::cout << -1 << std::endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class B {
public:
    static void solve() {
        int tests;
        cin >> tests;
        for (int test = 0; test < tests; test++) {
            int n;
            cin >> n;
            string arr;
            cin >> arr;
            int k;
            cin >> k;
            bool special[26];
            memset(special, false, sizeof(special));
            for (int i = 0; i < k; i++) {
                string s;
                cin >> s;
                special[s[0] - 'a'] = true;
            }
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (special[arr[i] - 'a'])
                    idx = i;
            }
            int max_length = 0;
            for (int i = idx - 1; i >= 0; i--) {
                int j = i;
                while (j > 0 && !special[arr[j] - 'a'])
                    j--;
                max_length = max(max_length, i + 1 - j);
                i = j;
            }
            cout << max_length << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    B::solve();

    return 0;
}

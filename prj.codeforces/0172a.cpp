#include <iostream>
#include <string>

int main() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  int codeLength = s.length();

  for (int i = 1; i < n; i++) {
    std::string phoneNumber;
    std::cin >> phoneNumber;

    int j = 0;
    while (j < codeLength && j < phoneNumber.length() && s[j] == phoneNumber[j]) {
      j++;
    }

    codeLength = j;
  }

  std::cout << codeLength << std::endl;

  return 0;
}

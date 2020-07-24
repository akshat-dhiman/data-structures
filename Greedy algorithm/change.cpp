#include <iostream>

int get_change(int m) {
  //write your code here
  int sum_ = 0;
  sum_ += m/10;
  m %= 10;
  sum_ += m/5;
  m %= 5;
  sum_ += m;
  return sum_;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

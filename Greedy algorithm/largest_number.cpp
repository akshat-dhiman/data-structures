#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
bool sortit(string a, string b){
    return (a + b > b + a);
}

string largest_number(vector<string> a) {
  //write your code here
  string result;
  result = "";
  sort(a.begin(), a.end(), sortit);
  for(int i=0;i<a.size();i++)
    result += a[i];
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}

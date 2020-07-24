#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

void swap(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int divide(vector<int> &x, int l, int h){
    int i=l-1;
    for(int j=l;j<h;j++){
        if (x[j] < x[h]){
            i++;
            swap(&x[j], &x[i]);
        }
    }
    i++;
    swap(&x[i], &x[h]);
    return i;
}

void quicksort(vector<int> &x, int l ,int h){
    if (l < h){
        int pivot = divide(x, l, h);
        quicksort(x, l, pivot-1);
        quicksort(x, pivot+1, h);
    }
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  quicksort(a, 0, n-1);
  quicksort(b, 0, n-1);
  std::cout << max_dot_product(a, b) << std::endl;
}

// #include <iostream>
// #include <vector>
//
// using std::vector;
//
// double get_optimal_value(int capacity, vector<int> weights, vector<int> values, int n) {
//   long double value = 0.0;
//   vector<double> per_unit(n);
//   // write your code here
//   for(int i=0;i<n;i++)
//     per_unit[i] = (double)values[i]/weights[i];
//
//   while(capacity > 0 && !per_unit.empty()){
//       double max = 0;
//       int max_index;
//       for(int i=0;i<per_unit.size();i++){
//           if (max < per_unit[i]){
//             max = per_unit[i];
//             max_index = i;
//         }
//      }
//      // std::cout<<max<<std::endl;
//      int x = capacity < weights[max_index] ? capacity : weights[max_index];
//      capacity -= x;
//      value += x * per_unit[max_index];
//      per_unit.erase(per_unit.begin() + max_index);
//   }
//   return value;
// }
//
// int main() {
//   int n;
//   int capacity;
//   std::cin >> n >> capacity;
//   vector<int> values(n);
//   vector<int> weights(n);
//   for (int i = 0; i < n; i++) {
//     std::cin >> values[i] >> weights[i];
//   }
//
//   double optimal_value = get_optimal_value(capacity, weights, values, n);
//
//   std::cout.precision(10);
//   std::cout << optimal_value << std::endl;
//   return 0;
// }

#include <iostream>
#include <vector>

using std::vector;

int get_max_index(vector<int> weights, vector<int> values) {
    int max_i = 0;
    double max = 0;

    for (int i = 0; i < weights.size(); i++) {
        if (weights[i] != 0 && (double) values[i] / weights[i] > max) {
            max = (double) values[i] / weights[i];
            max_i = i;
        }
    }
    return max_i;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    for (int i = 0; i < weights.size(); i++) {
        if (capacity == 0) return value;
        int index = get_max_index(weights, values);
        int a = std::min(capacity, weights[index]);
        value += a * (double) values[index] / weights[index];
        weights[index] -= a;
        capacity -= a;
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool sort_(Segment a, Segment b){
    return (a.start < b.start);
}
vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  std::sort(segments.begin(), segments.end(), sort_);
  while(!segments.empty()){
      int left = segments[0].start;
      int right = segments[0].end, i = 0;
      segments.erase(segments.begin());
      while(i < segments.size()){
          if (segments[i].start > right || segments[i].end < left){
              i++;
              continue;
          }
          if (segments[i].start > left)
            left = segments[i].start;
          if (segments[i].end < right)
            right = segments[i].end;
          segments.erase(segments.begin() + i);
      }
      points.push_back(right);
  }
  // for (size_t i = 0; i < segments.size(); ++i) {
  //   points.push_back(segments[i].start);
  //   points.push_back(segments[i].end);
  // }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}

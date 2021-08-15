#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

class RouteManager {
public:
    void AddRoute(int start, int finish) {
    reachable_lists_[start].insert(finish);
    reachable_lists_[finish].insert(start);
    }
    int FindNearestFinish(int start, int finish) const {
        return getResult(start, finish);
    }
private:
    int getResult(int start, int finish) const {
        int result = abs(start - finish);
        if (reachable_lists_.count(start) < 1) {
            return result;
        }
        const set<int>& reachable_stations = reachable_lists_.at(start);
        auto greaterValue = reachable_stations.lower_bound(finish);
        auto lowerValue = greaterValue == reachable_stations.begin() ? greaterValue : prev(greaterValue);

        if(greaterValue != reachable_stations.end() && lowerValue != reachable_stations.end()) {
            return min(result, min(abs(*lowerValue - finish), abs(*greaterValue - finish)));
        } else if(greaterValue == reachable_stations.end() && lowerValue == reachable_stations.end()) {
            return result;
        } else if(greaterValue == reachable_stations.end()) {
            return min(result, abs(*lowerValue - finish));
        } else {
            return min(result, abs(*greaterValue - finish));
        }
    }
    map<int, set<int>> reachable_lists_;
};


int main() {
  RouteManager routes;
    vector<int> v;

  int query_count;
  cin >> query_count;
  for (int query_id = 0; query_id < query_count; ++query_id) {
    string query_type;
    cin >> query_type;
    int start, finish;
    cin >> start >> finish;
    if (query_type == "ADD") {
      routes.AddRoute(start, finish);
    } else if (query_type == "GO") {
      cout << routes.FindNearestFinish(start, finish) << "\n";
    }
  }

  return 0;
}

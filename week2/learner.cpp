#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <deque>

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    size_t oldSize = dict.size();
    dict.insert(words.begin(),  words.end());
    return dict.size() - oldSize;
  }

  vector<string> KnownWords() {
    return {dict.begin(), dict.end()};
  }
};

int main() {
    deque<int> v;
    v.pus
    Learner learner;
    string line;
    while (getline(cin, line)) {
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        cout << learner.Learn(words) << "\n";
    }
    cout << "=== known words ===\n";
    for (auto word : learner.KnownWords()) {
        cout << word << "\n";
    }
}

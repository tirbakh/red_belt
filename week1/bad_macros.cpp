#include <string>
#include <vector>
using namespace std;

#define CONCAT2(uniq) v##uniq
#define CONCAT(uniq) CONCAT2(uniq)
#define UNIQ_ID CONCAT(__LINE__)

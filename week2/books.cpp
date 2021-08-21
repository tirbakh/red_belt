#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

class ReadingManager {
public:
    void Read(int userId, int pageCount) {
        if(usersToPage.count(userId)) {
            int userLastPage = usersToPage[userId];
            if(pagesToUsers[userLastPage].size() == 1) {
                pagesToUsers.erase(userLastPage);
            } else {
                pagesToUsers[userLastPage].erase(userId);
            }
        }

        usersToPage[userId] = pageCount;
        pagesToUsers[pageCount].insert(userId);
    }

    double Cheer(int userId) const {
        if (!usersToPage.count(userId)) {
            return 0;
        }
        const size_t usersCount = usersToPage.size();
        if (usersCount == 1) {
            return 1;
        }

        const auto userPos = pagesToUsers.find(usersToPage.at(userId));
        const size_t worseUsers = GetWorseUsersCount(userPos);

        return worseUsers * 1.0 / (usersCount - 1);
    }

private:
    template<typename It>
    size_t GetWorseUsersCount(const It userIt) const {
        size_t count = 0;
        for(It it = pagesToUsers.begin(); it != userIt; it++) {
            count += it->second.size();
        }
        return count;
    }

    map<int, int> usersToPage;
    map<int, set<int>> pagesToUsers;
};


int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int userId;
        cin >> userId;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(userId, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(userId) << "\n";
        }
    }

    return 0;
}
#include <iostream>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct Event {
    uint64_t timestamp;
    string hotelName;
    uint clientId;
    uint roomCount;
};

class Hotel {
public:
    void book(uint64_t timestamp, const string& hotelName, uint clientId, uint roomCount) {
        adjust(timestamp);
        events.push({timestamp, hotelName, clientId, roomCount});
        clientsByHotel[hotelName].insert(clientId);
        bookedRoomsByHotel[hotelName] += roomCount;
    }

    uint clients(const string& hotelName) const {
        if(clientsByHotel.count(hotelName)) {
            //cout << "clientsByHotel.at(hotelName).size(): " << clientsByHotel.at(hotelName).size() << endl;
            return clientsByHotel.at(hotelName).size();
        }

        return 0;
    }

    uint rooms(const string& hotelName) const {
        if(bookedRoomsByHotel.count(hotelName)) {
            //cout << "bookedRoomsByHotel.at(hotelName): " << bookedRoomsByHotel.at(hotelName) << endl;
            return bookedRoomsByHotel.at(hotelName);
        }

        return 0;
    }

private:
    void adjust(uint64_t timestamp) {
        while(!events.empty() && timestamp - events.front().timestamp >= SECONDS_IN_DAY) {
            const Event& event = events.front();
            clientsByHotel[event.hotelName].erase(event.clientId);
            bookedRoomsByHotel[event.hotelName] -= event.roomCount;
            events.pop();
        }
    }

    map<string, set<uint>> clientsByHotel;
    map<string, uint> bookedRoomsByHotel;
    queue<Event> events;
    static const int SECONDS_IN_DAY = 86400;
};

int main() {
    Hotel hotel;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        string query, hotelName;
        cin >> query;

        if(query == "BOOK") {
            uint64_t timestamp;
            uint clientId, roomCount;
            cin >> timestamp >> hotelName >> clientId >> roomCount;
            hotel.book(timestamp, hotelName, clientId, roomCount);
        } else if(query == "CLIENTS") {
            cin >> hotelName;
            cout << hotel.clients(hotelName) << "\n";
        } else if(query == "ROOMS") {
            cin >> hotelName;
            cout << hotel.rooms(hotelName) << "\n";
        }

    }

}
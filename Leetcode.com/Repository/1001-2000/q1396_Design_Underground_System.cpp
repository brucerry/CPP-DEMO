// https://leetcode.com/problems/design-underground-system/

#include <string>
#include <map>
#include <unordered_map>
using namespace std;

// time: O(1) for each method
// space: O(n)

class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> record_in; // id, { check_in_station, time }
    map<pair<string, string>, pair<double, int>> record_time; // { start_station, end_station }, { total_time, count }

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        record_in[id] = { stationName, t };
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [ checkin_station, checkin_time ] = record_in[id];
        int time_taken = t - checkin_time;
        auto& [ total_time, count ] = record_time[{ checkin_station, stationName }];
        total_time += time_taken;
        count++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& [ total_time, count ] = record_time[{ startStation, endStation }];
        return total_time / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
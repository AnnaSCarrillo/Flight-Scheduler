#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class FlightTimes {
    public:
        FlightTimes(string CurrTime, bool IsDeparture, string Location) {
            currTime = CurrTime;
            isDeparture = IsDeparture;
            location = Location;
        }
        string GetTime() const {return currTime;};
        bool GetDeparture() const {return isDeparture;};
        string GetLocation() const {return location;};
    private:
        string currTime;
        bool isDeparture;
        string location;
};

class TimeBlocks {
    public:
    private:
};

class Time {
    public:
    private:
};

int main() {

    FlightTimes test("0630", true, "Boston");

    cout << test.GetTime() << " " << test.GetDeparture() << " " << test.GetLocation() << endl;

    return 0;
}
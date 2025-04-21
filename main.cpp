#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
        Time(string TimeString) {
            SetHourMinutes(TimeString);
            totalMinutes = (hour * 60) + minutes;
        }

        void SetHourMinutes(const string& TimeString) {
            hour = stoi(TimeString.substr(0, 2));
            minutes = stoi(TimeString.substr(2, 2));
        }

        string ToString() {
            int h = hour;
            int m = minutes;
            stringstream ss;
            if (h < 10) ss << "0";
            ss << h;
            if (m < 10) ss << "0";
            ss << m;

            return ss.str();
        }

        void AdjustTime(int delta) {
            totalMinutes += delta;

            totalMinutes = (totalMinutes + 1440) % 1440;
            hour = totalMinutes / 60;
            minutes = totalMinutes % 60;
        }
    private:
        int hour;
        int minutes;
        int totalMinutes;
};

int main() {

    FlightTimes test("0630", true, "Boston");

    Time testTime(test.GetTime());

    cout << testTime.GetHour() << " " << testTime.GetMinutes() << endl;

    return 0;
}
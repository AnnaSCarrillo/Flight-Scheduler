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

        void ToString() {
            int h = hour;
            int m = minutes;
            stringstream ss;
            if (h < 10) ss << "0";
            ss << h;
            if (m < 10) ss << "0";
            ss << m;

            finalTime = ss.str();
        }

        void AdjustTime(int delta) {
            totalMinutes += delta;

            totalMinutes = (totalMinutes % 1440 + 1440) % 1440;
            hour = totalMinutes / 60;
            minutes = totalMinutes % 60;

            ToString();
        }

        string getFinalString() const {return finalTime;};
    private:
        int hour;
        int minutes;
        int totalMinutes;
        string finalTime;
};

int main() {

    FlightTimes test("0630", true, "Boston");

    Time testTime(test.GetTime()); 

    //Testing 

    testTime.AdjustTime(60);
    cout << "60 " << (testTime.getFinalString() == "0730") << endl;

    testTime.AdjustTime(-60);
    cout << "-60 " << (testTime.getFinalString() == "0630") << endl;

    testTime.AdjustTime(150);
    cout << "150 " << (testTime.getFinalString() == "0900") << endl;

    testTime.AdjustTime(-150);
    cout << "-150 " << (testTime.getFinalString() == "0630") << endl;

    testTime.AdjustTime(2880);
    cout << "2880 " << (testTime.getFinalString() == "0630") << endl;

    testTime.AdjustTime(30);
    cout << "30 " << (testTime.getFinalString() == "0700") << endl;

    testTime.AdjustTime(-30);
    cout << "-30 " << (testTime.getFinalString() == "0630") << endl;

    testTime.AdjustTime(0);
    cout << "0 " << (testTime.getFinalString() == "0630") << endl;

    testTime.AdjustTime(1440);
    cout << "1440 " << (testTime.getFinalString() == "0630") << endl;

    testTime.AdjustTime(1441);
    cout << "1441 " << (testTime.getFinalString() == "0631") << endl;

    testTime.AdjustTime(-1441);
    cout << "-1441 " << (testTime.getFinalString() == "0630") << endl;

    testTime.AdjustTime(68);
    cout << "68 " << (testTime.getFinalString() == "0738") << endl;

    testTime.AdjustTime(-68);
    cout << "-68 " << (testTime.getFinalString() == "0630") << endl;

    return 0;
}
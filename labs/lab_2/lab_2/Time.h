using namespace std;
class Time{
public:
    Time();
    Time(int hour, int minute, int second);
    
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    
private:
    int hour;
    int minute;
    int second;
};
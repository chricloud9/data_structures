using namespace std;
class Time{
public:
    Time();
    Time(uintptr_t hour, uintptr_t minute, uintptr_t second);
    
    uintptr_t getHour() const;
    uintptr_t getMinute() const;
    uintptr_t getSecond() const;
    
    void setHour(uintptr_t h);
    void setMinute(uintptr_t m);
    void setSecond(uintptr_t s);
    void change_times(const Time& t1, const Time& t2);
    
    void printAmPm();
    
    bool isEarlierThan(const Time& t1, const Time& t2);
    
private:
    uintptr_t hour;
    uintptr_t minute;
    uintptr_t second;
};
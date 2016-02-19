using namespace std;
class Time{
public:
    Time();
    Time(int hour, int minute, int second);
    
    int getHour() const;
    int getMinute() const;
    int getSecond() const;
    
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    
    void printAmPm();
    
   
    
private:
    int hour;
    int minute;
    int second;
};
 bool isEarlierThan(const Time& t1, const Time& t2);
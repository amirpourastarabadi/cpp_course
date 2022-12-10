#include <iostream>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year)
    {
        set_date(day, month, year);
    }

    void set_date(int day, int month, int year)
    {
        if (
            day < 0 || day > 31 || month < 0 || month > 12 || year < 0 ||
            (month < 7 && day > 31) ||
            (month < 12 && day > 30))
            throw exception();

        this->day = day;
        this->month = month;
        this->year = year;
    }
    void get_date()
    {
        cout << day << "-" << month << "-" << year << endl;
    }
};

int main()
{
    Date d(4, 5, 6);
    d.get_date();
    return 0;
}
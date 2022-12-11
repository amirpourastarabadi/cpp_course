#include <iostream>
#include <string>

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

    Date()
    {
        set_date(1, 1, 0);
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
    
    // getters
    string get_date() { return "" + to_string(day) + '-' + to_string(month) + '-' + to_string(year); }
    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }

    int diff_in_days(Date date)
    {
        int diff = 0;

        while (!this->is_equals(date))
        {
            date.add_days();
            diff++;
        }

        return diff;
    }

    bool is_equals(Date date)
    {
        return day == date.day && month == date.month && year == date.year;
    }

    void add_days(int amount = 1)
    {
        day++;
        if (month >= 1 && month <= 6 && day > 31)
        {
            month += 1;
            day = day % 31;
        }
        else if (month >= 7 && day > 30)
        {
            month += 1;
            day = day % 30;

            if (month > 12)
            {
                year += 1;
                month %= 12;
            }
        }
    }
};

int main()
{
    Date d(4, 5, 6);
    cout << d.get_date() << endl;
    cout << "Day = " << d.get_day() << endl;
    cout << "Month = " << d.get_month() << endl;
    cout << "Year = " << d.get_year() << endl;

    Date big(1, 1, 2);
    Date small(1, 1, 1);
    int diff = big.diff_in_days(small);

    cout << "Diff days = " << diff << endl;
    return 0;
}
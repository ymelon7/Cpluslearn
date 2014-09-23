/*************************************************************************
	> File Name: Date.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Tue 23 Sep 2014 04:55:56 AM PDT
 ************************************************************************/
#include "Date.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

const int Date::kDaysOfMonth[2][12] =
{
    {31,28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},   // common year days of each month 
    {31,29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

const string Date::kNameOfMonth[12] = 
{
    "January", "February", "March", "April", "May", "June", 
   "July", "August", "September", "October", "November", "December"
};

Date::Date()
    :year_(0),
    month_(0),
    day_(0)
{ }

Date::Date(int year, 
           int month, 
            int day)
    :year_(year),
    month_(month),
    day_(day)
{ }

bool Date::isLeapYear() const
{
    // attention here, should write statements streamline 
    return ((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0); 
}

bool Date::isValid() const
{
   return (year_ > 0 
          && month_ > 0
          && month_ <= 12
          && day_ > 0
          && day_ <= kDaysOfMonth[isLeapYear()][month_ - 1]);
   // month_ is the actual month, elem in array is subcrip, so need to - 1
}

void Date::assertValid() const
{
    // if the date invalid, abort the process
    if(!isValid())
        abort();
}


int Date::calDaysOfYear() const
{
   assertValid();  // date if valid

   int leap = isLeapYear();  // explain ? bool to int 
   int result = 0;
   for(int cnt = 1; cnt < month_; cnt ++)
   {
        // cnt is the actual month num
        result += kDaysOfMonth[leap][cnt - 1];
   }
   result += day_;

   return result;
}

int Date::calLeftDaysOfYear() const
{
    assertValid();

    bool leap = isLeapYear();
    int days = calDaysOfYear();

    if(leap == true)
        return (366 - days);
    else
        return (365 - days);
}

int Date::compareDate(const Date &other) const
{
    assertValid();
    other.assertValid();
    // attention  this if's logic  here , learn it
    int res = year_ - other.year_;
    if(res == 0)
        res = month_ - other.month_;
    if(res == 0)
        res = day_ - other.day_;

    return res;
}

void Date::setDate(int year, int month, int day)
{
    year_ = year;
    month_ = month;
    day_ = day;
}

void Date::setToday()
{
    time_t now = 0;
    time(&now);
    struct tm loc;
    struct tm *pt = localtime_r(&now, &loc);
    if(pt == NULL)
    {
        perror("localtime_r");
        exit(EXIT_FAILURE);
    }
    
    year_ = 1900 + loc.tm_year;
    month_ = 1 + loc.tm_mon;
    day_ = loc.tm_mday;
}

string Date::toString() const
{
    assertValid();

    char text[80] = {0};
    snprintf(text, sizeof text, "%04d/%02d/%02d", year_, month_, day_);

    return string(text);
}

string Date::toFormatString() const
{
    assertValid();
    
    char text[80] = {0};
    snprintf(text, sizeof text, "%s %02d %04d", kNameOfMonth[month_ - 1].c_str(), day_ , year_);
    
    return string(text);
}

int Date::diffDate(const Date &d1, const Date &d2)
{
    Date t1, t2;
    int diff = d1.compareDate(d2);

    if(diff == 0)  // date equal,
        return 0;
    // ensure large - small, t1 - t2
    else if(diff > 0)
    {
        t1 = d1;
        t2 = d2;
    }
    else
    {
        t1 = d2;
        t2 = d1;
    }

    int days = 0;
    for(int ix = t1.year_; ix < t2.year_; ix ++)
    {
        bool leap = ( (ix % 4 == 0 && ix %100 != 0) || ix % 400 == 0);
        days += ( (leap == true) ? 366 : 365);     
    }
    days += t2.calDaysOfYear();
    days -= t1.calDaysOfYear();

    return days;
}





























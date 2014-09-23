/*************************************************************************
	> File Name: Date.h
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Mon 22 Sep 2014 06:10:00 PM PDT
 ************************************************************************/
#ifndef _DATE_H_
#define _DATE_H_

#include <string>

class Date
{
    private:
        int   year_;
        int   month_;
        int   day_;

        static const int kDaysOfMonth[2][12];
        static const std::string kNameOfMonth[12];
    public:
        Date();
        Date(int year, int month, int day);

        void assertValid() const;
        bool isValid() const;
        bool isLeapYear() const;
        int calDaysOfYear() const;
        int calLeftDaysOfYear() const;
        int compareDate(const Date &other) const;

        void setDate(int year, int month, int day);
        void setToday();

        std::string toString() const;
        std::string toFormatString() const;

        int getYear() const      // inline functions
        {return year_;}

        int getMonth() const
        {return month_;}

        int getDay()
        {return day_;}
        
        static int diffDate(const Date &t1, const Date &t2);

};
#endif /*_DATE_H_*/


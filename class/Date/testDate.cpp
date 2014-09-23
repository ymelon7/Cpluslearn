/*************************************************************************
	> File Name: pro1Cla.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Mon 22 Sep 2014 05:58:25 PM PDT
 ************************************************************************/
#include "Date.h"
#include <iostream>
#include <string>
//#include <assert.h>
using namespace std;

int main (int argc, char *argv[])
{
    Date d;
   // d.assertValid();

    d.setToday();
    cout << "today: " << d.toString() << endl;
    cout << "today format: " << d.toFormatString() << endl;

    cout << "today is 2014's " << d.calDaysOfYear() << "day" << endl;
    cout << "this year left " << d.calLeftDaysOfYear() << "day" << endl;
}

/*************************************************************************
	> File Name: test_main.cpp
	> Author: Melon
	> Mail:ymelon7@gmail.com 
	> Created Time: Wed 24 Sep 2014 06:37:41 AM PDT
 ************************************************************************/
#include "Word.h"

using namespace std;

int main (int argc, char *argv[])
{
    Word word;
    word.wFre("The_Holy_Bible.txt");
    word.print();
}

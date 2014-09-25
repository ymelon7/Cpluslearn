#include "Word.h"
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

Word::Word()
{
    words_.clear();
    stopList_.clear();
    loadStopList("stoplist.txt"); 
}

void Word::loadStopList(const string &filename)
{
    ifstream in(filename.c_str());
    if(!in)
        throw runtime_error("load stoplist file error");

    string word;
    word.clear();
    while(in >> word)
    {
        stopList_.insert(word);
    }
}

void Word::wFre(const string &filename)
{
   ifstream in(filename.c_str());
   if(!in)
       throw runtime_error("open file error");

   string word;
   while(in >> word)
   {
        trimPunct(word);
        if(isStop(word))
            continue;

        words_[word] ++; 
   }
}

void Word::trimPunct(string &word)
{
    string::iterator it = word.begin();
    while(it != word.end())
    {
        if(ispunct(*it))
            it = word.erase(it);
        else
            it ++;
    }
}

bool Word::isStop(const string &word) const
{
   set<string>::iterator it = stopList_.find(word);
    if(it != stopList_.end()) // is stopword
        return true;
    else
        return false;
}

void Word::print() const 
{
    vector<pair<string, int> > result;
    result.clear();

    map<string, int>::const_iterator map_it = words_.begin();
    while(map_it != words_.end())
    {
        result.push_back(*map_it);
        map_it ++;
    }

    sort(result.begin(), result.end(), cmp);

    vector<pair<string, int> >::iterator it = result.begin();
    while(it != result.end())
    {
        cout << it->first << ": " << it->second << endl;
        it ++;
    }
}

bool Word::cmp(const pair<string, int> &p1, const pair<string, int> &p2)
{
    return p1.second > p2.second;
}

#ifndef _WORD_H_
#define _WORD_H_

#include <string>
#include <map>
#include <set>

class Word
{
    private:
        std::map<std::string, int> words_;
        std::set<std::string> stopList_;
    public:
        Word();
        void loadStopList(const std::string &filename);
        void wFre(const std::string &filename);
        void trimPunct(std::string &word);
        bool isStop(const std::string &word) const;
        void print() const;

        static  bool cmp(const std::pair<std::string, int> &p1, const std::pair<std::string, int> &p2);
        //attention this , static is needed
};

#endif /* _WORD_H_ */

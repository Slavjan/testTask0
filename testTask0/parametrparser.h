#ifndef PARAMETRPARSER_H
#define PARAMETRPARSER_H

#include <string>
#include <vector>
#include <map>
#include <functional>

using std::string;
using std::map;
using std::vector;
using std::function;

class ParametrParser
{
private:
    typedef function<void(string)> func;
    char optionLetter = '-';

    int _argc;
    vector<string> _argv;
    map<string, func> _shortCallback;
    map<string, func> _longCallback;

    bool isOption(string);
    bool isShortOption(string);
    bool isLongOption(string);

public:
    ParametrParser(int argc, char** argv);
    void setOption(string shortKey, string longKey, func callback);
    void setShortOption(string key, func callback);
    void setLongOption(string key, func callback);
    bool exec();

    class UnknownOption{
    public:
        string optionName;
        UnknownOption(string opt){optionName=opt;}
    };
};

#endif // PARAMETRPARSER_H

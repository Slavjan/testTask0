#include "parametrparser.h"


#include <iostream>

bool ParametrParser::isOption(std::string str)
{
    if( str[0] == optionLetter )
        return true;
    return false;
}

bool ParametrParser::isShortOption(std::string str)
{
    if( str[0] == optionLetter && str[1] != optionLetter )
        return true;
    return false;
}

bool ParametrParser::isLongOption(std::string str)
{
    if( str[0] == optionLetter && str[1] == optionLetter )
        return true;
    return false;
}

ParametrParser::ParametrParser(int argc, char **argv)
{
    _argc = argc;
    for(int i = 0; i < argc; ++i){
        _argv.push_back( argv[i] );
//        std::cout << _argv.back() << std::endl;
    }
}

void ParametrParser::setOption(std::string shortKey, std::string longKey, ParametrParser::func callback)
{
    _longCallback["--"+longKey]   = callback;
    _shortCallback["-"+shortKey] = callback;
}

void ParametrParser::setShortOption(std::string key, ParametrParser::func callback)
{
    _shortCallback["-"+key] = callback;
}

void ParametrParser::setLongOption(std::string key, ParametrParser::func callback)
{
    _longCallback["--"+key] = callback;
}

bool ParametrParser::exec()
{
    string opt;
    try{
        for(size_t i = 0; i < _argv.size(); ++i){
            if( ! isOption( _argv[i] ) )
                continue;
            opt = _argv[i];
            if( isShortOption( _argv[i] ) ){
                _shortCallback[ _argv[i] ]( ( i+1 < _argv.size() )?_argv[i+1]:"" );
                continue;
            }
            if( isLongOption( _argv[i] ) ){
                _longCallback[ _argv[i] ]( ( i+1 < _argv.size() )?_argv[i+1]:"" );
                continue;
            }
        }
    }catch( std::bad_function_call ){
        throw UnknownOption(opt);
        return false;
    }catch(...){
        std::cerr << "Unknown error" << std::endl;
    }
    return true;
}

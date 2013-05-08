#include "StringToint.h"

StringToint::StringToint()
{
    //ctor
}

StringToint::~StringToint()
{
    //dtor
}
std::string StringToint::toString(int number)
{
    if (number == 0)
        return "0";
    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

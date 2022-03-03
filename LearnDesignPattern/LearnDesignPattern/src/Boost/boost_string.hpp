#ifndef BOOST_STRING_HPP
#define BOOST_STRING_HPP

#include "../Utility/common.h"
#include <boost/algorithm/string.hpp>
#include <vector>
using namespace std;

void is_star()
{
}

void testBoostString1()
{
    string str = "asdfa*sd*f**asdf";
    vector<string> list;
    boost::split(list, str, boost::is_any_of("*"), boost::token_compress_on);
    for (size_t i = 0; i < list.size(); i++)
    {
        cout << list[i] << endl;
    }
    string str2 = boost::join(list, "&");
    //boost::join(list, "%", is_star); ?
    cout << str2 << endl;
}

#endif //! BOOST_STRING_HPP
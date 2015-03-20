#ifndef STRINGUTILS_H_2015_3_20_RENREN
#define STRINGUTILS_H_2015_3_20_RENREN

#include <iconv.h>
#include <iostream>
using namespace std;
#include <boost/locale.hpp>

namespace StringUtils {
    inline string gbk2utf(const char* str) {
        return boost::locale::conv::to_utf<char>(str, "GBK");
    }

} // namespace Stringutils
#endif

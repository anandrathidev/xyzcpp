
#include "StrUtils.h"

void split_quoted(const std::string& str, std::vector<std::string>& v) {
    size_t i = 0, j = 0, begin = 0;
    while (i < str.size()) {
        if (str[i] == ' ' || i == 0) {
            if (i + 1 < str.size() && str[i + 1] == '\"') {
                j = begin + 1;
                while (j < str.size() && str[j++] != '\"');
                v.push_back(std::string(str, begin, j - 1 - i));
                begin = j - 1;
                i = j - 1;
                continue;
            }

            j = begin + 1;
            while (j < str.size() && str[j++] != ' ');
            v.push_back(std::string(str, begin, j - 1 - i - (i ? 1 : 0)));
            begin = j;
        }
        ++i;
    }
}
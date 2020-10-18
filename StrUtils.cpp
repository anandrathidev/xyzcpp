
#include "StrUtils.h"

void move_till_nospace(int& i, const std::string& command) {
    int len = command.length();
    while (i < len && (command[i] == ' ' || command[i] == '\t')) i++;
}


void split_in_args(std::vector<std::string>& qargs, const std::string& command) {
    int len = command.length();
    bool qot = false, sqot = false;
    bool eq = false;
    int arglen = 0;
    for (int i = 0; i < len; i++) {
        move_till_nospace(i, command);
        int start = i;
        while (i < len && command[i] != '=')
            i++;
        if (command[i] == '=') {
            i++;
            move_till_nospace(i, command);
            bool qot = false, sqot = false;
            if (command[i] == '"') {
                qot = true;
            }
            else if (command[i] == '\'') sqot = true;
            if (qot) {
                i++;
                while (i < len && command[i] != '"')
                    i++;
                if (i < len)
                    qot = false;
            }
            else if (sqot) {
                i++;
                while (i < len && command[i] != '\'')
                    i++;
                if (i < len)
                    sqot = false;
            }
            else {
                while (i < len && (command[i] != ' ')) {
                    i++;
                }
            }
            qargs.push_back(command.substr(start, i));
        }
    }
}



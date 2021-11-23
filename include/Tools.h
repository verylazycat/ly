//
// Created by admin233 on 2021/11/23.
//

#ifndef LY_TOOLS_H
#define LY_TOOLS_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Utils.h"
using namespace std;
class Tools {
private:
    string failbanconfig = "/etc/fail2ban/jail.conf";
public:
    bool CheckFailBanConfig(void);
};


#endif //LY_TOOLS_H

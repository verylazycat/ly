//
// Created by admin233 on 2022/01/20.
//

#ifndef LY_SQUID_H
#define LY_SQUID_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Utils.h"
using namespace std;
class Squid {
private:
    string confpath =  "/etc/squid/squid.conf";
public:
    bool CheckConfigFile(void);
    void CheckSquidStatus(void);
};


#endif //LY_SQUID_H

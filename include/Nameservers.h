//
// Created by admin233 on 2021/11/21.
//

#ifndef LY_NAMESERVERS_H
#define LY_NAMESERVERS_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Utils.h"
using namespace std;
class Nameservers {
private:
    string resolvpath =  "/etc/resolv.conf";
public:
    bool CheckConfigFile(void);
    void CheckDNS(void);
};

#endif //LY_NAMESERVERS_H

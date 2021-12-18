//
// Created by admin233 on 2021/12/16.
//

#ifndef LY_NETWORKING_H
#define LY_NETWORKING_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Utils.h"
using namespace std;
class NetWorking {
private:    
    //The file must exist
    string hostConf = "/etc/hosts";
public:
// https://www.cnblogs.com/cangqinglang/p/13343469.html
    void HostsParsing(void);
    void NicStatus(void);
    // https://www.cnblogs.com/sztom/p/10810508.html
    void ss(void);
    void arp(void);
};

#endif //LY_NETWORKING_H

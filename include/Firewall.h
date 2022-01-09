//
// Created by admin233 on 2022/1/9.
//

#ifndef LY_FIREWALL_H
#define LY_FIREWALL_H
#include "Utils.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
using namespace std;
class Firewall {
public:
    bool CheckIptableInstall(void);
    void GetIptabelse(void);
};


#endif //LY_FIREWALL_H

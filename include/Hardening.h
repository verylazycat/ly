//
// Created by admin233 on 2021/12/8.
//

#ifndef LY_HARDENING_H
#define LY_HARDENING_H
#include "Utils.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
using namespace std;
class Hardening {
public:
    void CheckGCC();
    void CheckGPP();
    void CheckCMAKE();
};


#endif //LY_HARDENING_H
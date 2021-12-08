//
// Created by admin233 on 2021/12/8.
//

#ifndef LY_KERNEL_H
#define LY_KERNEL_H
#include "Utils.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
using namespace std;
class Kernel {
private:
    string cpuinfo = "/proc/cpuinfo";
public:
    bool CheckCPUINIFO(void);
    void CheckPAE(void);
    void CheckCoreDumpOK(void);
};


#endif //LY_KERNEL_H

//
// Created by admin233 on 2021/11/29.
//

#ifndef LY_PROCESSES_H
#define LY_PROCESSES_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Utils.h"
using namespace std;
class Processes {
public:
// https://developer.aliyun.com/article/555362
    void RetrievingZombieProcesses(void);
    // https://blog.csdn.net/donglynn/article/details/80041144
    // void FindIoTop(void);
};


#endif //LY_PROCESSES_H

//
// Created by admin233 on 2021/11/18.
//

#ifndef LY_LOGGING_H
#define LY_LOGGING_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Utils.h"
using namespace std;
class Logging {
private:
    string logconf = "/etc/rsyslog.conf";
    string conf = "/etc/audit/audit.conf";
public:
// https://blog.csdn.net/sunny_na/article/details/65444602
// https://cloud.tencent.com/developer/article/1459390
// https://blog.csdn.net/GentleCP/article/details/87918664
// https://blog.csdn.net/xiayun1995/article/details/83962934
    bool CheckLogConfFile(void);
    void AuditConfiguration(void);
    void AuditLog(void);
};

#endif //LY_LOGGING_H

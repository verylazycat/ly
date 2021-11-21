//
// Created by admin233 on 2021/11/21.
//

#ifndef LY_SSH_H
#define LY_SSH_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "Utils.h"
using namespace std;
class SSH {
private:
    string sshconfig = "/etc/ssh/ssh_config";
public:
    bool CheckSSHConfig(void);
    void AuditSSHConfig(void);
};


#endif //LY_SSH_H

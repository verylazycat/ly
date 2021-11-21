//
// Created by admin233 on 2021/11/21.
//

#include "SSH.h"
bool SSH::CheckSSHConfig(void){
    int fd = open(this->sshconfig.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
void SSH::AuditSSHConfig(void){
    auto logger = spdlog::basic_logger_mt("AuditSSHConfig_logger", "logs/basic-log.txt");
    if (!this->CheckSSHConfig()){
        spdlog::critical("ssh_config does not exist!");
        logger->critical("ssh_config does not exist!");
        return;
    }
    //TODO:文件权限
    //TODO:安全配置
    // https://blog.csdn.net/samginshen/article/details/104852042
    
}
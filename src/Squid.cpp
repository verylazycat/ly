//
// Created by admin233 on 2022/01/20.
//

#include "Squid.h"

bool Squid::CheckConfigFile(void){
    int fd = open(this->confpath.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
void Squid::CheckSquidStatus(void){
    auto logger = spdlog::basic_logger_mt("CheckSquidStatus_logger", "logs/basic-log.txt");
    if (!this->CheckConfigFile()){
        spdlog::critical("squid.conf does not exist!");
        logger->critical("squid.conf does not exist!");
        return;
    }
    //status
    const char *cmd = "sudo systemctl status squid | grep -E \"Active\"";
    char res[10000];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    spdlog::info("{}",res);
    logger->info("{}",res);
    Utils::updatebyip("LY-core","Squid","status",string(res));
    /// pid
    cmd = "sudo systemctl status squid | grep -E \"PID\"";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    spdlog::info("{}",res);
    logger->info("{}",res);
    Utils::updatebyip("LY-core","Squid","pid",string(res));
    //version
    cmd = "squid --version  | grep Version | awk '{print $4}'";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    spdlog::info("squid version:{}",res);
    logger->info("squid version:{}",res);
    Utils::updatebyip("LY-core","Squid","version",string(res));
    //bit
    cmd = "ls -la /etc/squid/squid.conf | awk '{print$1}'";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    spdlog::info("squid permissions:{}",res);
    logger->info("squid permissions:{}",res);
    Utils::updatebyip("LY-core","Squid","bit",string(res));
}
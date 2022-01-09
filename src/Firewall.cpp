//
// Created by admin233 on 2022/1/9.
//

#include "Firewall.h"
bool Firewall::CheckIptableInstall(void){
    auto logger = spdlog::basic_logger_mt("CheckIptableInstall_logger", "logs/basic-log.txt");
    const char *cmd = "which iptables";
    char res[1024];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    if (Utils::KMPsearch(res,"not found")){
        return false;
    }
    else
        return true;
}

void Firewall::GetIptabelse(void){
    auto logger = spdlog::basic_logger_mt("GetIptabelse_logger", "logs/basic-log.txt");
    const char *cmd = "sudo iptables -L";
    if (!CheckIptableInstall()){
        //not install
        spdlog::critical("you are not install iptbels!");
        logger->critical("you are not install iptbels!");
        return;
    }
    //install 
    char res[10000];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    spdlog::info("iptables rules:\n{}",res);
    logger->info("iptables rules:\n{}",res);
    return;
}
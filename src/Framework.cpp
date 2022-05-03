//
// Created by admin233 on 2021/12/26.
//


#include "Framework.h"
void Framework::apparmor_status(void){
    auto logger = spdlog::basic_logger_mt("apparmor_status_logger", "logs/basic-log.txt");
    const char *cmd = "sudo apparmor_status";
    char res[10240];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    spdlog::info("apparmor_status:{}\n",res);
    logger->info("apparmor_status:{}\n",res);
    Utils::updatebyip("LY-core","Framework","apparmor_status",string(res));
}
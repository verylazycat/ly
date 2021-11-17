//
// Created by admin233 on 2021/11/17.
//
#include "Printing.h"
//https://www.jianshu.com/p/0868dd2d5418
void Printing::CheckCUPSPermissions(void){
    auto logger = spdlog::basic_logger_mt("CheckCUPSPermissions_logger", "logs/basic-log.txt");
    // -rwxr-xr-x : cupsfilter
    const char *cmd = "ls -la /sbin/cupsfilter | awk '{print $1}'";
    char res[1024] = "";
    Utils::executeCMD(cmd,res);
    if (Utils::KMPsearch(res,"-rwxr-xr-x")){
        spdlog::info("CUPS permission security");
        logger->info("CUPS permission security");
        return;
    }
    spdlog::critical("CUPS permission not security");
    logger->critical("CUPS permission not security");
    return;
}
//
// Created by admin233 on 2021/11/29.
//

#include "Processes.h"

// https://developer.aliyun.com/article/555362
void Processes::RetrievingZombieProcesses(){
    auto logger = spdlog::basic_logger_mt("RetrievingZombieProcesses_logger", "logs/basic-log.txt");
    const char *cmd = "ps -A -ostat,ppid,pid,cmd | grep -e '^[Zz]' | awk '{print $2}'";
    char res[1024];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    string copy_res = "";
    for(char c :res){
        copy_res += c;
    }
    if (copy_res.empty()){
        spdlog::info("No zombie progression");
        logger->info("No zombie progression");
        return;
    }
    char pid[1024];
    bzero(pid,sizeof(pid));
    int index = 0;
    for (char c : copy_res){
        pid[index++] = c;
        if (c == '\n'){
            spdlog::critical("zombie progression pid:{}",pid);
            logger->critical("zombie progression pid:{}",pid);
            index = 0;
            bzero(pid,sizeof(pid));
            continue;
        }
    }
}
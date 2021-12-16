//
// Created by admin233 on 2021/12/16.
//

#include "Networking.h"
void NetWorking::HostsParsing(){
    auto logger = spdlog::basic_logger_mt("HostsParsing_logger", "logs/basic-log.txt");
    ifstream in(this->hostConf);
    string line;
    if (in){
        while (getline(in,line)){
            if (Utils::KMPsearch(line,"#") || line.empty()){
                continue;
            }
            else{
                spdlog::info("IP-DOMAIN:{}",line);
                logger->info("IP-DOMAIN:{}",line);
            }
        }
    }
    return;
}
//网卡状态
void NetWorking::NicStatus(void){
    auto logger = spdlog::basic_logger_mt("NicStatus_logger", "logs/basic-log.txt");
    const char *cmd = "ifconfig";
    char res[2048];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    spdlog::info("NicStatus:\n{}",res);
    logger->info("NicStatus:\n{}",res);
    return;
}
//连接状态细节
void NetWorking::ss(void){
    auto logger = spdlog::basic_logger_mt("ss_logger", "logs/basic-log.txt");
    //ss -tan state syn-sent
    const char *cmd1 = "ss -tan state syn-sent";
    char res[1024];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd1,res);
    spdlog::info("tcp-state-syn_sent:\n{}",res);
    logger->info("tcp-state-syn_sent:\n{}",res);
    //todo:more state ....https://www.cnblogs.com/sztom/p/10810508.html
    return;
};
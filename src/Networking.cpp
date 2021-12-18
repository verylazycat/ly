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
    // core dump !!!!
    char res[2048];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd1,res);
    spdlog::info("tcp-state-syn_sent:\n{}",res);
    logger->info("tcp-state-syn_sent:\n{}",res);
    //ss -tan state syn-recv
    const char *cmd2 = "ss -tan state syn-recv";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd2,res);
    spdlog::info("tcp-state-syn_recv:\n{}",res);
    logger->info("tcp-state-syn_recv:\n{}",res);
    //ss -tan state listening
    const char *cmd3 = "ss -tan state listening";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd3,res);
    spdlog::info("tcp-state-listening:\n{}",res);
    logger->info("tcp-state-listening:\n{}",res);
    //ss -tan state established
    const char *cmd4 = "ss -tan state established";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd4,res);
    spdlog::info("tcp-state-established:\n{}",res);
    logger->info("tcp-state-established:\n{}",res);
    //ss -tan state fin-wait-1
    const char *cmd5 = "ss -tan state fin-wait-1";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd5,res);
    spdlog::info("tcp-state-fin-wait-1:\n{}",res);
    logger->info("tcp-state-fin-wait-1:\n{}",res);
    //ss -tan state close-wait
    const char *cmd6 = "ss -tan state close-wait";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd6,res);
    spdlog::info("tcp-state-close-wait:\n{}",res);
    logger->info("tcp-state-close-wait:\n{}",res);
    //ss -tan state fin-wait-2
    const char *cmd7 = "ss -tan state fin-wait-2";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd7,res);
    spdlog::info("tcp-state-fin-wait-2:\n{}",res);
    logger->info("tcp-state-fin-wait-2:\n{}",res);
    //ss -tan state time-wait
    const char *cmd8 = "ss -tan state time-wait";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd8,res);
    spdlog::info("tcp-state-time-wait:\n{}",res);
    logger->info("tcp-state-time-wait:\n{}",res);
    //ss -tan state last-ack
    const char *cmd9 = "ss -tan state last-ack";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd9,res);
    spdlog::info("tcp-state-last-ack:\n{}",res);
    logger->info("tcp-state-last-ack:\n{}",res);
    //ss -tan state closing
    const char *cmd10 = "ss -tan state closing";
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd10,res);
    spdlog::info("tcp-state-closing:\n{}",res);
    logger->info("tcp-state-closing:\n{}",res);
    //todo:more state ....https://www.cnblogs.com/sztom/p/10810508.html
    return;
};
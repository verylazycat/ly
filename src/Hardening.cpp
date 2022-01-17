//
// Created by admin233 on 2022/1/9.
//

#include "Hardening.h"

void Hardening::CheckGCC(void){
    auto logger = spdlog::basic_logger_mt("CheckGCC_logger", "logs/basic-log.txt");
    // get version
    const char *cmd0 = "gcc --version | grep \"gcc\" | awk '{print $4}'";
    //get bit
    const char *cmd1 = "ls -la /bin/gcc | awk '{print $1}'";
    char res[1024];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd0,res);
    if (Utils::KMPsearch(res,"command not found")){
        spdlog::info("you are not install gcc");
        logger->info("you are not install gcc");
        return;
    }
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd1,res);
    spdlog::info("The production environment gcc permissions:{}",res);
    logger->info("The production environment gcc permissions:{}",res);
    return;
}

void Hardening::CheckGPP(void){
    auto logger = spdlog::basic_logger_mt("CheckGPP_logger", "logs/basic-log.txt");
    // get version
    const char *cmd0 = "g++ --version | grep \"g++\" | awk '{print $4}'";
    //get bit
    const char *cmd1 = "ls -la /bin/g++ | awk '{print $1}'";
    char res[1024];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd0,res);
    if (Utils::KMPsearch(res,"command not found")){
        spdlog::info("you are not install g++");
        logger->info("you are not install g++");
        return;
    }
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd1,res);
    spdlog::info("The production environment g++ permissions:{}",res);
    logger->info("The production environment g++ permissions:{}",res);
    return;
}
void Hardening::CheckCMAKE(void){
    auto logger = spdlog::basic_logger_mt("CheckCMAKE_logger", "logs/basic-log.txt");
    // get version
    const char *cmd0 = "cmake --version | head -n 1 | awk '{print $3}'";
    //get bit
    const char *cmd1 = "ls -la /bin/cmake | awk '{print $1}'";
    char res[1024];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd0,res);
    if (Utils::KMPsearch(res,"command not found")){
        spdlog::info("you are not install cmake");
        logger->info("you are not install cmake");
        return;
    }
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd1,res);
    spdlog::info("The production environment cmake permissions:{}",res);
    logger->info("The production environment cmake permissions:{}",res);
    return;
}
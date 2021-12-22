//
// Created by admin233 on 2021/12/22.
//

#include "FileIntegrity.h"

void FileIntegrity::CheckNecessaryBlock(void){
    auto logger = spdlog::basic_logger_mt("CheckNecessaryBlock_logger", "logs/basic-log.txt");
    const char *cmd1 = "df -h /home";
    const char *cmd2 = "df -h /tmp";
    char res[1024];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd1,res);
    spdlog::info("/home info:\n{}",res);
    logger->info("/home info:\n{}",res);
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd2,res);
    spdlog::info("/tmp info:\n{}",res);
    logger->info("/tmp info:\n{}",res);
}
void FileIntegrity::CheckSwap(void){
    auto logger = spdlog::basic_logger_mt("CheckSwap_logger", "logs/basic-log.txt");
    ifstream in(this->fstab.c_str());
    string line;
    if (in){
        while (getline(in,line)){
            if (Utils::KMPsearch(line,"/swapfile")){
                spdlog::info("swap block have been configured");
                logger->info("swap block have been configured");
                return;
            }
        }       
    }
    spdlog::critical("swap block have not been configured");
    logger->critical("swap block have not been configured");
    return;
}
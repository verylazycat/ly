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

void FileIntegrity::CheckTmp(void){
    auto logger = spdlog::basic_logger_mt("CheckTmp_logger", "logs/basic-log.txt");
    const char *cmd = "find /tmp -type f";
    char res[1024];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    spdlog::info("/tmp file info:\n{}",res);
    logger->info("/tmp file info:\n{}",res);
    return;
}
bool FileIntegrity::CheckAIDEConfFile(void){
    int fd = open(this->aideconfig.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
void FileIntegrity::CheckAIDE(void){
    // https://blog.csdn.net/weixin_44232712/article/details/107226013
    auto logger = spdlog::basic_logger_mt("CheckAIDE_logger", "logs/basic-log.txt");
    if (!this->CheckAIDEConfFile()){
        spdlog::critical("aide.Conf does not exist!");
        logger->critical("aide.Conf does not exist!");
        spdlog::critical("you need install aide:sudo apt-get install aide");
        logger->critical("you need install aide:sudo apt-get install aide");
        return;
    }
    const char *cmd = "cat /etc/aide/aide.conf";
    char res[2048];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    spdlog::info("aide confif info:\n{}",res);
    logger->info("aide confif info:\n{}",res);
    return;
}
void FileIntegrity::TmpStickybit(void){
    // ls -l -d /tmp | awk '{print $1}'
    auto logger = spdlog::basic_logger_mt("TmpStickybit_logger", "logs/basic-log.txt");
    const char *cmd = "ls -l -d /tmp | awk '{print $1}'";
    char res[4096];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    if (Utils::KMPsearch(res,"drwxrwxrwt")){
        spdlog::info("/tmp permissions bit is safe");
        logger->info("/tmp permissions bit is safe");   
    }
    else{
        spdlog::critical("/tmp permissions bit is not safe");
        logger->critical("/tmp permissions bit is not safe");
    }
    return;
}
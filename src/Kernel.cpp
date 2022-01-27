//
// Created by admin233 on 2021/12/8.
//

#include "Kernel.h"

bool Kernel::CheckCPUINIFO(void){
    int fd = open(this->cpuinfo.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}

bool Kernel::CheckSYSCTL(void){
    int fd = open(this->sysctl.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
// https://blog.csdn.net/ohhmygod/article/details/7596341
// https://askubuntu.com/questions/128396/how-can-i-tell-if-a-machine-has-pae
void Kernel::CheckPAE(void){
    // const char *cmd = "grep --color=always -i PAE /proc/cpuinfo";
    auto logger = spdlog::basic_logger_mt("CheckPAE_logger", "logs/basic-log.txt");
    if (!CheckCPUINIFO()){
        spdlog::critical("Cpuinfo System file is lost");
        logger->critical("Cpuinfo System file is lost");
        return;
    }
    bool PAE = false;
    ifstream in(this->cpuinfo);
    string line;
    if (in){
        while (getline(in,line)){
            if (Utils::KMPsearch(line,"pae")){
                PAE = true;
                break;
            }
        }
    }
    if (PAE){
        spdlog::info("The PAE patch has been installed");
        logger->info("The PAE patch has been installed");
        Utils::updatebyip("LY-core","Kernel","PAE",1);
        return;
    }
    else{
        spdlog::critical("The PAE patch has not been installed");
        logger->critical("The PAE patch has not been installed");
        Utils::updatebyip("LY-core","Kernel","PAE",0);
        return;
    }
}

// https://www.cnblogs.com/zlcxbb/p/6431191.html
void Kernel::CheckCoreDumpOK(void){
    auto logger = spdlog::basic_logger_mt("CheckCoreDumpOK_logger", "logs/basic-log.txt");
    const char *cmd = "ulimit -c";
    char res[1024];
    bzero(res,sizeof(res));
    Utils::executeCMD(cmd,res);
    if (res[0] == '0'){
        spdlog::critical("Core dump is not started");
        logger->critical("Core dump is not started");
        Utils::updatebyip("LY-core","Kernel","core_dump",0);
        return;
    }
    else{
        spdlog::critical("Core dump is started");
        logger->critical("Core dump is started");
        Utils::updatebyip("LY-core","Kernel","core_dump",1);
        return;
    }
}

void Kernel::CheckSysCtlValue(void){
    auto logger = spdlog::basic_logger_mt("CheckSysCtlValue_logger", "logs/basic-log.txt");
    if (!CheckSYSCTL()){
        spdlog::critical("Sysctl System file is lost");
        logger->critical("Sysctl System file is lost");
        return;
    }
    // https://developer.aliyun.com/article/700149
    //todo:学位完成
}
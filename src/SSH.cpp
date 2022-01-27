//
// Created by admin233 on 2021/11/21.
//

#include "SSH.h"
bool SSH::CheckSSHConfig(void){
    int fd = open(this->sshconfig.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
// https://blog.csdn.net/samginshen/article/details/104852042
void SSH::AuditSSHConfig(void){
    auto logger = spdlog::basic_logger_mt("AuditSSHConfig_logger", "logs/basic-log.txt");
    if (!this->CheckSSHConfig()){
        spdlog::critical("ssh_config does not exist!");
        logger->critical("ssh_config does not exist!");
        return;
    }
    char res[20];
    const char *cmd  = "ls  -la /etc/ssh/ssh_config | awk '{print $1}'";
    Utils::executeCMD(cmd,res);
    if (Utils::KMPsearch(res,"-rw-r--r--")){
        spdlog::info("SSH profile permission security:{}",res);
        logger->info("SSH profile permission security:{}",res);
        Utils::updatebyip("LY-core","SSH","confsecurity",1);
    }
    else{
        spdlog::critical("SSH profile permission not security:{}",res);
        logger->critical("SSH profile permission not security:{}",res);
        Utils::updatebyip("LY-core","SSH","confsecurity",0);
    }
    // PasswordAuthentication
    bool PasswordAuthentication = false;
    ifstream in(this->sshconfig);
    string line;
    if (in){
        while (getline(in,line)){
            // #   PasswordAuthentication
            if (Utils::KMPsearch(line,"#   PasswordAuthentication")
               || Utils::KMPsearch(line,"PasswordAuthentication no")){
                continue;
            }
            else if (Utils::KMPsearch(line,"PasswordAuthentication yes")){
                PasswordAuthentication = true;
                continue;
            }
            //todo:其他校验写这里...
        }
    }
    if (PasswordAuthentication){
        spdlog::info("PasswordAuthentication is ok");
        logger->info("PasswordAuthentication is ok");
        Utils::updatebyip("LY-core","SSH","PasswordAuthentication",1);
    }
    else{
        spdlog::critical("PasswordAuthentication is unsafe");
        logger->critical("PasswordAuthentication is unsafe");
        Utils::updatebyip("LY-core","SSH","PasswordAuthentication",0);
    }
    //...
}

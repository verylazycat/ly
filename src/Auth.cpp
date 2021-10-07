//
// Created by admin233 on 2021/10/7.
//

#include "Auth.h"


void Auth::CheckIsOnlyUser() {
    auto logger = spdlog::basic_logger_mt("CheckIsOnlyUser_logger", "logs/basic-log.txt");
    int fd = open("/etc/passwd",O_RDONLY);
    if(fd == -1){
        spdlog::critical("cat't open /etc/passwd");
        logger->critical("cat't open /etc/passwd");
        return;
    }
    char  buf[2048];
    if((read(fd,&buf,sizeof(buf))) == -1){
        spdlog::critical("cat't read /etc/passwd");
        logger->critical("cat't read /etc/passwd");
        close(fd);
        return;
    }
    std::unordered_set<char *> lookup;
    char *p;
    char *line;
    char *username;
    p = strtok(buf,"\n");
    while((line = strtok(NULL,"\n"))){
        username = Utils::GetNameFromPass(line);
        if(lookup.find(username) == lookup.end())
            lookup.insert(username);
        else{
            spdlog::critical("Duplicate user name:{}",username);
            logger->critical("Duplicate user name:{}",username);
            break;
        }
    }
    spdlog::info("User name Security");
    logger->info("User name Security");
}

void Auth::CheckNoPwUser() {
    auto logger = spdlog::basic_logger_mt("CheckNoPwUser_logger", "logs/basic-log.txt");
    int fd = open("/etc/passwd",O_RDONLY);
    if (fd == -1){
        spdlog::critical("cat't open /etc/passwd");
        logger->critical("cat't open /etc/passwd");
        return;
    }
    char buf[2048];
    if ((read(fd,&buf,sizeof(buf))) == -1){
        spdlog::critical("cat't read /etc/passwd");
        logger->critical("cat't read /etc/passwd");
        close(fd);
        return;
    }
    char *username;
    char *passwd;
    char  *p;
    char *line;
    int invalidcount = 0;
    p = strtok(buf,"\n");
    while (( line = strtok(NULL,"\n"))){
        username = Utils::GetNameFromPass(line);
        passwd = Utils::GetPassFromPass(line);
        if (strcmp(passwd,"x") != 0){
            invalidcount++;
            spdlog::critical("user[{}] has no password",username);
            logger->critical("user[{}] has no password",username);
        }
    }
    if (invalidcount) {
        spdlog::critical("A total of {} users do not have passwords",invalidcount);
        logger->critical("A total of {} users do not have passwords",invalidcount);
    }
    else {
        spdlog::info("All users have passwords");
        logger->info("All users have passwords");
    }
}
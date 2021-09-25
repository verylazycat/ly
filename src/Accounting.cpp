//
// Created by admin233 on 2021/9/19.
//

#include "Accounting.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "config.h"

Accounting::Accounting() {
    //init
    int ua = uname(&this->sysuname);
    if (ua != 0)
        spdlog::critical("uname init fail!");
    else
        spdlog::info("uname init sucess!");
    int sy = sysinfo(&this->info);
    if (sy != 0)
        spdlog::critical("sysinfo init fail!");
    else
        spdlog::info("sysinfo init sucess!");
}

void Accounting::BaseInfo() {
    //============== sysuname =============
    spdlog::info({"domainname:{}"}, this->sysuname.domainname);
    spdlog::info("machine:{}", this->sysuname.machine);
    spdlog::info("nodename:{}", this->sysuname.nodename);
    spdlog::info("release:{}", this->sysuname.release);
    spdlog::info("sysname:{}", this->sysuname.sysname);
    spdlog::info("version:{}", this->sysuname.version);
//    //================= info ===============
    spdlog::info("bufferram:{}", this->info.bufferram);
    spdlog::info("freehigh:{}", this->info.freehigh);
    spdlog::info("freeswap:{}", this->info.freeswap);
    spdlog::info("mem_unit:{}", this->info.mem_unit);
    spdlog::info("pad:{}", this->info.pad);
    spdlog::info("procs:{}", this->info.procs);
    spdlog::info("sharedram:{}", this->info.sharedram);
    spdlog::info("totalhigh:{}", this->info.totalhigh);
    spdlog::info("uptime:{}", this->info.uptime);
    try {
//        ============ log ===============
//        ============= sysuname ============
        auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
        logger->info("domainname:{}", this->sysuname.domainname);
        logger->info("machine:{}", this->sysuname.machine);
        logger->info("nodename:{}", this->sysuname.nodename);
        logger->info("release:{}", this->sysuname.release);
        logger->info("version:{}", this->sysuname.version);
//        ============== info ====================
        logger->info("bufferram:{}", this->info.bufferram);;
        logger->info("freehigh:{}", this->info.freehigh);
        logger->info("freeswap:{}", this->info.freeswap);
        logger->info("mem_unit:{}", this->info.mem_unit);
        logger->info("pad:{}", this->info.pad);
        logger->info("procs:{}", this->info.procs);
        logger->info("sharedram:{}", this->info.sharedram);
        logger->info("totalhigh:{}", this->info.totalhigh);
        logger->info("uptime:{}", this->info.uptime);
    }
    catch (const spdlog::spdlog_ex &ex) {
        spdlog::critical("Log init failed: {}", ex.what());
    }
}
void Accounting::CheckUmask(){
    auto logger = spdlog::basic_logger_mt("CheckUmask_logger", "logs/basic-log.txt");
    uid_t current_uid = getuid();
    mode_t mode = umask(mode);
    mode_t safe_common_mode = 002;
    mode_t  safe_super_mode = 0022;
    spdlog::info("curent user uid:{}",current_uid);
    spdlog::info("curent umask(18 hexadecimal):{}",mode);
     //common users
    if(current_uid != 0){
        if(mode == safe_common_mode){
            spdlog::info("Umask for common users is secure");
            logger->info("Umask for common users is secure");
        }
        else{
            spdlog::warn("Umask for common users is not secure");
            logger->warn("Umask for common users is not secure");
        }
    }
    //root user
    else{
        if(mode == safe_super_mode){
            spdlog::info("Umask for super user is secure");
            logger->info("Umask for super user is secure");
        }
        else{
            spdlog::warn("Umask for super user is not secure");
            logger->warn("Umask for super user is not secure");
        }
    }
}
void Accounting::CheckIsOnlyUser() {
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
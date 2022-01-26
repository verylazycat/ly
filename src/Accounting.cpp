//
// Created by admin233 on 2021/9/19.
//

#include "Accounting.h"


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
    Utils::updatebyip("LY-core","BaseInfo","domainname",string(this->sysuname.domainname));
    spdlog::info("machine:{}", this->sysuname.machine);
    Utils::updatebyip("LY-core","BaseInfo","machine",string(this->sysuname.machine));
    spdlog::info("nodename:{}", this->sysuname.nodename);
    // Utils::updatebyip("LY-core","BaseInfo","nodename",string(this->sysuname.nodename));
    spdlog::info("release:{}", this->sysuname.release);
    Utils::updatebyip("LY-core","BaseInfo","sysrelease",string(this->sysuname.release));
    spdlog::info("sysname:{}", this->sysuname.sysname);
    Utils::updatebyip("LY-core","BaseInfo","sysname",string(this->sysuname.sysname));
    spdlog::info("version:{}", this->sysuname.version);
    Utils::updatebyip("LY-core","BaseInfo","version",string(this->sysuname.version));
//    //================= info ===============
    spdlog::info("bufferram:{}", this->info.bufferram);
    Utils::updatebyip("LY-core","BaseInfo","bufferram",this->info.bufferram);
    spdlog::info("freehigh:{}", this->info.freehigh);
    Utils::updatebyip("LY-core","BaseInfo","freehigh",this->info.freehigh);
    spdlog::info("freeswap:{}", this->info.freeswap);
    Utils::updatebyip("LY-core","BaseInfo","freeswap",this->info.freeswap);
    spdlog::info("mem_unit:{}", this->info.mem_unit);
    Utils::updatebyip("LY-core","BaseInfo","mem_unit",this->info.mem_unit);
    spdlog::info("pad:{}", this->info.pad);
    Utils::updatebyip("LY-core","BaseInfo","pad",this->info.pad);
    spdlog::info("procs:{}", this->info.procs);
    Utils::updatebyip("LY-core","BaseInfo","procs",this->info.procs);
    spdlog::info("sharedram:{}", this->info.sharedram);
    Utils::updatebyip("LY-core","BaseInfo","sharedram",this->info.sharedram);
    spdlog::info("totalhigh:{}", this->info.totalhigh);
    Utils::updatebyip("LY-core","BaseInfo","totalhigh",this->info.totalhigh);
    spdlog::info("uptime:{}", this->info.uptime);
    Utils::updatebyip("LY-core","BaseInfo","uptime",this->info.uptime);
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
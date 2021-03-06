//
// Created by admin233 on 2021/10/25.
//
#include "Boot.h"

void Boot::CheckGrubBootLoader(){
    const string grub_cfg_md5 = "151ae9b399fc47d6cf88de754756d";
    auto logger = spdlog::basic_logger_mt("CheckGrubBootLoader_logger", "logs/basic-log.txt");
    int fd = open("/boot/grub/grub.cfg",O_RDONLY);
    if (fd == -1)
    {
        logger->critical("cat't open /boot/grub/grub.cfg");
        spdlog::critical("cat't open /boot/grub/grub.cfg");
        return;
    }
    logger->info("open /boot/grub/grub.cfg sucess");
    spdlog::info("open /boot/grub/grub.cfg sucess");
    close(fd);
    // TODO:校验md5值 
    if (grub_cfg_md5.compare(Utils::CalculateMD5(config_path))){
        // not same
        logger->warn("grub.cfg is not automatically generated by grub-mkconfig using templates");
        spdlog::warn("grub.cfg is not automatically generated by grub-mkconfig using templates");
        Utils::updatebyip("LY-core","Boot","grubsecurity",0);
        return;
    }
    logger->info("grub.cfg is security");
    spdlog::info("grub.cfg is security");
    Utils::updatebyip("LY-core","Boot","grubsecurity",1);
}
/*
验证是否加密grub以及是否hash，不是明文写入
https://blog.51cto.com/chenxiaojian/1619540
https://blog.51cto.com/yangzhiming/835281
*/
void Boot::CheckAuthBoot(){
    auto logger = spdlog::basic_logger_mt("CheckAuthBoot_logger", "logs/basic-log.txt");
    bool pwflag = false;
    bool md5pwflag = false;
    ifstream in(config_path);
    string line;
    if(in){
        while (getline(in,line)){
            if (Utils::KMPsearch(line,"password")){
                pwflag = !pwflag;
            }
            if (Utils::KMPsearch(line,"password  --md5")){
                md5pwflag = !md5pwflag;
            }
        } 
    }else{
        logger->critical("cat't open /boot/grub/grub.cfg");
        spdlog::critical("cat't open /boot/grub/grub.cfg");
        return;
    }
    if (pwflag && md5pwflag){
        logger->info("Grub is encrypted and stored securely");
        spdlog::info("Grub is encrypted and stored securely");
        Utils::updatebyip("LY-core","Boot","grubencrypted",1);
        Utils::updatebyip("LY-core","Boot","storedsecurely",1);
    }
    else if(pwflag){
        logger->warn("Grub is encrypted but not stored securely");
        spdlog::warn("Grub is encrypted but not stored securely");
        Utils::updatebyip("LY-core","Boot","grubencrypted",1);
        Utils::updatebyip("LY-core","Boot","storedsecurely",0);
    }
    else{
        logger->critical("Grub unencrypted");
        spdlog::critical("Grub unencrypted");
        Utils::updatebyip("LY-core","Boot","grubencrypted",0);
        Utils::updatebyip("LY-core","Boot","storedsecurely",0);
    }
}
void Boot::CheckCron(){
    auto logger = spdlog::basic_logger_mt("CheckCron_logger", "logs/basic-log.txt");
    ifstream in(crontab);
    string line;
    string save = "";
    if (in){
        while (getline(in,line)){
            if (line.empty())
                continue;
            if (line.at(0) == '#')
                continue;
            else{
                logger->warn(line);
                spdlog::warn(line);
                save += line;
            }
        }
        Utils::updatebyip("LY-core","Boot","cron",save);
    }else{
        logger->critical("cat't open /etc/crontab");
        spdlog::critical("cat't open /etc/crontab");
    }
}
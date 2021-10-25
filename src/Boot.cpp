//
// Created by admin233 on 2021/10/25.
//
#include "Boot.h"

void Boot::CheckGrubBootLoader(){
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
}
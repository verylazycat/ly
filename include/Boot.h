//
// Created by admin233 on 2021/10/25.
//
#ifndef LY_BOOT_H
#define LY_BOOT_H
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Utils.h"
class Boot{
public:
    const string config_path = "/boot/grub/grub.cfg";
    const string crontab = "/etc/crontab";
    // GRUB boot loader
    void CheckGrubBootLoader();
    void CheckAuthBoot();
    void CheckCron();
};
#endif
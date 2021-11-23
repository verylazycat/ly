//
// Created by admin233 on 2021/11/23.
//

#include "Tools.h"

bool Tools::CheckFailBanConfig(){
    int fd = open(this->failbanconfig.c_str(),O_RDONLY);
    if (fd == 0){
        close(fd);
        return false;
    }
    close(fd);
    return true;
}
//
// Created by admin233 on 2021/9/18.
//

#ifndef LY_BANNER_H
#define LY_BANNER_H
#include <string.h>
#include <stdio.h>
const static  char bannerstring[] = "                      .__                                      __          \n"
                           "     __  _  __  ____  |  |    ____   ____    _____    ____   _/  |_  ____  \n"
                           "     \\ \\/ \\/ /_/ __ \\ |  |  _/ ___\\ /  _ \\  /     \\ _/ __ \\  \\   __\\/  _ \\ \n"
                           "      \\     / \\  ___/ |  |__\\  \\___(  <_> )|  Y Y  \\\\  ___/   |  | (  <_> )\n"
                           "       \\/\\_/   \\___  >|____/ \\___  >\\____/ |__|_|  / \\___  >  |__|  \\____/ \n"
                           "                   \\/            \\/              \\/      \\/                \n"
                           "                               .____            \n"
                           "                               |    |    ___.__.\n"
                           "                               |    |   <   |  |\n"
                           "                               |    |___ \\___  |\n"
                           "                               |_______ \\/ ____|\n"
                           "                                       \\/\\/     ";
__attribute__((constructor)) static void beforeFunction(){
    fprintf(stdout,bannerstring);
    fprintf(stdout,"\n");
}
#endif //LY_BANNER_H

//
// Created by admin233 on 2021/9/25.
//

#include "Utils.h"
char *Utils::GetNameFromPass(char *ps) {
    char *res = (char *)malloc(20);
    for(int i = 0;i < strlen(ps);i++){
        if (ps[i] != ':')
            res[i] = ps[i];
        else{
            res[i] = '\0';
            break;
        }
    }
    return res;
}
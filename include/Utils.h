//
// Created by admin233 on 2021/9/25.
//

#ifndef LY_UTILS_H
#define LY_UTILS_H
#include <string.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream> 
#include <iomanip>
#include <openssl/md5.h>

#define MAXDATABUFF 1024
#define MD5LENTH 16

using namespace std;
class Utils {
public:
    static char *GetNameFromPass(char *ps);
    static char *GetPassFromPass(char  *ps);
    static string CalculateMD5(const string &filePath);
    static string dec2hex(int x);
    static bool KMPsearch(const string &source,const string &target);
};


#endif //LY_UTILS_H

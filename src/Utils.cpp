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

char *Utils::GetPassFromPass(char *ps) {
    char  *res = (char *) malloc(2);
    for (int i = 0; i < strlen(ps); ++i) {
        if (ps[i] != ':')
            continue;
        else{
            i++;
            res[0] = ps[i];
            res[1] = '\0';
            break;
        }
    }
    return res;
}

//Calculate MD5
string Utils::CalculateMD5(const string &filePath){
    string res = "";
    ifstream ifile(filePath.c_str(),ios::in|ios::binary);
    unsigned char MD5result[MD5LENTH];
    if (ifile.fail()){
        cout<<"open file failure!so only display string MD5!"<<endl;
        return "";
    } 
    MD5_CTX md5_ctx;    
    MD5_Init(&md5_ctx);
    char DataBuff[MAXDATABUFF];
    while(!ifile.eof())
    {
        ifile.read(DataBuff,MAXDATABUFF);   //读文件
        int length = ifile.gcount();
        if(length)
        {
            MD5_Update(&md5_ctx,DataBuff,length);   //将当前文件块加入并更新MD5
        }
    }
    MD5_Final(MD5result,&md5_ctx);  //获取MD5
    for(int i = 0; i < MD5LENTH; i++){
        res += dec2hex(MD5result[i]);
    }
    // cout<<res;
    return res;
}
// to 16 bit
string Utils::dec2hex(int x){
    stringstream ioss;
    string s_temp;
    ioss<<setiosflags(ios::uppercase)<<hex<<x;
    ioss>>s_temp;
    transform(s_temp.begin(),s_temp.end(),s_temp.begin(),::tolower);
    return s_temp;
}
//
// Created by basto on 3/22/18.
//


#include <logging.h>

int main(){
    Log::advacedConf()->pintLogSrc(true);
    Log::advacedConf()->setSrcShift(true);
    Log::log("do something with default logLevel",UserInfo);
    Log::log(" asdasdasdasdasdasdasdasdasdasdasasdasdasdasdasdasdasdasd","meesage",Error);
    Log::log("bub",Error);

}
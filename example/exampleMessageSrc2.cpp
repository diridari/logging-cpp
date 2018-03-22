//
// Created by basti on 16.03.2018.
//

#include <logging.h>
#include <unistd.h>

/**
 * Just a litle step to improve the readability of logfiles if need the information
 * from where the logmessage has been send.
 * @return
 */
int main(){

    Log::setLogLevel(Message,None);
    Log::advacedConf()->pintLogSrc(true);
    Log::log("just a long message src", "Do you not also think ", Message);
    Log::log("", "that it's hard to read a log file where loggSrc", Message);

    Log::log("message src", "is very important",Message);
    Log::log("src", "and you do",Message);
    Log::log("verrrry Long and important Log Src ", "not want to disable it. But",Message);
    Log::log("","you also like to have a readable logfile?\n\n",Message);

    Log::advacedConf()->setSrcShift(true);
    Log::log("enabled SrcShift for a better veiw",Error);
    Log::log("shortSrc","Then let me tell you that",Message);
    Log::log("very long function  abcedghijkl", "it is possible to set the length of the LogSrc so that the logfile is",Message);
    Log::log("src","a little more readable and ",Message);
    Log::log("src","you do have  a logile with",Message);
    Log::log("src","the LogSrc :)",Message);
    Log::log("just a long message src" ,"Do you not also think ",Message);
    Log::log("","that it's hard to read a log file where loggSrc",Message);
    Log::log("message src", "is very important",Message);
    Log::log("src", "and you don't",Message);
    Log::log("verrrry Long and important Log Src ", "want to disable it. But",Message);
    Log::log("","you also like to have a readable logfile?\n\n",Message);

}
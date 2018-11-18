/*
 * example.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: Sebastian Balz
 */

#include <logging.h>
#include <unistd.h>
int main() {

    Log::advancedConf()->pintLogSrc(false);
    // Log level cli and log level file are equal ->
    // each message printed to the file gets printed to the logfile
    Log::setLogLevel(Debug);

    std::cout << "Simple Logfile example" << std::endl;
    Log::log("This message gets not printed because the Log level is lower that the the level of this message",DebugL2);
    Log::log("This message gets printed because the Log level is higher that the the level of this message",Message);

    usleep(11030); // make the timestamp more interesting ... :)
    // change the log file
    Log::setLogFileName("newLog.log");
    // just for the usage of the application relevant information gets printed to the cli and every print get written to the logfile
    Log::setLogLevel(UserInfo,DebugL3);
    Log::log("gets printed to cli and logfile",UserInfo);
    Log::log("get just written to the logfile",Message);

    // change the logLevel
    Log::setLogLevel(Message,DebugL3);
    Log::log("get to both because of the new log level",Message);

    Log::setLogLevel(DebugL3,DebugL3);

    usleep(10100);
    Log::setLogLevel(DebugL3,DebugL3);
    Log::log("DebugL3",DebugL3);
    Log::log("DebugL2",DebugL2);
    Log::log("Debug",Debug);
    Log::log("Info",Info);
    Log::log("Message",Message);
    Log::log("Error",Error);
    Log::log("CriticError",CriticError);
    Log::log("UserInfo",UserInfo);

    usleep(10000);
    // disable the cli highlighting
    Log::advancedConf()->setCliHighLight(false);
    Log::log("CriticError with out highlighting",CriticError);
    return 0;
}
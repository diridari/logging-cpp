#include <iostream>
#include <loging.h>
#include <unistd.h>

int main() {
    // Loglevel cli and loglevel file are equal ->
    // each message printed to the file gets printed to the logfile
    Log::setLogLevel(Debug);

    std::cout << "Simple Logfile example" << std::endl;
    Log::log("This message gets printed because the Loglevel is higher that the the level of this message",Message);
    Log::log("This message gets not printed because the Loglevel is lower that the the level of this message",DebugL2);

    // change the log file
    Log::setLogFileName("newLog.log");
    // just for the usage of the application relevant information gets printed to the cli and every print get written to the logfile
    Log::setLogLevel(UserInfo,DebugL3);
    Log::log("gets printed to cli and logfile",UserInfo);
    Log::log("get just written to the logfile",Message);

    // change the logLevel
    Log::setLogLevel(Message,DebugL3);
    Log::log("get to both because of the new loglevel",Message);

    cout << "ende"<<endl;
    return 0;
}
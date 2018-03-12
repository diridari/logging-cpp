//
// Created by Sebastian Balz on 12.03.2018.
//

#include <logging.h>

int main(){
    Log::log("src of message" , "not printed to file/cli because default level ar : file=None,cli=Error",Message);
    Log::log("src of message" , "printed to cli because level eql default ",Error);
    Log::log("main" , "just printed to cli",UserInfo);

    // change to log level with int values
    Log::setLogLevel(4,-1); // == Error, None
    Log::log("main ","printed to cli with new log prio set with int values",Message);

}
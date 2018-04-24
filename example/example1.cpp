//
// Created by Sebastian Balz on 12.03.2018.
//

#include <string>
#include <logging.h>
#include <unistd.h>

using  namespace std;

class abc{
    public:

    /**
     * wast some time
     */
    void heavyCalculation(){
        Log::log("start heavy calc",Info);

        int time = rand()%10000;
        Log::log("calculation does need " + to_string(time) + "us",Debug);
        usleep(time);
        Log::log("calculation done",Message);
    }
    /**
     * random example function
     * @param abc string
     * @param num number added to string
     * @return string + num
     */
    string magicFunction(string abc, int num){
        if(num < 0){
            Log::log("not allowed parameter : " + to_string(num),CriticError);
            return "";
        }
        Log::log("got param : " + abc + " and " + to_string(num),Debug);
        heavyCalculation();
        string out = abc + to_string(num);
        Log::log("magically result : " + out,Message);
        return out;

    }
};
int main(){
    abc a;
    Log::advancedConf()->pintLogSrc(true, 0);
    Log::log("do something with default logLevel",UserInfo);
    a.magicFunction("abc",42);
    a.magicFunction("hello world",-1);

    Log::setLogLevel(Message,None);
    Log::log("do something with Message as logLevel",UserInfo);
    a. magicFunction("abc",42);
    a.magicFunction("hello world",-1);

    Log::setLogLevel(DebugL3,None);
    Log::log("do something with Debug as logLevel",UserInfo);
    a.magicFunction("abc",42);
    a.magicFunction("hello world",-1);

    ///////////////////////////////////////
    // Change the level where the Src line gets printed
    ///////////////////////////////////////
    Log::log("\n\nChange the level in which the src line is displayed",UserInfo);
    Log::printSrcLine(Message);
    Log::log("message src line are now printed even at Messages-Level",Message)
    Log::printSrcLine(CriticError);
    Log::log("message src line are not anymore printed at Error-Messages",Error)

}
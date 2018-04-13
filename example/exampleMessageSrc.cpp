//
// Created by Sebastian Balz on 12.03.2018.
//

#include <logging.h>

class exp{
public:
    void functionWithAnVeryLongMethodNameJustToShowTheShortCut(int cutAt){
        Log::log(" cut src short at " + to_string(cutAt),Message);
    }
};
int main(){
    Log::setLogLevel(Message,None);
    Log::advancedConf()->setSrcShift(true);
    exp exp;
    for(int i = 0; i<=15;i+=5) {
        Log::advancedConf()->pintLogSrc(true, i);
        exp.functionWithAnVeryLongMethodNameJustToShowTheShortCut(i);
    }
    Log::advancedConf()->pintLogSrc(true, 0);
    Log::log("src of message", "print the log with an custon log src",Message);
    Log::log("or use the default log src with teh function name",Message);
    Log::advancedConf()->pintLogSrc(false, 0);
    Log::log("src of message", "with disabled printSrc and custom log src",Message);
    Log::log("and disabled printSrc and default src",Message);

}
//
// Created by Sebastian Balz on 12.03.2018.
//

#include <logging.h>

class exp {
public:
    void functionName(int print) {
        Log::log(" printed from : functionName" + to_string(print), Message);
    }

    void abc(int print) {
        Log::log(" printed from : abc" + to_string(print), Message);
    }

    void xxx(int print) {
        Log::log(" printed from : xxx" + to_string(print), Message);
    }
};

int main() {
    Log::advancedConf()->pintLogSrc(true);
    Log::setLogLevel(Message);
    (new exp())->functionName(8);
    (new exp())->abc(8);
    (new exp())->xxx(8);
}
//
// Created by basto on 4/24/18.
//

#include <iostream>
#include <logging.h>

#define intr_1 1<<0
#define intr_2 1<<1
#define intr_3 1<<2
#define intr_4 1<<3
#define intr_5 1<<10

using namespace std;

void runSomeLogMessagesWithDifferentPointsOfIntr(){
    Log::log("point of intressed : 0",Message);        // gets printed in each run
    Log::log("point of intressed : 1",Message,1);      // just if the flag is set to 0bXXXXXX1
    Log::log("point of intressed : 2",Message,intr_2);  // just if the flag is set to 0bXXXXX1X
    Log::log("point of intressed : 3",Message,intr_3);  // just if the flag is set to 0bXXXX1XX
    Log::log("point of intressed : 4",Message,intr_4);
    Log::log("point of intressed : 5",Message,intr_5);

}
int main(){

    Log::setLogLevel(Message,Message);
    // single point
    for(int i = 0; i<4; i++){
       Log::setPointOfIntressed(1<<i);
       runSomeLogMessagesWithDifferentPointsOfIntr();
    }
    // multiple points
    for(int i = 0; i<4; i++){
        Log::setPointOfIntressed(1<<i | 1<<10);
        runSomeLogMessagesWithDifferentPointsOfIntr();
    }


}
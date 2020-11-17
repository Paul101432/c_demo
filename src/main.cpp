#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
typedef std::string string;

static char *GLOBAL_PIN = "88888888"; //´æ´¢µÄPINÂë
int str(){
    const char *pin = "67890";
    string showPin = "1";
    char * tip = "1";

    /*if (strlen(pin) > 0) {
       printf("recv 1.1 [%d]\n", strlen(pin));
       //strcpy(GLOBAL_PIN,pin);
       GLOBAL_PIN = (char*)pin;
       printf("recv 1.2 [%s]\n", GLOBAL_PIN);
   }*/

    if( strcmp(showPin.c_str(),tip)==0 ){
        printf("recv 2 [%s]]\n", showPin.c_str());
        pin =  (const char*)GLOBAL_PIN  ;
        printf("recv 2 [%s]\n", pin);
    }
    printf("recv pin [%s]\n", pin);
    return 0;
}

int main() {

    str();
    return 0;
}

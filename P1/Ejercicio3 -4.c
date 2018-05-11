
#include <time.h>
#include <iostream>

int main(){

time_t r ;
time(&r);
 char t[100];
 ctime_r(&r,t);


std::cout<< t<<std::endl;

return 1;

}

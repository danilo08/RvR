
#include <time.h>
#include <iostream>

int main(){

time_t r ;
time(&r);
 char t[100] ="Hoy es el dia";
 char t2[100]="Estamos en el año ";


std::cout<< t<<std::endl;
 strftime(t2,100,t,r);//esto no es asi creo
return 1;

}

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <iostream>
#include <time.h>

int main (){
	time_t tiempo;
	localtime(&tiempo);

	char año[100] = "Estamos en el año ";
	char day[100] = "Hoy es el dia ";
	char s[100];
	strftime (s,100,'%w',&tiempo);
	std::cout<<año<<s<<day<<std::endl;
	return 1;
}

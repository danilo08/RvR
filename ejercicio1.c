#include <sys/types.h> 
 #include <unistd.h>
 #include <stdio.h>

int main(){


setuid(0);
 perror("setuid()");
return 1;

}           

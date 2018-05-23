#include "Serializable.h"

#include <iostream>
#include <string>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

class Jugador: public Serializable
{
public:
    Jugador(const char * _n, int16_t _x, int16_t _y):x(_x),y(_y)
    {
        strncpy(name, _n, 80);
    };

    virtual ~Jugador(){};

    void to_bin()
    {
    int32_t total=80*sizeof(char)+2*sizeof(int16_t)+sizeof(int32_t);
    alloc_data(total);
    char*tmp=_data+sizeof(int32_t);
    memcpy(tmp,name,80);
    tmp+=80;   
    memcpy(tmp,&x,sizeof(int16_t));
    tmp+=sizeof(int16_t);
    memcpy(tmp,&y,sizeof(int16_t));
    tmp+=sizeof(int16_t);  
    }

    int from_bin(char * data)
    {   
    char* tmp=data+sizeof(int32_t);
    memcpy(name,tmp,80);
    tmp+=80;
    std::cout<<name;
    memcpy(&x,tmp,sizeof(int16_t));
    tmp+=sizeof(int16_t);
    memcpy(&y,tmp,sizeof(int16_t));
    tmp+=sizeof(int16_t);
    }
    

public:
    char name[80];

    int16_t x;
    int16_t y;
};

int main(int argc, char **argv)
{
////ejrcicio 1
	Jugador one("Player one",134,23);
	int fd = open("Pumita.txt", O_CREAT| O_WRONLY | O_TRUNC);
	one.to_bin();
	write(fd, one.data(), one.size());
	close(fd);
	/////////////////// 2 y 3
	Jugador one_("",0,0);
	int fd1 = open("Pumita.txt",O_RDONLY);
	char *buffer;
	int tam;
	read(fd1,&tam,sizeof(int32_t));
	lseek(fd1,0,SEEK_SET);//coloca el indice al principio del archivo
	///
	buffer=(char*)malloc(tam);
	read(fd1,&buffer,tam);
	one_.from_bin(buffer);
	close(fd1);
	std::cout<<one_.name<<one_.x;
	return 0;
	//faltan cosas con el frombin aqui loko
}

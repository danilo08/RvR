/*
 * ejercicio2.cc
 *
 *  Created on: 20/4/2018
 *      Author: usuario_vms
 */




#include <stdio.h>
#include <stdlib.h>
#include "iostream"
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

using namespace std;


int main(int argc,char**argv){

	
	struct addrinfo hints;
	struct addrinfo *res;
	memset((void*)&hints,'\0',sizeof(struct addrinfo));
	hints.ai_flags    = AI_PASSIVE;//
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;//
	
	int rc =getaddrinfo(argv[1],argv[2],&hints,&res);
	int sd=socket(res->ai_family,res->ai_socktype,0);
	
if(rc!=0){
	cout<<"error getaddrinfo() "<< gai_strerror(rc)<<endl;
	return-1;
}
if (sd == -1) {
	std::cout << "Error" << std::endl;
	return -1;
}
		char host [NI_MAXHOST];
		char serv [NI_MAXSERV];
		getnameinfo(res->ai_addr,res->ai_addrlen,host,NI_MAXHOST,
				serv,NI_MAXSERV,NI_NUMERICHOST);
		char peticion[20];
		memset((void*)peticion, '\0', 20);
		peticion[0] = argv[3][0];

		sendto(sd, peticion, 20, 0, res->ai_addr, res->ai_addrlen);

		if (peticion[0] == 'q') {
			return 0;
		}
		struct sockaddr src_addr;
		socklen_t addrlen = sizeof(src_addr);

		recvfrom(sd, peticion, 20, 0, &src_addr, &addrlen);

		std::cout << peticion << std::endl;

		freeaddrinfo(res);


		return 0;
}
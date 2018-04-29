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
	hints.ai_family = AF_INET;

	int rc =getaddrinfo(argv[1],argv[2],&hints,&res);
if(rc!=0){
	cout<<"error getaddrinfo() "<< gai_strerror(rc)<<endl;
	return-1;
}
		char host [NI_MAXHOST];
		char serv [NI_MAXSERV];
		getnameinfo(res->ai_addr,res->ai_addrlen,host,NI_MAXHOST,
				serv,NI_MAXSERV,NI_NUMERICHOST);
		char buf[256];
		struct sockaddr src_addr;
		socklen_t addrlen=sizeof(src_addr);
		int sd=socket(res->ai_family,res->ai_socktype,0);
		bind(sd,res->ai_addr,res->ai_addrlen);

		while(true){

			ssize_t s=recvfrom(sd,buf,255,0,&src_addr,&addrlen);

			getnameinfo(&src_addr,addrlen,host,NI_MAXHOST,serv,
					NI_MAXSERV,NI_NUMERICHOST);
			cout<<"Conexion : " <<host<<": "<<serv;
			cout<< " Mensaje: "<<buf<<"\n";
			sendto(sd,buf,s,0,&src_addr,addrlen);
		}

		freeaddrinfo(res);
}





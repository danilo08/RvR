/*
 * ejercicio1.cc
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

	for(struct addrinfo *tmp=res;tmp!=0;tmp=tmp->ai_next){

		char host [NI_MAXHOST];
		char serv [NI_MAXSERV];
		getnameinfo(tmp->ai_addr,tmp->ai_addrlen,host,NI_MAXHOST,
				serv,NI_MAXSERV,NI_NUMERICHOST);

			cout<<"Host: "<<host<<"  "<<tmp->ai_family<<" " <<tmp->ai_socktype<<"\n";
	}
freeaddrinfo(res);
}

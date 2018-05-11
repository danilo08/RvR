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
		char host [NI_MAXHOST];
		char serv [NI_MAXSERV];
		getnameinfo(res->ai_addr,res->ai_addrlen,host,NI_MAXHOST,
				serv,NI_MAXSERV,NI_NUMERICHOST);
		char buf[256];
				
				
		
		struct sockaddr cliente;
		
		socklen_t cliente_len=sizeof(cliente);
		
		
		int cliente_sd = accept(sd, (struct sockaddr *) &cliente, &cliente_len);
		
		bind(sd, (struct sockaddr *) res->ai_addr, res->ai_addrlen);//
		listen(sd, 5);//
	
		while(true){

			ssize_t s=recvfrom(sd,buf,255,0,&cliente,&cliente_len);

			getnameinfo((struct sockaddr *) &cliente, cliente_len, host, 
      NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST|NI_NUMERICSERV);

			cout<<"Conexion : " <<host<<": "<<serv;
			cout<<"Puerto : " <<host<<": "<<serv;
			
			int  c = recv(cliente_sd, &(buf), 255, 0);
	int i=0;
do{
		c = recv(cliente_sd, &(buf[i]), 1, 0);
  
   } while ( c >= 0 && i < 79 && buf[i++] != '\n');
  		send(cliente_sd, buf, i, 0);
  
	}	

		freeaddrinfo(res);
}
		
  			
				
		

	






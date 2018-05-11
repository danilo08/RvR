

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

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
	int conc = connect(sd, res->ai_addr, res->ai_addrlen);
	
	if(rc!=0){
	cout<<"error"<< <<endl;
	return-1;
	}
		
		if(sd==-1||conc==-1){
		cout<<"error "<<endl;
			return-1;
		}
	
		char peticion[256];
		memset((void*) peticion,'\0',256);
		bool conect=true;
				
		
		struct sockaddr cliente;
		
		socklen_t cliente_len=sizeof(cliente);
		
	
		while(conect){
		cin>>peticion;
			send(sd,peticion,256,0);
			ssize_t s=recv(sd,peticion,256,0);
			cout>>peticion>>endl;
			
		}
		freeaddrinfo(res);
  			
				return 0;
	}	

	






/*	IMPLEMENTIRANE SU FUNKCIJE:
	a) exit - izlazak iz programa                                            	  [mora da radi] 
	b) mkfile [putanja do fajla] - pravi novi prazan fajl                             [treba da radi]
	c) mkdir [putanja do direktorijuma] - pravi novi direktorijum                     [treba da radi]
	d) rm [putanja do fajla] - brise fajl                                             [treba da radi]
	e) rmdir [putanja do praznog direktorijuma] - brise prazan direktorijum           [treba da radi]
*/
#include <sys/types.h>				
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NISKA 51

/*kod narednog define-a, __FILE__ je sistemski makro koji se menja uvek sa trenutnim fajlom nad kojim operisemo,
 __func__ je makro se menja sa trenutnom funkcijom koju izvrsavamo, a __LINE__ predstavlja trenutnu liniju koju izvrsavamo */
 
#define osErrorFatal(userMsg) osErrorFatalImpl((userMsg), __FILE__, __func__, __LINE__)
#define osAssert(expr, userMsg) \
	do{ \
		if(!(expr)) \
			osErrorFatal(userMsg); \
	} while(0);

void osErrorFatalImpl(const char *userMsg, const char *fileName, const char *funcName, const int lineNum);
bool osFileOpen(const char* filePath,const char *mode,int *fd);              
int main(int argc,char **argv)
{
	char niska[MAX_NISKA];					//niska "niska" predstavlja naredbu koja se cita
	char niska2[MAX_NISKA];					//niska "niska2" predstavlja ime fajla(foldera sa kojim se operise)
        while(1)
        {
        	printf("%% ");
        	fscanf(stdin,"%s",niska);
        	if(!strcmp(niska,"exit"))			//izlaz iz programa
        		break;
        	else if(!strcmp(niska,"mkdir"))			//pravljenje direktorijum
		{
			fscanf(stdin,"%s",niska2);
			static mode_t defaultModeDir = 0644;
			osAssert(mkdir(niska2,defaultModeDir)>= 0,"Pravljenje foldera nije uspelo\n");

		}      
		else if(!strcmp(niska,"mkfile"))		//pravi fajl
		{
			fscanf(stdin,"%s",niska2);
			static mode_t defaultModeFile = 0644;
			int fd;
			osAssert(osFileOpen(niska2,"w",&fd), "Pravljenje fajla nije uspelo\n");
			close(fd);
		}
		else if(!strcmp(niska,"rmdir"))			//brise direktorijum
		{
			fscanf(stdin,"%s",niska2);
			osAssert(rmdir(niska2)>=0 ,"Brisanje direktorijuma nije uspelo\n"); //rmdir-sistemska fja za brisanje direktorijuma
		} 
		else if(!strcmp(niska,"rmfile"))		//brise fajl
		{
			fscanf(stdin,"%s",niska2);
			osAssert(unlink(niska2)>=0, "Brisanje fajla nije uspelo\n");	//unlink - sistemska funkcija za brisanje fajla
		} 	
		else
		{
			printf("%% Nepostojeca operacija\n");	
		}	
        }
        return 0;
}
void osErrorFatalImpl(const char *userMsg, const char *fileName, 
                      const char *functionName, const int lineNum) {
    perror(userMsg);
    fprintf(stderr, "File: '%s'\nFunction: '%s'\nLine: '%d'\n", fileName, functionName, lineNum);
    exit(EXIT_FAILURE);
}
bool osFileOpen(const char* filePath,const char *mode,int *fd)
{
	static mode_t defaultMode = 0644;
	int flags = 0;
	
	switch(mode[0])	
	{
		case 'r':
			flags |= '+' == mode[1] ? O_RDWR : O_RDONLY;	//RDWR - read write ; RDONLY - read only
			break;
		case 'w':
			flags |= '+' == mode[1] ? O_RDWR : O_WRONLY;	//WRONLY - write only
			flags |= O_TRUNC;	//kad otvori neku datoteku, brise celokupan sadrzaj iz nje
			flags |= O_CREAT;	//ako ne postoji ime foldera koje je dato, pravi se novi folder sa tim imenom
			break;
		case 'a':
			flags |= '+' == mode[1] ? O_RDWR : O_WRONLY;
			flags |= O_CREAT;	
			flags |= O_APPEND;	
			break;
		default:
			return false;
	}
	
	*fd = open(filePath,flags,defaultMode);
	return *fd >=0;	
}

















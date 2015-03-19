#include <Windows.h>
#include <WinInet.h>
#include <stdio.h>

#pragma comment(lib, "wininet.lib")

int main(int argc, char * argv[]) 
{ 
	//char buff[256] = "127.0.0.1:8087";
	//char buff2[256] = "http://127.0.0.1:8086/proxy.pac"; 
	// To include server for FTP, HTTPS, and so on, use the string
	// (ftp=http://<ProxyServerName>:80; https=https://<ProxyServerName>:80) 
	INTERNET_PER_CONN_OPTION_LIST    List; 
	INTERNET_PER_CONN_OPTION         Option[3]; 
	unsigned long                    nSize = sizeof(INTERNET_PER_CONN_OPTION_LIST); 

	Option[0].dwOption = INTERNET_PER_CONN_FLAGS; 
	Option[1].dwOption = INTERNET_PER_CONN_AUTOCONFIG_URL; 
	Option[2].dwOption = INTERNET_PER_CONN_PROXY_SERVER; 

	List.dwSize = sizeof(INTERNET_PER_CONN_OPTION_LIST); 
	List.pszConnection = NULL; 
	List.dwOptionCount = 3; 
	List.dwOptionError = 0; 
	List.pOptions = Option; 

	if(!InternetQueryOption(NULL, INTERNET_OPTION_PER_CONNECTION_OPTION, &List, &nSize)) 
		printf("InternetQueryOption failed! (%d)\n", GetLastError()); 

	if((Option[0].Value.dwValue & INTERNET_PER_CONN_AUTOCONFIG_URL) != NULL)
		printf("PAC:%s\n", Option[1].Value.pszValue);
	else if((Option[0].Value.dwValue & INTERNET_PER_CONN_PROXY_SERVER) != NULL)
		printf("proxy server: %s\n", Option[2].Value.pszValue);
	else if ((Option[0].Value.dwValue & PROXY_TYPE_DIRECT) != NULL)
		printf("Direct Connection!");


	return 0; 

}
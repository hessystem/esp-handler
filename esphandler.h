//March,24
//I added some simple method
//there are other method which i haven't added yet such as check join devices from certain IP, TCP/IP connection status
//Send TCP/IP data and so on
//parameters from these method are still not correct
#include "Arduino.h";
#include "SoftwareSerial.h"
class esphandler
{
public:
	SoftwareSerial wifimodul(0,0);
	esphandler(int RX,int TX);
	~esphandler(int RX,int TX);
	void checkCommand(String command);
	String getResponse(String resp);
	String joinAP(String ssid,String password);
	String firmwareVersion();
	String listAP();
	String QuitAP();
	String getIP();
	String setparamAP();
	String wifiMode(char mode);
	String TCPUDP(char p);
};
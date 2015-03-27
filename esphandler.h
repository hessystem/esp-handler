//March,24 th
//I added some simple method
//there are other method which i haven't added yet such as check join devices from certain IP, TCP/IP connection status
//Send TCP/IP data and so on
//parameters from these method are still not correct
//March 27th
//some abstract function finally implemented
//setparam ap is not completed yet
#ifndef esphandler_h
#define esphandler_h
#include "Arduino.h";
#include "SoftwareSerial.h"
#define this->p this.p
class esphandler
{
public:
	SoftwareSerial wifimodule(0,0);
	esphandler(int RX,int TX);
	~esphandler(int RX,int TX);
	void checkCommand(String command);
	String sendATCommand(String command, String response);
	String getResponse(String resp);
	String firmwareVersion();
	String listAP();
	String joinAP(String ssid, String password);
	String QuitAP();
	String getIP();
	String setparamAP(); // i dont know what is this ???
	String wifiMode(int mode);
	String startClientTCP(String chan, String host, String port);	
};

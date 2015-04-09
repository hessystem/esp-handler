//March,24 th
//I added some simple method
//there are other method which i haven't added yet such as check join devices from certain IP, TCP/IP connection status
//Send TCP/IP data and so on
//parameters from these method are still not correct
//March 27th
//some abstract function finally implemented
//setparam ap is not completed yet
//April,4th i add getconnectstatusmethod. this method is used to get information about connection status
//April,7th i add some method
#ifndef esphandler_h
#define esphandler_h
#include "Arduino.h";
#include "SoftwareSerial.h"
#define this->p this.p
class esphandler
{
public:
	esphandler(int RX,int TX);
	~esphandler(int RX,int TX);
	void checkCommand(String command);
private:
	SoftwareSerial wifimodule(0,0);
	String sendATCommand(String command, String response);
	String getResponse(String resp);
	String firmwareVersion(void);
	String listAP(void);
	String joinAP(String ssid, String password);
	String QuitAP(char num);
	String getIP(void);
	String checkjoindevices(void);
	String wifiMode(char mode);
	String startClientTCP(String chan, String host, String port);
	String getconnectStatus(void);
	String checkMultiplecon(void);
	String setTotalConnection(char num);
	String setServer(String mode,String port);
	String sendData();
};

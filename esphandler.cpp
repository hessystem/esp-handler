//March, 27th : i added getresponse, firmware version and list of AP function. i think getresponse function is not yet completed
//April, 3rd : finally, the problem about  how to change RX and TX value on wifimodule attribute is solved
#include "esphandler.h";
#include "Arduino.h";

esphandler::esphandler(int RX,int TX,int rate)
{
	SoftwareSerial temp(RX,TX);
	this.wifimodule = temp ;
	this.wifimodule.begin(rate);
}
void esphandler::Checkcommand(String command);
{
	command=String.toLowerCase(command);
	if(command.equals("working"))
	{
		Serial.println(this.getResponse("AT"));
	}
	else if(command.equals("restart"))
	{
		Serial.println(this.getResponse("AT+RST"));
	}
	else if(command.equals("firmware"))
	{
		Serial.println(this.getResponse(this.firmwareVersion));
	}
	else if(command.equals("list_ap"))
	{
		Serial.println(this.getResponse(this.listAP()));
	}
	else if(command.equals("join_ap"))
	{
		
	}
}
String esphandler::getResponse(String resp)
{
	this.wifimodule.print(resp);
	String response="";
	while(this.wifimodule.available())
	{
		char l = this.wifimodule.read();
		response = response+l;
	}
	return response;
}
String esphandler::firmwareVersion(void)
{
	return "AT+GMR";
}
String esphandler::listAP();
{
	return "AT+CWLAP";
}
String esphandler::joinAP(String ssid, String password)
{
	String join=String.concat("AT+CWJAP=<",ssid);
	join=String.concat(join,">");
	join=String.concat(join,",");
	join=String.concat(join,"<");
	join=String.concat(join,"password");
	join=String.concat(join,">");
	return join;
}


#include "esphandler.h";
#include "Arduino.h";

esphandler::esphandler(int RX,int TX)
{
	this.wifimodule(RX,TX);
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
		//this.getResponse("Restart done");
	}
	else if(command.equals("firmware"))
	{
		//this.getResponse(this.firmwareVersion());
	}
	else if(command.equals("list_ap"))
	{
		this.getResponse
	}
	else
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


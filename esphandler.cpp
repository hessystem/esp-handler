#include "esphandler.h";
#include "Arduino.h";
esphandler::esphandler(int RX,int TX)
{
	this.wifimodul(RX,TX);
}
void esphandler::Checkcommand(String command);
{
	command=String.toLowerCase(command);
	if(command.equals(String.toLowerCase("working")))
	{
		this.getResponse("it's working");
	}
	else if(command.equals(String.toLowerCase("restart")))
	{
		this.getResponse("Restart done");
	}
	else if(command.equals(String.toLowerCase("firmware")))
	{
		this.getResponse(this.firmwareVersion());
	}
	else
	{
		
	}
}


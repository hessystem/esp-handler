//March, 27th : i added getresponse, firmware version and list of AP function. i think getresponse function is not yet completed
//April, 3rd : finally, the problem about  how to change RX and TX value on wifimodule attribute is solved
//April, 6th : i added 3 more method : getconnectStatus, setTotalConnection and checkMultipleConnection
//April, 7th : i implemented some method that have not implemented yet (you dont say) 
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
		Serial.println(this.getResponse(this.firmwareVersion()));
	}
	else if(command.equals("list_ap"))
	{
		Serial.println(this.getResponse(this.listAP()));
	}
	else if(command.equals("join_ap"))
	{
		char ssid[40] = Serial.read();
		char password[20] = Serial.read();
	}
	else if(command.equals("multicon?"))
	{
		Serial.println(this.getResponse(this.checkMultipleCon()));	
	}
	else if(command.equals("setcon"))
	{
		Serial.print("\nset mode:");
		char t = Serial.read();
		if((t=='0')||(t=='1'))
		{
			Serial.println("");
			Serial.println(this.getResponse(this.setTotalConnection(t)));		
		}
		else
		{
			Serial.print("\nonly available with mode 0 or 1 ");
		}
	}
	else if(command.equals("con_stat"))
	{
		Serial.println(this.getResponse(this.getconnectStatus()));
	}
	else if(command.equals("quit_ap"))
	{
		Serial.println(this.getResponse(this.QuitAP('1')));
	}
	else if(command.equals("connectap?"))
	{
		Serial.println(this.getResponse(this.QuitAP('0')));
	}
	else if(command.equals("wifimode?"))
	{
		Serial.println(this.getResponse(this.wifiMode('0')));
	}
	else if(command.equals("setwifimode"))
	{
		char mode = Serial.read();
		if((mode=='1')||(mode=='2')||(mode=='3'))
		{
			Serial.println(this.getResponse(this.wifiMode(mode)));
		}
		else
		{
			Serial.println("\nthis module will work with mode 1,2 or 3");
		}
		
	}
	else if(command.equals("setserver"))
	{
		char mode2 = Serial.readln();
		char port2[5] = Serial.readln();
		String mod(mode2);
		String 
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
	return "AT+GMR\n";
}
String esphandler::listAP(void);
{
	return "AT+CWLAP\n";
}
String esphandler::joinAP(String ssid, String password)
{
	return "AT+CWJAP=\"" + ssid + "\"" + "," + "\"" + password + "\"" + "\n";
}
String esphandler::startClientTCP(String chan, String host, String port)
{
	return "AT+CIPSTART="+chan+",\"TCP\",\""+host+"\","+port;
}
String esphandler::checkMultiplecon(void)
{
	return "AT+CIPMUX?\n";
}
String esphandler::setTotalConnection(char num)
{
	return "AT+CIPMUX="+num;
}
String esphandler::getconnectStatus(void)
{
	return "AT+CIPSTATUS\n";
}
String esphandler::QuitAP(void)
{
	return "AT+CWQAP\n";
}
String esphandler::getIP(void)
{
	return "AT+CIFSR\n";
}
String esphandler::setServer(String mode,String port);
{
	return "AT+CIPSERVER=" + mode + "," + port;
}
String esphandler::QuitAP(char num)
{
	if(num=='1')
	{
		return"AT+CWQAP?";
	}
	else
	{
		return"AT+CWQAP";
	}
}
String esphandler::wifiMode(char mode)
{
	if(mode=='0')
	{
		return"AT+CWMODE?";
	}
	else
	{
		return "AT+CWMODE="mode);
	}
}
String esphandler::sendData()
{
	
}

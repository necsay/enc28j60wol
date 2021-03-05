#include <UIPEthernet.h>

//#define resetPin 8 //uncomment for HARD-RESET

byte mac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 }; //setting up a mac address for enc28j60.

byte ip[] = { 192, 168, 1, 177 };  // local IP address for enc28j60

byte myDns[] = {192, 168, 1, 1};   // DNS

byte gateway[] = {192, 168, 1, 1}; // Gateway



EthernetUDP udp;

const char remoteServer[] = "www.arduino.cc"; //remote server
const char host[]= "Host: www.arduino.cc";
const char page[]= "GET /latest.txt HTTP/1.1"; // request www.arduino.cc/latest.txt
 
 //remote server
EthernetClient remoteClient;
byte port = 80;          //Port to connect, set to default HTTP


String remoteString;

unsigned long lastConnection = 0;           // time of the last connection to remote server

const unsigned long repeatTimer = 1000 * 25; 
//repeatTimer *= 25;  // repeating frequency in seconds to send requests to server

// Mac Addresses for your devices  
// Note: MAC addresses are hexadecimal hence we use 0x notation
// Example: MAC address of TargetMac1 is 01-69-2D-30-AA
const PROGMEM byte targetMac1[6] = {0x01,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac2[6] = {0x02,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac3[6] = {0x03,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac4[6] = {0x04,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac5[6] = {0x05,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac6[6] = {0x06,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac7[6] = {0x07,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac8[6] = {0x08,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac9[6] = {0x09,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac10[6] = {0x10,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac11[6] = {0x11,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac12[6] = {0x12,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac13[6] = {0x13,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac14[6] = {0x14,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac15[6] = {0x15,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac16[6] = {0x16,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac17[6] = {0x17,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac18[6] = {0x18,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac19[6] = {0x19,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac20[6] = {0x20,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac21[6] = {0x21,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac22[6] = {0x22,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac23[6] = {0x23,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac24[6] = {0x24,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac25[6] = {0x25,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac26[6] = {0x26,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac27[6] = {0x27,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac28[6] = {0x28,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac29[6] = {0x29,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac30[6] = {0x30,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac31[6] = {0x31,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac32[6] = {0x32,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac33[6] = {0x33,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac34[6] = {0x34,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac35[6] = {0x35,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac36[6] = {0x36,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac37[6] = {0x37,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac38[6] = {0x38,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac39[6] = {0x39,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac40[6] = {0x40,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac41[6] = {0x41,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac42[6] = {0x42,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac43[6] = {0x43,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac44[6] = {0x44,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac45[6] = {0x45,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac46[6] = {0x46,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac47[6] = {0x47,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac48[6] = {0x48,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac49[6] = {0x49,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac50[6] = {0x50,0x69,0x69,0x2D,0x30,0xAA};


 

void setup(){
//  digitalWrite(resetPin,HIGH);    //uncomment for HARD-RESET
//  pinMode(resetPin,OUTPUT);       //uncomment for HARD-RESET


	Ethernet.begin(mac, ip, myDns, gateway);
	  

	
//	Serial.begin(9600);

}

//void(* resetFunc) (void) = 0;   //uncomment for SOFT-RESET

// A magic packet consists of 6 FF HEX values followed by mac address repeated 16 times

int sendwol( byte *targetMac){                           // function for wake on lan signal
	
	udp.beginPacket(IPAddress(255,255,255,255),9);         // broadcast to whole network from port 9 
  
//note: broadcast does not involve IP addresses it's a data link layer signal.
  
	for (int i = 0; i < 6; i++) udp.write(0xFF);           // Write first 6 FF HEX values of magic packet.
	  
	  
	//for (byte i = 0; i < 16; i++) udp.write(targetMac,6); //If you haven't placed your MAC addresses in PROGMEM use this instead of following function 

	for (byte i = 0; i<16;i++){                            
	for (byte i = 0; i < 6; i ++) udp.write(pgm_read_byte(&targetMac[i]));       
	//Read MAC address from PROGMEM and add to udp.write packet 16 times
	}
  
	udp.endPacket();  // Seal the packet and send
	udp.stop();
}
 
void loop(){

//	if (millis()>600000) resetFunc();           // uncomment for SOFT-RESET every 600 seconds
//  if (millis()>600000) digitalWrite(resetPin,LOW);     //uncomment for HARD-RESET every 600 seconds


	if (remoteClient.available()) {
		
		char d = remoteClient.read();
		remoteString += d;
	}

	if (millis() - lastConnection > repeatTimer) httpRequest();
}


void httpRequest() {



	remoteClient.stop();

	if (remoteClient.connect(remoteServer, port)) { //if the connection was successful

		remoteClient.println(page);
		//Instead of defining a const char you could also use the following line
		//remoteClient.println("GET /latest.txt HTTP/1.1");
		
		remoteClient.println(host);
		//Instead of defining a const char you could also use the following line
		//remoteClient.println("Host: www.arduino.com");

		remoteClient.println("Connection: close");

		remoteClient.println();


		lastConnection = millis();

	} else {

    // if you couldn't make a connection:

	//Serial.println("connection failed");

	}
	
	// IndexOf will check the page if the string you define exists.
	// Be vary if you do Computer200 that includes Computer2 as well so choose names wisely
	// Suppose you set a wake up for computer, and another for personal computer
	// So when you have personal computer on your web page
	// You will end up waking both "personal computer" and "computer" up
	// So the ideal case would be doing it like "Computer001" instead of "Computer1"
	// Notice that there is no else statement to if statements 
	// This is because one could have a list of computers that should be running.
   	
	if(remoteString.indexOf(F("computer50")) >0) sendwol(targetMac50);
	if(remoteString.indexOf(F("computer49")) >0) sendwol(targetMac49);
	if(remoteString.indexOf(F("computer48")) >0) sendwol(targetMac48);
	if(remoteString.indexOf(F("computer47")) >0) sendwol(targetMac47);
	if(remoteString.indexOf(F("computer46")) >0) sendwol(targetMac46);
	if(remoteString.indexOf(F("computer45")) >0) sendwol(targetMac45);
	if(remoteString.indexOf(F("computer44")) >0) sendwol(targetMac44);
	if(remoteString.indexOf(F("computer43")) >0) sendwol(targetMac43);
	if(remoteString.indexOf(F("computer42")) >0) sendwol(targetMac42);
	if(remoteString.indexOf(F("computer41")) >0) sendwol(targetMac41);
	if(remoteString.indexOf(F("computer40")) >0) sendwol(targetMac40);
	if(remoteString.indexOf(F("computer39")) >0) sendwol(targetMac39);
	if(remoteString.indexOf(F("computer38")) >0) sendwol(targetMac38);
	if(remoteString.indexOf(F("computer37")) >0) sendwol(targetMac37);
	if(remoteString.indexOf(F("computer36")) >0) sendwol(targetMac36);
	if(remoteString.indexOf(F("computer35")) >0) sendwol(targetMac35);
	if(remoteString.indexOf(F("computer34")) >0) sendwol(targetMac34);
	if(remoteString.indexOf(F("computer33")) >0) sendwol(targetMac33);
	if(remoteString.indexOf(F("computer32")) >0) sendwol(targetMac32);
	if(remoteString.indexOf(F("computer31")) >0) sendwol(targetMac31);
	if(remoteString.indexOf(F("computer30")) >0) sendwol(targetMac30);
	if(remoteString.indexOf(F("computer29")) >0) sendwol(targetMac29);
	if(remoteString.indexOf(F("computer28")) >0) sendwol(targetMac28);
	if(remoteString.indexOf(F("computer27")) >0) sendwol(targetMac27);
	if(remoteString.indexOf(F("computer26")) >0) sendwol(targetMac26);
	if(remoteString.indexOf(F("computer25")) >0) sendwol(targetMac25);
	if(remoteString.indexOf(F("computer24")) >0) sendwol(targetMac24);
	if(remoteString.indexOf(F("computer23")) >0) sendwol(targetMac23);
	if(remoteString.indexOf(F("computer22")) >0) sendwol(targetMac22);
	if(remoteString.indexOf(F("computer21")) >0) sendwol(targetMac21);
	if(remoteString.indexOf(F("computer20")) >0) sendwol(targetMac20);
	if(remoteString.indexOf(F("computer19")) >0) sendwol(targetMac19);
	if(remoteString.indexOf(F("computer18")) >0) sendwol(targetMac18);
	if(remoteString.indexOf(F("computer17")) >0) sendwol(targetMac17);
	if(remoteString.indexOf(F("computer16")) >0) sendwol(targetMac16);
	if(remoteString.indexOf(F("computer15")) >0) sendwol(targetMac15);
	if(remoteString.indexOf(F("computer14")) >0) sendwol(targetMac14);
	if(remoteString.indexOf(F("computer13")) >0) sendwol(targetMac13);
	if(remoteString.indexOf(F("computer12")) >0) sendwol(targetMac12);
	if(remoteString.indexOf(F("computer11")) >0) sendwol(targetMac11);
	if(remoteString.indexOf(F("computer10")) >0) sendwol(targetMac10);
	if(remoteString.indexOf(F("computer09")) >0) sendwol(targetMac9);
	if(remoteString.indexOf(F("computer08")) >0) sendwol(targetMac8);
	if(remoteString.indexOf(F("computer07")) >0) sendwol(targetMac7);
	if(remoteString.indexOf(F("computer06")) >0) sendwol(targetMac6);
	if(remoteString.indexOf(F("computer05")) >0) sendwol(targetMac5);
	if(remoteString.indexOf(F("computer04")) >0) sendwol(targetMac4);
	if(remoteString.indexOf(F("computer03")) >0) sendwol(targetMac3);
	if(remoteString.indexOf(F("computer02")) >0) sendwol(targetMac2);
	if(remoteString.indexOf(F("computer01")) >0) sendwol(targetMac1);
	remoteString="";
}

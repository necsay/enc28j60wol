
#include <UIPEthernet.h>

//#define resetPin 8 //uncomment for HARD-RESET

byte mac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 }; //setting up a mac address for enc28j60.

byte ip[] = { 192, 168, 1, 177 };  // local IP address for enc28j60

//byte myDns[] = {192, 168, 1, 1};
// DNS is not really required in this setup
// Should you require a specific need for name resolution you can uncomment
// Another example {8, 8, 8, 8}

EthernetServer localServer(80);         //server port 80 HTTP
EthernetUDP udp;

String localString;


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
const PROGMEM byte targetMac51[6] = {0x51,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac52[6] = {0x52,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac53[6] = {0x53,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac54[6] = {0x54,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac55[6] = {0x55,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac56[6] = {0x56,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac57[6] = {0x57,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac58[6] = {0x58,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac59[6] = {0x59,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac60[6] = {0x60,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac61[6] = {0x61,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac62[6] = {0x62,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac63[6] = {0x63,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac64[6] = {0x64,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac65[6] = {0x65,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac66[6] = {0x66,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac67[6] = {0x67,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac68[6] = {0x68,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac69[6] = {0x69,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac70[6] = {0x70,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac71[6] = {0x71,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac72[6] = {0x72,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac73[6] = {0x73,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac74[6] = {0x74,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac75[6] = {0x75,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac76[6] = {0x76,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac77[6] = {0x77,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac78[6] = {0x78,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac79[6] = {0x79,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac80[6] = {0x80,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac81[6] = {0x81,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac82[6] = {0x82,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac83[6] = {0x83,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac84[6] = {0x84,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac85[6] = {0x85,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac86[6] = {0x86,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac87[6] = {0x87,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac88[6] = {0x88,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac89[6] = {0x89,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac90[6] = {0x90,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac91[6] = {0x91,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac92[6] = {0x92,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac93[6] = {0x93,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac94[6] = {0x94,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac95[6] = {0x95,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac96[6] = {0x96,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac97[6] = {0x97,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac98[6] = {0x98,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac99[6] = {0x99,0x69,0x69,0x2D,0x30,0xAA};
const PROGMEM byte targetMac100[6] = {0x10,0xAA,0xAA,0xAA,0xAA,0xAA};

 

void setup(){
//  digitalWrite(resetPin,HIGH);    //uncomment for HARD-RESET
//  pinMode(resetPin,OUTPUT);       //uncomment for HARD-RESET

Ethernet.begin(mac, ip);

// Ethernet.begin(mac, ip, myDns); // uncomment for DNS

  
  localServer.begin();
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

//if (millis()>600000) resetFunc();           // uncomment for SOFT-RESET every 600 seconds
//  if (millis()>600000) digitalWrite(resetPin,LOW);     //uncomment for HARD-RESET every 600 seconds
  
  EthernetClient localClient = localServer.available();   // Create a client connection
  if (localClient) {
    while (localClient.connected()) {
      if (localClient.available()) {
        char c = localClient.read(); //read char by char HTTP request
 
        if (localString.length() < 100) {
          //store characters 1 by 1 to string
          localString += c;
        }
 
        //if HTTP request has ended
        if (c == '\n') {

  // YOUR HTML WEB PAGE IS HERE
  //I wouldn't recommend putting a direct link in web page because anyone can run your computer if IP is obtained.

localClient.println(F("<br><style>body{background:tan}*{font-size:18pt}</style>Enter PC ID: <input id=\"t\"> <button onclick=\"location.href='?'+document.getElementById('t').value\">TURN ON<title>MY REMOTE"));

// You could also do localClient.println(""); if you don't want to use PROGMEM.
// A single line is better for ram management
// However, if that is not an issue multiple localClient.println functions could be utilized
 
          delay(1);
          //stopping client
          client.stop();

// All set up, here we need to analyize the string localString which is simply the URL requested by browser

/* Here is an example empty localString:
GET /? HTTP/1.1

GET /favicon.ico HTTP/1.1
*/

// On this URL nothing was typed into the box, so it is minimal string
/* When we enter test string to box we get:
GET /?test%20string HTTP/1.1

GET /favicon.ico HTTP/1.1
*/
// Notice "%20" which is simply a single space

// In the following section we will be using indexOf method I suggest looking it up.
// IndexOf will check if the entered text includes the text you give it.
// Be vary if you do Computer200 that includes Computer2 as well
// So the ideal case would be looking for Computer002 instead of Computer200
// However for using less ram I'm using computer2 instead of computer 200
// For this reason I 

          if(localString.indexOf(F("computer100")) >0) sendwol(targetMac100);
          // Computer 100 is your-pc-id-link, you will have to enter this link
          // Example "HP%20server%20xyzfc" so when you enter to box "HP server password" it boots the corresponding server. 
          // YOU HAVE TO PUT LONGEST STRINGS ON TOP, if you put computer2 on top, even if you type computer200 the computer2 will fire up because "computer200" includes "computer2".
          // Do not use if instead of else if because you will end up waking up more computers because of the reason I just pointed out.



          else if(localString.indexOf(F("computer99")) >0) sendwol(targetMac99);
          else if(localString.indexOf(F("computer98")) >0) sendwol(targetMac98);
          else if(localString.indexOf(F("computer97")) >0) sendwol(targetMac97);
          else if(localString.indexOf(F("computer96")) >0) sendwol(targetMac96);
          else if(localString.indexOf(F("computer95")) >0) sendwol(targetMac95);
          else if(localString.indexOf(F("computer94")) >0) sendwol(targetMac94);
          else if(localString.indexOf(F("computer93")) >0) sendwol(targetMac93);
          else if(localString.indexOf(F("computer92")) >0) sendwol(targetMac92);
          else if(localString.indexOf(F("computer91")) >0) sendwol(targetMac91);
          else if(localString.indexOf(F("computer90")) >0) sendwol(targetMac90);
          else if(localString.indexOf(F("computer89")) >0) sendwol(targetMac89);
          else if(localString.indexOf(F("computer88")) >0) sendwol(targetMac88);
          else if(localString.indexOf(F("computer87")) >0) sendwol(targetMac87);
          else if(localString.indexOf(F("computer86")) >0) sendwol(targetMac86);
          else if(localString.indexOf(F("computer85")) >0) sendwol(targetMac85);
          else if(localString.indexOf(F("computer84")) >0) sendwol(targetMac84);
          else if(localString.indexOf(F("computer83")) >0) sendwol(targetMac83);
          else if(localString.indexOf(F("computer82")) >0) sendwol(targetMac82);
          else if(localString.indexOf(F("computer81")) >0) sendwol(targetMac81);
          else if(localString.indexOf(F("computer80")) >0) sendwol(targetMac80);
          else if(localString.indexOf(F("computer79")) >0) sendwol(targetMac79);
          else if(localString.indexOf(F("computer78")) >0) sendwol(targetMac78);
          else if(localString.indexOf(F("computer77")) >0) sendwol(targetMac77);
          else if(localString.indexOf(F("computer76")) >0) sendwol(targetMac76);
          else if(localString.indexOf(F("computer75")) >0) sendwol(targetMac75);
          else if(localString.indexOf(F("computer74")) >0) sendwol(targetMac74);
          else if(localString.indexOf(F("computer73")) >0) sendwol(targetMac73);
          else if(localString.indexOf(F("computer72")) >0) sendwol(targetMac72);
          else if(localString.indexOf(F("computer71")) >0) sendwol(targetMac71);
          else if(localString.indexOf(F("computer70")) >0) sendwol(targetMac70);
          else if(localString.indexOf(F("computer69")) >0) sendwol(targetMac69);
          else if(localString.indexOf(F("computer68")) >0) sendwol(targetMac68);
          else if(localString.indexOf(F("computer67")) >0) sendwol(targetMac67);
          else if(localString.indexOf(F("computer66")) >0) sendwol(targetMac66);
          else if(localString.indexOf(F("computer65")) >0) sendwol(targetMac65);
          else if(localString.indexOf(F("computer64")) >0) sendwol(targetMac64);
          else if(localString.indexOf(F("computer63")) >0) sendwol(targetMac63);
          else if(localString.indexOf(F("computer62")) >0) sendwol(targetMac62);
          else if(localString.indexOf(F("computer61")) >0) sendwol(targetMac61);
          else if(localString.indexOf(F("computer60")) >0) sendwol(targetMac60);
          else if(localString.indexOf(F("computer59")) >0) sendwol(targetMac59);
          else if(localString.indexOf(F("computer58")) >0) sendwol(targetMac58);
          else if(localString.indexOf(F("computer57")) >0) sendwol(targetMac57);
          else if(localString.indexOf(F("computer56")) >0) sendwol(targetMac56);
          else if(localString.indexOf(F("computer55")) >0) sendwol(targetMac55);
          else if(localString.indexOf(F("computer54")) >0) sendwol(targetMac54);
          else if(localString.indexOf(F("computer53")) >0) sendwol(targetMac53);
          else if(localString.indexOf(F("computer52")) >0) sendwol(targetMac52);
          else if(localString.indexOf(F("computer51")) >0) sendwol(targetMac51);
          else if(localString.indexOf(F("computer50")) >0) sendwol(targetMac50);
          else if(localString.indexOf(F("computer49")) >0) sendwol(targetMac49);
          else if(localString.indexOf(F("computer48")) >0) sendwol(targetMac48);
          else if(localString.indexOf(F("computer47")) >0) sendwol(targetMac47);
          else if(localString.indexOf(F("computer46")) >0) sendwol(targetMac46);
          else if(localString.indexOf(F("computer45")) >0) sendwol(targetMac45);
          else if(localString.indexOf(F("computer44")) >0) sendwol(targetMac44);
          else if(localString.indexOf(F("computer43")) >0) sendwol(targetMac43);
          else if(localString.indexOf(F("computer42")) >0) sendwol(targetMac42);
          else if(localString.indexOf(F("computer41")) >0) sendwol(targetMac41);
          else if(localString.indexOf(F("computer40")) >0) sendwol(targetMac40);
          else if(localString.indexOf(F("computer39")) >0) sendwol(targetMac39);
          else if(localString.indexOf(F("computer38")) >0) sendwol(targetMac38);
          else if(localString.indexOf(F("computer37")) >0) sendwol(targetMac37);
          else if(localString.indexOf(F("computer36")) >0) sendwol(targetMac36);
          else if(localString.indexOf(F("computer35")) >0) sendwol(targetMac35);
          else if(localString.indexOf(F("computer34")) >0) sendwol(targetMac34);
          else if(localString.indexOf(F("computer33")) >0) sendwol(targetMac33);
          else if(localString.indexOf(F("computer32")) >0) sendwol(targetMac32);
          else if(localString.indexOf(F("computer31")) >0) sendwol(targetMac31);
          else if(localString.indexOf(F("computer30")) >0) sendwol(targetMac30);
          else if(localString.indexOf(F("computer29")) >0) sendwol(targetMac29);
          else if(localString.indexOf(F("computer28")) >0) sendwol(targetMac28);
          else if(localString.indexOf(F("computer27")) >0) sendwol(targetMac27);
          else if(localString.indexOf(F("computer26")) >0) sendwol(targetMac26);
          else if(localString.indexOf(F("computer25")) >0) sendwol(targetMac25);
          else if(localString.indexOf(F("computer24")) >0) sendwol(targetMac24);
          else if(localString.indexOf(F("computer23")) >0) sendwol(targetMac23);
          else if(localString.indexOf(F("computer22")) >0) sendwol(targetMac22);
          else if(localString.indexOf(F("computer21")) >0) sendwol(targetMac21);
          else if(localString.indexOf(F("computer20")) >0) sendwol(targetMac20);
          else if(localString.indexOf(F("computer19")) >0) sendwol(targetMac19);
          else if(localString.indexOf(F("computer18")) >0) sendwol(targetMac18);
          else if(localString.indexOf(F("computer17")) >0) sendwol(targetMac17);
          else if(localString.indexOf(F("computer16")) >0) sendwol(targetMac16);
          else if(localString.indexOf(F("computer15")) >0) sendwol(targetMac15);
          else if(localString.indexOf(F("computer14")) >0) sendwol(targetMac14);
          else if(localString.indexOf(F("computer13")) >0) sendwol(targetMac13);
          else if(localString.indexOf(F("computer12")) >0) sendwol(targetMac12);
          else if(localString.indexOf(F("computer11")) >0) sendwol(targetMac11);
          else if(localString.indexOf(F("computer10")) >0) sendwol(targetMac10);
          else if(localString.indexOf(F("computer9")) >0) sendwol(targetMac9);
          else if(localString.indexOf(F("computer8")) >0) sendwol(targetMac8);
          else if(localString.indexOf(F("computer7")) >0) sendwol(targetMac7);
          else if(localString.indexOf(F("computer6")) >0) sendwol(targetMac6);
          else if(localString.indexOf(F("computer5")) >0) sendwol(targetMac5);
          else if(localString.indexOf(F("computer4")) >0) sendwol(targetMac4);
          else if(localString.indexOf(F("computer3")) >0) sendwol(targetMac3);
          else if(localString.indexOf(F("computer2")) >0) sendwol(targetMac2);
          else if(localString.indexOf(F("computer1")) >0) sendwol(targetMac1);

                 
          //clear the string
          localString="";
 
        }
      }
    }
  }
}

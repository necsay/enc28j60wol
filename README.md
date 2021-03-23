# enc28j60wol


A project to use Arduino as a WOL server.

Components: Arduino Board(ATmega328P) and ENC28J60 ethernet board.

Pin configuration for ENC28J60 
VCC => 3.3V
GND => GND
CS  => pin 10
SI  => pin 11
SO  => pin 12
SCK => pin 13

LocalHTTPserver.ino: Wake up computers on local network by hosting an HTTP page.

This scenario is useful for networks using Dynamic IP or Static IP. By forwarding selected port on the router a local WOL server can be set up.


Remoteserver.ino: Wake up computers via HTTP GET requests to user defined web server(s).

This scenario is useful for networks behind CGNAT. As the user is behind a dual nat configuration, forwarding ports is not possible.

This approach reverts the operation so the connection is not initiated by the client on the internet. Rather it is the arduino that initiates the connection hence there is no need for port forwarding. 

Localserver&Remoteserver.ino: Both projects above combined. Note that both approaches are using GET requests.
Unfortunately ENC28j60 libraries are not capable of handling HTTPS traffic as of yet hence why both approaches require HTTP connection.


What to do:
1) Work on UDP
2) Work on ipv6
3) Will share PHP/MySQL website for remote server approach, function wise it's complete but needs some polishing.


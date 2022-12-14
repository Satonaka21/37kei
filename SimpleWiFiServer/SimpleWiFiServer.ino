/*
 WiFi Web Server LED Blink

 A simple web server that lets you blink an LED via the web.
 This sketch will print the IP address of your WiFi Shield (once connected)
 to the Serial monitor. From there, you can open that address in a web browser
 to turn on and off the LED on pin 5.

 If the IP address of your shield is yourAddress:
 http://yourAddress/H turns the LED on
 http://yourAddress/L turns it off

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * LED attached to pin 5

 created for arduino 25 Nov 2012
 by Tom Igoe

ported for sparkfun esp32 
31.01.2017 by Jan Hendrik Berlin
 
 */

#include <WiFi.h>

const char* ssid     = "JOHARI2";
const char* password = "987654321a";
const char sendChar = 'e';

WiFiServer server(80);

void setup()
{
    Serial.begin(9600);
    pinMode(5, OUTPUT);      // set the LED pin mode

    delay(10);

    // We start by connecting to a WiFi network

//    Serial.println();
//    Serial.println();
//    Serial.print("Connecting to ");
//    Serial.println(ssid);

    WiFi.begin(ssid, password);
    
    IPAddress ip(192, 168, 179, 12);
    IPAddress subnet(255, 255, 255, 0);
    WiFi.config(ip, ip, subnet);
    
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
//        Serial.print(".");
    }

//    Serial.println("");
//    Serial.println("WiFi connected.");
//    Serial.println("IP address: ");
//    Serial.println(WiFi.localIP());
    
    server.begin();
//    Serial.println("All completed.");
}

int value = 0;

void loop(){
 WiFiClient client = server.available();   // listen for incoming clients
// Serial.println(client);

  if (client) {                             // if you get a client,
//    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        
        client.println("HTTP/1.1 200 OK");
        client.println("Content-type:text/html");
        client.println();
        client.println("<head>");
        client.println("<meta charset=\"UTF-8\">");
        client.println("</head>");
        client.println("<body>");
        client.print("あなたがこれを見ているということは、私はもうhttpリクエストに答えているのでしょう。");
        client.println("</body>");
        client.println();
        break;
      }
    }
    // close the connection:
    client.stop();
//    Serial.println("Client Disconnected.");
    delay(100);
    Serial.write(sendChar);
  }
}

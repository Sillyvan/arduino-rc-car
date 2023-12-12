#include <WiFiNINA.h>
#include <WiFiUdp.h>

char ssid[] = "";        // your network SSID (name)
char pass[] = "";    // your network password (use for WPA, or use as key for WEP)
int status = WL_IDLE_STATUS;     // the Wifi radio's status

WiFiServer server(80);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinMode(2, OUTPUT); //LEFT FORWARD
  pinMode(3, OUTPUT); //LEFT BACKWARDS
  pinMode(4, OUTPUT); //RIGHT BACKWARDS
  pinMode(5, OUTPUT); //RIGHT FORWARD

  // attempt to connect to Wifi network:
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    delay(3000);
  }
  // you're connected now, so print out the data:
  Serial.print("You're connected to the network");
  printCurrentNet();

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("new client");           
    String currentLine = "";               
    while (client.connected()) {  
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        if (c == '\n') {                    
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Access-Control-Allow-Origin: *");
            client.println("Content-type:text/plain");
            client.println();
            client.stop();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') { 
          currentLine += c;
        }

        // check what the client requested and also how hard!
        // to go forward send a post request with 2 params in following order: power=30&direction=forward
        // example
        // curl 172.20.10.8/100/forward
        if (currentLine.endsWith("/forward")) {
            digitalWrite(2, HIGH);
            digitalWrite(5, HIGH);
        }
        // backwards
        if (currentLine.endsWith("/backwards")) {
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
        }
        // right
        if (currentLine.endsWith("/left")) {
            digitalWrite(2, HIGH);
        }
        // left
        if (currentLine.endsWith("/right")) {
            digitalWrite(5, HIGH);
        }
        // stop
        if (currentLine.endsWith("/stop")) {
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);

        }
      } 
    }
  }
}

void printCurrentNet() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the received signal strength:
  Serial.print("signal strength (RSSI):");
  Serial.println(WiFi.RSSI());

  // print your board's IP address:
  Serial.print("Board IP Address: ");
  Serial.println(WiFi.localIP());
}

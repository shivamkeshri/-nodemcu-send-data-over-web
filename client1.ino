/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

IPAddress staticIP552_20(10,11,116,20);
IPAddress gateway552_20(10,11,116,1);
IPAddress subnet552_20(255,255,254,0);

WiFiServer server(80);

void setup()
{
  pinMode(D2,INPUT_PULLUP);
  Serial.begin(9600);

    WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("Casual","ilmaaessi");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  WiFi.config(staticIP552_20, gateway552_20, subnet552_20);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
  server.begin();

   
}


void loop()
{
    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    client.flush();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println(digitalRead(D2));
    client.println("</html>");
    client.stop();
    delay(100);
    
}

/////////////////////////////////
// Generated with a lot of love//
// with TUNIOT FOR ESP8266     //
// Website: Easycoding.tn      //
/////////////////////////////////
#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

String  sensor20;
String  sensor30;

IPAddress staticIP144_10(10,11,116,40);
IPAddress gateway144_10(10,11,116,1);
IPAddress subnet144_10(255,255,254,0);

WiFiServer server(80);

String  httpurl;
String  TheHiddenAnswerOfClient;
HTTPClient http;

String SendWithAnswer(String IPcache, String monmessagecache) {
httpurl = "http://";
httpurl+=IPcache;
httpurl+="/";
httpurl+=monmessagecache;
http.begin(httpurl);
http.GET();
TheHiddenAnswerOfClient = (http.getString());
http.end();
return TheHiddenAnswerOfClient;
}

void setup()
{
  sensor20 = "";

  sensor30 = "";

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
  WiFi.config(staticIP144_10, gateway144_10, subnet144_10);
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
     sensor20 = (SendWithAnswer("10.11.116.20","Yes"));
     sensor20.remove(0, 25);
     sensor20.remove(sensor20.length()-11,11);
     Serial.print("sen20 ");
     Serial.println(sensor20);
     sensor30 = (SendWithAnswer("10.11.116.30","Yes"));
     sensor30.remove(0, 25);
     sensor30.remove(sensor30.length()-11,11);
     Serial.print("sen30 ");
     Serial.println(sensor30);
    client.flush();
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
      client.println("<title>server network!</title>");
      client.println("<h1 style=""color:#cc0000"">");
      client.println("chair monitoring page");
      client.println("</h1>");
    client.println("</head>");
    client.println("<body>");
      client.println("<span style=""color:#000000;font-size:14px"">");
      client.println("the program started since :");
      client.println("</span>");
      client.println("<span style=""color:#000000;font-size:14px"">");
      client.println((millis()/1000));
      client.println("</span>");
      client.println("<h2 style=""color:#33ff33"">");
      client.println("chair1");
      client.println("</h2>");
      client.println("<span style=""color:#000099;font-size:14px"">");
      if(sensor20 == "1")
      {
      client.println("chair is vacant");
      }
      else if(sensor20 == "0")
      {
        client.println("someone is on chair");
        }
         else
        {
          client.println("status not getting problem with sensor");
          }

      client.println("</span>");
      client.println("<h2 style=""color:#33ff33"">");
      client.println("chair2");
      client.println("</h2>");
      client.println("<span style=""color:#000099;font-size:14px"">");
       if(sensor30 == "1")
      {
      client.println("chair is vacant");
      }
      else if(sensor30 == "0")
      {
        client.println("someone is on chair");
        }

        else
        {
          client.println("status not getting problem with sensor");
          }

      client.println("</span>");
    client.println("</body>");
    client.println("</html>");
    client.stop();
     delay(100);
    
}

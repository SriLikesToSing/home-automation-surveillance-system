#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Servo.h>
// WiFi
const char *ssid = "TP-link_Kish"; // Enter your WiFi name
const char *password = "6267345363";  // Enter WiFi password
// MQTT Broker
const char *mqtt_broker = "192.168.0.151"; // Enter your WiFi or Ethernet IP
const char *topic = "test/topic";
const int mqtt_port = 1883;
WiFiClient espClient;
PubSubClient client(espClient);

//Create Servo object and inititialize pin
Servo servo;
Servo servo2;

const uint8_t servoPin = 5;
const uint8_t servoPin2 = 4;

void setup() {
  //Attach Servo to pin
  servo.attach(servoPin);
  servo.write(-180);

  servo2.attach(servoPin2);
  servo2.write(-180);
  
  
  pinMode(LED_BUILTIN, OUTPUT);
 // Set software serial baud to 115200;
 Serial.begin(115200);
 
 // connecting to a WiFi network
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.println("Connecting to WiFi..");
 }
 
 Serial.println("Connected to the WiFi network");
 
 //connecting to a mqtt broker
 client.setServer(mqtt_broker, mqtt_port);
 client.setCallback(callback);
 
 while (!client.connected()) {
 String client_id = "esp8266-client-1";
 client_id += String(WiFi.macAddress());
 
 Serial.printf("The client %s connects to mosquitto mqtt broker\n", client_id.c_str());
 
 if (client.connect(client_id.c_str())) {
  Serial.println("Public emqx mqtt broker connected");
 } else {
  Serial.print("failed with state ");
  Serial.print(client.state());
  delay(2000);
 }
}
 
 // publish and subscribe
 client.publish(topic, "Hello From ESP8266 NUMBER#1!");
 Serial.print("printing the topic");
 client.subscribe(topic);
 
}
void callback(char *topic, byte *payload, unsigned int length) {
 Serial.print("BRO PLEASE");
 Serial.print("Message arrived in topic: ");
 Serial.println(topic);
 Serial.print("Message:");
 String res;
 
  for (int i = 0; i < length; i++) {
  Serial.print((char) payload[i]);
  res+=((char) payload[i]);
 }

 Serial.println("THE RESULTING PAOAOH");
 Serial.println(res);
 digitalWrite(LED_BUILTIN, HIGH);
 delay(1000);
 digitalWrite(LED_BUILTIN, LOW);

 if(res == "play!"){
    Serial.println("playing beautiful music...");
    servo.write(180);
    delay(500); 
    servo.write(-40);
    servo2.write(180);
    delay(500);
    servo2.write(-50);
     servo.write(180);
    delay(500); 
    servo.write(-40);
    servo2.write(180);
    delay(500);
    servo2.write(-50);
     servo.write(180);
    delay(500); 
    servo.write(-40);
    servo2.write(180);
    delay(500);
    servo2.write(-50);
     servo.write(180);
    delay(500); 
    servo.write(-40);
    servo2.write(180);
    delay(500);
    servo2.write(-50);
     servo.write(180);
    delay(500); 
    servo.write(-40);
    servo2.write(180);
    delay(500);
    servo2.write(-50);
     servo.write(180);
    delay(500); 
    servo.write(-40);
    servo2.write(180);
    delay(500);
    servo2.write(-50);
     servo.write(180);
    delay(500); 
    servo.write(-40);
    servo2.write(180);
    delay(500);
    servo2.write(-50);
     servo.write(180);
    delay(500); 
    servo.write(-40);
    servo2.write(180);
    delay(500);
    servo2.write(-50);
    
    
 }
 
 Serial.println();
 Serial.println(" - - - - - - - - - - - -");
}
void loop() {
 client.loop();
}

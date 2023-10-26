#include <Servo.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TimeLib.h> // For time-based functions

char auth[] = "YourAuthToken";
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

Servo myservo;
const int servoPin = 9;
const int ledPin = D2; // Feedback LED
const int waterQualitySensorPin = A0; // Analog pin for water quality sensor
const float lowBatteryVoltage = 3.0; // Define low battery voltage threshold

BlynkTimer timer;
unsigned long feedingInterval = 43200000L;
time_t lastFeedingTime = 0;
bool manualFeeding = false;
bool lowBatteryAlertSent = false;

void setup()
{
  Blynk.begin(auth, ssid, pass);
  myservo.attach(servoPin);
  myservo.write(0);
  pinMode(ledPin, OUTPUT);
  timer.setInterval(60000L, checkFeedingSchedule); // Check every minute
}

void loop()
{
  Blynk.run();
  timer.run();
  monitorBatteryLevel();
}

void checkFeedingSchedule()
{
  time_t currentTime = now();

  if (currentTime - lastFeedingTime >= feedingInterval && !manualFeeding)
  {
    feedFish();
    lastFeedingTime = currentTime;
    Blynk.virtualWrite(V5, "Last fed at: " + String(hour(currentTime)) + ":" + String(minute(currentTime)));
  }
}

void feedFish()
{
  for (int pos = 0; pos <= 180; pos++)
  {
    myservo.write(pos);
    delay(15);
  }

  for (int pos = 180; pos >= 0; pos--)
  {
    myservo.write(pos);
    delay(15);
  }

  digitalWrite(ledPin, HIGH); // Turn on the LED
  delay(2000); // LED on for 2 seconds
  digitalWrite(ledPin, LOW); // Turn off the LED

  Blynk.virtualWrite(V1, "Feeding in progress...");
  // Integrate water quality sensor
  int waterQuality = analogRead(waterQualitySensorPin);
  Blynk.virtualWrite(V6, "Water Quality: " + String(waterQuality)); // Send water quality data to app or cloud

  }

void monitorBatteryLevel()
{
  float batteryVoltage = analogRead(A1) * (3.3 / 1023.0); // Assuming voltage divider setup
  if (batteryVoltage < lowBatteryVoltage && !lowBatteryAlertSent)
  {
    Blynk.virtualWrite(V2, "Low Battery Alert!");
    lowBatteryAlertSent = true;
  }
  else if (batteryVoltage > (lowBatteryVoltage + 0.2)) // Hysteresis to avoid constant alerts
  {
    lowBatteryAlertSent = false;
  }
}

BLYNK_WRITE(V3)
{
  int isManualFeeding = param.asInt();
  if (isManualFeeding == 1)
  {
    manualFeeding = true;
    feedFish();
    manualFeeding = false;
    Blynk.virtualWrite(V3, 0);
  }
}

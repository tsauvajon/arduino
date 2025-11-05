
#include <ELECHOUSE_CC1101.h> //Download it here: http://electronoobs.com/eng_arduino_ELECHOUSE_CC1101.php
#define size 1

byte TX_buffer[size]={0};
byte i;

void setup()
{
    Serial.begin(9600);
    ELECHOUSE_cc1101.Init();
    randomSeed(analogRead(0));
    Serial.println("CC1101 Random Transmitter Started");
}

void loop()
{
    byte val = random(0, 256);
    TX_buffer[0] = val;
    ELECHOUSE_cc1101.SendData(TX_buffer,size);

    Serial.print("Sent value: ");
    Serial.println(val);

    delay(1000); // 1 sec
}

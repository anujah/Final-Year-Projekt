#include <SPI.h>
    #include <nRF24L01.h>
    #include <RF24.h>

    RF24 radio(7,8);

    const uint64_t pipes[2] = { 0x00000, 0x00001 };
    unsigned long Command = 1;
    void setup()
    {
    Serial.begin(57600);

    radio.begin();
    radio.setRetries(15,15);
    radio.openReadingPipe(0,pipes[1]);
    radio.startListening();
    radio.printDetails();
    radio.openWritingPipe(pipes[0]);
    radio.openReadingPipe(0,pipes[1]);
    radio.stopListening();
    }

    void loop(void)
    {
    radio.stopListening();

    radio.write( &Command, sizeof(unsigned long) );

    radio.startListening();

    delay(1000);
    }

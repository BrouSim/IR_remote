#define IR_LED 4

int cisloVysilani = 1;

void log_0()
{
    digitalWrite(IR_LED, 1);
    delayMicroseconds(562);
    digitalWrite(IR_LED, 0);
    delayMicroseconds(562);
}

void log_1()
{
    digitalWrite(IR_LED, 1);
    delayMicroseconds(562);
    digitalWrite(IR_LED, 0);
    delayMicroseconds(1628);
}

void TX(byte hodnota)
{
    if( hodnota & 0b10000000 ) log_1();
    else log_0();
    
    if( hodnota & 0b01000000 ) log_1();
    else log_0();
    
    if( hodnota & 0b00100000 ) log_1();
    else log_0();
    
    if( hodnota & 0b00010000 ) log_1();
    else log_0();
    
    if( hodnota & 0b00001000 ) log_1();
    else log_0();
    
    if( hodnota & 0b00000100 ) log_1();
    else log_0();
    
    if( hodnota & 0b00000010 ) log_1();
    else log_0();
    
    if( hodnota & 0b00000001 ) log_1();
    else log_0();
}

void TX_invert(byte hodnota)
{
    if( hodnota & 0b10000000 ) log_0();
    else log_1();
    
    if( hodnota & 0b01000000 ) log_0();
    else log_1();
    
    if( hodnota & 0b00100000 ) log_0();
    else log_1();
    
    if( hodnota & 0b00010000 ) log_0();
    else log_1();
    
    if( hodnota & 0b00001000 ) log_0();
    else log_1();
    
    if( hodnota & 0b00000100 ) log_0();
    else log_1();
    
    if( hodnota & 0b00000010 ) log_0();
    else log_1();
    
    if( hodnota & 0b00000001 ) log_0();
    else log_1();
}

void IR_send_NEC(byte adresa, byte data)
{
    digitalWrite(IR_LED, 1);
    delay(9);
    digitalWrite(IR_LED, 0);
    delayMicroseconds(4500);
    
    TX(adresa);
    TX_invert(adresa);
    
    TX(data);
    TX_invert(data);
    
    digitalWrite(IR_LED, 1);
    delayMicroseconds(562);
    digitalWrite(IR_LED, 0);
    
    delay(100);
}

void IR_send_data(byte data1, byte data2, byte data3, byte data4)
{
    digitalWrite(IR_LED, 1);
    delay(9);
    digitalWrite(IR_LED, 0);
    delayMicroseconds(4500);
    
    TX(data1);
    TX(data2);
    TX(data3);
    TX(data4);

    digitalWrite(IR_LED, 1);
    delayMicroseconds(562);
    digitalWrite(IR_LED, 0);
    
    delay(100);
}

void IR_send_data_3B(byte data1, byte data2, byte data3)
{
    digitalWrite(IR_LED, 1);
    delay(9);
    digitalWrite(IR_LED, 0);
    delayMicroseconds(4500);
    
    TX(data1);
    TX(data2);
    TX(data3);

    digitalWrite(IR_LED, 1);
    delayMicroseconds(562);
    digitalWrite(IR_LED, 0);
    
    delay(100);
}

void IR_send_data_6B(byte data1, byte data2, byte data3, byte data4, byte data5, byte data6)
{
    digitalWrite(IR_LED, 1);
    delay(9);
    digitalWrite(IR_LED, 0);
    delayMicroseconds(4500);
    
    TX(data1);
    TX(data2);
    TX(data3);
    TX(data4);
    TX(data5);
    TX(data6);

    digitalWrite(IR_LED, 1);
    delayMicroseconds(562);
    digitalWrite(IR_LED, 0);
    
    delay(100);
}

void setup() {
  pinMode(8, OUTPUT);
  
  Serial.begin(115200);

}

void loop() { // run over and over
  IR_send_data(0b00100000,   0b11011111,   0b00010000,   0b11101111); 
  IR_send_data(0b10000000,   0b01111111,   0b00000000,   0b11111111); 
  delay(3000);

}


int sekvence1[] = {, 99}; 
int sekvence2[] = {, 99}; 

void vypis( int* sekvence ) 
{
  Serial.println("");
  Serial.print("IR_send_data(");
  Serial.print("0b");
  for(int i = 0; i <= 99; i++)
  {
      if(sekvence[i] == 0) Serial.print("0");
      else Serial.print("1");

      if(sekvence[i+1] == 99 ) break;

      if( i%8 == 7 )
      {
          Serial.print(",   0b");  
      }  
  }
  Serial.println("); ");
}

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("start");

  vypis( sekvence1 );
  vypis( sekvence2 );
}

void loop() {
  
  
  }

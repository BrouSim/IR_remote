
long time_ = 0;
long field[208];
int pozice;
bool end_ = 0;
int adress = 0;
int data = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("start");
  pinMode( 7, INPUT_PULLUP );
  pinMode( LED_BUILTIN, OUTPUT );
}

int i = 0;

void loop() {
  if(digitalRead(7) == 0)
  {
    while(1)
    {
      if(digitalRead(7) == 0)
      {
        digitalWrite( LED_BUILTIN, HIGH );        
        long begin_=micros();
        while(digitalRead(7) == 0)
        {
          time_ = micros()-begin_;
          if(time_ > 10000) 
          {
            end_ = 1;
            break;
          }
        }
        time_ = micros()-begin_;
        digitalWrite( LED_BUILTIN, LOW );
        field[i]=time_;
        i++;
        
        if(i>=200) { end_=1;  }
      }
      
      if(end_==0 && digitalRead(7) == 1)
      {
        digitalWrite( LED_BUILTIN, HIGH );        
        long begin_=micros();
        while(digitalRead(7) == 1)
        {
          time_ = micros()-begin_;
          if(time_ > 10000) 
          {
            end_ = 1;
            break;
          }
        }
        time_ = micros()-begin_;
        digitalWrite( LED_BUILTIN, LOW );
        field[i]=time_;
        i++;
                
        if(i>=200) { end_=1; }
      }

      if(end_ == 1) 
      {
        end_ = 0;  
        for( int j = 0; j<i; j++ ) {
          Serial.print( field[j] );
          Serial.print( ", " ); 
        }
        Serial.println( "end_.");

        // kontrola zda prvni dva impulzy jsou OK
        if(5000 < field[0] < 10000 & 3000 < field[1] < 5000)
        {
          for( int j = 2; j<i; j=j+2 ) {
            if( field[j] < 1000 &  field[j+1] < 1000 ) {
              Serial.print( "0, " );  
            } else if( field[j] < 1000 &  field[j+1] > 1000 ) {
              Serial.print( "1, " );  
            } else {
              Serial.print( "ERROR, " );
            }
          }
              Serial.println( ". " );
        }
        
        

        adress = 0;
        for(int j = 2; j < 18; j=j+2 )
        {
          if( field[j] < 1000 &  field[j+1] < 1000 ) {
              adress = adress << 1;  
            } else if( field[j] < 1000 &  field[j+1] > 1000 ) {
              adress = (adress << 1)  + 1;
            } else {
              Serial.print( "ERROR, " );
            }
        }
        Serial.print( "adress = " );
        Serial.println( adress );
        
        data = 0;
        for(int j = 34; j < 34+16; j=j+2 )
        {
          if( field[j] < 1000 &  field[j+1] < 1000 ) {
              data = data << 1;  
            } else if( field[j] < 1000 &  field[j+1] > 1000 ) {
              data = (data << 1)  + 1;
            } else {
              Serial.print( "ERROR, " );
            }
        }
        Serial.print( "data = " );
        Serial.println( data );

        i=0;
        break;
      }
    }
  }
}

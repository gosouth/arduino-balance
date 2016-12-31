
/*
 Balance Emulator - (c) 2016 Online LIMS, Ricardo Timmermann

    The 'Balance emulator' sent random weights around TARGEDREAD 
    with a tolerance of READERROR in %. Adjust this values to get 
    a desired weight.

    Example: emulate a balance to read around 2 gr

      #define TARGETREAD 200
      #define READERROR 5    

      You must sent to the Arduino Balance "READ\n" to get data.
      Similar on a read balance when you request a weight by pressing print.
    
      Weight 1.9998 gr
      Weight 2.0212 gr
      Weight 1.8950 gr
      Weight 2.1010 gr
      Weight 2.0018 gr
      ...

*/

#define TARGETREAD 200
#define READERROR 5

// == initialize the device =====================

float fminRead;
float fmaxRead;

void setup()
 {
    
 Serial.begin(9600);
 Serial.println("Device Started, (c) by Online LIMS");

 fminRead = TARGETREAD - TARGETREAD*READERROR/100;
 fmaxRead = TARGETREAD + TARGETREAD*READERROR/100;
   
 Serial.print("read range ");
 Serial.print(fminRead);
 Serial.print(" -  "); 
 Serial.println(fmaxRead);
  
 randomSeed(42);
 }

// == balance weihjt emulator =====================

float readData() 
{  
   float fRead;
   
   fRead = random(fminRead,fmaxRead);
   fRead = fRead/100;
   return fRead;
}

// == main loop ==================================

String sReadCmd;

void loop()
{
  
  if( Serial.available() ) {

    sReadCmd = Serial.readString(); 
    
    //-- read only if READ string is requested (the read commando)

   if( sReadCmd.equals("READ\n") ) {  

      float fRead = readData();
      Serial.print( "Weigth "); 
      Serial.print(fRead);
      Serial.println( " gr");
      
      delay(500);
     }     
   }            
}
 


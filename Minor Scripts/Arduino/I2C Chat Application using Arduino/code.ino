//Arduino 1
#include <Wire.h>   // adding library 

String data = "";   //initializing empty string


//setting up
void setup()
{
  Wire.begin(4);
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);  //receive function
}

void loop()
{
  String s = Serial.readString();   //reading the string
 if(s != ""){                       //If string is not null
   Serial.println("Me : "+ s);      //Printing message on serial monitor
    sendMessage(s);                 //sending message to another arduino board via sendMesssage function
  }
}


//sendMessage Function
void sendMessage(String s)    //passing message string
{
  Wire.beginTransmission(2);  //function call to begin transmission
  Wire.write(s.c_str());      //writes the data 
  Wire.endTransmission();     //End of transmission
  delay(500);
}

//recieveEent function
void receiveEvent(int howMany)
{
  data = "";
  while( Wire.available()){             
    data += (char)Wire.read();      //read data from wire
  }
  Serial.println("Second : "+data);      //print data
}




//Arduino 2

#include <Wire.h>   // adding library 

void setup()
{
  Wire.begin(2); 
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);       //receiving data
}

String data = "";

void loop()
{
  String s = Serial.readString();      //read data
 if(s != ""){
   	Serial.println("Me : "+ s);      //print data
    sendMessage(s);                  //send message
  }  
}



void sendMessage(String s)
{
  Wire.beginTransmission(4);           //begin transmission
  Wire.write(s.c_str());               //write functio 
  Wire.endTransmission();              //end transmission
  delay(500);
}

void receiveEvent(int howMany)
{
  data = "";
  while( Wire.available()){        
    data += (char)Wire.read();       //read data
  }
   Serial.println("First : "+data);    //print data
}
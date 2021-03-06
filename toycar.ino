//Updated on 02 April 2017 by Nudge Me
//Reupdated on 26 December 2017 by the same Nudge Me
//Reupdated on 10 June 2019 by the same Nudge Me :)

signed int x;
signed int y;
signed int z;
signed int btna;
signed int btnb;
float a;
float m;


String str;
char dir = 0;


int ML1 = 5;
int ML2 = 4;
int MR1 = 13;
int MR2 = 12;


int EL = 3;   
int ER = 11; 

int el = 0;
int er = 0;

int elp = 0;
int erp = 0;


boolean fast = true;
boolean StateA0 = false;
boolean StateA1 = false;
boolean StateA2 = false;


void setup() {
  
pinMode(ER, OUTPUT); 
pinMode(EL, OUTPUT); 
pinMode(ML1, OUTPUT); 
pinMode(ML2, OUTPUT); 
pinMode(MR1, OUTPUT); 
pinMode(MR2, OUTPUT); 

pinMode(A0, OUTPUT); 
pinMode(A1, OUTPUT); 
pinMode(A2, OUTPUT); 
pinMode(10,OUTPUT);
digitalWrite(10,LOW);

Serial.begin(9600);
Serial.println("Start");
}


void loop() 
{
    while(Serial.available())
    {
      
      char getData = Serial.read();
      
        if (getData == 'M')
        {
          m = Serial.parseFloat();
          
          if (Serial.read() == '#') 
          {
            processM();
          }
        }
        
        if (getData == 'A')
        {
          a = Serial.parseFloat();
          
          if (Serial.read() == '#') 
          {
            processA();
          }
        }
       
        if (getData == 'a')
        {  
          delay(5);        
          if (Serial.read() == '#') 
          {
            processa();
          }
        }      
       
        if (getData == 'b')
        {    
          delay(5);
          if (Serial.read() == '#') 
          {
            processb();
          }
        }   

        if (getData == 'c')
        {     
          delay(5);
          if (Serial.read() == '#') 
          {
            processc();
          }
        } 

        if (getData == 'x')
        {  
          delay(5);        
          if (Serial.read() == '#') 
          {
            processx();
          }
        }      
       
        if (getData == 'y')
        {    
          delay(5);
          if (Serial.read() == '#') 
          {
            processy();
          }
        }   

        if (getData == 'z')
        {     
          delay(5);
          if (Serial.read() == '#') 
          {
            processz();
          }
        } 
        
        if (getData == '~') {
        
          x = Serial.parseInt();
        
            if (Serial.read() == '*') {
        
              y = Serial.parseInt();
        
                if (Serial.read() == '@') {
                
                  z = Serial.parseInt();
                  
                    if (Serial.read() == '#') {
                    
                      process();
                  }                
              } 
           }
        }
        
          
        
    }
    
}

void processa(){
  Serial.println("Button a! ");
  StateA0 = !StateA0;
  if (StateA0 == true) { digitalWrite(A0, HIGH); } else { digitalWrite(A0, LOW); }
  Serial.flush();  
}

void processb(){
  Serial.println("Button b! "); 
  StateA1 = !StateA1;
  if (StateA1 == true) { digitalWrite(A1, HIGH); } else { digitalWrite(A1, LOW); }
  Serial.flush(); 
}

void processc(){
  Serial.println("Button c! ");
  StateA2 = !StateA2;
  if (StateA2 == true) { digitalWrite(A2, HIGH); } else { digitalWrite(A2, LOW); }
  Serial.flush();  
}

void processx(){
  Serial.println("Button x! "); 
  Serial.flush(); 
  fast = true;
}

void processy(){
  Serial.println("Button y! "); 
  Serial.flush(); 
}

void processz(){
  Serial.println("Button z! "); 
  Serial.flush(); 
  fast = false;
}



void processM(){
//  m1 = map(m, 0, 500, 0, 255); 
//  Serial.print("Received Magnitude: ");
//  Serial.println(m1); 
//  Serial.flush();   
}

void processA(){
  Serial.print("Received Angle: ");
  Serial.println(a); 
  Serial.flush();   
}

void process(){

//  Serial.println("x: " + String(x) + ", y: " + String(y));
//
//  Serial.print("Received x: " );
//  Serial.print(x);
//  
//  Serial.print(", Received y: " );
//  Serial.println(y);
  

  //left motor control:

  y = constrain(y, -255, 255);
    
  if (fast == false) { er = map(y, 0, 255, 0, 255); }
  else { er = y; }

  if (er < 0) { 
    digitalWrite(MR1, HIGH);
    digitalWrite(MR2, LOW);  
  } 
  
  else if (er >= 0) { 
    digitalWrite(MR1, LOW);
    digitalWrite(MR2, HIGH);
  } 
  
  erp = abs(er);
  

//right motor control:

  x = constrain(x, -255, 255);

  if (fast == false) { el = map(x, 0, 255, 0, 255); }
  else { el = x; }

  if (el < 0) { 
    digitalWrite(ML1, HIGH); 
    digitalWrite(ML2, LOW); 
  } 
  
  else if (el >= 0)  {
    digitalWrite(ML1, LOW); 
    digitalWrite(ML2, HIGH); 
  } 
  
  elp = abs(el);
                                                 
  analogWrite(EL, elp);  
  analogWrite(ER, erp);     
  
  
  Serial.flush(); 
}  

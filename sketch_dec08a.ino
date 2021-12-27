uint8_t decimal,s,unit,dig1,dig2,dig3,dig4,state,tim;
uint8_t charchters[10][7]={
  
 // {a,b,c,d,e,f,g}
    {0,1,1,1,1,1,1}, // =0
    {0,0,0,0,1,1,0}, // =1
    {1,0,1,1,0,1,1}, // =2
    {1,0,0,1,1,1,1}, // = 3
    {1,1,0,0,1,1,0}, //=4
    {1,1,0,1,1,0,1}, // =5
    {1,1,1,1,1,0,1}, //=6 
    {0,0,0,0,1,1,1}, // = 7
    {1,1,1,1,1,1,1}, // =8
    {1,1,0,1,1,1,1}
  
};
char j=7;
void setup() {
 
for(char i=1;i<14;i++)
  {
  pinMode(i,OUTPUT);
  
  }
  pinMode(0,INPUT);
  pinMode(1,INPUT);

  dig1=0;
  dig2=0;
  dig3=0;
  dig4=0;

}

void loop() {
  // put your main code here, to run repeatedly:
display_number();
  
}


void digit1(){
  
    j=7;
   s=0;
    digitalWrite(5,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
   for( s;s<7;s++){
    digitalWrite(j,charchters[dig1][s]);
    
    j++;
      
    }
    
    
    
    
    digitalWrite(2,0);
    delay(2);
  
     
   
}


void digit2(){
   j=7;
   s=0;
   digitalWrite(5,1);
   digitalWrite(2,1);
   digitalWrite(4,1);
  for(s;s<7;s++){
    digitalWrite(j,charchters[dig2][s]);
    
    j++;
    
    
    
    
   
    
    
        }
        digitalWrite(3,0);
    delay(1);
   
    
}
void digit3(){
   j=7;
   s=0;
   digitalWrite(3,1);
   digitalWrite(5,1);
    digitalWrite(2,1);
  for(s;s<7;s++){
    digitalWrite(j,charchters[dig3][s]);
    
    j++;
    
    
    
    
   
    
    
        }
        digitalWrite(4,0);
    delay(1);
   
    
}
void digit4(){
   j=7;
   s=0;
   digitalWrite(3,1);
   digitalWrite(4,1);
   digitalWrite(2,1);
  for(s;s<7;s++){
    digitalWrite(j,charchters[dig4][s]);
    
    j++;
    
    
    
    
   
    
    
        }
        digitalWrite(5,0);
    delay(1);
   
    
}





void display_number(){
  for(uint8_t rep;rep<48;rep++){
    

    digit1();

    
   digit2();

  digit3();

  digit4();

  }

  digitalRead(0);
  digitalRead(1);
  if(digitalRead(0)==0){
    state=1;
    }
    else {
      if(digitalRead(1)==0)
      state=0;
    }
    
  
  
  if(state==1){
  dig1++;
    if(dig1>9){
      dig1=0;
      dig2++;
      if(dig2>9){
        
       dig2=0;
       dig3++;
       if(dig3>9){
        dig3=0;
        dig4++;
       }
       
      }
    }
  }
  else{
     dig1--;
    if(dig1==0){
      digit1();
  
    
   digit2();
   
  digit3();
  digit4();
  
      dig1=9;
      dig2--;
      if(dig2==0){
        
       dig2=9;
       dig3--;
       if(dig3==0){
        dig3=9;
        dig4--;
       }
       
      }
    }
    
  }
}


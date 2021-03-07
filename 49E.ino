const int pinHall = A0; 
#define NOFIELD 515L
#define TOMILLIGAUSS 3487L

void setup() {
  pinMode(pinHall, INPUT);
  Serial.begin(9600);
} 

void measure_milligauss(){

  //we measure 10 times adn make the mean
  long measure = 0;
  for(int i = 0; i < 10; i++){
      int value = 
      measure += analogRead(pinHall);
  }
  measure /= 10;  

  long compensated = measure - NOFIELD; // adjust relative to no applied field
  long gauss = compensated * TOMILLIGAUSS / 1000; // adjust scale to Gauss
  
  Serial.print("Gauss = ");
  Serial.print(gauss);
  Serial.print("\tG");
  if (gauss > 0) Serial.print("\t(South)");
  else if (gauss < 0) Serial.print("\t(North)");
  Serial.print("\n");
  
}

void loop() {
 measure_milligauss(); 
 delay(100);
}

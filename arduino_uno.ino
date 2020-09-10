int sensor_pin = A0;

int motor = 13;

int tx = 1;

int rx = 0;

int output_value ;

const int analogOutPin = 1; 

int threshold = 800;

int current_value;


void setup() 

{
   Serial.begin(9600);

   Serial.println("Reading From the Sensor ...");

   pinMode(motor, OUTPUT);

   pinMode(tx, OUTPUT);

   pinMode(rx, INPUT);

   delay(2000);

   }

void loop() 

{
   output_value= analogRead(sensor_pin);

   current_value = output_value;

   output_value= constrain(output_value,10,1023); 

   output_value= map(output_value,10,1023,150,0); 

   analogWrite(analogOutPin, output_value); 

   Serial.print("Moisture : ");

   Serial.print(output_value);

   Serial.println("%");

   if(current_value >=threshold)

   {

    Serial.println("water level low... turning water pump on..");

    digitalWrite(motor,HIGH);

   }
   else
   {

    Serial.println("Water level high... turning water pump off");

    digitalWrite(motor,LOW);

   }
   delay(3000);
   
}

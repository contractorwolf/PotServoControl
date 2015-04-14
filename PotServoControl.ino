int led = 13;

int pot1pin = A0;  // analog pin used to connect the potentiometer
//int pot1power = 2;  
int pot2pin = A1;  // analog pin used to connect the potentiometer
//int pot2power = 4; 
//int pot2GND = 3; 




int val;
int val2;
int time_delay = 300;
int centers[] = {1360,1341,1391,1392};//1572,1132

int vertical_sway = 250;
int horizontal_sway = 200;
int horizontal_angle;
int vertical_angle;
int reverse_horizontal_angle;
int reverse_vertical_angle;





void setup()
{
	pinMode(led, OUTPUT);  
	pinMode(pot1pin, INPUT);  
	pinMode(pot2pin, INPUT);  



	//pinMode(pot1power, OUTPUT); 
	//pinMode(pot2power, OUTPUT); 
	//pinMode(pot2GND, OUTPUT); 





	//digitalWrite(pot1power,HIGH);
	//digitalWrite(pot2power,HIGH);
	//digitalWrite(pot2GND,LOW);

	Serial.begin(115200);
	Serial1.begin(9600);
  

	Serial.println("PotServoControl v1.0 Started");

	delay(3000);
  /* add setup code here */

}

void loop()
{
	val = analogRead(pot1pin);            // reads the value of the potentiometer (value between 0 and 1023) 
	val2 = analogRead(pot2pin);            // reads the value of the potentiometer (value between 0 and 1023) 
  //0-1017 pot values
	//530-2340 max values





	Serial.print("analog1 value: ");  
	Serial.println(val); 
	Serial.print("analog2 value: ");  
	Serial.println(val2); 


	//SendServoCommand(val,time_delay);





  /* add main program code here */
	delay(10);
}




void SendServoCommand(int pot_angle, int time_delay){

	horizontal_angle = map(pot_angle, 0, 1020, centers[0] + horizontal_sway, centers[0] - horizontal_sway);     // scale it to use it with the servo (value between 0 and 180) 
	vertical_angle = map(pot_angle,0, 1020, centers[1] + vertical_sway, centers[1] - vertical_sway);


		reverse_horizontal_angle = map(pot_angle, 0, 1020, centers[0] - horizontal_sway, centers[0] + horizontal_sway);     // scale it to use it with the servo (value between 0 and 180) 
	reverse_vertical_angle = map(pot_angle,0, 1020, centers[1] - vertical_sway, centers[1] + vertical_sway);




	Serial1.print("#1P");
	Serial1.print(horizontal_angle);
	Serial1.print("#2P");
	Serial1.print(vertical_angle);
	Serial1.print("#3P");
	Serial1.print(reverse_horizontal_angle);
	Serial1.print("#4P");
	Serial1.print(reverse_vertical_angle);
	Serial1.print("T");
	Serial1.println(time_delay);


	Serial.print("#1P");
	Serial.print(horizontal_angle);
	Serial.print("#2P");
	Serial.print(vertical_angle);
	Serial.print("#3P");
	Serial.print(reverse_horizontal_angle);
	Serial.print("#4P");
	Serial.print(reverse_vertical_angle);
	Serial.print("T");
	Serial.println(time_delay);






	delay(time_delay); 
}

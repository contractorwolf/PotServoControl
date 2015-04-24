//int led = 13;

int pot1pin = A0;  // analog pin used to connect the potentiometer
//int pot1power = 2;  
int pot2pin = A1;  // analog pin used to connect the potentiometer
//int pot2power = 4; 
//int pot2GND = 3; 




int val;
int val2;
int time_delay = 300;
int centers[] = {1360,1341,1391,1392,1360,1341,1391,1392};//1572,1132

int vertical_sway = 250;
int horizontal_sway = 175;
int horizontal_angle;
int vertical_angle;
int reverse_horizontal_angle;
int reverse_vertical_angle;





void setup()
{
	//pinMode(led, OUTPUT);  
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


	SendServoCommand(val, val2, time_delay);





  /* add main program code here */
	delay(100);
}




void SendServoCommand(int pot_angle, int pot_angle2, int time_delay){


	int servo0 = map(pot_angle, 0, 1023, centers[0] + horizontal_sway, centers[0] - horizontal_sway); //horizontal_angle
	int servo1 = map(pot_angle2,0, 1023, centers[1] + vertical_sway, centers[1] - vertical_sway); //vertical_angle


	int servo2 = map(pot_angle, 0, 1023, centers[2] - horizontal_sway, centers[2] + horizontal_sway); //reverse_horizontal_angle
	int servo3 = map(pot_angle2,0, 1023, centers[3] - vertical_sway, centers[3] + vertical_sway); //reverse_vertical_angle

	int servo4 = map(pot_angle, 0, 1023, centers[4] + horizontal_sway, centers[4] - horizontal_sway); //horizontal_angle
	int servo5 = map(pot_angle2,0, 1023, centers[5] + vertical_sway, centers[5] - vertical_sway); //vertical_angle


	int servo6 = map(pot_angle, 0, 1023, centers[6] - horizontal_sway, centers[6] + horizontal_sway); //reverse_horizontal_angle
	int servo7 = map(pot_angle2,0, 1023, centers[7] - vertical_sway, centers[7] + vertical_sway); //reverse_vertical_angle







	//horizontal_angle = map(pot_angle, 0, 1023, centers[0] + horizontal_sway, centers[0] - horizontal_sway);     // scale it to use it with the servo (value between 0 and 180) 
	//reverse_horizontal_angle = map(pot_angle, 0, 1023, centers[0] - horizontal_sway, centers[0] + horizontal_sway);     // scale it to use it with the servo (value between 0 and 180) 
	//
	//
	//
	//vertical_angle = map(pot_angle2,0, 1023, centers[1] + vertical_sway, centers[1] - vertical_sway);
	//reverse_vertical_angle = map(pot_angle2,0, 1023, centers[1] - vertical_sway, centers[1] + vertical_sway);




	Serial1.print("#1P");
	Serial1.print(servo0);
	Serial1.print("#2P");
	Serial1.print(servo1);
	Serial1.print("#3P");
	Serial1.print(servo2);
	Serial1.print("#4P");
	Serial1.print(servo3);


	Serial1.print("#5P");
	Serial1.print(servo4);
	Serial1.print("#6P");
	Serial1.print(servo5);
	Serial1.print("#7P");
	Serial1.print(servo6);
	Serial1.print("#8P");
	Serial1.print(servo7);






	Serial1.print("T");
	Serial1.println(time_delay);


	Serial.print("#1P");
	Serial.print(servo0);
	Serial.print("#2P");
	Serial.print(servo1);
	Serial.print("#3P");
	Serial.print(servo2);
	Serial.print("#4P");
	Serial.print(servo3);


	Serial.print("#5P");
	Serial.print(servo4);
	Serial.print("#6P");
	Serial.print(servo5);
	Serial.print("#7P");
	Serial.print(servo6);
	Serial.print("#8P");
	Serial.print(servo7);




	Serial.print("T");
	Serial.println(time_delay);






	delay(time_delay); 
}

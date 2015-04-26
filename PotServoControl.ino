//int led = 13;

int pot1pin = A0;  // analog pin used to connect the potentiometer
//int pot1power = 2;  
int pot2pin = A1;  // analog pin used to connect the potentiometer
//int pot2power = 4; 
//int pot2GND = 3; 




int val;
int val2;
int time_delay = 300;
int centers[] = {1366,1329,1367,1369,1407,1399,1402,1297};//1572,1132

int vertical_sway = 250;
int horizontal_sway = 175;
int horizontal_angle;
int vertical_angle;
int reverse_horizontal_angle;
int reverse_vertical_angle;




/*

FORWARD DIRECTION, max speed ~180
step 1: #1P1541#2P1579#3P1192#4P1119#5P1582#6P1649#7P1227#8P1047T300
step 2: #1P1541#2P1079#3P1192#4P1619#5P1582#6P1149#7P1227#8P1547T300
step 3: #1P1191#2P1079#3P1542#4P1619#5P1232#6P1149#7P1577#8P1547T300
step 4: #1P1191#2P1579#3P1542#4P1119#5P1232#6P1649#7P1577#8P1047T300
*/

void setup()
{
	//pinMode(led, OUTPUT);  
	pinMode(pot1pin, INPUT);  // backbone servos controller
	pinMode(pot2pin, INPUT);  // leg servo controller

	Serial.begin(115200);// COM7 USB

	Serial1.begin(9600);// USC32 Servo Control Board
  

	Serial.println("PotServoControl v1.1 Started");

	delay(3000);
}


void loop()
{
	val = analogRead(pot1pin);            // reads the value of the potentiometer (value between 0 and 1023) 
	val2 = analogRead(pot2pin);            // reads the value of the potentiometer (value between 0 and 1023) 
	//0-1017 pot values
	//530-2340 max values

	// show analog values
	Serial.print("analog1 value: ");  
	Serial.println(val); 

	Serial.print("analog2 value: ");  
	Serial.println(val2); 


	SendServoCommandList(1541,1579,1192,1119,1582,1649,1227,1047,val);
	SendServoCommandList(1541,1079,1192,1619,1582,1149,1227,1547,val);
	SendServoCommandList(1191,1079,1542,1619,1232,1149,1577,1547,val);
	SendServoCommandList(1191,1579,1542,1119,1232,1649,1577,1047,val);


	/*

	SendServoCommand(val, val2, time_delay);

	*/

	delay(100);
}


void SendServoCommandList(int servo0,int servo1,int servo2,int servo3,int servo4,int servo5,int servo6,int servo7,int time_delay){

	//send to USC32 servo
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

	//output to USB
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











void SendServoCommand(int pot_angle, int pot_angle2, int time_delay){

	//first segment responding to potentiometers
	int servo0 = map(pot_angle, 0, 1023, centers[0] + horizontal_sway, centers[0] - horizontal_sway); //horizontal_angle
	int servo1 = map(pot_angle2,0, 1023, centers[1] + vertical_sway, centers[1] - vertical_sway); //vertical_angle


	int servo2 = map(pot_angle, 0, 1023, centers[2] - horizontal_sway, centers[2] + horizontal_sway); //reverse_horizontal_angle
	int servo3 = map(pot_angle2,0, 1023, centers[3] - vertical_sway, centers[3] + vertical_sway); //reverse_vertical_angle

	int servo4 = map(pot_angle, 0, 1023, centers[4] + horizontal_sway, centers[4] - horizontal_sway); //horizontal_angle
	int servo5 = map(pot_angle2,0, 1023, centers[5] + vertical_sway, centers[5] - vertical_sway); //vertical_angle


	int servo6 = map(pot_angle, 0, 1023, centers[6] - horizontal_sway, centers[6] + horizontal_sway); //reverse_horizontal_angle
	int servo7 = map(pot_angle2,0, 1023, centers[7] - vertical_sway, centers[7] + vertical_sway); //reverse_vertical_angle

	//send to USC32 servo
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

	//output to USB
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






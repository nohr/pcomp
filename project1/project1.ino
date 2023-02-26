//define the two direction logic pins and the speed / PWM pin
const int DIR_A = 11;
const int DIR_B = 10;
const int PWM = 9;

void setup()
{
//set all pins as output
pinMode(DIR_A, OUTPUT);
pinMode(DIR_B, OUTPUT);
pinMode(PWM, OUTPUT);
}

void loop()
{
 //drive forward at full speed by pulling DIR_A High
 //and DIR_B low, while writing a full 255 to PWM to 
 //control speed
 digitalWrite(DIR_A, HIGH);
 digitalWrite(DIR_B, LOW);
 analogWrite(PWM, 255);

 //wait 1 second
 delay(1000);

 //Brake the motor by pulling both direction pins to 
 //the same state (in this case LOW). PWM doesn't matter
 //in a brake situation, but set as 0.
 digitalWrite(DIR_A, LOW);
 digitalWrite(DIR_B, LOW);
 analogWrite(PWM, 0);

 //wait 1 second
 delay(1000);

 //change direction to reverse by flipping the states
 //of the direction pins from their forward state
 digitalWrite(DIR_A, LOW);
 digitalWrite(DIR_B, HIGH);
 analogWrite(PWM, 255);

 //wait 1 second
 delay(1000);

 //Brake again
 digitalWrite(DIR_A, LOW);
 digitalWrite(DIR_B, LOW);
 analogWrite(PWM, 0);

 //wait 1 second
 delay(1000);
 }

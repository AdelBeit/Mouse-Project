/* Pro Micro Test Code
   by: Nathan Seidle
   modified by: Jim Lindblom
   SparkFun Electronics
   date: September 16, 2013
   license: Public Domain - please use this code however you'd like.
   It's provided as a learning tool.

   This code is provided to show how to control the SparkFun
   ProMicro's TX and RX LEDs within a sketch. It also serves
   to explain the difference between Serial.print() and
   Serial1.print().
*/

int RXLED = 17;  // The RX LED has a defined Arduino pin
int l2 = 2;
int l3 = 3;
// The TX LED was not so lucky, we'll need to use pre-defined
// macros (TXLED1, TXLED0) to control that.
// (We could use the same macros for the RX LED too -- RXLED1,
//  and RXLED0.)

void setup()
{
 pinMode(RXLED, OUTPUT);  // Set RX LED as an output
 pinMode(l2, OUTPUT);  // Set RX LED as an output
 pinMode(l3, OUTPUT);  // Set RX LED as an output
 // TX LED is set as an output behind the scenes

 Serial.begin(9600); //This pipes to the serial monitor
 Serial1.begin(9600); //This is the UART, pipes to sensors attached to board
}

void loop()
{
 Serial.println("Hello world");  // Print "Hello World" to the Serial Monitor
 Serial1.println("Hello!");  // Print "Hello!" over hardware UART

 digitalWrite(RXLED, LOW);   // set the RX LED ON
 digitalWrite(l2, LOW);   // set the RX LED ON
 digitalWrite(l3, LOW);   // set the RX LED ON
 TXLED0; //TX LED is not tied to a normally controlled pin so a macro is needed, turn LED OFF
 delay(100);              // wait for a second

 digitalWrite(RXLED, HIGH);    // set the RX LED OFF
 digitalWrite(l2, HIGH);    // set the RX LED OFF
 digitalWrite(l3, HIGH);    // set the RX LED OFF
 TXLED1; //TX LED macro to turn LED ON
 delay(1000);              // wait for a second
}
  

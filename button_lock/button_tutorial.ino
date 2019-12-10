/*

  For more inforamation of button state changes you can visit
  http://www.arduino.cc/en/Tutorial/ButtonStateChange
*/


const int pass_length = 4;
const int num_buttons = 3;
int checked = -1;

//TODO 1: Record values of button pins
const int  button1 = 2;    // the pin that the pushbutton1 is attached to
const int  button2 = 4;    // the pin that the pushbutton2 is attached to
const int  button3 = 6;    // the pin that the pushbutton3 is attached to

//TODO 2: Record values of LED pins
const int ledWrong = 9;       // the pin that the LED is attached to
const int ledRight = 8;       // the pin that the LED is attached to

const int led1 = 10;       // the pin that the LED is attached to
const int led2 = 11;       // the pin that the LED is attached to
const int led3 = 12;       // the pin that the LED is attached to
const int led4 = 13;       // the pin that the LED is attached to

//These store changes in button states, it'll be useful soon
int ButtonStates[3] = {0,0,0};
int LastButtonStates[3] = {0,0,0};

//TODO 3: Store the password and store user inputs
int password[pass_length] = {1,2,3,1};
int entry[pass_length] = {0,0,0,0};


//TODO 4: Keep track of how many buttons were pressed
int buttonPushCounter = 0;   // counter for the number of button presses


void setup() {
  Serial.begin(9600);
  // TODO 5: Print some button's pin number
  Serial.print("Button pin: "); 
  Serial.println(button1);
  // TODO 6: Initialize buttons pins as input pins
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  // TODO 7: Initialize LED pins as output pins
  pinMode(ledRight, OUTPUT);
  pinMode(ledWrong, OUTPUT);
  //TODO 8: Reset values on all output pins
  digitalWrite(ledWrong, LOW);
  digitalWrite(ledRight, LOW);
}


void loop(){
    //TODO 9: Fill button_states array with input from the buttons
    ButtonStates[0] = digitalRead(button1);
    ButtonStates[1] = digitalRead(button2);
    ButtonStates[2] = digitalRead(button3);

    //TODO: Loop through the buttons and check if 
    //the button_states array matches the last_states array
    for(int i =0; i <num_buttons; i++){
      //TODO 10: check difference by button_states[i] != last_states[i]
      if (ButtonStates[i] != LastButtonStates[i]) {
          //TODO 11: if button changed state it should be recorded as input

          /*Note
          buttons take on states HIGH and LOW
          so ButtonStates[i] == HIGH or ButtonStates[i] == LOW
          
          if button state is HIGH, the button was pressed
          if button state is LOW, the button was unpressed

          We only care if ButtonStates[i] == HIGH
          */

          
          if (ButtonStates[i] == HIGH) {
            // if the current state is HIGH then the button went from off to on:
      
            entry[buttonPushCounter] = i+1;
            buttonPushCounter++;

            
            Serial.println("on");
            Serial.print("number of button pushes: ");
            Serial.println(buttonPushCounter);
            
          } 
          
          else {
            // if the current state is LOW then the button went from on to off:
            Serial.println("off");
          }
          
          //TODO 12: update the last_states array with the current state for this button
          LastButtonStates[i] =  ButtonStates[i];
          //TODO 13: issue a delay if a button was pressed
          delay(50);
      }
      
    }

  //TODO 14: if the expected number of buttons have been pressed
  if (buttonPushCounter % pass_length == 0 && checked == -1) {
    //TODO 15: Loop through the buttons 
    for(int i =0; i <pass_length; i++){
      //TODO 16: check if password doesn't match input
      Serial.print(password[i]);
      Serial.print(",");
      Serial.println(entry[i]);
      
      if(password[i] != entry[i]){
          checked = 0;
      }
    }
    //TODO 17: Reset the lights
    digitalWrite(ledWrong, LOW);
    digitalWrite(ledRight, LOW);

    //If password matches input
    if(checked == -1){
      //TODO 18: Turn on the red light
       digitalWrite(ledRight, HIGH);
       checked = 1; 
    }

    //If password does not match input
    if(checked == 0){
      //TODO 19: Turn on the red light
       digitalWrite(ledWrong, HIGH);
       checked = 1; 
    }

    buttonPushCounter = 0;
  }
 
  if(buttonPushCounter != 0){
    checked = -1;
  }

  //If password matches input
  if(buttonPushCounter > 0){
    digitalWrite(led1, HIGH);
    if(buttonPushCounter > 1){
      digitalWrite(led2, HIGH);
       if(buttonPushCounter > 2){
        digitalWrite(led3, HIGH);
        }
       else{
         digitalWrite(led3, LOW);
      }
    }
    else{
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
  }
  //If password does not match input
  else{
      //TODO 19: Turn on the red light
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
  }
}
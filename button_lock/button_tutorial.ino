/*

  For more inforamation of button state changes you can visit
  http://www.arduino.cc/en/Tutorial/ButtonStateChange
*/

//const int pass_length = 4;
//const int num_buttons = 3;

//TODO 1: Record values of button pins
//Ex: const int  button_pin = ;    

//TODO 2: Record values of LED pins
//Ex: const int led_pin = ;

//These store changes in button states, it'll be useful soon
int button_states[num_buttons] = {0,0,0};
int last_states[num_buttons] = {0,0,0};

//TODO 3: Store the password and store user inputs
// Ex:  password[pass_length] = {1,2,3,1};
// Ex:  input[pass_length] = {0,0,0,0};

//TODO 4: Keep track of how many buttons were pressed
//Ex: int push_counter = ;

void setup() {
  Serial.begin(9600);
  // TODO 5: Print some button's pin number
  // Serial.print("Button pin: "); 
  // Serial.println(button);

  // TODO 6: Initialize buttons pins as input pins
  // Ex: pinMode(button_pin, INPUT);

  // TODO 7: Initialize LED pins as output pins
  // Ex: pinMode(led_pin, OUTPUT);
  
  //TODO 8: Reset values on all output pins
  //Ex: digitalWrite(pin, LOW);
  
}


void loop(){
  //TODO 9: Fill button_states array with input from the buttons
  //Ex: button_states[0] = digitalRead(button_pin)

  //TODO: Loop through the buttons and check if 
  //the button_states array matches the last_states array
  //for(){
      //TODO 10: check difference by button_states[i] != last_states[i]
      //if () {
          //TODO 11: if button changed state it should be recorded as input

          /*Note
          buttons take on states HIGH and LOW
          so ButtonStates[i] == HIGH or ButtonStates[i] == LOW
          
          if button state is HIGH, the button was pressed
          if button state is LOW, the button was unpressed

          We only care if ButtonStates[i] == HIGH
          */

          
          //TODO 12: update the last_states array with the current state for this button
          
          //TODO 13: issue a delay if a button was pressed
          //delay(50);
      //}
  //}

  //update the last_states array with the current states

  
  //TODO 14: if the expected number of buttons have been pressed
  //if(){
  
    //TODO 15: Loop through the buttons 
    //for(){
    
      //TODO 16: check if password matches input
      
    //}

    //TODO 17: Reset the lights
    //digitalWrite(led, LOW);

    //If password matches input
    //if(){
        //TODO 18: Turn on the green light
        //digitalWrite(led_pin, HIGH);
    //}

    //If password does not match input
    //else(){
        //TODO 19: Turn on the red light
        //digitalWrite(led_pin, HIGH);
    //}
  //}
}

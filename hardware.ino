// This #include statement was automatically added by the Particle IDE.
#include <InternetButton.h>

InternetButton button = InternetButton();
void setup() {
  button.begin();

  // Exposed functions-test

  // 1. showing the score
  // http://api.particle.io/<deviceid>/score
  Particle.function("score", displayScore);
  // 2. showing if the answer is correct / incorrect
  // http://api.particle.io/<deviceid>/answer
  Particle.function("answer", showCorrectOrIncorrect);

  // Show a visual indication to the player that the Particle
  // is loaded & ready to accept inputs
  for (int i = 0; i < 3; i++) {
    button.allLedsOn(20,0,0);
    delay(250);
    button.allLedsOff();
    delay(250);
  }
}

int showCorrectOrIncorrect(String cmd) {
  if (cmd == "green") {
      
      
   button.allLedsOn(0,255,0);

delay(3000);
button.allLedsOn(102,255,102); 



delay(3000);
button.allLedsOn(255,255,110);

delay(3000);



button.allLedsOn(255,255,0);
delay(3000);

button.allLedsOn(255,128,0);



delay(8000);


button.allLedsOn(255,0,0);

  }
  else if (cmd == "red") {
  
    button.allLedsOff();
  }
  else {
    // you received an invalid color, so
    // return error code = -1
    return -1;
  }
  // function succesfully finished
  return 1;
}

int DELAY = 200;

void loop() {

  // EVENT 1:
  // when person presses button 4 & 2 send player choice to phone
  if (button.buttonOn(4)) {
    // CHOICE = A
    Particle.publish("playerChoice","A", 60, PRIVATE);
    delay(DELAY);
  }
  if (button.buttonOn(2)) {
    // CHOICE = B
    Particle.publish("playerChoice","B", 60, PRIVATE);
    delay(DELAY);
  }

  // EVENT 2:
  // when person presses button 3, change the question on the phone
  if (button.buttonOn(3)) {
    // CHANGE QUESTION
    Particle.publish("nextQuestion","true", 60, PRIVATE);
    delay(DELAY);
  }
}

int displayScore(String cmd) {
  // reset the displayed score
  button.allLedsOff();

  // turn on the specified number of lights
  int score = cmd.toInt();

  if (score < 0 || score > 11) {
    // error: becaues there are only 11 lights
    // return -1 means an error occurred
    return -1;
  }

  for (int i = 1; i <= score; i++) {
      button.ledOn(i, 255, 255, 0);
  }

  // return = 1 means the function finished running successfully
  return 1;
}


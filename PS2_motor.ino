// For interfacing visit https://www.rhydolabz.com/wiki/?p=12663


#include <PS2X_lib.h>

PS2X ps2x;

int error = 0;
byte type = 0;
byte vibrate = 0;
int lx,ly,rx,ry;
void setup() {
  Serial.begin(57600);

  error = ps2x.config_gamepad(13, 11, 10, 12, true, true); //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error

  if (error == 0) {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }

  else if (error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");

  else if (error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

  else if (error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

  //Serial.print(ps2x.Analog(1), HEX);

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
  }
}

void loop() {
  /* You must Read Gamepad to get new values
    Read GamePad and set vibration values
    ps2x.read_gamepad(small motor on/off, larger motor strenght from 0-255)
    if you don't enable the rumble, use ps2x.read_gamepad(); with no values

    you should call this at least once a second
  */

 

  if (error == 1) //skip loop if no controller found
    return;

  if (type == 3) {
    ps2x.read_gamepad();          //read controller and set large motor to spin at 'vibrate' speed


    
    if (ps2x.Button(PSB_PAD_UP)) {        //will be TRUE as long as button is pressed
      Forward();
    }
    if (ps2x.Button(PSB_PAD_RIGHT)) {
      Right();
    }
    if (ps2x.Button(PSB_PAD_LEFT)) {
      Left();
    }
    if (ps2x.Button(PSB_PAD_DOWN)) {
      Reverse();
    }
    if(ps2x.Button(PSB_START)){
      halt();
    }
    
    //
    //    if (ps2x.NewButtonState())               //will be TRUE if any button changes state (on to off, or off to on)
    //    {
    //
    //
    //
    //      if (ps2x.Button(PSB_L3))
    //        Serial.println("L3 pressed");
    //      if (ps2x.Button(PSB_R3))
    //        Serial.println("R3 pressed");
    //      if (ps2x.Button(PSB_L2))
    //        Serial.println("L2 pressed");
    //      if (ps2x.Button(PSB_R2))
    //        Serial.println("R2 pressed");
    //      if (ps2x.Button(PSB_GREEN))
    //        Serial.println("Triangle pressed");
    //
    //    }
    //
    //
    //    if (ps2x.ButtonPressed(PSB_RED))            //will be TRUE if button was JUST pressed
    //      Serial.println("Circle just pressed");
    //
    //    if (ps2x.ButtonReleased(PSB_PINK))            //will be TRUE if button was JUST released
    //      Serial.println("Square just released");
    //
    //    if (ps2x.NewButtonState(PSB_BLUE))           //will be TRUE if button was JUST pressed OR released
    //      Serial.println("X just changed");



//
//    ly = ps2x.Analog(PSS_LY); //Left stick, Y axis
//
//    lx = ps2x.Analog(PSS_LX); //Left stick, X axis
//
//    ry = ps2x.Analog(PSS_RY); //Right stick, Y axis
//    rx = ps2x.Analog(PSS_RX); //Right stick, X axis         Later use these analog values to control speed of the motor 

  }


  delay(50);

}

void Forward(){
  //enter the digitalWrite function as per your connection
}

void Left(){
  //enter the digitalWrite function as per your connection
}

void Right(){
  //enter the digitalWrite function as per your connection
}

void Reverse(){
  //enter the digitalWrite function as per your connection
}

void halt(){
  //enter the digitalWrite function as per your connection
}

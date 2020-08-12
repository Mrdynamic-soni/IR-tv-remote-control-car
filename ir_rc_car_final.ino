#include<IRremote.h>
#include<AFMotor.h>
const int pin =2     ;
IRrecv rec(pin);
decode_results result;

AF_DCMotor m3(3);
AF_DCMotor m4(4);

void setup() {
 rec.enableIRIn();
 m3.setSpeed(255);
 m4.setSpeed(255);
}

void loop() {
  if(rec.decode(&result)){
    if(result.value == 3772778233){
      m3.run(FORWARD);
      m4.run(FORWARD);
    }
    else if(result.value == 3772810873 )
    {
      m3.run(BACKWARD);
      m4.run(BACKWARD);
    }
    else if(result.value == 3772819033)
    {
      m3.run(FORWARD);
      m4.run(BACKWARD);
    }
    else if(result.value == 3772794553)
    {
      m3.run(BACKWARD);
      m4.run(FORWARD);
    }
    else{
      m3.run(RELEASE);
      m4.run(RELEASE);
    }
    rec.resume();
  }
}

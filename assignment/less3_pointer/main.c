#include <stdio.h>


typedef int PIN;

typedef struct {
   void (*start)(void);
   void (*stop)(void);
   void (*changeSpeed)(int speed);
   PIN pinNumber;
} MotorController;

MotorController *currentMotor = NULL;


// Các hàm chung
void startMotor(void) {
   printf("Start motor at PIN %d\n", currentMotor->pinNumber);
}

void stopMotor(void) {
   printf("Stop motor at PIN %d\n", currentMotor->pinNumber);
}

void changeSpeedMotor(int speed) {
   printf("Change speed at PIN %d: %d\n", currentMotor->pinNumber, speed);
}

// Macro để khởi tạo GPIO và MotorController
#define INIT_MOTOR(motorName, pinNumber) \
   MotorController motorName = {startMotor, stopMotor, changeSpeedMotor, pinNumber};

#define SET_CURRENT_MOTOR(motorName) \
    currentMotor = &motorName;

int main() {
   // Sử dụng macro để khởi tạo
   INIT_MOTOR(motorA, 1);
   INIT_MOTOR(motorB, 2);

   // Sử dụng motorA
   SET_CURRENT_MOTOR(motorA);
   motorA.start();
   motorA.changeSpeed(50);
   motorA.stop();

   // Sử dụng motorB
   SET_CURRENT_MOTOR(motorB);
   motorB.start();
   motorB.changeSpeed( 75);
   motorB.stop();

   return 0;
}

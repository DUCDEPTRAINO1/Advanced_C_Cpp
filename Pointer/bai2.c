#include <stdio.h>

/*Định nghĩa một kiểu dữ liệu MotorController, trong đó bao gồm các con trỏ hàm:*/
typedef struct {
   void (*start)(int gpio);
   void (*stop)(int gpio);
   void (*changeSpeed)(int gpio, int speed);
} MotorController;

/* Định nghĩa một kiểu PIN là kiểu nguyên int. Điều này giúp mã nguồn dễ đọc hơn khi làm việc với các giá trị đại diện cho chân GPIO */
typedef int PIN;

// Các hàm chung
void startMotor(PIN pin) {
   printf("Start motor at PIN %d\n", pin);
}

void stopMotor(PIN pin) {
   printf("Stop motor at PIN %d\n", pin);
}

void changeSpeedMotor(PIN pin, int speed) {
   printf("Change speed at PIN %d: %d\n", pin, speed);
}

/* Đây là macro, cho phép bạn tự động tạo ra một cấu trúc MotorController và gán các hàm điều khiển cho nó.*/
#define INIT_MOTOR(motorName, pinNumber) \
   PIN PIN_##motorName = pinNumber; \
   MotorController motorName = {startMotor, stopMotor, changeSpeedMotor};

int main() {
   // Sử dụng macro để khởi tạo
   INIT_MOTOR(motorA, 1);
   INIT_MOTOR(motorB, 2);

   // Sử dụng motorA
   motorA.start(PIN_motorA);
   motorA.changeSpeed(PIN_motorA, 50);
   motorA.stop(PIN_motorA);

   // Sử dụng motorB
   motorB.start(PIN_motorB);
   motorB.changeSpeed(PIN_motorB, 75);
   motorB.stop(PIN_motorB);

   return 0;
}

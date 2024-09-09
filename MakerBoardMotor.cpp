#include "MakerBoardMotor.h"
#include "Arduino.h"

MakerBoardMotor::MakerBoardMotor(uint8_t INA, uint8_t INB)
{
  this->pin_A = INA;
  this->pin_B = INB;
}

int MakerBoardMotor::pinSwitch()
{
  if (this->direction == FORWARD)
  {
    digitalWrite(this->pin_B, LOW);
    return this->pin_A;
  }
  if (this->direction == BACKWARD)
  {
    digitalWrite(this->pin_A, LOW);
    return this->pin_B;
  }
}
void MakerBoardMotor::set(int16_t duration, int8_t direction)
{
  if (duration < 0)
  {
    this->direction = direction == FORWARD ? BACKWARD : FORWARD;
  }
  else
  {
    this->direction = direction;
  }
  this->duration = abs(TIME * duration / 100);
}


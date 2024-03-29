/*
  DetectaFlanco.cpp - Library for detecting button state change.
  Created by aprendiendoarduino, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DetectaFlanco.h"

DetectaFlanco::DetectaFlanco(int pin) {
  _pin = pin ;
}

void DetectaFlanco::inicio(int input) {  //solo admitre los parámetros INPUT e INPUT_PULLUP
  pinMode(_pin, input);
  _anterior_estado = digitalRead(_pin);
}

int DetectaFlanco::comprueba() {
  _estado = digitalRead(_pin);

  if (_anterior_estado != _estado) {
    if (_estado == HIGH) {
      _anterior_estado = _estado;
      return 1; //Flanco Ascendente
    }
    else {
      _anterior_estado = _estado;
      return -1; //Flanco Descendente
    }
  }
  else
    return 0;
}

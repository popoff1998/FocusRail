#include "motor.h"
#include <Arduino.h>

void Motor::initMotor()
{
    // Configuración de los pines de control del motor
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(ENDSTOP_PIN, INPUT_PULLUP);
    movDistance = 10;
    movDistances[0] = 10;
    movDistances[1] = 1;
    movDistances[2] = 0.1;
}

//Funcion para poner la distancia de movimiento en funcion del indice
void Motor::setMovDistance(int indice)
{
    movDistance = movDistances[indice];
}

// Función para mover el motor un número de pasos en una dirección
void Motor::moveMotorSteps(int steps, int dir)
{
    // Configuración de la dirección del motor
    digitalWrite(DIR_PIN, dir);

    // Movimiento del motor
    for (int i = 0; i < abs(steps); i++)
    {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(500);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(500);
    }
}

// Funcion para mover el motor una distancia en milímetros
void Motor::moveMotorDistance(float distance, int dir)
{
    // Calculo de los pasos necesarios para mover la distancia deseada
    int steps = distance * STEPS_PER_REVOLUTION / MM_PER_REVOLUTION;

    // Movimiento del motor
    moveMotorSteps(steps, dir);
}

// Funcion para mover el motor hasta que se active el final de carrera
void Motor::moveMotorUntilEndstop(int dir)
{
    // Movimiento del motor
    while (digitalRead(ENDSTOP_PIN) == HIGH)
    {
        moveMotorSteps(1, dir);
    }
}

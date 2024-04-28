#include "motor.h"
#include "ui.h"
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
    atEndStop = false;
    lastDir = FORWARD;
}

//Funcion para poner la distancia de movimiento en funcion del indice
void Motor::setMovDistance(int indice)
{
    movDistance = movDistances[indice];
}

// Función para mover el motor un número de pasos en una dirección
void Motor::moveMotorSteps(int steps, int dir)
{
    //Ponemos la etiqueta de movimiento en funcion del movimiento
    if (steps == 0)
    {
        _ui_label_set_property(ui_movLabel, _UI_LABEL_PROPERTY_TEXT, "Stop");
    }
    else if (dir == FORWARD)
    {
        _ui_label_set_property(ui_movLabel, _UI_LABEL_PROPERTY_TEXT, "Move Forward");
    }
    else
    {
        _ui_label_set_property(ui_movLabel, _UI_LABEL_PROPERTY_TEXT, "Move Backward");
    }
    #ifdef DEBUG
    Serial.print("Moving motor ");
    Serial.print(steps);
    Serial.print(" steps in direction ");
    Serial.println(dir);
    //Imprimimos el estado del final de carrera
    Serial.print("Endstop state: ");
    Serial.println(digitalRead(ENDSTOP_PIN));
    #endif
    //Comprobamos que no hemos llegado al final de carrera
    if (atEndStop && dir == lastDir)
    {
        Serial.println("Endstop reached, can't move");
        return;
    }
    else
    {
        atEndStop = false;
    }

    // Configuración de la dirección del motor
    digitalWrite(DIR_PIN, dir);
    lastDir = dir;

    // Movimiento del motor
    for (int i = 0; i < abs(steps); i++)
    {
        digitalWrite(STEP_PIN, HIGH);
        delayMicroseconds(500);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(500);
        if (endStopReached())
        {
            Serial.println("Endstop reached");
            atEndStop = true;
            return;
        }
    }
}

// Funcion para mover el motor una distancia en milímetros
void Motor::moveMotorDistance(float distance, int dir)
{
    // Calculo de los pasos necesarios para mover la distancia deseada
    int steps = distance * STEPS_PER_REVOLUTION / MM_PER_REVOLUTION;

    // Movimiento del motor
    moveMotorSteps(steps, dir);
    // Escribimos stop en ui_movLabel
    _ui_label_set_property(ui_movLabel, _UI_LABEL_PROPERTY_TEXT, "Stop");
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

// Funcion para comprobar si se ha llegado al final de carrera
bool Motor::endStopReached()
{
    return digitalRead(ENDSTOP_PIN) == HIGH;
}
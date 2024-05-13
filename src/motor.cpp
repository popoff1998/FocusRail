#include "motor.hpp"
#include "ui.h"
#include <Arduino.h>
#include <WebSerial.h>
#include "config.hpp"
#include "log.hpp"

void Motor::initMotor()
{
    // Configuración de los pines de control del motor
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(ENDSTOP_PIN, INPUT_PULLUP);
    movDistance = 10;
    movDistances[0] = 9999;
    movDistances[1] = 50;
    movDistances[2] = 10;
    movDistances[3] = 1;
    movDistances[4] = 0.1;
    forwardEndStop = false;
    backwardEndStop = false;
    currentDir = FORWARD;
    lastDir = FORWARD;
}

//Funcion para poner la distancia de movimiento en funcion del indice
void Motor::setMovDistance(int indice)
{
    movDistance = movDistances[indice];
}

//Funcion para actualizar las etiquetas de movimiento
void Motor::updateMoveLabels(int steps,int dir)
{
    if (steps == 0)
    {
        MyLog.println("Update Label Stop");
        _ui_label_set_property(ui_movLabel, _UI_LABEL_PROPERTY_TEXT, "Stop");
    }
    else if (dir == FORWARD)
    {
        MyLog.println("Update Label Move Forward");
        _ui_label_set_property(ui_movLabel, _UI_LABEL_PROPERTY_TEXT, "Move Forward");
    }
    else
    {
        MyLog.println("Update Label Move Backward");
        _ui_label_set_property(ui_movLabel, _UI_LABEL_PROPERTY_TEXT, "Move Backward");
    }
}
//Funcion para mover el motor
void Motor::moveMotor()
{
    // Movimiento del motor
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(500);
}
//Funcion para poner la direccion del motor
void Motor::setDir(bool dir)
{
    digitalWrite(DIR_PIN, dir);
    lastDir = dir;
}
// Función para mover el motor un número de pasos en una dirección
void Motor::moveMotorSteps(int steps, bool dir)
{
    currentDir = dir;
    //Ponemos la etiqueta de movimiento en funcion del movimiento
            #ifdef DEBUG
            if(logType == SERIAL_LOG)
            {
                Serial.print("Moving motor ");
                Serial.print(steps);
                Serial.print(" steps in direction ");
                Serial.println(dir);
                Serial.print("Endstop state: ");
                Serial.println(digitalRead(ENDSTOP_PIN));
            }
            else if(logType == WEB_LOG)
            {
                WebSerial.print("Moving motor ");
                WebSerial.print(steps);
                WebSerial.print(" steps in direction ");
                WebSerial.println(dir);
                WebSerial.print("Endstop state: ");
                WebSerial.println(digitalRead(ENDSTOP_PIN));
            }
            #endif
    //Comprobamos que no hemos llegado al final de carrera
    if (!canMove())
    {
            #ifdef DEBUG
            if(logType == SERIAL_LOG)
            {
                Serial.println("Can't move");
            }
            else if(logType == WEB_LOG)
            {
                WebSerial.println("Can't move");
            }
            #endif
        return;
    }
    // Configuración de la dirección del motor
    setDir(dir);
    // Movimiento del motor
    for (int i = 0; i < abs(steps); i++)
    {
        //Comprobamos que podemos movernos
        if (!canMove())
        {
            //Cambiamos de direccion y movemos el motor 5 pasos
           setDir(!currentDir);
           #ifdef DEBUG
            if(logType == SERIAL_LOG)
            {
                Serial.println("Endstop reached, moving backwards");
            }
            else if(logType == WEB_LOG)
            {
                WebSerial.println("Endstop reached, moving backwards");
            }
            #endif
           for (int j = 0; j < BACKWARD_STEPS; j++)
            {
                moveMotor();
            }
            return;
        }
        //Movemos el motor 
        moveMotor();
    }
    //Comprobamos si después del movimiento hemos llegado al final de carrera
    if (endStopReached())
    {
        //Cambiamos de direccion y movemos el motor 5 pasos
        setDir(!currentDir);
        #ifdef DEBUG
        if(logType == SERIAL_LOG)
        {
            Serial.println("Endstop reached after last moveMotor, moving backwards");
        }
        else if(logType == WEB_LOG)
        {
            WebSerial.println("Endstop reached after last moveMotor, moving backwards");
        }
        #endif
        for (int j = 0; j < BACKWARD_STEPS; j++)
        {
            moveMotor();
        }
    }
}

// Funcion para mover el motor una distancia en milímetros
void Motor::moveMotorDistance(float distance, bool dir)
{
    // Calculo de los pasos necesarios para mover la distancia deseada
    int steps = distance * STEPS_PER_REVOLUTION / MM_PER_REVOLUTION;
    //Ponemos la etiqueta de movimiento en funcion del movimiento
    updateMoveLabels(steps,dir);
    // Movimiento del motor
    moveMotorSteps(steps, dir);
    // Escribimos stop en ui_movLabel
    _ui_label_set_property(ui_movLabel, _UI_LABEL_PROPERTY_TEXT, "Stop");
}

// Funcion para mover el motor hasta que se active el final de carrera
void Motor::moveMotorUntilEndstop(bool dir)
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
    if(digitalRead(ENDSTOP_PIN) == HIGH)
    {
        switch(currentDir)
        {
            case FORWARD:
                forwardEndStop = true;
                backwardEndStop = false;
                break;
            case BACKWARD:
                backwardEndStop = true;
                forwardEndStop = false;
                break;
        }
        return true;
    }
    // ponemos a false los endstops
    forwardEndStop = false;
    backwardEndStop = false;
    return false;
}

bool Motor::canMove()
{
    //Leemos el estado del final de carrera
    if(!endStopReached())
    {
        return true;
    }
    //Comprobamos que podemos movernos aunque hayamos llegado a un final de carrera
    if (forwardEndStop && (currentDir == FORWARD))
    {
        return false;
    }
    if (backwardEndStop && (currentDir == BACKWARD))
    {
        return false;
    }
    return true;
}
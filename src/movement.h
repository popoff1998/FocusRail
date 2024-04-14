// Definición de los pines de control del motor
#define STEP_PIN 22
#define DIR_PIN 27

// Definición de los pines de control de los finales de carrera
#define ENDSTOP_PIN 34

// Pasos por vuelta del motor
#define STEPS_PER_REVOLUTION 200

//Definimos las direcciones de los motores
#define FORWARD 0
#define BACKWARD 1

//Definimos los milimetros por vuelta del motor
#define MM_PER_REVOLUTION 2



//Variables globales
#ifndef MOVEMENT_H
#define MOVEMENT_H
//Variable para almacenar la distancia de movimiento
extern float movDistance;
extern float movDistances[3];
#endif
//Protoripos de las funciones de movement.cpp
void initMotor();
void moveMotorSteps(int, int);
void moveMotorDistance(float, int);
void moveMotorUntilEndstop(int);

//Fin del archivo movement.h
// Path: src/movement.cpp

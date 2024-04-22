#define DEBUG 1
// Definición de los pines de control del motor
#define STEP_PIN 22
#define DIR_PIN 27

// Definición de los pines de control de los finales de carrera
#define ENDSTOP_PIN 4 //RED led

// Pasos por vuelta del motor
#define STEPS_PER_REVOLUTION 200

// Definimos las direcciones de los motores
#pragma once

#define FORWARD 0
#define BACKWARD 1

// Definimos los milimetros por vuelta del motor
#define MM_PER_REVOLUTION 2

class Motor
{
    public:
        //Metodos de la clase Motor
        Motor() {};
        void initMotor();
        void moveMotorSteps(int, int);
        void moveMotorDistance(float, int);
        void moveMotorUntilEndstop(int);
        void setMovDistance(int);
        //Variables de la clase Motor
        float movDistances[3];
        float movDistance;
    private:
        int lastDir;
        bool atEndStop;
        bool endStopReached();
};
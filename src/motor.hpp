#pragma once

#include "config.hpp"
#include "log.hpp"

// Definición de los pines de control del motor
#define STEP_PIN 22
#define DIR_PIN 27

// Definición de los pines de control de los finales de carrera
#define ENDSTOP_PIN 4 //RED led

// Pasos por vuelta del motor
#define STEPS_PER_REVOLUTION 200

#define FORWARD false
#define BACKWARD true

// Definimos los milimetros por vuelta del motor
#define MM_PER_REVOLUTION 2
//definimos los pasos de vuelta atras en caso de endstoop
#define BACKWARD_STEPS 400

class Motor
{
    public:
        //Metodos de la clase Motor
        Motor() {};
        void initMotor(Config,Log);
        void moveMotorSteps(int, bool);
        void moveMotorDistance(float, bool);
        void moveMotorUntilEndstop(bool);
        void setMovDistance(int);
        //Variables de la clase Motor
        float movDistances[5];
        float movDistance;
    private:
        bool lastDir;
        float lastDistance;
        bool currentDir;
        bool forwardEndStop;
        bool backwardEndStop;
		Config config;
		Log log;
        bool endStopReached();
        bool canMove();
        void updateMoveLabels(int,int);
        void moveMotor();
        void setDir(bool);
};
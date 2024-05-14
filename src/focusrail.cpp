#include "focusrail.hpp"

FocusRail::FocusRail()
{
	//Inicializamos las clases
	config.initConfiguration();
	log.initLog(config);
	motor.initMotor(config,log);
	camera.initCamera(config,log);
}

FocusRail::~FocusRail()
{
}

void FocusRail::initFocusRail()
{
	//Inicializamos el motor
	motor.initMotor(config,log);
	//Inicializamos la camara
	camera.initCamera(config,log);
}

void FocusRail::setMovDistance(int distance)
{
	//Guardamos la distancia de movimiento
	motor.setMovDistance(distance);
}

void FocusRail::moveMotor(bool dir)
{
	//Movemos el motor
	motor.moveMotorDistance(motor.movDistance,dir);
}

void FocusRail::setCamera(int camType)
{
	camera.setCamera(camType);
}

void FocusRail::setCameraInterface(int camInterface)
{
	camera.setInterface(camInterface);
}

void FocusRail::setCapProf(int capProf)
{
	camera.setCapProf(capProf);
}

void FocusRail::setCapFotos(int capFotos)
{
	camera.setCapFotos(capFotos);
}

void FocusRail::setCapTime(int capTime)
{
	camera.setCapTime(capTime);
}

void FocusRail::capturePhotos()
{
	// Calculamos la distancia de movimiento en funcion de captFotos y capProf
	float distance = (float)camera.getCapProf() / (float)camera.getCapFotos();

	// Iniciamos la captura de fotos
	for (int i = 0; i < camera.getCapFotos(); i++)
	{
		// Movemos el motor
		motor.moveMotorDistance(distance, FORWARD);
		// Esperamos el tiempo de captura
		delay(camera.getCapTime() * 1000);
		// Capturamos la foto
		camera.capturePhoto();
		// Esperamos un tiempo para que la cámara se prepare para la siguiente foto
		delay(camera.getCapTime() * 1000);
	}
}

// Path: src/focusrail.hpp
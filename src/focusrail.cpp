#include "focusrail.hpp"

FocusRail::FocusRail()
{
	//Inicializamos las clases
	config.initConfiguration();
	log.initLog(config);
	motor.initMotor(config,log);
	camera.initCamera(config,log);
}
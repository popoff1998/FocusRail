#include "focusrail.hpp"

FocusRail::FocusRail()
{
}

FocusRail::~FocusRail()
{
}

void FocusRail::initFocusRail()
{
	// Inicializamos las clases
	config.initConfiguration();
	//Actualizamos el interfaz con los valores de la configuración
	log.initLog(config);
	motor.initMotor(config, log);
	camera.initCamera(config, log);

	//Ponemos la camara y el interface por defecto
	setCamera(CANON);
	setCameraInterface(IR);
	if(config.camType == CANON)
	{
		setCanonTime(config.canon_time);
	}
}

String FocusRail::getSsid()
{
	return config.ssid;
}

String FocusRail::getPassword()
{
	return config.password;
}

String FocusRail::getHostname()
{
	return config.hostname;
}

void FocusRail::setMovDistance(int distance)
{
	//Guardamos la distancia de movimiento
	motor.setMovDistance(distance);
}

void FocusRail::moveMotor(bool dir)
{
	//Movemos el motor
	motor.moveMotorDistance(motor.getMovDistance(),dir);
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
		// Capturamos la foto
		camera.capturePhoto();
		// Esperamos el tiempo de captura
		delay(camera.getCapTime() * 1000);
		// Movemos el motor
		motor.moveMotorDistance(distance, FORWARD);
		// Esperamos un tiempo para que la cámara se prepare para la siguiente foto
		delay(camera.getCapTime() * 1000);
	}
}

void FocusRail::setCanonTime(int canonTime)
{
	config.canon_time = canonTime;
	camera.setCanonTime(canonTime);
}

//Funcion para actualizar la interfaz con los valores de la configuración
void FocusRail::updateInterfaceFromConfig()
{
	//Actualizamos el interfaz con los valores de la configuración
	updateInterfaceCapture();
	updateInterfaceMovement();
	updateInterfaceConfig();
}

void FocusRail::updateInterfaceCapture()
{
	//Actualizamos camprof en el interfaz
	lv_slider_set_value(ui_capProfSlider, config.capProf, LV_ANIM_OFF);
	lv_label_set_text_fmt(ui_capProfLabel, "%d", config.capProf);
	//Actualizamos capFotos en el interfaz
	lv_slider_set_value(ui_capFotSlider, config.capFotos, LV_ANIM_OFF);
	lv_label_set_text_fmt(ui_capFotLabel, "%d", config.capFotos);
	//Actualizamos capTime en el interfaz
	lv_slider_set_value(ui_capTimeSlider, config.capTime, LV_ANIM_OFF);
	lv_label_set_text_fmt(ui_capTimeLabel, "%d", config.capTime);
	//Actualizamos camType en el interfaz
	lv_dropdown_set_selected(ui_camType, config.camType);
}

void FocusRail::updateInterfaceMovement()
{
	lv_dropdown_set_selected(ui_dropDownDistMov, motor.getMovDistance());
}

void FocusRail::updateInterfaceConfig()
{
	//Actualizamos el canon_time en el interfaz
	lv_slider_set_value(ui_canonTimeSlider, config.canon_time, LV_ANIM_OFF);
	lv_label_set_text_fmt(ui_canonTimeLabel, "%d", config.canon_time);
}

	


// Path: src/focusrail.hpp
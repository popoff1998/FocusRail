//incluimos los headers del resto de clases
#include "motor.hpp"
#include "camera.hpp"
#include "config.hpp"
#include "log.hpp"

//Definimos la clase FocusRail
class FocusRail
{
	public:
		FocusRail();
		~FocusRail();
		void initFocusRail();
		void setMovDistance(int);
		void moveMotor(bool);
		void capturePhotos();
		void setCamera(int);
		void setCameraInterface(int);
		void setCapProf(int);
		void setCapFotos(int);
		void setCapTime(int);
	private:
		Motor motor;
		Camera camera;
		Config config;
		Log log;
};
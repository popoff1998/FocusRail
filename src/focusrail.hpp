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
	private:
		Motor motor;
		Camera camera;
		Config config;
		Log log;
};
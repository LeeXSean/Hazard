#include "Hazard.h"

class Sandbox : public Hazard::Application 
{
public:
	Sandbox() {
		
	}

	~Sandbox() {
	
	}

};

Hazard::Application* Hazard::CreateApplication() 
{
	return new Sandbox();
}
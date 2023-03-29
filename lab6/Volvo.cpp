#include "Volvo.h"

const char* Volvo::Name() const {
	return "Volvo";
}

unsigned int Volvo::FuelCapacity() const {
	return m_fuelCapacity;
}

double Volvo::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int Volvo::Speed(Weather weather) const {
	switch (weather) {
	case Weather::Sunny:
		return m_maxSpeed;
		break;
	case Weather::Rain:
		return 8 * m_maxSpeed / 10;
		break;
	case Weather::Snow:
		return 6 * m_maxSpeed / 10;
		break;
	default:
		return m_maxSpeed;
	}
}
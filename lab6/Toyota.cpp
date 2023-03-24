#include "Toyota.h"

const char* Toyota::Name() const {
	return "Toyota";
}

unsigned int Toyota::FuelCapacity() const {
	return m_fuelCapacity;
}

double Toyota::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int Toyota::Speed(Weather weather) const {
	switch (weather) {
	case Weather::Sunny:
		return m_maxSpeed;
		break;
	case Weather::Rain:
		return 84 * m_maxSpeed / 100;
		break;
	case Weather::Snow:
		return 60 * m_maxSpeed / 100;
		break;
	default:
		return m_maxSpeed;
	}
}
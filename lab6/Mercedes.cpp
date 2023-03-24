#include "Mercedes.h"

const char* Mercedes::Name() const {
	return "Mercedes";
}

unsigned int Mercedes::FuelCapacity() const {
	return m_fuelCapacity;
}

double Mercedes::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int Mercedes::Speed(Weather weather) const {
	switch (weather) {
	case Weather::Sunny:
		return m_maxSpeed;
		break;
	case Weather::Rain:
		return 90 * m_maxSpeed / 100;
		break;
	case Weather::Snow:
		return 80 * m_maxSpeed / 100;
		break;
	default:
		return m_maxSpeed;
	}
}
#include "Ford.h"

const char* Ford::Name() const {
	return "Ford";
}

unsigned int Ford::FuelCapacity() const {
	return m_fuelCapacity;
}

double Ford::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int Ford::Speed(Weather weather) const {
	switch (weather) {
	case Weather::Sunny:
		return m_maxSpeed;
		break;
	case Weather::Rain:
		return 85 * m_maxSpeed / 100;
		break;
	case Weather::Snow:
		return 57 * m_maxSpeed / 100;
		break;
	default:
		return m_maxSpeed;
	}
}
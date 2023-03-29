#include "Fiat.h"

const char* Fiat::Name() const {
	return "Fiat";
}

unsigned int Fiat::FuelCapacity() const {
	return m_fuelCapacity;
}

double Fiat::FuelConsumption() const {
	return m_fuelConsumption;
}

unsigned int Fiat::Speed(Weather weather) const {
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
#include "pch.h"
#include "MyWeatherPrediction.h"

void MyWeatherPrediction::setCurrentTempCelsius(int inTemp)
{
	int fahrenheitTemp = convertCelsiusToFahrenheit(inTemp);
	setCurrentTempFahrenheit(fahrenheitTemp);
}

int MyWeatherPrediction::getTomorrowTempCelsius() const
{
	int fahrenheitTemp = getTomorrowTempFahrenheit();
	return convertFahrenheitToCelsius(fahrenheitTemp);
}

void MyWeatherPrediction::showResult() const
{
	cout << "Tomorrow's temperature will be " <<
		getTomorrowTempCelsius() << " degrees Celsuis (" <<
		getTomorrowTempFahrenheit() << " degrees Fahrenheit)" << endl;
	cout << "Chance of rain is " << (getChanceOfRain() * 100) << " percent"
		<< endl;

	if (getChanceOfRain() > 0.5)
		cout << "Bring an umbrella!" << endl;
}

std::string MyWeatherPrediction::getTemperature() const
{
	// \u00B0�� ISO/IEC 10646 ǥ�ؿ� ���� �µ��� ��Ÿ���� ��ȣ�� �ǹ�
	return WeatherPrediction::getTemperature() + "\u00B0"; 
	//����!
	/*C++������ ���� ������ ������, �״������� Ŭ���� ����������
	�޼��� �̸��� ã�� ������ �ᱹ getTemperature()ȣ���� 
	MyWeatherPrediction::getTemperature() ȣ��� ����.
	�ǵ���� �۵��ϴ� �ڵ带 ������� ������ ���� �����ڸ� ����ؾ� �Ѵ�.
	
	NOTE : ����ũ�μ���Ʈ ���־� C++������ __super Ű���带 �����Ͽ� ��������� 
	�θ��̸��� �������� �ʾƵ� �����ϰ� �θ��� �޼��带 ȣ�� �� �� �ְ� ���ش�.
	return __super::getTemperature() + "\u00B0F";
	*/
}

int MyWeatherPrediction::convertCelsiusToFahrenheit(int inCelsius)
{
	return 0;
}

int MyWeatherPrediction::convertFahrenheitToCelsius(int inFahrenheit)
{
	return 0;
}

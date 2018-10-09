//�������� ����� �̿��ؼ� �µ��� �����ϰ�, �񼺿��� ȭ�� ������ �Ÿ��� ������� ������
//�����Ѵ�. ������ �׷��� ���� �������� �ʾƵ� ������ ������ �� �ִ�.
//��, �� ��쿡�� ��Ȯ���� 99%�ۿ� �� �ȴ�.
#pragma once

class WeatherPrediction
{
public:
	WeatherPrediction() = default;
	//���߾� �Ҹ���
	virtual ~WeatherPrediction();
	//���� �µ��� ȭ�� ������ �����Ѵ�.
	virtual void setCurrentTempFahrenheit(int inTemp);
	//�񼺰� ȭ���� ������ �Ÿ��� �����Ѵ�.
	virtual void setPositionOfJupiter(int inDistanceFromMars);
	//������ �µ� ���� ����� �����Ѵ�.
	virtual int getTomorrowTempFahrenheit() const;
	//���� �� �� Ȯ���� ��´�. ���ϰ� 1�� ���� �ݵ�� �� �´ٴ� �ǹ̰�,
	//���ϰ� 0�� �� ���� �ʴ´ٴ� �ǹ̴�.
	virtual double getChanceOfRain() const;
	//�Ʒ� �������� ���� ���� ����� ����Ѵ�.
	//Result: x.xx chance. Temp. xx
	virtual void showResult() const;
	//�µ� ���� ����� ���ڿ��� �����Ѵ�.
	virtual std::string getTemperature() const;
private:
	int mCurrentTempFahrenheit;
	int mDistanceFromMars;
};


#ifndef ENGINECONFIGURATION_H
#define ENGINECONFIGURATION_H

#include <QObject>
#include <QDebug>
class EngineConfiguration : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int engineRPM READ engineRPM WRITE set_engineRPM NOTIFY engineRPMChanged)
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(double maxEngineRPM READ maxEngineRPM WRITE setmaxEngineRPM NOTIFY maxEngineRPMChanged)
    Q_PROPERTY(int curGear READ curGear WRITE setcurGear NOTIFY curGearChanged)
    Q_PROPERTY(int fuelLevel READ fuelLevel WRITE setfuelLevel NOTIFY fuelLevelChanged)
    Q_PROPERTY(int engineTemp READ engineTemp WRITE setengineTemp NOTIFY engineTempChanged)
    Q_PROPERTY(QString distanceStr READ distanceStr WRITE setdistanceStr NOTIFY distanceStrChanged)

public:
    explicit EngineConfiguration(QObject *parent = nullptr);
    int engineRPM() const;
    void set_engineRPM(int temp);
    int speed() const;
    void setSpeed(int temp);

    Q_INVOKABLE void accelerate(bool acc);
    Q_INVOKABLE void applyBrake(bool brakes);
    Q_INVOKABLE void updateEngineProp(QString param, double value);

    Q_INVOKABLE double maxEngineRPM() const;
    Q_INVOKABLE double getEngineProperty(QString param);
    void setmaxEngineRPM(double newMaxEngineRPM);

    int curGear() const;
    void setcurGear(int newCurGear);

    int fuelLevel() const;
    void setfuelLevel(int newFuelLevel);

    int engineTemp() const;
    void setengineTemp(int newEngineTemp);

    const QString &distanceStr() const;
    void setdistanceStr(const QString &newDistanceStr);

    void init();

public slots:
    void calculateSpeed();
    void calculateDistance();
    void generateEvent();

signals:
    void engineRPMChanged();
    void speedChanged();

    void maxEngineRPMChanged();

    void curGearChanged();

    void fuelLevelChanged();

    void engineTempChanged();

    void eventGenerated(QString event);

    void distanceStrChanged();

private:
    void saveDistance(double distance);

    int m_engineRPM;
    int m_speed;
    int m_curGear;
    int m_fuelLevel;
    int m_engineTemp;
    bool isAccelerating;
    bool isBraking;
    double m_maxEngineRPM;
    double m_tyreDiameter;
    double m_distance;
    QString m_distanceStr;
    QVector<double> m_gearRatios;
    QVector<int> m_gearSpeeds;
    double m_driveRatio;



};

#endif // ENGINECONFIGURATION_H

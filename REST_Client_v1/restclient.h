#ifndef RESTCLIENT_H
#define RESTCLIENT_H
#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

class RESTClient : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString responseText READ responseText WRITE setresponseText NOTIFY responseTextChanged)
    Q_PROPERTY(QString imageUrl READ imageUrl WRITE setimageUrl NOTIFY imageUrlChanged)
public:
    explicit RESTClient(QObject *parent = nullptr);
    const QString &responseText() const;
    void setresponseText(const QString &newResponseText);
    const QString &imageUrl() const;
    void setimageUrl(const QString &newImageUrl);
signals:
    void responseTextChanged();
    void imageUrlChanged();
public slots:
    void onResponseReceived(QNetworkReply* reply);
    void createGetRequest(QUrl requestUrl);
private:
    void parseImageUrl(QJsonObject jsonObj);
    QNetworkAccessManager* m_networkManager;
    QString m_responseText;
    QString m_imageUrl;
};

#endif // RESTCLIENT_H

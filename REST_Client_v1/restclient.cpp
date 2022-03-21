#include "restclient.h"

RESTClient::RESTClient(QObject *parent)
    : QObject{parent}
{
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager, &QNetworkAccessManager::finished, this, &RESTClient::onResponseReceived);
}

void RESTClient::createGetRequest(QUrl requestUrl)
{
    if(!requestUrl.isEmpty())
    {
        QNetworkRequest request(requestUrl);
        m_networkManager->get(request);
    }
    else
    {
        qDebug() << "Request URL is empty";
        m_responseText = m_responseText + "Request URL is empty";
        emit responseTextChanged();
    }
}

void RESTClient::parseImageUrl(QJsonObject jsonObj)
{
    QJsonValue imageURLVal = jsonObj.value(QStringLiteral("url"));
    m_imageUrl = imageURLVal.toString();
    emit imageUrlChanged();
}

void RESTClient::onResponseReceived(QNetworkReply *reply)
{
//    QString rep = QString::fromStdString(reply->readAll().toStdString());
//    qDebug() << rep;
    QByteArray respBytes = reply->readAll();
    QJsonDocument jsondocResponse = QJsonDocument::fromJson(respBytes);
    QJsonObject jsonRespObject = jsondocResponse.object();
    parseImageUrl(jsonRespObject);
    QString jsonStringResp(jsondocResponse.toJson(QJsonDocument::Indented));
    m_responseText = jsonStringResp;
    emit responseTextChanged();
}


const QString &RESTClient::responseText() const
{
    return m_responseText;
}

void RESTClient::setresponseText(const QString &newResponseText)
{
    if (m_responseText == newResponseText)
        return;
    m_responseText = newResponseText;
    emit responseTextChanged();
}

const QString &RESTClient::imageUrl() const
{
    return m_imageUrl;
}

void RESTClient::setimageUrl(const QString &newImageUrl)
{
    if (m_imageUrl == newImageUrl)
        return;
    m_imageUrl = newImageUrl;
    emit imageUrlChanged();
}

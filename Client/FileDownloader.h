#pragma once

#define QT_NO_NETWORKPROXY
#define QT_NO_SSL

#include <QtNetwork/qnetworkreply.h>
#include <qnetworkaccessmanager.h>

namespace Client
{
class FileDownloader : public QObject
{
    Q_OBJECT;

  public:
    FileDownloader(QObject *aParent);

    void Download(const QUrl &aURL, const QString &aFile);

  private slots:
    void Downloaded(QNetworkReply *aReply);
    void AuthenticationRequired(QNetworkReply *aReply, QAuthenticator *aAuthenticator);

  private:
    QNetworkAccessManager mManager;

    std::map<QNetworkReply *, QString> mURLToFile{};
    std::mutex mMutexURLToFile;

    void Initialize();
};
} // namespace Client

#include "pch.h"
#include "FileDownloader.h"

namespace Client
{
FileDownloader::FileDownloader(QObject *aParent) : QObject(aParent), mManager(this)
{
    Initialize();
}

void FileDownloader::Initialize()
{
    QObject::connect(&mManager, &QNetworkAccessManager::finished, this, &FileDownloader::Downloaded);
}

void FileDownloader::Download(const QUrl &aURL, const QString &aFile)
{
    QNetworkRequest request(aURL);
    auto reply = mManager.get(request);

    scoped_lock lock(mMutexURLToFile);
    mURLToFile[reply] = aFile;
}

void FileDownloader::Downloaded(QNetworkReply *aReply)
{
    aReply->deleteLater();

    if (aReply->error() || !aReply->isReadable())
    {
        qDebug() << QString("%1 -> %2 || not readable").arg(Q_FUNC_INFO, aReply->errorString());
        return;
    }

    QFile file;
    {
        scoped_lock lock(mMutexURLToFile);
        file.setFileName(mURLToFile[aReply]);
    }

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << QString("%1 -> %2").arg(Q_FUNC_INFO, file.errorString());
        return;
    }

    file.write(aReply->readAll());
}

void FileDownloader::AuthenticationRequired(QNetworkReply *, QAuthenticator *)
{
    qDebug() << Q_FUNC_INFO;
}
} // namespace Client

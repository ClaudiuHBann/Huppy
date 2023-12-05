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

    Q_ASSERT_X(!aReply->error() && aReply->isReadable(), "function", aReply->errorString().toStdString().c_str());

    QFile file;
    {
        scoped_lock lock(mMutexURLToFile);
        file.setFileName(mURLToFile[aReply]);
    }

    Q_ASSERT_X(file.open(QIODevice::WriteOnly), "function", file.errorString().toStdString().c_str());
    file.write(aReply->readAll());
}

void FileDownloader::AuthenticationRequired(QNetworkReply *, QAuthenticator *)
{
    Q_ASSERT_X(false, "function", "");
}
} // namespace Client

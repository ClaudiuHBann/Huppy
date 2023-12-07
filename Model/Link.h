#pragma once

#include "IModel.h"

namespace Model
{
class Link : public QObject, public IModel<int, int, QString, QString, QString, QString>
{
    Q_OBJECT;
    DEFINE_MODEL(Link, id, app, url, format, os, arch);
};
} // namespace Model

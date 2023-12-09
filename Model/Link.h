#pragma once

#include "IModel.h"

namespace Model
{
class Link : public IModel<int, int, QString, QString, QString, QString>
{
    Q_GADGET;
    DEFINE_MODEL(Link, id, app, url, format, os, arch);
};
} // namespace Model

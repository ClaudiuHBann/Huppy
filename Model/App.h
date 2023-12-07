#pragma once

#include "IModel.h"

namespace Model
{
class App : public QObject, public IModel<int, int, QString, bool>
{
    Q_OBJECT;
    DEFINE_MODEL(App, id, category, name, proposed);
};
} // namespace Model

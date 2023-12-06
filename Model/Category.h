#pragma once

#include "IModel.h"

namespace Model
{
class Category : public QObject, public IModel<int, QString, QString, int>
{
    Q_OBJECT;
    DEFINE_MODEL(id, name, description, count);
};
} // namespace Model

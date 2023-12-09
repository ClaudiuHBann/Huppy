#pragma once

#include "IModel.h"

namespace Model
{
class Category : public IModel<int, QString, QString, int>
{
    Q_GADGET;
    DEFINE_MODEL(Category, id, name, description, count);
};
} // namespace Model

Q_DECLARE_METATYPE(Model::Category);

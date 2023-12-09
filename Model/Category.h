#pragma once

#include "IModel.h"

namespace Model
{
class Category : public IModel<int, QString, QString, int>
{
    Q_GADGET;
    DEFINE_MODEL(Category, id, name, description, count);

    bool operator<(const Category &aCategory) const noexcept
    {
        return id < aCategory.id;
    }
};
} // namespace Model

Q_DECLARE_METATYPE(Model::Category);

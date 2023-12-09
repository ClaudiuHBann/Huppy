#pragma once

#include "IModel.h"

namespace Model
{
class Category : public QObject, public IModel<int, QString, QString, int>
{
    // TODO: remove this workaround for not being able to access properties in QML
    // Q_OBJECT;
    Q_GADGET;
    DEFINE_MODEL(Category, id, name, description, count);
    QML_ELEMENT;
};
} // namespace Model

Q_DECLARE_METATYPE(Model::Category);

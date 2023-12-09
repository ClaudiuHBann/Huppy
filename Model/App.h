#pragma once

#include "IModel.h"

namespace Model
{
class App : public QObject, public IModel<int, int, QString, bool>
{
    // TODO: remove this workaround for not being able to access properties in QML
    // Q_OBJECT;
    Q_GADGET;
    DEFINE_MODEL(App, id, category, name, proposed);
    QML_ELEMENT;
};
} // namespace Model

Q_DECLARE_METATYPE(Model::App);

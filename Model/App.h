#pragma once

#include "IModel.h"

namespace Model
{
class App : public IModel<int, int, QString, bool>
{
    Q_GADGET;
    DEFINE_MODEL(App, id, category, name, proposed);
};
} // namespace Model

Q_DECLARE_METATYPE(Model::App);

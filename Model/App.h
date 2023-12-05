#pragma once

#include "IModel.h"

namespace Model
{
class App : public IModel<int, int, QString, bool>
{
    DEFINE_MODEL(id, category, name, proposed);

  public:
    std::tuple_element_t<0, props> id{};
    std::tuple_element_t<1, props> category{};
    std::tuple_element_t<2, props> name{};
    std::tuple_element_t<3, props> proposed{};
};
} // namespace Model

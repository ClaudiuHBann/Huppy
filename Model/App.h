#pragma once

#include "IModel.h"

namespace Model
{
class App : public IModel<int, int, QString>
{
    DEFINE_MODEL(id, category, name);

  public:
    std::tuple_element_t<0, props> id{};
    std::tuple_element_t<1, props> category{};
    std::tuple_element_t<2, props> name{};
};
} // namespace Model

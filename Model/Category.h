#pragma once

#include "IModel.h"

namespace Model
{
class Category : public IModel<int, QString, QString, int>
{
    DEFINE_MODEL(id, name, description, count);

  public:
    std::tuple_element_t<0, props> id{};
    std::tuple_element_t<1, props> name{};
    std::tuple_element_t<2, props> description{};
    std::tuple_element_t<3, props> count{};
};
} // namespace Model

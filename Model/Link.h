#pragma once

#include "IModel.h"

namespace Model
{
class Link : public IModel<int, int, QString, QString, QString, QString>
{
    DEFINE_MODEL(id, app, url, format, os, arch);

  public:
    std::tuple_element_t<0, props> id{};
    std::tuple_element_t<1, props> app{};
    std::tuple_element_t<2, props> url{};
    std::tuple_element_t<3, props> format{};
    std::tuple_element_t<4, props> os{};
    std::tuple_element_t<5, props> arch{};
};
} // namespace Model

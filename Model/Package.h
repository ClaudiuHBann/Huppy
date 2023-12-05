#pragma once

#include <quuid.h>

#include "IModel.h"

namespace Model
{
class Package : public IModel<int, QUuid, QString>
{
    DEFINE_MODEL(id, uuid, apps);

  public:
    std::tuple_element_t<0, props> id{};
    std::tuple_element_t<1, props> uuid{};
    std::tuple_element_t<2, props> apps{};
};
} // namespace Model

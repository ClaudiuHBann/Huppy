#pragma once

#include <qsqlfield.h>
#include <qsqlrecord.h>

#include "Magic.h"

// TODO: can i add the record as a param?

// from record
#define FR_PROP(prop) prop = aRecord.value(#prop).value<decltype(prop)>();
#define FR_PROPS(...) EXPAND(PASTE(FR_PROP, __VA_ARGS__))

// to record append
#define TR_A_PROP(prop) record.append(QSqlField{#prop, QMetaType::fromType<decltype(prop)>()});
#define TR_A_PROPS(...) EXPAND(PASTE(TR_A_PROP, __VA_ARGS__))

// to record set value
#define TR_SV_PROP(prop) record.setValue(#prop, QVariant::fromValue(prop));
#define TR_SV_PROPS(...) EXPAND(PASTE(TR_SV_PROP, __VA_ARGS__))

#define DEFINE_MODEL_PROPS(...)                                                                                        \
  public:                                                                                                              \
    constexpr props_cref Props() const override                                                                        \
    {                                                                                                                  \
        return {__VA_ARGS__};                                                                                          \
    }

#define DEFINE_MODEL_FR(...)                                                                                           \
  public:                                                                                                              \
    void FromRecord(const QSqlRecord &aRecord) override                                                                \
    {                                                                                                                  \
        FR_PROPS(__VA_ARGS__);                                                                                         \
    }

#define DEFINE_MODEL_TR(...)                                                                                           \
  public:                                                                                                              \
    QSqlRecord ToRecord() const override                                                                               \
    {                                                                                                                  \
        QSqlRecord record;                                                                                             \
        TR_A_PROPS(__VA_ARGS__);                                                                                       \
        TR_SV_PROPS(__VA_ARGS__);                                                                                      \
        return record;                                                                                                 \
    }

#define DEFINE_MODEL(...)                                                                                              \
    DEFINE_MODEL_PROPS(__VA_ARGS__);                                                                                   \
    DEFINE_MODEL_FR(__VA_ARGS__);                                                                                      \
    DEFINE_MODEL_TR(__VA_ARGS__);

namespace Model
{
template <typename... Types> class IModel
{
  public:
    using props = std::tuple<Types...>;
    using props_cref = std::tuple<std::add_lvalue_reference_t<std::add_const_t<Types>>...>;

    virtual props_cref Props() const = 0;

    virtual void FromRecord(const QSqlRecord &aRecord) = 0;
    virtual QSqlRecord ToRecord() const = 0;
};
} // namespace Model

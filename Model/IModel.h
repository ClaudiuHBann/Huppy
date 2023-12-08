#pragma once

#include <qsqlfield.h>
#include <qsqlrecord.h>

#include "Utility/Magic.h"

// from record
#define FR_PROP(prop) prop = aRecord.value(#prop).value<decltype(prop)>();
#define FR_PROPS(...) EXPAND(PASTE(FR_PROP, __VA_ARGS__))

#define DEFINE_MODEL_FR(...)                                                                                           \
  public:                                                                                                              \
    void FromRecord(const QSqlRecord &aRecord) override                                                                \
    {                                                                                                                  \
        FR_PROPS(__VA_ARGS__);                                                                                         \
    }

// to record append
#define TR_A_PROP(prop) record.append(QSqlField{#prop, QMetaType::fromType<decltype(prop)>()});
#define TR_A_PROPS(...) EXPAND(PASTE(TR_A_PROP, __VA_ARGS__))

// to record set value
#define TR_SV_PROP(prop) record.setValue(#prop, QVariant::fromValue(prop));
#define TR_SV_PROPS(...) EXPAND(PASTE(TR_SV_PROP, __VA_ARGS__))

#define DEFINE_MODEL_TR(...)                                                                                           \
  public:                                                                                                              \
    QSqlRecord ToRecord() const override                                                                               \
    {                                                                                                                  \
        QSqlRecord record;                                                                                             \
        TR_A_PROPS(__VA_ARGS__);                                                                                       \
        TR_SV_PROPS(__VA_ARGS__);                                                                                      \
        return record;                                                                                                 \
    }

#define DEFINE_PROP_GET(name)                                                                                          \
  public:                                                                                                              \
    constexpr const auto &Get##name() const                                                                            \
    {                                                                                                                  \
        return name;                                                                                                   \
    }

#define DEFINE_PROP_ON_CHANGE(name)                                                                                    \
  signals:                                                                                                             \
    constexpr void OnChanged##name()                                                                                   \
    {                                                                                                                  \
    }

#define DEFINE_PROP_SET(name)                                                                                          \
  public:                                                                                                              \
    inline decltype(auto) Set##name(const decltype(name) &a##name)                                                     \
    {                                                                                                                  \
        if (name == a##name)                                                                                           \
        {                                                                                                              \
            return *this;                                                                                              \
        }                                                                                                              \
                                                                                                                       \
        name = a##name;                                                                                                \
        emit OnChanged##name();                                                                                        \
                                                                                                                       \
        return *this;                                                                                                  \
    }

#define DEFINE_PROP(index, name)                                                                                       \
  private:                                                                                                             \
    std::tuple_element_t<index, props> name{};                                                                         \
                                                                                                                       \
    Q_PROPERTY(std::tuple_element_t<index, props> name READ Get##name WRITE Set##name NOTIFY OnChanged##name);         \
                                                                                                                       \
    DEFINE_PROP_GET(name);                                                                                             \
    DEFINE_PROP_ON_CHANGE(name);                                                                                       \
    DEFINE_PROP_SET(name);

// clang-format off
#define DEFINE_PROPS(...) EXPAND(GET_MACRO(__VA_ARGS__, DEFINE_PROP10, DEFINE_PROP9, DEFINE_PROP8, DEFINE_PROP7, DEFINE_PROP6, DEFINE_PROP5, DEFINE_PROP4, DEFINE_PROP3, DEFINE_PROP2, DEFINE_PROP1)(__VA_ARGS__))

#define DEFINE_PROP1(v1) DEFINE_PROP(0, v1)
#define DEFINE_PROP2(v1, v2) DEFINE_PROP1(v1) DEFINE_PROP(1, v2)
#define DEFINE_PROP3(v1, v2, v3) DEFINE_PROP2(v1, v2) DEFINE_PROP(2, v3)
#define DEFINE_PROP4(v1, v2, v3, v4) DEFINE_PROP3(v1, v2, v3) DEFINE_PROP(3, v4)
#define DEFINE_PROP5(v1, v2, v3, v4, v5) DEFINE_PROP4(v1, v2, v3, v4) DEFINE_PROP(4, v5)
#define DEFINE_PROP6(v1, v2, v3, v4, v5, v6) DEFINE_PROP5(v1, v2, v3, v4, v5) DEFINE_PROP(5, v6)
#define DEFINE_PROP7(v1, v2, v3, v4, v5, v6, v7) DEFINE_PROP6(v1, v2, v3, v4, v5, v6) DEFINE_PROP(6, v7)
#define DEFINE_PROP8(v1, v2, v3, v4, v5, v6, v7, v8) DEFINE_PROP7(v1, v2, v3, v4, v5, v6, v7) DEFINE_PROP(7, v8)
#define DEFINE_PROP9(v1, v2, v3, v4, v5, v6, v7, v8, v9) DEFINE_PROP8(v1, v2, v3, v4, v5, v6, v7, v8) DEFINE_PROP(8, v9)
#define DEFINE_PROP10(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10) DEFINE_PROP9(v1, v2, v3, v4, v5, v6, v7, v8, v9) DEFINE_PROP(9, v10)
// clang-format on

// const arg1Type& arg1, const arg2Type& arg2, ...
#define DEFINE_ARG(prop) const decltype(prop) &a##prop,
#define DEFINE_ARGS(...) EXPAND(PASTE(DEFINE_ARG, __VA_ARGS__))

// arg1(aarg1), arg2(aarg2), ...
#define DEFINE_ARG_INIT(prop) prop(a##prop),
#define DEFINE_ARGS_INIT(...) EXPAND(PASTE(DEFINE_ARG_INIT, __VA_ARGS__))

#define DEFINE_MODEL_CONSTRUCTORS(className, ...)                                                                      \
  public:                                                                                                              \
    className(QObject *aParent = {}) : QObject(aParent)                                                                \
    {                                                                                                                  \
    }                                                                                                                  \
                                                                                                                       \
    className(DEFINE_ARGS(__VA_ARGS__) QObject *aParent = {}) : DEFINE_ARGS_INIT(__VA_ARGS__) QObject(aParent)         \
    {                                                                                                                  \
    }                                                                                                                  \
                                                                                                                       \
    className(const className &a##className) : QObject(a##className.parent())                                          \
    {                                                                                                                  \
        *this = a##className;                                                                                          \
    }                                                                                                                  \
                                                                                                                       \
    className(className &&a##className) noexcept : QObject(a##className.parent())                                      \
    {                                                                                                                  \
        *this = std::move(a##className);                                                                               \
    }

// arg1 = aarg1; arg2 = aarg2; ...
#define DEFINE_ARG_ASSIGN(prop) prop = aObject.prop;
#define DEFINE_ARGS_ASSIGN(...) EXPAND(PASTE(DEFINE_ARG_ASSIGN, __VA_ARGS__))

// arg1 = std::move(aarg1); arg2 = std::move(aarg2); ...
#define DEFINE_ARG_ASSIGN_MOVE(prop) Utility::Move(prop, aObject.prop);
#define DEFINE_ARGS_ASSIGN_MOVE(...) EXPAND(PASTE(DEFINE_ARG_ASSIGN_MOVE, __VA_ARGS__))

#define DEFINE_MODEL_OPERATORS_ASSIGN(className, ...)                                                                  \
  public:                                                                                                              \
    decltype(auto) operator=(const className & aObject)                                                                \
    {                                                                                                                  \
        DEFINE_ARGS_ASSIGN(__VA_ARGS__);                                                                               \
        return *this;                                                                                                  \
    }                                                                                                                  \
                                                                                                                       \
    decltype(auto) operator=(className && aObject) noexcept                                                            \
    {                                                                                                                  \
        DEFINE_ARGS_ASSIGN_MOVE(__VA_ARGS__);                                                                          \
        return *this;                                                                                                  \
    }                                                                                                                  \
                                                                                                                       \
    auto operator<=>(const className &) const = default;

#define DEFINE_MODEL(className, ...)                                                                                   \
    DEFINE_PROPS(__VA_ARGS__);                                                                                         \
                                                                                                                       \
    DEFINE_MODEL_FR(__VA_ARGS__);                                                                                      \
    DEFINE_MODEL_TR(__VA_ARGS__);                                                                                      \
                                                                                                                       \
    DEFINE_MODEL_OPERATORS_ASSIGN(className, __VA_ARGS__);                                                             \
                                                                                                                       \
    DEFINE_MODEL_CONSTRUCTORS(className, __VA_ARGS__);

namespace Model
{
template <typename... Types> class IModel
{
  public:
    using props = std::tuple<Types...>;

    virtual void FromRecord(const QSqlRecord &aRecord) = 0;
    virtual QSqlRecord ToRecord() const = 0;
};
} // namespace Model

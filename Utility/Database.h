#pragma once

#include <QtSql/qsqldatabase.h>
#include <QtSql/qsqlrelationaltablemodel.h>

class Database : public QObject
{
    Q_OBJECT;

  public:
    Database(QObject *aParent);

    template <typename Model> decltype(auto) Insert(const Model &aModel)
    {
        constexpr auto propsCount = std::tuple_size_v<typename Model::props>;
        static_assert(
            /*std::derived_from<Model, ::Model::IModel<props...>> &&*/ propsCount,
            "Model must be derived from IModel and have at least one prop.");

        // get table name
        const QString modelNameFull(typeid(Model).name());
        const auto modelName = modelNameFull.mid(modelNameFull.lastIndexOf("::") + 2).toLower();

        QSqlRelationalTableModel relationalTableModel(this, mDatabase);
        relationalTableModel.setTable(modelName);
        relationalTableModel.setEditStrategy(QSqlRelationalTableModel::EditStrategy::OnManualSubmit);
        Q_ASSERT_X(relationalTableModel.insertRecord(-1, aModel.ToRecord()), "function",
                   relationalTableModel.lastError().text().toLatin1().constData());
        relationalTableModel.submitAll();

        return *this;
    }

    // TODO: make it look for the actual model property not the id from it
    template <typename Model> QVector<Model> SelectAll()
    {
        static_assert(
            /*std::derived_from<Model, ::Model::IModel<props...>> &&*/ std::tuple_size_v<typename Model::props>,
            "Model must be derived from IModel and have at least one prop.");

        // get table name
        const QString modelNameFull(typeid(Model).name());
        const auto modelName = modelNameFull.mid(modelNameFull.lastIndexOf("::") + 2).toLower();

        QSqlTableModel tableModel(this, mDatabase);
        tableModel.setTable(modelName);
        Q_ASSERT_X(tableModel.select(), "function", tableModel.lastError().text().toLatin1().constData());

        QVector<Model> models{};
        for (int i = 0; i < tableModel.rowCount(); i++)
        {
            Model model{};
            model.FromRecord(tableModel.record(i));
            models.push_back(std::move(model));
        }

        return models;
    }

  private:
    QSqlDatabase mDatabase;

    void Initialize();
};

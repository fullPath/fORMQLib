#ifndef MODELBASE_H
#define MODELBASE_H

#include <QVector>
#include <QString>
#include <QMap>

#include "fORMQLib_global.h"
#include "form_exceptions.h"

namespace fORM
{

class Attribute;

class FORMQLIBSHARED_EXPORT ModelBase
{
    friend class fORM::Attribute;

public:
    virtual ~ModelBase();
    QString table() const;

protected:
    ModelBase(QString const& name, QString const& table);
    void registerType(QString const& type);

private:
    void registerAttribute(fORM::Attribute* attr) throw(fORM::AttributeExistsException);

private:
    static QMap<QString, QString> sm_models;

private:
    QVector<fORM::Attribute*> m_primaries;
    QMap<QString, fORM::Attribute*> m_attributes;

    QString m_name;
    QString m_table;
};

}

#endif // MODELBASE_H

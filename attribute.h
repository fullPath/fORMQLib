#ifndef FORMQLIB_ATTRIBUTE_H
#define FORMQLIB_ATTRIBUTE_H

#include <QVariant>
#include <QString>
#include <QtGlobal>

#include "fORMQLib_global.h"
#include "modelbase.h"

namespace fORM
{

enum AttributeFlag {
    NO_FLAGS    = 0,
    PRIMARY_KEY = 1,
    UNIQUE      = 2,
    NOT_NULL    = 4,
    CONST       = 8,
    SERIAL      = 16
};

typedef quint8 AttributeFlags;

class FORMQLIBSHARED_EXPORT Attribute
{
    friend class fORM::ModelBase;

protected:
    Attribute(fORM::ModelBase* parent, QString const& name, fORM::AttributeFlags flags = fORM::NO_FLAGS);
    Attribute(fORM::ModelBase* parent, QString const& name, QVariant const& value, fORM::AttributeFlags flags = fORM::NO_FLAGS);

public:
    virtual ~Attribute();

    QString name() const;

    bool isPrimaryKey() const;
    bool isUnique() const;
    bool isNotNull() const;
    bool isConst() const;
    bool isSerial() const;

    bool isNull() const;

protected:
    bool setValue(QVariant const& value);
    QVariant value() const;

private:
    void registerAttribute();

private:
    fORM::ModelBase* m_parent;
    QString m_name;
    QVariant m_value;
    fORM::AttributeFlags m_flags;
};

}

#endif // FORMQLIB_ATTRIBUTE_H

#include <iostream>
#include "attribute.h"

namespace fORM
{

Attribute::Attribute(fORM::ModelBase* parent, QString const& name, fORM::AttributeFlags flags)
:m_parent(parent),m_name(name),m_flags(flags)
{
    registerAttribute();
}

Attribute::Attribute(fORM::ModelBase* parent, QString const& name, QVariant const& value, fORM::AttributeFlags flags)
:m_parent(parent),m_name(name),m_value(value),m_flags(flags)
{
    registerAttribute();
}

void Attribute::registerAttribute()
{
    if(!m_parent)
        throw InvalidModelAttributeException(m_name.toStdString());
    m_parent->registerAttribute(this);
}

Attribute::~Attribute()
{
}

QString Attribute::name() const
{
    return m_name;
}

bool Attribute::isPrimaryKey() const
{
    return (m_flags & fORM::PRIMARY_KEY);
}

bool Attribute::isUnique() const
{
    return (m_flags & fORM::UNIQUE);
}

bool Attribute::isNotNull() const
{
    return (m_flags & fORM::NOT_NULL);
}

bool Attribute::isConst() const
{
    return (m_flags & fORM::CONST);
}

bool Attribute::isSerial() const
{
    return (m_flags & fORM::SERIAL);
}

bool Attribute::setValue(QVariant const& value)
{
    if(isSerial())
        throw IllegalValueChangeException(m_parent->m_name.toStdString(),m_name.toStdString(),"SERIAL");
    else if(isConst())
        throw IllegalValueChangeException(m_parent->m_name.toStdString(),m_name.toStdString(),"CONST");

    m_value = value;
    return false;
}

QVariant Attribute::value() const
{
    return m_value;
}

bool Attribute::isNull() const
{
    return m_value.isNull();
}

}

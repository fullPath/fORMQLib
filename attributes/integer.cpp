#include <iostream>
#include "integer.h"

namespace fORM
{

Integer::Integer(fORM::ModelBase* parent, QString const& name, AttributeFlags flags)
:fORM::Attribute(parent,name,QVariant::Int,flags)
{
}

Integer::~Integer()
{
}

Integer& Integer::operator=(qint32 const& other)
{
    setValue(other);
    return *this;
}

Integer& Integer::operator=(Integer const& other)
{
    setValue(static_cast<qint32>(other));
    return *this;
}

bool Integer::operator==(qint32 const& other)
{
    return value() == other;
}

bool Integer::operator!=(qint32 const& other)
{
    return value() == other;
}

Integer::operator qint32() const
{
    return Attribute::value().toInt();
}

qint32 Integer::value()
{
    return Attribute::value().toInt();
}

Integer& Integer::operator++()
{
    setValue(value()+1);
    return *this;
}

Integer& Integer::operator--()
{
    setValue(value()-1);
    return *this;
}

//Integer Integer::operator++(qint32);
//Integer Integer::operator--(qint32);

}

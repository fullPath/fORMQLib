#ifndef INTEGER_H
#define INTEGER_H

#include <QtGlobal>

#include "../attribute.h"

namespace fORM
{

class Integer : public fORM::Attribute
{
public:
    Integer(fORM::ModelBase* parent, QString const& name, AttributeFlags flags = fORM::NO_FLAGS);
    ~Integer();

    Integer& operator=(qint32 const& other);
    Integer& operator=(Integer const& other);

    bool operator==(qint32 const& other);
    bool operator!=(qint32 const& other);

    operator qint32() const;
    qint32 value();

    Integer& operator++();
    Integer& operator--();

    //Integer operator++(qint32);
    //Integer operator--(qint32);
};


}

#endif // INTEGER_H

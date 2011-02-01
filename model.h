/*

 fORMQLib - A Qt-based C++ Object-Relational-Mapping Library
 ====================================================================

    File        : model.h
    Author      : Tony Dietrich (fullPath)
    Created at  : 2011-01-31
    Description : fORM::Model class is base for ORM-Models

 */

#ifndef FORMQLIB_MODEL_H
#define FORMQLIB_MODEL_H

#include <typeinfo>

#include "fORMQLib_global.h"
#include "modelbase.h"

namespace fORM
{

template<class modeltype>
class FORMQLIBSHARED_EXPORT Model : public fORM::ModelBase
{
public:
    virtual ~Model();

protected:
    Model(modeltype* model, QString const& name, QString const& table);

private:
    modeltype* m_model;
};

template<class modeltype>
Model<modeltype>::Model(modeltype* model, QString const& name, QString const& table)
:fORM::ModelBase(name,table),m_model(model)
{
    if(!m_model)
        throw InvalidModelException(name.toStdString());
    registerType(typeid(*m_model).name());
}

template<class modeltype>
Model<modeltype>::~Model()
{
}

}

#endif // FORMQLIB_MODEL_H

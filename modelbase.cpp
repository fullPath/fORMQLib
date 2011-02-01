#include "modelbase.h"
#include "attribute.h"

namespace fORM
{

QMap<QString, QString> ModelBase::sm_models = QMap<QString,QString>();

ModelBase::ModelBase(QString const& name, QString const& table)
:m_name(name),m_table(table)
{
}

ModelBase::~ModelBase()
{
}

void ModelBase::registerType(QString const& type)
{
    if(ModelBase::sm_models.contains(m_name) && ModelBase::sm_models[m_name] != type)
        throw fORM::ModelExistsException(m_name.toStdString());
    ModelBase::sm_models[m_name] = type;
}

void ModelBase::registerAttribute(fORM::Attribute* attr) throw(fORM::AttributeExistsException)
{
    if(m_attributes.contains(attr->name()) && m_attributes[attr->name()] != attr)
        throw fORM::AttributeExistsException();
    m_attributes[attr->name()] = attr;

    if(attr->isPrimaryKey())
        m_primaries.push_back(attr);
}

QString ModelBase::table() const
{
    return m_table;
}

}

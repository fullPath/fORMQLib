#ifndef FORMQLIB_FORM_EXCEPTIONS_H
#define FORMQLIB_FORM_EXCEPTIONS_H

#include <string>
#include <stdexcept>

namespace fORM
{

class AttributeExistsException : public std::invalid_argument
{
public:
    AttributeExistsException()
    :std::invalid_argument("There is still an attribute with this name!")
    {
    }
};

class InvalidModelAttributeException : public std::invalid_argument
{
public:
    InvalidModelAttributeException(std::string name)
    :std::invalid_argument("The model reference of the attribute <<"+name+">> is invalid!")
    {
    }
};

class InvalidModelException : public std::invalid_argument
{
public:
    InvalidModelException(std::string name)
    :std::invalid_argument("The model reference of the model <<"+name+">> is invalid!")
    {
    }
};

class ModelExistsException : public std::runtime_error
{
public:
    ModelExistsException(std::string const& name)
    :std::runtime_error("The model <<"+name+">> still exists!")
    {
    }
};

class IllegalValueChangeException : public std::runtime_error
{
public:
    IllegalValueChangeException(std::string const& model, std::string const& name, std::string const& reason)
    :std::runtime_error("Attribute <<"+name+">> of Model <<"+model+">> can't be changed, "+reason+"!")
    {
    }
};

}

#endif // FORM_EXCEPTIONS_H

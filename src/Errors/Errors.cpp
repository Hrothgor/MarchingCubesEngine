/*
** EPITECH PROJECT, 2021
** Errors
** File description:
** Errors
*/

#include "Errors.hpp"

IS::Errors::Errors(const std::string &message) noexcept : _what(message)
{
}

IS::Errors::~Errors() noexcept
{
}

const char *IS::Errors::what(void) const noexcept
{
    return _what.c_str();
}
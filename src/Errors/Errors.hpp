/*
** EPITECH PROJECT, 2021
** Errors
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <exception>

namespace IS {
    class Errors : public std::exception {
    public:
        explicit Errors(std::string const &message = "") noexcept;
        virtual ~Errors() noexcept;

        const char *what() const noexcept;

    private:
        std::string _what;
    };
}

#endif /* !ERRORS_HPP_ */

#pragma once

#include <string>

namespace Term
{

namespace Platform
{
// Returns true if a character is read, otherwise immediately returns false
// This can't be made inline
bool read_raw(char* s);

char read_raw_stdin();
}  // namespace Platform

// Waits for a key press, translates escape codes
// if Term:Terminal is not enabling the keyboard it'll loop for infinity
std::int32_t read_key();

// If there was a key press, returns the translated key from escape codes,
// otherwise returns 0. If the escape code is not supported it returns a
// negative number.
// if Term::Terminal is not enabling the keyboard it'll always return 0
std::int32_t read_key0();

// returns the stdin as a string
// waits until the EOT signal is send
// if Term::Terminal is not enabling the keyboard this function will wait until
// the user presses CTRL+D (which sends the EOT signal)
std::string read_stdin();

}  // namespace Term

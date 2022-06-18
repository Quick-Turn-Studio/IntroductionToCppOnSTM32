#ifndef SRC_OUTPUTSTREAM_H_
#define SRC_OUTPUTSTREAM_H_

#include <string>

namespace stream
{

class OutputStream
{
	/**
	 * @brief Appends string to stream buffer
	 * @return reference to itself to allow stream << value << value; syntax
	 */
	OutputStream& operator << (const std::string&);

	/**
	 * @brief Parse integer to string and appends it to stream buffer
	 * @return reference to itself to allow stream << value << value; syntax
	 */
	OutputStream& operator << (int value);

	/**
	 * @brief sends buffer content to destination and clear buffer
	 */
	void flush();

	/**
	 * @brief Parse float to string and appends it to stream buffer
	 * @return reference to itself to allow stream << value << value; syntax
	 */
	OutputStream& operator << (float value);
};

}

#endif /* SRC_OUTPUTSTREAM_H_ */

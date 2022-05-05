#ifndef JSONTYPE_H
#define JSONTYPE_H

#include <string>

class JsonType {
protected:
    std::string m_name;
    std::string m_contents;
public:
    JsonType(std::string name, std::string contents) : m_name{ name }, m_contents{ contents } {}

    virtual ~JsonType(){}

    /**
     * @brief Get the Name object
     *
     * @return std::string
     */
    virtual std::string getName() {
        return this->m_name;
    }

    /**
     * @brief Get the Contents object
     * 
     * @return std::string 
     */
    virtual std::string getContents() {
        return this->m_contents;
    }

    /**
     * @brief Checking if the string given is in the currect type
     * 
     * @param str - the string given
     * @return true - if it is the correct type
     * @return false - otherwise
     */
    static bool isType(std::string str);

    /**
     * @brief Get the index of the end of the object given a string
     *        that might have more than the type itself, but does
     *        start with it.
     *        * Note - it counts the items included in the current type,
     *        *        therefore, it will be more of a 'count' of the chars
     *        *        included than the index (so the index + 1)
     * 
     * @param str - the string to check
     * @return int - the end index of the type
     */
    static int getEnd(std::string str);

    /**
     * @brief checks if the string given starts with the relevant type
     * 
     * @param str - the string
     * @return true - if it does
     * @return false - otherwise
     */
    static bool isPartialType(std::string str);
};

#endif // JSONTYPE_H
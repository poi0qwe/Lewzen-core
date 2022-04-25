#ifndef __LZ_ATTR__URL__
#define __LZ_ATTR__URL__
#include <functional>
#include <string>
#include <memory>
#include <iostream>
#include "../../utils.h"

namespace Lewzen {
    /**
    * A Uniform Resource Locator.
    * A URL is a sequence of Unicode characters, building an address to an internal or external resource.
    * Before SVG 2, the more limited IRI content type was used instead, because the URL specification was not standardized before.
    */
    class AttrURL {
    private:
        std::function<const std::string()> _commit;
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
    public:
        /**
        * Empty constructor of URL.
        */
        AttrURL();
        /**
        * Constructor of URL, with binding with getter and setter.
        *
        * @param getter getter function
        * @param setter setter function
        */
        AttrURL(std::function<const std::string()> getter, std::function<void(const std::string &)> setter);

        /**
        * Set getter of URL this attribute.
        * @param getter getter function
        */
        void set_getter(std::function<const std::string()> getter);
        /**
        * Set setter of URL this attribute.
        *
        * @param setter setter function
        */
        void set_setter(std::function<void(const std::string &)> setter);

        /**
        * Return attribute string, from getter.
        *
        * @return attribute string.
        */
        const std::string get() const;
        /**
        * Return attribute string to be committed.
        *
        * @return attribute string.
        */
        const std::string get_commit() const;
        /**
        * Commit binding or value by setter.
        */
        void commit();

    public:
        /**
        * Set attribute from value, conver to string. This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        void set(const T &attr);
        /**
        * Set attribute from value, conver to string.  This will break value binding with bind_func and bind_ptr. (This function will reset commit)
        *
        * @param attr attribute.
        */
        template <typename T>
        AttrURL &operator=(const T &attr);

        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        void bind(std::function<const T()>bind_func);
        /**
        * Bind attribute to a function. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_func binding function.
        */
        template <typename T>
        AttrURL &operator[](std::function<const T()>bind_func);
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        void bind(const std::weak_ptr<T> &bind_ptr);
        /**
        * Bind attribute to a pointer. This will break value binding with bind_ptr. (This function will reset commit)
        *
        * @param bind_ptr binding pointer.
        */
        template <typename T>
        AttrURL &operator[](const std::weak_ptr<T> &bind_ptr);

    private:
        std::string _con_val_string;
        const std::string _from_con_val_string();
        std::function<const std::string()> _bind_func_string;
        const std::string _from_bind_func_string();
        std::weak_ptr<std::string> _bind_ptr_string;
        const std::string _from_bind_ptr_string();
        /**
        * Convert string to string of AttrURL.
        */
        static std::string string_to_string(const std::string &attr);
    public:
        /**
        * Set attribute from string, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr string attribute.
        */
        void set(const std::string &attr);
        /**
        * Set attribute from string, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr string attribute.
        */
        AttrURL &operator=(const std::string &attr);
        /**
        * Set attribute from string, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr string attribute.
        */
        void set(const char * attr);
        /**
        * Set attribute from string, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr string attribute.
        */
        AttrURL &operator=(const char * attr);
        /**
        * Bind attribute to a string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::string()> bind_func);
        /**
        * Bind attribute to a string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrURL &operator[](std::function<const std::string()> bind_func);
        /**
        * Bind attribute to a string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::string> &bind_ptr);
        /**
        * Bind attribute to a string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrURL &operator[](const std::weak_ptr<std::string> &bind_ptr);

    /// Callback
    private:
        std::function<void(const std::string &)> _on_assign = [](const std::string &last){};
        std::function<void()> _on_bind_func = [](){};
        std::function<void()> _on_bind_ptr = [](){};
    public:
        /**
        * Set callback for assignment operation.
        *
        * @param on_assign callback function.
        */
        void callback_assign(std::function<void(const std::string &)> on_assign);
        /**
        * Remove callback for assignment operation.
        */
        void callback_assign();
        /**
        * Set callback for binding function operation.
        *
        * @param on_bind_func callback function.
        */
        void callback_bind_func(std::function<void()> on_bind_func);
        /**
        * Remove callback for binding function operation.
        */
        void callback_bind_func();
        /**
        * Set callback for binding pointer operation.
        *
        * @param on_bind_ptr callback function.
        */
        void callback_bind_ptr(std::function<void()> on_bind_ptr);
        /**
        * Remove callback for binding pointer operation.
        */
        void callback_bind_ptr();
    };
}
#include "attr_URL.cpp"
#endif

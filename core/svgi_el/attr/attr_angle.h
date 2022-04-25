#ifndef __LZ_ATTR_ANGLE__
#define __LZ_ATTR_ANGLE__
#include <functional>
#include <string>
#include <memory>
#include <iostream>
#include <regex>
#include "../../utils.h"

namespace Lewzen {
    /**
    * Angles are specified in one of two ways. When used in the value of a property in a stylesheet, an <angle> is defined as follows:
    * ```
    * angle ::= number (~"deg" | ~"grad" | ~"rad")?
    * ```
    * where deg indicates degrees, grad indicates grads and rad indicates radians.
    * For properties defined in CSS2, an angle unit identifier must be provided. For angle values in SVG-specific properties and their corresponding presentation attributes, the angle unit identifier is optional. If not provided, the angle value is assumed to be in degrees. In presentation attributes for all properties, whether defined in SVG1.1 or in CSS2, the angle identifier, if specified, must be in lower case.
    * When angles are used in an SVG attribute, <angle> is instead defined as follows:
    * ```
    * angle ::= number ("deg" | "grad" | "rad")?
    * ```
    * The unit identifiers in such <angle> values must be in lower case.
    * In the SVG DOM, <angle> values are represented using SVGAngle or SVGAnimatedAngle objects.
    */
    class AttrAngle {
    private:
        std::function<const std::string()> _commit;
        std::function<const std::string()> _getter;
        std::function<void(const std::string &)> _setter;
    public:
        /**
        * Empty constructor of Angle.
        */
        AttrAngle();
        /**
        * Constructor of Angle, with binding with getter and setter.
        *
        * @param getter getter function
        * @param setter setter function
        */
        AttrAngle(std::function<const std::string()> getter, std::function<void(const std::string &)> setter);

        /**
        * Set getter of Angle this attribute.
        * @param getter getter function
        */
        void set_getter(std::function<const std::string()> getter);
        /**
        * Set setter of Angle this attribute.
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
        AttrAngle &operator=(const T &attr);

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
        AttrAngle &operator[](std::function<const T()>bind_func);
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
        AttrAngle &operator[](const std::weak_ptr<T> &bind_ptr);

    private:
        int _con_val_integer;
        const std::string _from_con_val_integer();
        std::function<const int()> _bind_func_integer;
        const std::string _from_bind_func_integer();
        std::weak_ptr<int> _bind_ptr_integer;
        const std::string _from_bind_ptr_integer();
        /**
        * Convert integer to string of AttrAngle.
        */
        static std::string integer_to_string(const int &attr);
    public:
        /**
        * Set attribute from integer, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr integer attribute.
        */
        void set(const int &attr);
        /**
        * Set attribute from integer, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr integer attribute.
        */
        AttrAngle &operator=(const int &attr);
        /**
        * Bind attribute to a integer function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const int()> bind_func);
        /**
        * Bind attribute to a integer function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrAngle &operator[](std::function<const int()> bind_func);
        /**
        * Bind attribute to a integer pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<int> &bind_ptr);
        /**
        * Bind attribute to a integer pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrAngle &operator[](const std::weak_ptr<int> &bind_ptr);

    private:
        float _con_val_float;
        const std::string _from_con_val_float();
        std::function<const float()> _bind_func_float;
        const std::string _from_bind_func_float();
        std::weak_ptr<float> _bind_ptr_float;
        const std::string _from_bind_ptr_float();
        /**
        * Convert float to string of AttrAngle.
        */
        static std::string float_to_string(const float &attr);
    public:
        /**
        * Set attribute from float, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr float attribute.
        */
        void set(const float &attr);
        /**
        * Set attribute from float, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr float attribute.
        */
        AttrAngle &operator=(const float &attr);
        /**
        * Bind attribute to a float function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const float()> bind_func);
        /**
        * Bind attribute to a float function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrAngle &operator[](std::function<const float()> bind_func);
        /**
        * Bind attribute to a float pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<float> &bind_ptr);
        /**
        * Bind attribute to a float pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrAngle &operator[](const std::weak_ptr<float> &bind_ptr);

    private:
        double _con_val_double;
        const std::string _from_con_val_double();
        std::function<const double()> _bind_func_double;
        const std::string _from_bind_func_double();
        std::weak_ptr<double> _bind_ptr_double;
        const std::string _from_bind_ptr_double();
        /**
        * Convert double to string of AttrAngle.
        */
        static std::string double_to_string(const double &attr);
    public:
        /**
        * Set attribute from double, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr double attribute.
        */
        void set(const double &attr);
        /**
        * Set attribute from double, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr double attribute.
        */
        AttrAngle &operator=(const double &attr);
        /**
        * Bind attribute to a double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const double()> bind_func);
        /**
        * Bind attribute to a double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrAngle &operator[](std::function<const double()> bind_func);
        /**
        * Bind attribute to a double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<double> &bind_ptr);
        /**
        * Bind attribute to a double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrAngle &operator[](const std::weak_ptr<double> &bind_ptr);

    private:
        long _con_val_long;
        const std::string _from_con_val_long();
        std::function<const long()> _bind_func_long;
        const std::string _from_bind_func_long();
        std::weak_ptr<long> _bind_ptr_long;
        const std::string _from_bind_ptr_long();
        /**
        * Convert long to string of AttrAngle.
        */
        static std::string long_to_string(const long &attr);
    public:
        /**
        * Set attribute from long, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long attribute.
        */
        void set(const long &attr);
        /**
        * Set attribute from long, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long attribute.
        */
        AttrAngle &operator=(const long &attr);
        /**
        * Bind attribute to a long function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const long()> bind_func);
        /**
        * Bind attribute to a long function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrAngle &operator[](std::function<const long()> bind_func);
        /**
        * Bind attribute to a long pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<long> &bind_ptr);
        /**
        * Bind attribute to a long pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrAngle &operator[](const std::weak_ptr<long> &bind_ptr);

    private:
        long long int _con_val_long_integer;
        const std::string _from_con_val_long_integer();
        std::function<const long long int()> _bind_func_long_integer;
        const std::string _from_bind_func_long_integer();
        std::weak_ptr<long long int> _bind_ptr_long_integer;
        const std::string _from_bind_ptr_long_integer();
        /**
        * Convert long integer to string of AttrAngle.
        */
        static std::string long_integer_to_string(const long long int &attr);
    public:
        /**
        * Set attribute from long integer, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long integer attribute.
        */
        void set(const long long int &attr);
        /**
        * Set attribute from long integer, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long integer attribute.
        */
        AttrAngle &operator=(const long long int &attr);
        /**
        * Bind attribute to a long integer function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const long long int()> bind_func);
        /**
        * Bind attribute to a long integer function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrAngle &operator[](std::function<const long long int()> bind_func);
        /**
        * Bind attribute to a long integer pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<long long int> &bind_ptr);
        /**
        * Bind attribute to a long integer pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrAngle &operator[](const std::weak_ptr<long long int> &bind_ptr);

    private:
        long double _con_val_long_double;
        const std::string _from_con_val_long_double();
        std::function<const long double()> _bind_func_long_double;
        const std::string _from_bind_func_long_double();
        std::weak_ptr<long double> _bind_ptr_long_double;
        const std::string _from_bind_ptr_long_double();
        /**
        * Convert long double to string of AttrAngle.
        */
        static std::string long_double_to_string(const long double &attr);
    public:
        /**
        * Set attribute from long double, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long double attribute.
        */
        void set(const long double &attr);
        /**
        * Set attribute from long double, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr long double attribute.
        */
        AttrAngle &operator=(const long double &attr);
        /**
        * Bind attribute to a long double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const long double()> bind_func);
        /**
        * Bind attribute to a long double function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrAngle &operator[](std::function<const long double()> bind_func);
        /**
        * Bind attribute to a long double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<long double> &bind_ptr);
        /**
        * Bind attribute to a long double pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrAngle &operator[](const std::weak_ptr<long double> &bind_ptr);

    private:
        std::string _con_val_legal_string;
        const std::string _from_con_val_legal_string();
        std::function<const std::string()> _bind_func_legal_string;
        const std::string _from_bind_func_legal_string();
        std::weak_ptr<std::string> _bind_ptr_legal_string;
        const std::string _from_bind_ptr_legal_string();
        /**
        * Convert legal string to string of AttrAngle.
        */
        static std::string legal_string_to_string(const std::string &attr);
    public:
        /**
        * Set attribute from legal string, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        void set(const std::string &attr);
        /**
        * Set attribute from legal string, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        AttrAngle &operator=(const std::string &attr);
        /**
        * Set attribute from legal string, conver to string. This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        void set(const char * attr);
        /**
        * Set attribute from legal string, conver to string.  This will break value binding with bind_func and bind_ptr.
        *
        * @param attr legal string attribute.
        */
        AttrAngle &operator=(const char * attr);
        /**
        * Bind attribute to a legal string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        void bind(std::function<const std::string()> bind_func);
        /**
        * Bind attribute to a legal string function. This will break value binding with bind_ptr.
        *
        * @param bind_func binding function.
        */
        AttrAngle &operator[](std::function<const std::string()> bind_func);
        /**
        * Bind attribute to a legal string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        void bind(const std::weak_ptr<std::string> &bind_ptr);
        /**
        * Bind attribute to a legal string pointer. This will break value binding with bind_func.
        *
        * @param bind_ptr binding pointer.
        */
        AttrAngle &operator[](const std::weak_ptr<std::string> &bind_ptr);
        /**
        * Check if a string is legal as a Angle attribute.
        */
        static bool is_legal_string(const std::string &attr);

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
#include "attr_angle.cpp"
#endif

#ifndef __LZ_SVG_LINE__
#define __LZ_SVG_LINE__
#include <string>
#include <sstream>
#include "../svg_el.h"

namespace Lewzen {
    /**
    * The <line> element is an SVG basic shape used to create a line connecting two points.
    */
    class SVGLine: public SVGElement {
    public:
        /**
        * Constructor of line.
        */
        SVGLine();
        /**
        * Deep copy of line.
        */
        SVGLine(const SVGLine &element);

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        const std::string get_tag() const;

        /// Line
    private:
        std::string _xQ;
    private:
        std::string _xR;
    private:
        std::string _yQ;
    private:
        std::string _yR;
    private:
        std::string _path_length;
    public:
        /**
        * Defines the x-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @return the x1
        */
        const std::string get_xQ() const;
        /**
        * Defines the x-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @param  the x1
        */
        void set_xQ(const std::string &xQ);
        /**
        * Defines the x-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @return the x2
        */
        const std::string get_xR() const;
        /**
        * Defines the x-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @param  the x2
        */
        void set_xR(const std::string &xR);
        /**
        * Defines the y-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @return the y1
        */
        const std::string get_yQ() const;
        /**
        * Defines the y-axis coordinate of the line starting point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @param  the y1
        */
        void set_yQ(const std::string &yQ);
        /**
        * Defines the y-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @return the y2
        */
        const std::string get_yR() const;
        /**
        * Defines the y-axis coordinate of the line ending point. 
        * Value type: <length>|<percentage>|<number> ; Default value: 0; Animatable: yes
        *
        * @param  the y2
        */
        void set_yR(const std::string &yR);
        /**
        * Defines the total path length in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @return the pathLength
        */
        const std::string get_path_length() const;
        /**
        * Defines the total path length in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        *
        * @param  the pathLength
        */
        void set_path_length(const std::string &path_length);

        /// Attributes
    protected:
        /**
        * Get attribute string of this SVG element.
        *
        * @return outer SVG.
        */
        const std::string get_attributes() const;

        /// Operators
    public:
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGElement
        */
        std::shared_ptr<SVGElement> clone() const;
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGElement
        */
        const std::string operator-(const SVGElement &element) const;
    };
}
#endif
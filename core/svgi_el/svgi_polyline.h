#ifndef __LZ_SVGI_POLYLINE__
#define __LZ_SVGI_POLYLINE__
#include "../svgi_el.h"

namespace Lewzen {
    /**
    * The <polyline> SVG element is an SVG basic shape that creates straight lines connecting several points. Typically a polyline is used to create open shapes as the last point doesn't have to be connected to the first point. For closed shapes see the <polygon> element.
    */
    class SVGIPolyline : public virtual SVGIElement, public virtual SVGPolyline {
    public:
        /**
        * Constructor of circle.
        */
        SVGIPolyline();
    protected:
        virtual void _bind_getter_setter() override;

        /// Tag
    public:
        /**
        * Get tag name of this element.
        *
        * @return tag name.
        */
        virtual const std::string get_tag() const override;

        /// Polyline
    public:
        /**
        * This attribute defines the list of points (pairs of x,y absolute coordinates) required to draw the polygon. 
        * Value type: <list-of-numbers> ; Default value: ""; Animatable: yes
        */
        AttrListOfNumbers Points;
    public:
        /**
        * This attribute lets specify the total length for the path, in user units. 
        * Value type: <number> ; Default value: none; Animatable: yes
        */
        AttrNumber PathLength;
    private:
        std::set<int> bound;
        std::set<int> modified;
        const std::array<std::function<void(const std::string &)>, 2> _attr_on_assign = {
            [this](const std::string &last){
                if (Points.get() == Points.get_commit()) modified.erase(0);
                else modified.insert(0);
                bound.erase(0);
            },
            [this](const std::string &last){
                if (PathLength.get() == PathLength.get_commit()) modified.erase(1);
                else modified.insert(1);
                bound.erase(1);
            },
        };
        const std::array<std::function<void()>, 2> _attr_on_bind = {
            std::bind([this](){
                modified.erase(0);
                bound.insert(0);
            }),
            std::bind([this](){
                modified.erase(1);
                bound.insert(1);
            }),
        };
        const std::array<std::function<const std::string()>, 2> _attr_commit = {
            [this](){
                Points.commit();
                if (Points.get() == STR_NULL) return std::string("reset Points");
                else return std::string("modify Points \"" + Points.get() + "\"");
            },
            [this](){
                PathLength.commit();
                if (PathLength.get() == STR_NULL) return std::string("reset PathLength");
                else return std::string("modify PathLength \"" + PathLength.get() + "\"");
            },
        };

        /// Operators
    public:
        /**
        * Commit all changes and get DOM commands.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string commit() override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGIElement
        */
        virtual std::shared_ptr<SVGElement> clone() const override;
        /**
        * Deep copy this SVG element.
        *
        * @relatesalso SVGIElement
        */
        std::shared_ptr<SVGIPolyline> clone(bool identity) const;
        /**
        * Assigning SVG element by deep copy.
        *
        * @relatesalso SVGIElement
        */
        virtual SVGIPolyline &operator=(const SVGIPolyline &element);
        /**
        * SVG substraction, returning differences.
        *
        * @relatesalso SVGIElement
        */
        virtual const std::string operator-(const SVGElement &element) const override;
    };
}
#endif

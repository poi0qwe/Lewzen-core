#include "svgi_polygon.h"

namespace Lewzen {
    SVGIPolygon::SVGIPolygon(): SVGIElement() {}
    void SVGIPolygon::_bind_getter_setter() {
        std::function<const std::string()> _getter_points = std::bind(&SVGPolygon::get_points, (SVGPolygon *)this);
        std::function<void(const std::string &)> _setter_points = std::bind(&SVGPolygon::set_points, (SVGPolygon *)this, std::placeholders::_1);
        Points.set_getter(_getter_points), Points.set_setter(_setter_points);
        Points.callback_assign(_attr_on_assign[0]), Points.callback_bind_func(_attr_on_bind[0]), Points.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_path_length = std::bind(&SVGPolygon::get_path_length, (SVGPolygon *)this);
        std::function<void(const std::string &)> _setter_path_length = std::bind(&SVGPolygon::set_path_length, (SVGPolygon *)this, std::placeholders::_1);
        PathLength.set_getter(_getter_path_length), PathLength.set_setter(_setter_path_length);
        PathLength.callback_assign(_attr_on_assign[1]), PathLength.callback_bind_func(_attr_on_bind[1]), PathLength.callback_bind_ptr(_attr_on_bind[1]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIPolygon::get_tag() const {
        return "polygon";
    }
    const std::string SVGIPolygon::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) ss << _attr_commit[i]() << std::endl;
        for (auto &i : modified) ss << _attr_commit[i]() << std::endl;
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIPolygon::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        *cloned = static_cast<SVGPolygon>(*this);
        return cloned;
    }
    std::shared_ptr<SVGIPolygon> SVGIPolygon::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIPolygon>();
        *cloned = *this;
        return cloned;
    }
    SVGIPolygon &SVGIPolygon::operator=(const SVGIPolygon &element) {
        SVGPolygon::operator=(static_cast<SVGPolygon>(*this));
        Points = element.Points;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIPolygon::operator-(const SVGElement &element) const {
        return SVGPolygon::operator-(static_cast<SVGPolygon>(*this));
    }
}
#include "svgi_polyline.h"

namespace Lewzen {
    SVGIPolyline::SVGIPolyline(): SVGIElement() {}
    void SVGIPolyline::_bind_getter_setter() {
        std::function<const std::string()> _getter_points = std::bind(&SVGPolyline::get_points, (SVGPolyline *)this);
        std::function<void(const std::string &)> _setter_points = std::bind(&SVGPolyline::set_points, (SVGPolyline *)this, std::placeholders::_1);
        Points.set_getter(_getter_points), Points.set_setter(_setter_points);
        Points.callback_assign(_attr_on_assign[0]), Points.callback_bind_func(_attr_on_bind[0]), Points.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_path_length = std::bind(&SVGPolyline::get_path_length, (SVGPolyline *)this);
        std::function<void(const std::string &)> _setter_path_length = std::bind(&SVGPolyline::set_path_length, (SVGPolyline *)this, std::placeholders::_1);
        PathLength.set_getter(_getter_path_length), PathLength.set_setter(_setter_path_length);
        PathLength.callback_assign(_attr_on_assign[1]), PathLength.callback_bind_func(_attr_on_bind[1]), PathLength.callback_bind_ptr(_attr_on_bind[1]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIPolyline::get_tag() const {
        return "polyline";
    }
    const std::string SVGIPolyline::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) ss << _attr_commit[i]() << std::endl;
        for (auto &i : modified) ss << _attr_commit[i]() << std::endl;
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIPolyline::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        *cloned = static_cast<SVGPolyline>(*this);
        return cloned;
    }
    std::shared_ptr<SVGIPolyline> SVGIPolyline::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIPolyline>();
        *cloned = *this;
        return cloned;
    }
    SVGIPolyline &SVGIPolyline::operator=(const SVGIPolyline &element) {
        SVGPolyline::operator=(static_cast<SVGPolyline>(*this));
        Points = element.Points;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIPolyline::operator-(const SVGElement &element) const {
        return SVGPolyline::operator-(static_cast<SVGPolyline>(*this));
    }
}
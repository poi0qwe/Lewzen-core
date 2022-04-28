#include "svgi_ellipse.h"

namespace Lewzen {
    SVGIEllipse::SVGIEllipse(): SVGIElement() {}
    void SVGIEllipse::_bind_getter_setter() {
        std::function<const std::string()> _getter_cx = std::bind(&SVGEllipse::get_cx, (SVGEllipse *)this);
        std::function<void(const std::string &)> _setter_cx = std::bind(&SVGEllipse::set_cx, (SVGEllipse *)this, std::placeholders::_1);
        Cx.set_getter(_getter_cx), Cx.set_setter(_setter_cx);
        Cx.callback_assign(_attr_on_assign[0]), Cx.callback_bind_func(_attr_on_bind[0]), Cx.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_cy = std::bind(&SVGEllipse::get_cy, (SVGEllipse *)this);
        std::function<void(const std::string &)> _setter_cy = std::bind(&SVGEllipse::set_cy, (SVGEllipse *)this, std::placeholders::_1);
        Cy.set_getter(_getter_cy), Cy.set_setter(_setter_cy);
        Cy.callback_assign(_attr_on_assign[1]), Cy.callback_bind_func(_attr_on_bind[1]), Cy.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_rx = std::bind(&SVGEllipse::get_rx, (SVGEllipse *)this);
        std::function<void(const std::string &)> _setter_rx = std::bind(&SVGEllipse::set_rx, (SVGEllipse *)this, std::placeholders::_1);
        Rx.set_getter(_getter_rx), Rx.set_setter(_setter_rx);
        Rx.callback_assign(_attr_on_assign[2]), Rx.callback_bind_func(_attr_on_bind[2]), Rx.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_ry = std::bind(&SVGEllipse::get_ry, (SVGEllipse *)this);
        std::function<void(const std::string &)> _setter_ry = std::bind(&SVGEllipse::set_ry, (SVGEllipse *)this, std::placeholders::_1);
        Ry.set_getter(_getter_ry), Ry.set_setter(_setter_ry);
        Ry.callback_assign(_attr_on_assign[3]), Ry.callback_bind_func(_attr_on_bind[3]), Ry.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_path_length = std::bind(&SVGEllipse::get_path_length, (SVGEllipse *)this);
        std::function<void(const std::string &)> _setter_path_length = std::bind(&SVGEllipse::set_path_length, (SVGEllipse *)this, std::placeholders::_1);
        PathLength.set_getter(_getter_path_length), PathLength.set_setter(_setter_path_length);
        PathLength.callback_assign(_attr_on_assign[4]), PathLength.callback_bind_func(_attr_on_bind[4]), PathLength.callback_bind_ptr(_attr_on_bind[4]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIEllipse::get_tag() const {
        return "ellipse";
    }
    const std::string SVGIEllipse::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) ss << _attr_commit[i]() << std::endl;
        for (auto &i : modified) ss << _attr_commit[i]() << std::endl;
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIEllipse::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        *cloned = static_cast<SVGEllipse>(*this);
        return cloned;
    }
    std::shared_ptr<SVGIEllipse> SVGIEllipse::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIEllipse>();
        *cloned = *this;
        return cloned;
    }
    SVGIEllipse &SVGIEllipse::operator=(const SVGIEllipse &element) {
        SVGEllipse::operator=(static_cast<SVGEllipse>(*this));
        Cx = element.Cx;
        Cy = element.Cy;
        Rx = element.Rx;
        Ry = element.Ry;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIEllipse::operator-(const SVGElement &element) const {
        return SVGEllipse::operator-(static_cast<SVGEllipse>(*this));
    }
}
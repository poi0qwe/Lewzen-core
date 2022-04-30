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
    const std::string SVGIEllipse::inner_SVG() const {
        return SVGIElement::inner_SVG();
    }
    void SVGIEllipse::set_inner_text(const std::string &text) {
        SVGIElement::set_inner_text(text);
    }
    const std::string SVGIEllipse::get_inner_text() const {
        return SVGIElement::get_inner_text();
    }
    void SVGIEllipse::append(const std::shared_ptr<SVGIElement> &inner_element) {
        SVGIElement::add_inner_element(inner_element);
    }
    void SVGIEllipse::remove(const std::shared_ptr<SVGIElement> &inner_element, bool remove_all) {
        SVGIElement::remove_inner_element(inner_element, remove_all);
    }
    const std::vector<std::shared_ptr<SVGIElement>> SVGIEllipse::get_inner_elements() const {
        return SVGIElement::get_inner_elements();
    }
    void SVGIEllipse::set_inner_elements(const std::vector<std::shared_ptr<SVGIElement>> &inner_elements) {
        SVGIElement::set_inner_elements(inner_elements);
    }
    const std::string SVGIEllipse::outer_SVG() const {
        return SVGIElement::outer_SVG();
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
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIEllipse> SVGIEllipse::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIEllipse>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIEllipse::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIEllipse &SVGIEllipse::operator=(const SVGIEllipse &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Cx = element.Cx;
        Cy = element.Cy;
        Rx = element.Rx;
        Ry = element.Ry;
        PathLength = element.PathLength;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIEllipse::operator-(const SVGElement &element) const {
        return SVGEllipse::operator-(element);
    }
}

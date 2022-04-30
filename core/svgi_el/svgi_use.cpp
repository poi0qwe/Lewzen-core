#include "svgi_use.h"

namespace Lewzen {
    SVGIUse::SVGIUse(): SVGIElement() {}
    void SVGIUse::_bind_getter_setter() {
        std::function<const std::string()> _getter_href = std::bind(&SVGUse::get_href, (SVGUse *)this);
        std::function<void(const std::string &)> _setter_href = std::bind(&SVGUse::set_href, (SVGUse *)this, std::placeholders::_1);
        Href.set_getter(_getter_href), Href.set_setter(_setter_href);
        Href.callback_assign(_attr_on_assign[0]), Href.callback_bind_func(_attr_on_bind[0]), Href.callback_bind_ptr(_attr_on_bind[0]);
        std::function<const std::string()> _getter_x = std::bind(&SVGUse::get_x, (SVGUse *)this);
        std::function<void(const std::string &)> _setter_x = std::bind(&SVGUse::set_x, (SVGUse *)this, std::placeholders::_1);
        X.set_getter(_getter_x), X.set_setter(_setter_x);
        X.callback_assign(_attr_on_assign[1]), X.callback_bind_func(_attr_on_bind[1]), X.callback_bind_ptr(_attr_on_bind[1]);
        std::function<const std::string()> _getter_y = std::bind(&SVGUse::get_y, (SVGUse *)this);
        std::function<void(const std::string &)> _setter_y = std::bind(&SVGUse::set_y, (SVGUse *)this, std::placeholders::_1);
        Y.set_getter(_getter_y), Y.set_setter(_setter_y);
        Y.callback_assign(_attr_on_assign[2]), Y.callback_bind_func(_attr_on_bind[2]), Y.callback_bind_ptr(_attr_on_bind[2]);
        std::function<const std::string()> _getter_width = std::bind(&SVGUse::get_width, (SVGUse *)this);
        std::function<void(const std::string &)> _setter_width = std::bind(&SVGUse::set_width, (SVGUse *)this, std::placeholders::_1);
        Width.set_getter(_getter_width), Width.set_setter(_setter_width);
        Width.callback_assign(_attr_on_assign[3]), Width.callback_bind_func(_attr_on_bind[3]), Width.callback_bind_ptr(_attr_on_bind[3]);
        std::function<const std::string()> _getter_height = std::bind(&SVGUse::get_height, (SVGUse *)this);
        std::function<void(const std::string &)> _setter_height = std::bind(&SVGUse::set_height, (SVGUse *)this, std::placeholders::_1);
        Height.set_getter(_getter_height), Height.set_setter(_setter_height);
        Height.callback_assign(_attr_on_assign[4]), Height.callback_bind_func(_attr_on_bind[4]), Height.callback_bind_ptr(_attr_on_bind[4]);
        SVGIElement::_bind_getter_setter();
    }
    const std::string SVGIUse::get_tag() const {
        return "use";
    }
    const std::string SVGIUse::inner_SVG() const {
        return SVGIElement::inner_SVG();
    }
    void SVGIUse::set_inner_text(const std::string &text) {
        SVGIElement::set_inner_text(text);
    }
    const std::string SVGIUse::get_inner_text() const {
        return SVGIElement::get_inner_text();
    }
    void SVGIUse::append(const std::shared_ptr<SVGIElement> &inner_element) {
        SVGIElement::add_inner_element(inner_element);
    }
    void SVGIUse::remove(const std::shared_ptr<SVGIElement> &inner_element, bool remove_all) {
        SVGIElement::remove_inner_element(inner_element, remove_all);
    }
    const std::vector<std::shared_ptr<SVGIElement>> SVGIUse::get_inner_elements() const {
        return SVGIElement::get_inner_elements();
    }
    void SVGIUse::set_inner_elements(const std::vector<std::shared_ptr<SVGIElement>> &inner_elements) {
        SVGIElement::set_inner_elements(inner_elements);
    }
    const std::string SVGIUse::outer_SVG() const {
        return SVGIElement::outer_SVG();
    }
    const std::string SVGIUse::commit() {
        std::stringstream ss;

        // attribute differ
        for (auto &i : bound) ss << _attr_commit[i]() << std::endl;
        for (auto &i : modified) ss << _attr_commit[i]() << std::endl;
        modified.clear();

        // base class
        ss << SVGIElement::commit();

        return ss.str();
    }
    std::shared_ptr<SVGElement> SVGIUse::clone() const {
        auto cloned = std::make_shared<SVGElement>();
        cloned->SVGElement::operator=(*this);
        return cloned;
    }
    std::shared_ptr<SVGIUse> SVGIUse::clone(bool identity) const {
        auto cloned = std::make_shared<SVGIUse>();
        *cloned = *this;
        return cloned;
    }
    SVGElement &SVGIUse::operator=(const SVGElement &element) {
        SVGElement::operator=(element);
        return *this;
    }
    SVGIUse &SVGIUse::operator=(const SVGIUse &element) {
        SVGIElement::operator=(static_cast<SVGIElement>(element));
        Href = element.Href;
        X = element.X;
        Y = element.Y;
        Width = element.Width;
        Height = element.Height;

        _bind_getter_setter();
        return *this;
    }
    const std::string SVGIUse::operator-(const SVGElement &element) const {
        return SVGUse::operator-(element);
    }
}

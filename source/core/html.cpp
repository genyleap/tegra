#include "html.hpp"
#include "core.hpp"

TEGRA_NAMESPACE_BEGIN(Tegra::System)

std::string Html::ParamValue(const std::string& s, ss8 mode,
                             const std::string& ch) __tegra_noexcept_expr(true)
{
    std::string str = s;
    if (mode == 1)
        str = Engine::htmlEntityDecode(str);
    if (mode == 2)
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '<') {
                str[i] += '&lt;';
            } else if (str[i] == '>') {
                str[i] += '&gt;';
            }
        }
    return str;
}

std::string Html::TagParams(const std::vector<std::string>& a) __tegra_noexcept_expr(true)
{
    std::string params = "";
    // ToDo... maybe use std::map :)
    for (int i = 0; i < a.size(); i++) {
        params += a[i];
    }

    return params;
}

std::string Html::Label(const std::string& value,
                        const std::vector<std::string>& extra) __tegra_noexcept_expr(true)
{
    return "<label " + TagParams(extra) + ">" + value + "</label>";
}

std::string Html::Text(const std::string& name,
                       const std::string& value,
                       const std::vector<std::string>& extra) __tegra_noexcept_expr(true)
{
    return "<p " + TagParams(extra) + "name='" + name + "'>" + value + "</p>";
}

std::string Html::Input(const std::string& name,
                        const std::string& title,
                        const std::string& description,
                        const std::string& value,
                        const std::vector<std::string>& extra, ss8 mode = 1) __tegra_noexcept_expr(true)
{
    return "<div class=\"form-group\">"
           "<!-- Label --><label class=\"mb-1\">"+title+"</label>"
                   "<!-- Form text --><small class=\"form-text text-muted\">"+description+"</small>"
                         "<!-- Input --><input class=\"form-control\"" + TagParams(extra) + " type='text' value='" +
           ParamValue(value, mode, "") + "' name='" + name + "'>";
}

std::string Html::TextArea(const std::string& name,
                           const std::string& value,
                           const std::vector<std::string>& extra, ss8 mode = 1) __tegra_noexcept_expr(true)
{
    return "<textarea " + TagParams(extra) +
           "name=" + name +">" + ParamValue(value, mode, "") +"</textarea>";
}

std::string Html::Check(const std::string& name, bool checked,
                        const std::string& text,
                        const std::vector<std::string>& extra) __tegra_noexcept_expr(true)
{
    std::string checkMode = {};
    if (checked)
        checkMode = "checked";
    return "<input " + TagParams(extra) + " type=\"checkbox\" value=1 name=" + name + " " + checkMode + "/>";
}

std::string Html::Button(const std::string& name,
                         const std::string& value, std::string type,
                         const std::string& text,
                         const std::vector<std::string>& extra) __tegra_noexcept_expr(true)
{
    if (type.empty())
        type = "button";
    return "<button " + TagParams(extra) + " name=\"" + name + "\" type=" + type + " value=" + value + " > " + std::string(text) + "</button> ";
}

std::string Html::Radio(const std::string& name,
                        const std::string& value, bool checked,
                        const std::string& text,
                        const std::vector<std::string>& extra) __tegra_noexcept_expr(true)
{
    std::string checkMode = {};
    if (checked)
        checkMode = "checked";
    return "<input " + TagParams(extra) + " type=\"radio\" " + checkMode + "/>";
}

std::string Html::Option(const std::string& view,
                         const std::string& value, bool selected,
                         const std::string& name,
                         const std::vector<std::string>& extra, ss8 mode) __tegra_noexcept_expr(true)
{
    std::string selectedStr {};
    if (!selected == true) {
        selectedStr = "";
    } else {
        selectedStr = "selected";
    }
    return "<option type='text' name=" + name + " " + TagParams(extra) + " value=" + value + " " + selectedStr + ">" + view + "</option>";
}

std::string Html::Select(const std::string& name,
                         const std::vector<std::string>& options,
                         const std::vector<std::string>& extra) __tegra_noexcept_expr(true)
{
    std::string start = "<select type='text' name=" + name + " " + TagParams(extra) + ">";
    std::string opt {};
    for (int o = 0; o < options.size(); o++) {
        opt += options[o];
    }
    return start + opt + "</select>";
}


std::string Html::Switch(const std::string& name,
                         const std::string& title,
                         const std::string& description,
                         const std::vector<std::string>& options,
                         const std::vector<std::string>& extra) __tegra_noexcept_expr(true)
{
    std::string start = "<div class=\"row align-items-center\">"
                        "<div class=\"col\">"
                        "<!-- Heading -->"
                        "<h4 class=\"font-weight-base mb-1\">"+title+"</h4>"
                                "<!-- Small -->"
                                "<small class=\"text-muted\">"+description+"</small>"
                                      "</div>"
                                      "<div class=\"col-auto\">"
                                      "<div class=\"form-check form-switch\">"
                                      "<input class=\"form-check-input\" type='checkbox' name=" + name + " " + TagParams(extra) + ">";
    std::string opt {};
    for (int o = 0; o < options.size(); o++)
    {
        opt += options[o];
    }
    return start + opt + "</div></div></div>";
}

std::string Html::Card(const std::string& name,
                       const std::string& title,
                       const std::vector<std::string>& options,
                       const std::vector<std::string>& extra,
                       const std::vector<std::string>& item) __tegra_noexcept_expr(true)
{
    std::string begin {"<div class=\"card\"><div class=\"card-body\">"};

    std::string header {"<div class=\"card-header\">"
                       "<!-- Title -->"
                       "<h4 class=\"card-header-title\">"
                       +title+
                       "</h4>"
                       "<!-- Button -->"
                       "<button class=\"btn btn-sm btn-white\">"
                       "Unsubscribe all"
                       "</button>"
                       "</div>"};

    std::string content {"<div class=\"card-body\">"};

    std::string listGroupItem {};

    for(const auto& i : item) {
        listGroupItem += "<div class=\"list-group-item\">" + i +"</div>";
    }

    std::string contentItem { "<div class=\"row align-items-center\"></div>"};

    std::string listGroup {"<div class=\"list-group list-group-flush my-n3\">"};

    std::string ending {"</div></div></div>"};

    return begin + header + content + listGroup + listGroupItem + ending;
}

std::string Html::Table(const std::string& name,
                        const std::string& title,
                        const VectorString& options,
                        const std::vector<std::string>& extra,
                        const std::vector<std::string>& header,
                        const std::vector<std::string>& item) __tegra_noexcept_expr(true)
{
    std::string content{};
    std::string theader{"<th scope=\"col\">#</th>"};
    std::string theaderItem{};
    for(const auto& h : header) {
        theader+="<th scope=\"col\">"+h+"</th>";
    }
    for(const auto& i : item) {
        theaderItem+="<td class=\""+i+"\">"+i+"</td>";
    }

    content = "<div class=\"card\"><div class=\"card-body\">"
              "<div class=\"table-responsive\" data-list='{\"valueNames\": []}'>"
              "<table class=\"table table-sm table-nowrap\">"
              "<thead>"
              "<tr>"+theader+"</tr>"
                        "</thead>"
                        "<tbody class=\"list\">"
                        "<tr>"
                        "<th scope=\"row\">1</th>"
              +theaderItem+
              "</tr>"
              "</tbody>"
              "</table></div></div></div>";

    return content;
}

TEGRA_NAMESPACE_END

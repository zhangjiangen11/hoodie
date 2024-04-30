#include "hn_add_attribute.h"

#include <godot_cpp/classes/array_mesh.hpp>

using namespace godot;

void HNAddAttribute::_process(const Array &p_inputs) {
    Ref<HoodieGeo> in_geo = p_inputs[0];
    String in_name;
    Array in_data = p_inputs[2];

    Array inputs = p_inputs.duplicate(true);

    if (p_inputs[1].get_type() == Variant::ARRAY) {
        Array a = inputs[1];
        if (a.size() > 0) {
            in_name = a[0];
        }
    }

    UtilityFunctions::print("HGeo points " + itos(in_geo->points.size()));
    in_geo->attributes[in_name] = in_data;

    outputs[0] = in_geo;
}

String HNAddAttribute::get_caption() const {
    return "Add Attribute";
}

int HNAddAttribute::get_input_port_count() const {
    return 3;
}

HoodieNode::PortType HNAddAttribute::get_input_port_type(int p_port) const {
    switch (p_port) {
        case 0:
            return PortType::PORT_TYPE_HGEO;
        case 1:
            return PortType::PORT_TYPE_STRING;
        case 2:
            return PortType::PORT_TYPE_DATA;
        default:
            return PortType::PORT_TYPE_SCALAR;
    }
}

String HNAddAttribute::get_input_port_name(int p_port) const {
    switch (p_port) {
        case 0:
            return "HGeo";
        case 1:
            return "String";
        case 2:
            return "Data";
        default:
            return "";
    }
}

int HNAddAttribute::get_output_port_count() const {
    return 1;
}

HoodieNode::PortType HNAddAttribute::get_output_port_type(int p_port) const {
    return PortType::PORT_TYPE_HGEO;
}

String HNAddAttribute::get_output_port_name(int p_port) const {
    return "HGeo";
}
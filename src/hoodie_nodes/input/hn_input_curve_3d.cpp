#include "hn_input_curve_3d.h"

using namespace godot;

int HNInputCurve3D::get_input_port_count() const {
    return 0;
}

HNInputCurve3D::PortType HNInputCurve3D::get_input_port_type(int p_port) const {
    return PortType::PORT_TYPE_SCALAR;
}

String HNInputCurve3D::get_input_port_name(int p_port) const {
    return "";
}

int HNInputCurve3D::get_output_port_count() const {
    return 4;
}

HNInputCurve3D::PortType HNInputCurve3D::get_output_port_type(int p_port) const {
    switch (p_port) {
        case 0:
            return PortType::PORT_TYPE_VECTOR_3D;
        case 1:
            return PortType::PORT_TYPE_VECTOR_3D;
        case 2:
            return PortType::PORT_TYPE_VECTOR_3D;
        case 3:
            return PortType::PORT_TYPE_SCALAR;
        default:
            return PortType::PORT_TYPE_SCALAR;
    }
}

String HNInputCurve3D::get_output_port_name(int p_port) const {
    switch (p_port) {
        case 0:
            return "Points";
        case 1:
            return "Tangents";
        case 2:
            return "Normals";
        case 3:
            return "Tilts";
        default:
            return "";
    }
}
#include "hn_combine_xy.h"

using namespace godot;

void HNCombineXY::_process(const Array &p_inputs) {
    if (p_inputs.size() == 0) {
        return;
    }

    Array in_x = p_inputs[0].duplicate();
    Array in_y = p_inputs[1].duplicate();

    int max = MAX(in_x.size(), in_y.size());
    if (in_x.size() < max) {
        in_x.resize(max);
    } else if (in_y.size() < max) {
        in_y.resize(max);
    }

    Array out_values;
    
    for (int i = 0; i < max; i++) {
        out_values.push_back(Vector2((float)in_x[i], (float)in_y[i]));
    }

    set_output(0, out_values);
}

String HNCombineXY::get_caption() const {
    return "Combine XY";
}

int HNCombineXY::get_input_port_count() const {
    return 2;
}

HNCombineXY::PortType HNCombineXY::get_input_port_type(int p_port) const {
    switch (p_port) {
        case 0:
            return PortType::PORT_TYPE_SCALAR;
        case 1:
            return PortType::PORT_TYPE_SCALAR;
    }

    return PortType::PORT_TYPE_SCALAR;
}

String HNCombineXY::get_input_port_name(int p_port) const {
    switch (p_port) {
        case 0:
            return "X";
        case 1:
            return "Y";
    }

    return "";
}

int HNCombineXY::get_output_port_count() const {
    return 1;
}

HNCombineXY::PortType HNCombineXY::get_output_port_type(int p_port) const {
    return PortType::PORT_TYPE_VECTOR_2D;
}

String HNCombineXY::get_output_port_name(int p_port) const {
    return "Vector2D";
}
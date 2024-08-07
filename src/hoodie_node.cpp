#include "hoodie_node.h"

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void HoodieNode::mark_dirty() {
    if (!has_button()) {
        dirty = true;
    }
    // TODO: emit_changed?
}

void HoodieNode::mark_dirty_button() {
    dirty = true;
}

void HoodieNode::set_status(const ProcessStatus &p_status) {
    status = p_status;
}

HoodieNode::ProcessStatus HoodieNode::get_status() const {
    return status;
}

void HoodieNode::_bind_methods() {
    ClassDB::bind_method(D_METHOD("mark_dirty"), &HoodieNode::mark_dirty);
    ClassDB::bind_method(D_METHOD("set_property_input", "id", "value"), &HoodieNode::set_property_input);
}

bool HoodieNode::update(bool p_inputs_updated, const Array &p_inputs) {
    bool inputs_button = has_button() ? false : p_inputs_updated;
    bool updated = dirty || inputs_button;
    dirty = false;

    if (updated) {
        outputs.clear();
        outputs.resize(get_output_port_count());
        
        _process(p_inputs);
    }

    return updated;
}

void HoodieNode::_process(const Array &p_inputs) {
}

String HoodieNode::get_caption() const {
    return "Hoodie Node";
}

int HoodieNode::get_input_port_count() const {
    return 0;
}

HoodieNode::PortType HoodieNode::get_input_port_type(int p_port) const {
    return PortType::PORT_TYPE_SCALAR;
}

String HoodieNode::get_input_port_name(int p_port) const {
    return "";
}

int HoodieNode::get_output_port_count() const {
    return 0;
}

HoodieNode::PortType HoodieNode::get_output_port_type(int p_port) const {
    return PortType::PORT_TYPE_SCALAR;
}

String HoodieNode::get_output_port_name(int p_port) const {
    return "";
}

int HoodieNode::get_property_input_count() const {
    return 0;
}

Variant::Type HoodieNode::get_property_input_type(vec_size_t p_prop) const {
    return Variant::NIL;
}

String HoodieNode::get_property_input_hint(vec_size_t p_prop) const {
    return "";
}

Variant HoodieNode::get_property_input(vec_size_t p_port) const {
    return Variant();
}

void HoodieNode::set_property_input(vec_size_t p_prop, Variant p_input) {
}

Vector<StringName> HoodieNode::get_editable_properties() const {
    return Vector<StringName>();
}

HashMap<StringName, String> HoodieNode::get_editable_properties_names() const {
    return HashMap<StringName, String>();
}

bool HoodieNode::has_button() const {
    return false;
}

const Variant HoodieNode::get_output(int p_port) {
    if (outputs.size() == 0 || outputs.size() < p_port) {
        return Variant();
    } else {
        if (get_output_port_type(p_port) == PortType::PORT_TYPE_HGEO) {
            Ref<HoodieGeo> hgeo = outputs[p_port];
            if (hgeo.is_null()) {
                hgeo.instantiate();
                outputs[p_port] = hgeo;
            }
        }
        return outputs[p_port];
    }
}

void HoodieNode::set_output(int p_port, const Variant &p_data) {
    if (p_data.get_type() == Variant::OBJECT || Variant::can_convert(p_data.get_type(), Variant::ARRAY)) {
        outputs[p_port] = p_data;
    } else {
        Array out_arr;
        out_arr.push_back(p_data);
        outputs[p_port] = out_arr;
    }
}

bool HoodieNode::is_output_port_connected(vec_size_t p_port) const {
    if (connected_output_ports.has(p_port)) {
        return connected_output_ports[p_port];
    }
    return false;
}

void HoodieNode::set_output_port_connected(vec_size_t p_port, bool p_connected) {
    connected_output_ports[p_port] = p_connected;
}

bool HoodieNode::is_input_port_connected(vec_size_t p_port) const {
    if (connected_input_ports.has(p_port)) {
        return connected_input_ports[p_port];
    }
    return false;
}

void HoodieNode::set_input_port_connected(vec_size_t p_port, bool p_connected) {
    connected_input_ports[p_port] = p_connected;
}

HoodieNode::HoodieNode() {
}

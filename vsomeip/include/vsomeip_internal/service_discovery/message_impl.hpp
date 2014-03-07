//
// message_impl.hpp
//
// Author: 	Lutz Bichler
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright © 2013, 2014 Bayerische Motoren Werke AG (BMW).
// All rights reserved.
//

#ifndef VSOMEIP_INTERNAL_SERVICE_DISCOVERY_MESSAGE_IMPL_HPP
#define VSOMEIP_INTERNAL_SERVICE_DISCOVERY_MESSAGE_IMPL_HPP

#include <vector>

#include <vsomeip/service_discovery/message.hpp>
#include <vsomeip_internal/message_base_impl.hpp>

namespace vsomeip {
namespace service_discovery {

class entry;
class option;

class message_impl
		: virtual public message,
		  virtual public vsomeip::message_base_impl {
public:
	message_impl();
	virtual ~message_impl();

	length get_length() const;
	void set_length(length _length);

	bool get_reboot_flag() const;
	void set_reboot_flag(bool _is_set);

	bool get_unicast_flag() const;
	void set_unicast_flag(bool _is_set);

	eventgroup_entry & create_eventgroup_entry();
	service_entry & create_service_entry();

	configuration_option & create_configuration_option();
	ipv4_endpoint_option & create_ipv4_endpoint_option();
	ipv6_endpoint_option & create_ipv6_endpoint_option();
	load_balancing_option & create_load_balancing_option();
	protection_option & create_protection_option();

	const std::vector<entry *> get_entries() const;
	const std::vector<option *> get_options() const;

	int16_t get_option_index(const option &_option) const;

	bool serialize(vsomeip::serializer *_to) const;
	bool deserialize(vsomeip::deserializer *_from);

private:
	entry * deserialize_entry(vsomeip::deserializer *_from);
	option * deserialize_option(vsomeip::deserializer *_from);

private:
	flags flags_;

	std::vector<entry *> entries_;
	std::vector<option *> options_;
};

} // namespace service_discovery
} // namespace vsomeip

#endif // VSOMEIP_INTERNAL_SERVICE_DISCOVERY_MESSAGE_IMPL_HPP
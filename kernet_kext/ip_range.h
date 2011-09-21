//
//  ip_range.h
//  kernet
//
//  Created by Mike Chen on 9/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef IP_RANGE_H
#define IP_RANGE_H


typedef enum _ip_range_policy {
	ip_range_apply_kernet = 1, 
	ip_range_direct = 2,
} ip_range_policy;

struct ip_range_entry {
	u_int32_t	ip;
	u_int8_t	netmask_bits;
    u_int16_t port;
	ip_range_policy	policy;
	
	TAILQ_ENTRY(ip_range_entry) link;
};


errno_t kn_ip_range_initialize();
errno_t kn_ip_range_close();

boolean_t kn_shall_apply_kernet_to_host(u_int32_t ip, u_int16_t port);
errno_t kn_append_ip_range_entry(u_int32_t ip, u_int8_t netmask_bits, u_int16_t port, ip_range_policy policy);
errno_t kn_append_ip_range_entry_default_ports(u_int32_t ip, u_int8_t netmask_bits, ip_range_policy policy);
errno_t kn_remove_ip_range_entry(u_int32_t ip, u_int8_t netmask_bits, u_int16_t port);
errno_t kn_remove_ip_range_entry_default_ports(u_int32_t ip, u_int8_t netmask_bits);
errno_t kn_append_readable_ip_range_entry_default_ports(const char* ip, u_int8_t netmask_bits, ip_range_policy policy);
void kn_fulfill_ip_ranges();

#endif
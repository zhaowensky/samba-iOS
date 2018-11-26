/* header auto-generated by pidl */

#ifndef _PIDL_HEADER_epmapper
#define _PIDL_HEADER_epmapper

#include <stdint.h>

#include "libcli/util/ntstatus.h"

#include "librpc/gen_ndr/misc.h"
#ifndef _HEADER_epmapper
#define _HEADER_epmapper

#define EPMAPPER_STATUS_CANT_PERFORM_OP	( 0x6d8 )
#define EPMAPPER_STATUS_NO_MORE_ENTRIES	( 0x16c9a0d6 )
#define EPMAPPER_STATUS_NO_MEMORY	( 0x16C9A012 )
#define EPMAPPER_STATUS_OK	( 0 )
enum epm_protocol
#ifndef USE_UINT_ENUMS
 {
	EPM_PROTOCOL_DNET_NSP=(int)(0x04),
	EPM_PROTOCOL_OSI_TP4=(int)(0x05),
	EPM_PROTOCOL_OSI_CLNS=(int)(0x06),
	EPM_PROTOCOL_TCP=(int)(0x07),
	EPM_PROTOCOL_UDP=(int)(0x08),
	EPM_PROTOCOL_IP=(int)(0x09),
	EPM_PROTOCOL_NCADG=(int)(0x0a),
	EPM_PROTOCOL_NCACN=(int)(0x0b),
	EPM_PROTOCOL_NCALRPC=(int)(0x0c),
	EPM_PROTOCOL_UUID=(int)(0x0d),
	EPM_PROTOCOL_IPX=(int)(0x0e),
	EPM_PROTOCOL_SMB=(int)(0x0f),
	EPM_PROTOCOL_NAMED_PIPE=(int)(0x10),
	EPM_PROTOCOL_NETBIOS=(int)(0x11),
	EPM_PROTOCOL_NETBEUI=(int)(0x12),
	EPM_PROTOCOL_SPX=(int)(0x13),
	EPM_PROTOCOL_NB_IPX=(int)(0x14),
	EPM_PROTOCOL_DSP=(int)(0x16),
	EPM_PROTOCOL_DDP=(int)(0x17),
	EPM_PROTOCOL_APPLETALK=(int)(0x18),
	EPM_PROTOCOL_VINES_SPP=(int)(0x1a),
	EPM_PROTOCOL_VINES_IPC=(int)(0x1b),
	EPM_PROTOCOL_STREETTALK=(int)(0x1c),
	EPM_PROTOCOL_HTTP=(int)(0x1f),
	EPM_PROTOCOL_UNIX_DS=(int)(0x20),
	EPM_PROTOCOL_NULL=(int)(0x21)
}
#else
 { __donnot_use_enum_epm_protocol=0x7FFFFFFF}
#define EPM_PROTOCOL_DNET_NSP ( 0x04 )
#define EPM_PROTOCOL_OSI_TP4 ( 0x05 )
#define EPM_PROTOCOL_OSI_CLNS ( 0x06 )
#define EPM_PROTOCOL_TCP ( 0x07 )
#define EPM_PROTOCOL_UDP ( 0x08 )
#define EPM_PROTOCOL_IP ( 0x09 )
#define EPM_PROTOCOL_NCADG ( 0x0a )
#define EPM_PROTOCOL_NCACN ( 0x0b )
#define EPM_PROTOCOL_NCALRPC ( 0x0c )
#define EPM_PROTOCOL_UUID ( 0x0d )
#define EPM_PROTOCOL_IPX ( 0x0e )
#define EPM_PROTOCOL_SMB ( 0x0f )
#define EPM_PROTOCOL_NAMED_PIPE ( 0x10 )
#define EPM_PROTOCOL_NETBIOS ( 0x11 )
#define EPM_PROTOCOL_NETBEUI ( 0x12 )
#define EPM_PROTOCOL_SPX ( 0x13 )
#define EPM_PROTOCOL_NB_IPX ( 0x14 )
#define EPM_PROTOCOL_DSP ( 0x16 )
#define EPM_PROTOCOL_DDP ( 0x17 )
#define EPM_PROTOCOL_APPLETALK ( 0x18 )
#define EPM_PROTOCOL_VINES_SPP ( 0x1a )
#define EPM_PROTOCOL_VINES_IPC ( 0x1b )
#define EPM_PROTOCOL_STREETTALK ( 0x1c )
#define EPM_PROTOCOL_HTTP ( 0x1f )
#define EPM_PROTOCOL_UNIX_DS ( 0x20 )
#define EPM_PROTOCOL_NULL ( 0x21 )
#endif
;

struct epm_rhs_dnet_nsp {
	char _empty_;
};

struct epm_rhs_osi_tp4 {
	char _empty_;
};

struct epm_rhs_osi_clns {
	char _empty_;
};

struct epm_rhs_udp {
	uint16_t port;
};

struct epm_rhs_tcp {
	uint16_t port;
};

struct epm_rhs_ip {
	const char * ipaddr;
};

struct epm_rhs_ncadg {
	uint16_t minor_version;
};

struct epm_rhs_ncacn {
	uint16_t minor_version;
};

struct epm_rhs_uuid {
	DATA_BLOB unknown;/* [flag(LIBNDR_FLAG_REMAINING)] */
};

struct epm_rhs_ipx {
	char _empty_;
};

struct epm_rhs_smb {
	const char * unc;/* [flag(LIBNDR_FLAG_STR_ASCII|LIBNDR_FLAG_STR_NULLTERM)] */
};

struct epm_rhs_named_pipe {
	const char * path;/* [flag(LIBNDR_FLAG_STR_ASCII|LIBNDR_FLAG_STR_NULLTERM)] */
};

struct epm_rhs_netbios {
	const char * name;/* [flag(LIBNDR_FLAG_STR_ASCII|LIBNDR_FLAG_STR_NULLTERM)] */
};

struct epm_rhs_netbeui {
	char _empty_;
};

struct epm_rhs_spx {
	char _empty_;
};

struct epm_rhs_nb_ipx {
	char _empty_;
};

struct epm_rhs_http {
	uint16_t port;
};

struct epm_rhs_unix_ds {
	const char * path;/* [flag(LIBNDR_FLAG_STR_ASCII|LIBNDR_FLAG_STR_NULLTERM)] */
};

struct epm_rhs_null {
	char _empty_;
};

struct epm_rhs_ncalrpc {
	uint16_t minor_version;
};

struct epm_rhs_appletalk {
	char _empty_;
};

struct epm_rhs_atalk_stream {
	char _empty_;
};

struct epm_rhs_atalk_datagram {
	char _empty_;
};

struct epm_rhs_vines_spp {
	uint16_t port;
};

struct epm_rhs_vines_ipc {
	uint16_t port;
};

struct epm_rhs_streettalk {
	const char * streettalk;/* [flag(LIBNDR_FLAG_STR_ASCII|LIBNDR_FLAG_STR_NULLTERM)] */
};

union epm_rhs {
	struct epm_rhs_dnet_nsp dnet_nsp;/* [case(EPM_PROTOCOL_DNET_NSP)] */
	struct epm_rhs_osi_tp4 osi_tp4;/* [case(EPM_PROTOCOL_OSI_TP4)] */
	struct epm_rhs_osi_clns osi_clns;/* [case(EPM_PROTOCOL_OSI_CLNS)] */
	struct epm_rhs_tcp tcp;/* [case(EPM_PROTOCOL_TCP)] */
	struct epm_rhs_udp udp;/* [case(EPM_PROTOCOL_UDP)] */
	struct epm_rhs_ip ip;/* [case(EPM_PROTOCOL_IP)] */
	struct epm_rhs_ncadg ncadg;/* [case(EPM_PROTOCOL_NCADG)] */
	struct epm_rhs_ncacn ncacn;/* [case(EPM_PROTOCOL_NCACN)] */
	struct epm_rhs_ncalrpc ncalrpc;/* [case(EPM_PROTOCOL_NCALRPC)] */
	struct epm_rhs_uuid uuid;/* [case(EPM_PROTOCOL_UUID)] */
	struct epm_rhs_ipx ipx;/* [case(EPM_PROTOCOL_IPX)] */
	struct epm_rhs_smb smb;/* [case(EPM_PROTOCOL_SMB)] */
	struct epm_rhs_named_pipe named_pipe;/* [case(EPM_PROTOCOL_NAMED_PIPE)] */
	struct epm_rhs_netbios netbios;/* [case(EPM_PROTOCOL_NETBIOS)] */
	struct epm_rhs_netbeui netbeui;/* [case(EPM_PROTOCOL_NETBEUI)] */
	struct epm_rhs_spx spx;/* [case(EPM_PROTOCOL_SPX)] */
	struct epm_rhs_nb_ipx nb_ipx;/* [case(EPM_PROTOCOL_NB_IPX)] */
	struct epm_rhs_atalk_stream atalk_stream;/* [case(EPM_PROTOCOL_DSP)] */
	struct epm_rhs_atalk_datagram atalk_datagram;/* [case(EPM_PROTOCOL_DDP)] */
	struct epm_rhs_appletalk appletalk;/* [case(EPM_PROTOCOL_APPLETALK)] */
	struct epm_rhs_vines_spp vines_spp;/* [case(EPM_PROTOCOL_VINES_SPP)] */
	struct epm_rhs_vines_ipc vines_ipc;/* [case(EPM_PROTOCOL_VINES_IPC)] */
	struct epm_rhs_streettalk streettalk;/* [case(EPM_PROTOCOL_STREETTALK)] */
	struct epm_rhs_http http;/* [case(EPM_PROTOCOL_HTTP)] */
	struct epm_rhs_unix_ds unix_ds;/* [case(EPM_PROTOCOL_UNIX_DS)] */
	struct epm_rhs_null null;/* [case(EPM_PROTOCOL_NULL)] */
	DATA_BLOB unknown;/* [flag(LIBNDR_FLAG_REMAINING),default] */
}/* [nodiscriminant,flag(LIBNDR_FLAG_BIGENDIAN)] */;

struct epm_lhs {
	enum epm_protocol protocol;
	DATA_BLOB lhs_data;/* [flag(LIBNDR_FLAG_REMAINING)] */
};

struct epm_floor {
	struct epm_lhs lhs;/* [subcontext(2)] */
	union epm_rhs rhs;/* [subcontext(2),switch_is(lhs.protocol)] */
};

struct epm_tower {
	uint16_t num_floors;
	struct epm_floor *floors;
}/* [gensize,flag(LIBNDR_FLAG_NOALIGN|LIBNDR_FLAG_LITTLE_ENDIAN)] */;

struct epm_twr_t {
	uint32_t tower_length;/* [value(ndr_size_epm_tower(&tower,ndr->flags))] */
	struct epm_tower tower;/* [subcontext(4)] */
};

struct epm_entry_t {
	struct GUID object;
	struct epm_twr_t *tower;/* [ptr] */
	uint32_t __annotation_offset;/* [value(0)] */
	uint32_t __annotation_length;/* [value(strlen(annotation)+1)] */
	const char *annotation;/* [charset(DOS)] */
};

struct rpc_if_id_t {
	struct GUID uuid;
	uint16_t vers_major;
	uint16_t vers_minor;
};

enum epm_InquiryType
#ifndef USE_UINT_ENUMS
 {
	RPC_C_EP_ALL_ELTS=(int)(0x00000000),
	RPC_C_EP_MATCH_BY_IF=(int)(0x00000001),
	RPC_C_EP_MATCH_BY_OBJ=(int)(0x00000002),
	RPC_C_EP_MATCH_BY_BOTH=(int)(0x00000003)
}
#else
 { __donnot_use_enum_epm_InquiryType=0x7FFFFFFF}
#define RPC_C_EP_ALL_ELTS ( 0x00000000 )
#define RPC_C_EP_MATCH_BY_IF ( 0x00000001 )
#define RPC_C_EP_MATCH_BY_OBJ ( 0x00000002 )
#define RPC_C_EP_MATCH_BY_BOTH ( 0x00000003 )
#endif
;

enum epm_VersionOption
#ifndef USE_UINT_ENUMS
 {
	RPC_C_VERS_ALL=(int)(0x00000000),
	RPC_C_VERS_COMPATIBLE=(int)(0x00000001),
	RPC_C_VERS_EXACT=(int)(0x00000002),
	RPC_C_VERS_MAJOR_ONLY=(int)(0x00000003),
	RPC_C_VERS_UPTO=(int)(0x00000004)
}
#else
 { __donnot_use_enum_epm_VersionOption=0x7FFFFFFF}
#define RPC_C_VERS_ALL ( 0x00000000 )
#define RPC_C_VERS_COMPATIBLE ( 0x00000001 )
#define RPC_C_VERS_EXACT ( 0x00000002 )
#define RPC_C_VERS_MAJOR_ONLY ( 0x00000003 )
#define RPC_C_VERS_UPTO ( 0x00000004 )
#endif
;

struct epm_twr_p_t {
	struct epm_twr_t *twr;/* [ptr] */
};


struct epm_Insert {
	struct {
		uint32_t num_ents;
		struct epm_entry_t *entries;/* [size_is(num_ents)] */
		uint32_t replace;
	} in;

	struct {
		uint32_t result;
	} out;

};


struct epm_Delete {
	struct {
		uint32_t num_ents;
		struct epm_entry_t *entries;/* [size_is(num_ents)] */
	} in;

	struct {
		uint32_t result;
	} out;

};


struct epm_Lookup {
	struct {
		enum epm_InquiryType inquiry_type;
		struct GUID *object;/* [ptr] */
		struct rpc_if_id_t *interface_id;/* [ptr] */
		enum epm_VersionOption vers_option;
		uint32_t max_ents;
		struct policy_handle *entry_handle;/* [ref] */
	} in;

	struct {
		uint32_t *num_ents;/* [ref] */
		struct epm_entry_t *entries;/* [length_is(*num_ents),size_is(max_ents)] */
		struct policy_handle *entry_handle;/* [ref] */
		uint32_t result;
	} out;

};


struct epm_Map {
	struct {
		struct GUID *object;/* [ptr] */
		struct epm_twr_t *map_tower;/* [ptr] */
		uint32_t max_towers;
		struct policy_handle *entry_handle;/* [ref] */
	} in;

	struct {
		uint32_t *num_towers;/* [ref] */
		struct epm_twr_p_t *towers;/* [size_is(max_towers),length_is(*num_towers)] */
		struct policy_handle *entry_handle;/* [ref] */
		uint32_t result;
	} out;

};


struct epm_LookupHandleFree {
	struct {
		struct policy_handle *entry_handle;/* [ref] */
	} in;

	struct {
		struct policy_handle *entry_handle;/* [ref] */
		uint32_t result;
	} out;

};


struct epm_InqObject {
	struct {
		struct GUID *epm_object;/* [ref] */
	} in;

	struct {
		uint32_t result;
	} out;

};


struct epm_MgmtDelete {
	struct {
		uint32_t object_speced;
		struct GUID *object;/* [ptr] */
		struct epm_twr_t *tower;/* [ptr] */
	} in;

	struct {
		uint32_t result;
	} out;

};


struct epm_MapAuth {
	struct {
		uint32_t result;
	} out;

};

#endif /* _HEADER_epmapper */
#endif /* _PIDL_HEADER_epmapper */

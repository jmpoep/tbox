/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author		ruki
 * @file		url.h
 * @ingroup 	network
 *
 */
#ifndef TB_NETWORK_URL_H
#define TB_NETWORK_URL_H

/* ///////////////////////////////////////////////////////////////////////
 * includes
 */
#include "prefix.h"
#include "ipv4.h"
#include "../string/string.h"

/* ///////////////////////////////////////////////////////////////////////
 * macros
 */
#ifdef __tb_small__
# 	define TB_URL_HOST_MAX 		(32)
# 	define TB_URL_PATH_MAX 		(1024)
#else
# 	define TB_URL_HOST_MAX 		(128)
# 	define TB_URL_PATH_MAX 		(4096)
#endif

/* ///////////////////////////////////////////////////////////////////////
 * types
 */

/// the url protocol type
typedef enum __tb_url_proto_t
{
	TB_URL_PROTO_NONE 	= 0
,	TB_URL_PROTO_DATA 	= 1 	//!< data://... 
,	TB_URL_PROTO_FILE 	= 2 	//!< file://... 
,	TB_URL_PROTO_SOCK 	= 3 	//!< sock://... or socks://...
,	TB_URL_PROTO_HTTP 	= 4 	//!< http://... or https://...
,	TB_URL_PROTO_RTSP 	= 5 	//!< rtsp://... 

}tb_url_proto_t;

/// the url type
typedef struct __tb_url_t
{
	// the protocol 
	tb_uint16_t 	poto: 	6;

	// is ssl?
	tb_uint16_t 	bssl: 	1;

	// is win?
	tb_uint16_t 	bwin: 	1;

	// the windows prefix 
	tb_uint16_t 	pwin: 	8;

	// the port
	tb_uint16_t 	port;

	// the ipv4
	tb_ipv4_t 		ipv4;

	// the host
	tb_sstring_t 	host;

	// the path
	tb_sstring_t 	path;

	// the urls
	tb_pstring_t 	urls;

	// the args
	tb_pstring_t 	args;

	// the data
	tb_char_t 		data[TB_URL_HOST_MAX + TB_URL_PATH_MAX];

}tb_url_t;

/* ///////////////////////////////////////////////////////////////////////
 * interfaces
 */

/*! init url
 *
 * @param url 		the url
 *
 * @return 			tb_true or tb_false
 */
tb_bool_t 			tb_url_init(tb_url_t* url);

/*! exit url
 *
 * @param url 		the url
 */
tb_void_t 			tb_url_exit(tb_url_t* url);

/*! clear url
 *
 * @param url 		the url
 */
tb_void_t 			tb_url_cler(tb_url_t* url);

/*! get the url c-string
 *
 * @param url 		the url
 *
 * @return 			the c-string
 */
tb_char_t const* 	tb_url_get(tb_url_t* url);

/*! set the url c-string
 *
 * @param url 		the url
 * @param cstr 		the url c-string
 *
 * @return 			tb_true or tb_false
 */
tb_bool_t 			tb_url_set(tb_url_t* url, tb_char_t const* cstr);

/*! copy the url 
 *
 * @param url 		the url
 * @param cpy 		the copied url
 */
tb_void_t 			tb_url_cpy(tb_url_t* url, tb_url_t const* cpy);

/*! is ssl?
 *
 * @param url 		the url
 *
 * @return 			tb_true or tb_false
 */
tb_bool_t 			tb_url_ssl_get(tb_url_t const* url);

/*! set ssl
 *
 * @param url 		the url
 * @param bssl 		is ssl?
 */
tb_void_t 			tb_url_ssl_set(tb_url_t* url, tb_bool_t bssl);

/*! get the protocol from the url
 *
 * @param url 		the url
 *
 * @return 			the url protocol
 */
tb_size_t 			tb_url_poto_get(tb_url_t const* url);

/*! set the protocol to the url
 *
 * @param url 		the url
 * @param poto 		the url protocol
 */
tb_void_t 			tb_url_poto_set(tb_url_t* url, tb_size_t poto);

/*! get the port from the url
 *
 * @param url 		the url
 *
 * @return 			the url port
 */
tb_size_t 			tb_url_port_get(tb_url_t const* url);

/*! set the port to the url
 *
 * @param url 		the url
 * @param port 		the url port
 */
tb_void_t 			tb_url_port_set(tb_url_t* url, tb_size_t port);

/*! get the ipv4 from the url
 *
 * @param url 		the url
 *
 * @return 			the url ipv4
 */
tb_ipv4_t const* 	tb_url_ipv4_get(tb_url_t const* url);

/*! set the ipv4 to the url
 *
 * @param url 		the url
 * @param ipv4 		the url ipv4
 */
tb_void_t 			tb_url_ipv4_set(tb_url_t* url, tb_ipv4_t const* ipv4);

/*! get the host from the url
 *
 * @param url 		the url
 *
 * @return 			the url host
 */
tb_char_t const* 	tb_url_host_get(tb_url_t const* url);

/*! set the host to the url
 *
 * @param url 		the url
 * @param host 		the url host
 */
tb_void_t 			tb_url_host_set(tb_url_t* url, tb_char_t const* host);

/*! get the path from the url
 *
 * @param url 		the url
 *
 * @return 			the url path
 */
tb_char_t const* 	tb_url_path_get(tb_url_t const* url);

/*! set the path to the url
 *
 * @param url 		the url
 * @param path 		the url path
 */
tb_void_t 			tb_url_path_set(tb_url_t* url, tb_char_t const* path);

/*! get the arguments from the url
 *
 * @param url 		the url
 *
 * @return 			the url arguments
 */
tb_char_t const* 	tb_url_args_get(tb_url_t const* url);

/*! set the arguments to the url
 *
 * @param url 		the url
 * @param args 		the url arguments
 */
tb_void_t 			tb_url_args_set(tb_url_t* url, tb_char_t const* args);




#endif

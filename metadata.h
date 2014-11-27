/*
 * Copyright (C) 2013-2014 Kay Sievers
 * Copyright (C) 2013-2014 Greg Kroah-Hartman <gregkh@linuxfoundation.org>
 * Copyright (C) 2013-2014 Daniel Mack <daniel@zonque.org>
 * Copyright (C) 2013-2014 David Herrmann <dh.herrmann@gmail.com>
 * Copyright (C) 2013-2014 Linux Foundation
 *
 * kdbus is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the
 * Free Software Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 */

#ifndef __KDBUS_METADATA_H
#define __KDBUS_METADATA_H

struct kdbus_meta;
struct kdbus_conn;
struct kdbus_domain;
struct kdbus_pool_slice;

extern unsigned long long kdbus_meta_attach_mask;

struct kdbus_meta *kdbus_meta_new(void);
struct kdbus_meta *kdbus_meta_ref(struct kdbus_meta *meta);
struct kdbus_meta *kdbus_meta_unref(struct kdbus_meta *meta);

int kdbus_meta_collect(struct kdbus_meta *meta, u64 seq, u64 which);
int kdbus_meta_collect_dst(struct kdbus_meta *meta, u64 seq,
			   const struct kdbus_conn *conn);
int kdbus_meta_fake(struct kdbus_meta *meta,
		    const struct kdbus_creds *creds,
		    const struct kdbus_pids *pids,
		    const char *seclabel);
int kdbus_meta_export(const struct kdbus_meta *meta,
		      struct kdbus_conn *conn_src,
		      struct kdbus_conn *conn_dst,
		      u64 mask, u8 **buf, size_t *size);

#endif

/*-
 * Copyright (c) 2010-2017 Varnish Software AS
 * All rights reserved.
 *
 * Author: Steven Wojcik <swojcik@varnish-software.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

#include "vcl.h"
#include "vrt.h"
#include "cache/cache.h"
#include "storage.h"

#include "vcc_if.h"

VCL_STRING
vmod_get(VRT_CTX)
{
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	/* req is only available in the client side */
	if (ctx->method == VCL_MET_BACKEND_FETCH ||
	    ctx->method == VCL_MET_BACKEND_RESPONSE ||
	    ctx->method == VCL_MET_BACKEND_ERROR) {
			return ("");
	}

	if (!ctx->req->objcore ||
	    !ctx->req->objcore->stobj ||
	    !ctx->req->objcore->stobj->stevedore ||
	    !ctx->req->objcore->stobj->stevedore->ident) {
		return ("");
	}

	return (ctx->req->objcore->stobj->stevedore->ident);
}


VCL_STRING
vmod_type(VRT_CTX)
{
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	/* req is only available in the client side */
	if (ctx->method == VCL_MET_BACKEND_FETCH ||
	    ctx->method == VCL_MET_BACKEND_RESPONSE ||
	    ctx->method == VCL_MET_BACKEND_ERROR) {
			return ("");
	}

	if (!ctx->req->objcore ||
	    !ctx->req->objcore->stobj ||
	    !ctx->req->objcore->stobj->stevedore ||
	    !ctx->req->objcore->stobj->stevedore->name) {
		return ("");
	}

	return (ctx->req->objcore->stobj->stevedore->name);
}
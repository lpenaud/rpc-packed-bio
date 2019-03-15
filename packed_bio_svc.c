/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "packed_bio.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
packed_bio_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		customer customer_update_or_create_1_arg;
		int customer_get_1_arg;
		int offer_get_1_arg;
		offer offer_create_1_arg;
		offer offre_delete_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case CUSTOMER_UPDATE_OR_CREATE:
		_xdr_argument = (xdrproc_t) xdr_customer;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) customer_update_or_create_1_svc;
		break;

	case CUSTOMER_GET:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_customer;
		local = (char *(*)(char *, struct svc_req *)) customer_get_1_svc;
		break;

	case OFFER_GET:
		_xdr_argument = (xdrproc_t) xdr_int;
		_xdr_result = (xdrproc_t) xdr_offer;
		local = (char *(*)(char *, struct svc_req *)) offer_get_1_svc;
		break;

	case OFFER_CREATE:
		_xdr_argument = (xdrproc_t) xdr_offer;
		_xdr_result = (xdrproc_t) xdr_offer;
		local = (char *(*)(char *, struct svc_req *)) offer_create_1_svc;
		break;

	case OFFRE_DELETE:
		_xdr_argument = (xdrproc_t) xdr_offer;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) offre_delete_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (PACKED_BIO, PACKED_BIO_VER);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, PACKED_BIO, PACKED_BIO_VER, packed_bio_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (PACKED_BIO, PACKED_BIO_VER, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, PACKED_BIO, PACKED_BIO_VER, packed_bio_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (PACKED_BIO, PACKED_BIO_VER, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
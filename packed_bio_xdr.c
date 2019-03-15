/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "packed_bio.h"

bool_t
xdr_typeOffer (XDR *xdrs, typeOffer *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_packedLunch (XDR *xdrs, packedLunch *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_fishRecipes (XDR *xdrs, fishRecipes *objp)
{
	register int32_t *buf;

	 if (!xdr_enum (xdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_customer (XDR *xdrs, customer *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->birth_date, BIRTH_DATE_LEN,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->name, BUF_LEN,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->surname, BUF_LEN,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->address, BUF_LEN,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_offer (XDR *xdrs, offer *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_typeOffer (xdrs, &objp->type))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->price))
		 return FALSE;
	return TRUE;
}
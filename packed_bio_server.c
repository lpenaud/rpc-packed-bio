/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "packed_bio.h"

#define CUSTOMER_MAX 10
#define OFFER_MAX 10
#define SUPPLIER_MAX 10

unsigned customers_count = 0;
customer customers[CUSTOMER_MAX];

offer offers[OFFER_MAX];
unsigned offers_count = 0;

supplier suppliers[SUPPLIER_MAX];
unsigned supplier_count = 0;

int customer_find_index(customer *c)
{
    unsigned i;
    for(i = 0; i < customers_count; i++) {
        if (strcmp(customers[i].name, c->name) == 0
            && strcmp(customers[i].surname, c->surname) == 0
            && strcmp(customers[i].address, c->address) == 0)
                return i;
    }
    return -1;
}

int offer_find_index(offer *o)
{
    unsigned i;
    for(i = 0; i < OFFER_MAX; i++) {
        if (offers[i].id != -1
            && o->type == offers[i].type
            && o->price == offers[i].price
            && o->nb == o->nb) {
            return i;
        }
    }
    return -1;
}

int supplier_find_index(supplier *s)
{
    unsigned i;
    for (i = 0; i < SUPPLIER_MAX; i++) {
        if (offers[i].id != -1
            && strcmp(suppliers[i].address, s->address) == 0
            && strcmp(suppliers[i].surname, s->surname) == 0
            && suppliers[i].type == s->type) {
            return i;
        }
    }
    return -1;
}

int *
customer_update_or_create_1_svc(customer *argp, struct svc_req *rqstp)
{
    static int  result = -1;

    if (argp == NULL) return &result;

    if (argp->id == -1) {
        if (customers_count + 1 < CUSTOMER_MAX && customer_find_index(argp) == -1) {
            argp->id = customers_count;
            customers[customers_count] = *argp;
            result = customers_count++;
        }
    } else if (argp->id < customers_count) {
        if (customer_find_index(argp) != -1) {
            return &result;
        }
        customers[argp->id] = *argp;
        result = argp->id;
    }

    return &result;
}

customer *
customer_get_1_svc(int *id, struct svc_req *rqstp)
{
	static customer  result;

    if (id != NULL && *id >= 0 && *id < customers_count) {
        result = customers[*id];
    } else {
        result.id = -1;
    }

	return &result;
}
anyCustomers *
customer_get_all_1_svc(void *argp, struct svc_req *rqstp)
{
    static anyCustomers result;
    unsigned i;

    for(i = 0; i < customers_count; i++) {
        result.customers[i] = customers[i];
    }
    result.len = customers_count;

    return &result;
}

offer *
offer_get_1_svc(int *id, struct svc_req *rqstp)
{
	static offer  result;
    unsigned i;

    if (id != NULL && *id >= 0) {
        for(i = 0; i < OFFER_MAX; i++) {
            if (offers[i].id == *id) {
                result = offers[i];
                return &result;
            }
        }
    }
    result.id = -1;

	return &result;
}

int *
offer_create_1_svc(offer *o, struct svc_req *rqstp)
{
	static int  result = -1;
    unsigned i;

    if (o == NULL || offer_find_index(o) != -1)
        return &result;

    if (o->id < 0) {
        for(i = 0; i < OFFER_MAX; i++) {
            if (offers[i].id == -1) {
                o->id = offers_count;
                offers[i] = *o;
                result = offers_count++;
                break;
            }
        }
    } else {
        for(i = 0; i < OFFER_MAX; i++) {
            if (offers[i].id == o->id) {
                offers[i] = *o;
                result = o->id;
                break;
            }
        }
    }

	return &result;
}

int *
offer_delete_1_svc(int *id, struct svc_req *rqstp)
{
	static int  result = -1;
    unsigned i;

    if (id == NULL) {
        printf("ERREUR %s:%d l'id est null\n", __FILE__, __LINE__);
        return &result;
    }

    if (*id < 0) {
        printf("ERREUR %s:%d l'id est inférieur à 0\n", __FILE__, __LINE__);
        return &result;
    }

    for(i = 0; i < OFFER_MAX; i++) {
        if (offers[i].id == *id) {
            offers[i].id = -1;
	        result = *id;
            break;
        }
    }

	return &result;
}

anyOffers *
offer_get_all_1_svc(void *argp, struct svc_req *rqstp)
{
    static anyOffers result;
    unsigned i;

    result.len = 0;
    for(i = 0; i < OFFER_MAX; i++) {
        if (offers[i].id != -1) {
            result.offers[result.len++] = offers[i];
        }
    }

    return &result;
}

void *
init_1_svc(void *argp, struct svc_req *rqstp)
{
    static char result;
    unsigned i;

    for(i = 0; i < OFFER_MAX; i++) {
        offers[i].id = -1;
    }
    for (i = 0; i < SUPPLIER_MAX; i++) {
        suppliers[i].id = -1;
    }

    return (void *) &result;
}

int *
supplier_create_1_svc(supplier *s, struct svc_req *rqstp)
{
    static int result = -1;
    unsigned i;

    if (s == NULL) {
        printf("ERREUR %s:%d Le fournisseur est null\n", __FILE__, __LINE__);
    }

    if ((result = supplier_find_index(s)) != -1) {
        printf("ERREUR %s:%d Le fournisseur existe déjà\n", __FILE__, __LINE__);
        return &result;
    }

    if (s->id < 0) {
        for (i = 0; i < SUPPLIER_MAX; i++) {
            if (suppliers[i].id == -1) {
                s->id = supplier_count;
                suppliers[i] = *s;
                result = supplier_count++;
                break;
            }
        }
    } else {
        for (i = 0; i < SUPPLIER_MAX; i++) {
            if (suppliers[i].id == s->id) {
                suppliers[i] = *s;
                result = s->id;
                break;
            }
        }
    }

    return &result;
}

supplier *
supplier_get_1_svc(int *id, struct svc_req *rqstp)
{
    static supplier result;
    unsigned i;

    if (id != NULL && *id >= 0) {
        for (i = 0; i < SUPPLIER_MAX; i++) {
            if (suppliers[i].id == *id) {
                result = suppliers[i];
                return &result;
            }
        }
    }
    result.id = -1;

    return &result;
}

int *
supplier_delete_1_svc(int *id, struct svc_req *rqstp)
{
    static int result = -1;
    unsigned i;

    if (id == NULL || *id < 0)
        return &result;

    for (i = 0; i < SUPPLIER_MAX; i++) {
        if (suppliers[i].id  == *id) {
            suppliers[i].id = -1;
            result = *id;
            break;
        }
    }

    return &result;
}

anySuppliers *
supplier_get_all_1_svc(supplierType *type, struct svc_req *rqstp)
{
    static anySuppliers result;
    unsigned i;

    result.len = 0;
    if (type == NULL)
        return &result;

    if (*type == UNKNOWN_OFFER) {
        for (i = 0; i < SUPPLIER_MAX; i++) {
            if (suppliers[i].id != -1) {
                result.suppliers[result.len++] = suppliers[i];
            }
        }
    } else {
        for (i = 0; i < SUPPLIER_MAX; i++) {
            if (suppliers[i].id != -1 && suppliers[i].type == *type) {
                result.suppliers[result.len++] = suppliers[i];
            }
        }
    }

    return &result;
}

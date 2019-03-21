const NB_CUSTOMER=10;
const BIRTH_DATE_LEN=11;
const BUF_LEN=20;

enum typeOffer {
    UNKNOWN_OFFER,
    PACKED_VEGETABLES,
    FISH_RECIPES,
    PACKED_FRUITS
};

enum supplierType {
    UNKOWN_SUPPLIER,
    VEGETABLES_SUPPLIER,
    FISH_SUPPLIER,
    FRUITS_SUPPLIER
};

struct customer {
    int id;
    char birth_date[BIRTH_DATE_LEN];
    char name[BUF_LEN];
    char surname[BUF_LEN];
    char address[BUF_LEN];
};

struct offer {
    int id;
    enum typeOffer type;
    double price;
    unsigned short nb;
};

struct anyCustomers {
    struct customer customers[10];
    unsigned len;
};

struct anyOffers {
    struct offer offers[10];
    unsigned len;
};

struct supplier {
    int id;
    char surname[BUF_LEN];
    char address[BUF_LEN];
    enum supplierType type;
};

struct anySuppliers {
    struct supplier suppliers[10];
    unsigned len;
};

program PACKED_BIO {
	version PACKED_BIO_VER {
        int CUSTOMER_UPDATE_OR_CREATE(customer) = 1;
        customer CUSTOMER_GET(int) = 2;
        anyCustomers CUSTOMER_GET_ALL() = 3;
        offer OFFER_GET(int) = 4;
        int OFFER_CREATE(offer) = 5;
        int OFFER_DELETE(int) = 6;
        anyOffers OFFER_GET_ALL() = 7;
        void INIT(void) = 8;
        int SUPPLIER_CREATE(supplier) = 9;
        supplier SUPPLIER_GET(int) = 10;
        int SUPPLIER_DELETE(int) = 11;
        anySuppliers SUPPLIER_GET_ALL(supplierType) = 12;
	} = 1 ;
} = 0x23456789;

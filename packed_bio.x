const NB_CUSTOMER=10;
const BIRTH_DATE_LEN=11;
const BUF_LEN=20;

enum typeOffer {
    UNKNOWN_OFFER,
    PACKED_VEGETABLES,
    FISH_RECIPES,
    PACKED_FRUITS
};

enum packedLunch {
    PL_PETIT = 16,
    PL_MOYEN = 24,
    PL_GRAND = 30
};

enum fishRecipes {
    FR_PETIT = 2,
    FR_MOYEN = 4,
    FR_GRAND = 6
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
	} = 1 ;
} = 0x23456789;

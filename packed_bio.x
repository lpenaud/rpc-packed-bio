const NB_CUSTOMER=10;
const BIRTH_DATE_LEN=11;
const BUF_LEN=20;

enum typeOffer {
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
};

program PACKED_BIO {
	version PACKED_BIO_VER {
        int CUSTOMER_UPDATE_OR_CREATE(customer) = 1;
        customer CUSTOMER_GET(int) = 2;
        offer OFFER_GET(int) = 3;
        offer OFFER_CREATE(offer) = 4;
        int OFFRE_DELETE(offer) = 5;
	} = 1 ;
} = 0x23456789;


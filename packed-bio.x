const NB_CUSTOMER=10;
const BUF_LEN=80;

struct customer {
    int id;
    char birth_date[10];
    char name[BUF_LEN];
    char surname[BUF_LEN];
    char address[80];
};

program PACKED_BIO {
	version PACKED_BIO_VER {
        int CUSTOMER_NEW(customer) = 1;
	} = 1 ;
} = 0x23456789;

